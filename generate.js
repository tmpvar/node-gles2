// this is used to generate node based webgl bindings
var get = require('request').get;
var fs = require('fs');

get('http://www.khronos.org/registry/gles/api/2.0/gl2.h', function(err, res, headerString) {

  var cc = [
    '#include <node.h>',
    '#include <v8.h>',
    '#include "arch_wrapper.h"',
    '',
    'using namespace v8;',
    'using namespace node;',
    '',
    ''
  ],
  init = [
    'void init(Handle<Object> target) {',
  ],
  initPost = [
    '}',
    '',
    'NODE_MODULE(gles2, init)',
  ];


  // Methods
  init.push('');
  init.push('  // Methods')
  headerString.match(/GL_APICALL .+ GL_APIENTRY gl[^;]+/g).forEach(function(fn) {
      var parts = fn.replace(/[\(\),]/g, '').replace(/ *GL_APIENTRY/g, '').replace(/GL_APICALL /g, '').split(' ');
      var signature = {};

      signature.returnType = parts.shift();
      if ( signature.returnType === 'const') {
        console.log('here');
         signature.returnType += ' ' + parts.shift();
         console.log(signature.returnType, parts);
      }

      var fnName = signature.name = parts.shift();
      var upper = fnName[0].toUpperCase() + fnName.substring(1);
      signature.arguments = {};
      signature.list = [];

      while (parts.length) {
        var argType = parts.shift();
        if (argType === 'const') {
          argType += ' ' + parts.shift();
        } else if (argType === '') {
          continue;
        } else if (parts.length === 0 && argType === 'void') {
          break;
        }

        var argName = parts.shift();
        if (argName === '') {
         continue
        }

        if (!argName || !argType) {
          console.log(signature, parts.length);
          throw new Error(argName + ' : ' + argType + ' : ' + fn);
        }
        signature.arguments[argName] = argType;
        signature.list.push(argName);
      }


      cc.push('Handle<Value> ' + upper  + '(const Arguments& args) {');
      cc.push('  HandleScope scope;');
      cc.push('');

      // collect arguments
      signature.list.forEach(function(name, i) {

        var type = this.arguments[name];

        switch (type) {
          case 'GLenum':
          case 'GLint':
          case 'GLsizei':
          case 'GLbitfield':
            cc.push('  ' + type + ' ' + name + ' = args[' + i + ']->Int32Value();')
          break;

          case 'GLboolean':
            cc.push('  ' + type + ' ' + name + ' = (GLboolean)args[' + i + ']->Int32Value();')
          break;

          case 'GLuint':
          case 'GLsizeiptr':
          case 'GLintptr':
            cc.push('  ' + type + ' ' + name + ' = args[' + i + ']->Uint32Value();')
          break;

          case 'GLfloat':
          case 'GLclampf':
            cc.push('  ' + type + ' ' + name + ' = args[' + i + ']->NumberValue();')
          break;

          case 'const GLchar*':
            cc.push('  v8::String::Utf8Value string_' + name + '(args[' + i + ']);')
            cc.push('  ' + type + ' ' + name + ' = *string_' + name + ';');
          break;

          case 'const GLvoid*':
          case 'const GLfloat*':
            cc.push('');
            cc.push('  // buffer');
            cc.push('  Local<Object> obj_' + name + ' = args[0]->ToObject();');
            cc.push('  if (obj_' + name + '->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {');
            cc.push('    ');
            cc.push('  }');
            cc.push('  ' + type + ' '+ name + ' = static_cast<' + type + '>(obj_' + name + '->GetIndexedPropertiesExternalArrayData());');
            cc.push('');
          break;


          case 'const GLuint*':
            cc.push('');
            cc.push('  // list of Gluints');
            cc.push('  Handle<Array> array_' + name + ' = Handle<Array>::Cast(args[' + i + ']);');
            cc.push('  int length = array_' + name + '->Get(String::New("length"))->ToObject()->Uint32Value();');
            cc.push('  ' + type.replace('*', '').replace('const ', '') + ' ' + name + '[length];');
            cc.push('  for (int i=0; i<length; i++) {');
            cc.push('    ' + name + '[i] = array_' + name + '->Get(i)->ToObject()->Uint32Value();');
            cc.push('  }');
            cc.push('');
          break;

        }

      }.bind(signature));

      cc.push('');

      if (signature.returnType === 'void') {
        cc.push('  ' + signature.name + '(' + Object.keys(signature.arguments).join(', ') + ');');
      }



      init.push('  SetMethod(target, "' + fnName + '", ' + upper + ');');

      cc.push('  return scope.Close(Undefined());');
      cc.push('}');
      cc.push('');
  });



  // CONSTANTS
  init.push('');
  init.push('  // Constants')
  headerString.match(/#define (GL_[^ ]+).*/g).forEach(function(constant) {
    constant = constant.replace(/[ ]*\/\*.*\*\/[ ]*/, '');
    constant = constant.replace('#define ', '').replace(/(  *)/g,'", ');
    init.push('  DEFINE_CONSTANT(target, "' + constant + ');');
  });
  init.push('');

  var out = cc.join('\n') + init.join('\n') + initPost.join('\n') + '\n';

  fs.writeFile(__dirname + '/src/gles2.cc', out, function() {});
});
/*
  var functions = {};
  // build a lookup tree
  functionMatches.forEach(function(fn) {
    var where = functions;

    var signature = {};
    var parts = fn.replace(/[\(\),]/g, '').replace(/ *GL_APIENTRY/g, '').replace(/GL_APICALL /g, '').split(' ');

    signature.returnType = parts.shift();
    if (signature.returnType === 'const') {
      signature.returnType += ' ' + parts.shift();
    }

    var fnName = signature.name = parts.shift();
    signature.arguments = {};
    signature.list = [];

    while (parts.length) {
      var argType = parts.shift();
      if (argType === 'const') {
        argType += ' ' + parts.shift();
      } else if (argType === '') {
        continue;
      } else if (parts.length === 0 && argType === 'void') {
        break;
      }

      var argName = parts.shift();
      if (argName === '') {
       continue
      }


      if (!argName || !argType) {
        console.log(signature, parts.length);
        throw new Error(argName + ' : ' + argType + ' : ' + fn);
      }
      signature.arguments[argName] = argType;
      signature.list.push(argName);
    }


    signature.deploy = function() {
      var ret = [''];
      // collect arguments
      this.list.forEach(function(name, i) {

        var type = this.arguments[name];

        switch (type) {
          case 'GLenum':
          case 'GLint':
            ret.push('  ' + type + ' ' + name + ' = args[' + i + ']->Int32Value();')
          break;
          case 'GLfloat':
            ret.push('  ' + type + ' ' + name + ' = args[' + i + ']->NumberValue();')
          break;

        }

      }.bind(this));

      ret.push('');
      ret.push('  scope.Close(Undefined());');
      return ret.join('\n');
    }

    for (var i=0; i<fnName.length; i++) {
      if (!where[fnName.charAt(i)]) {
        where[fnName.charAt(i)] = {
          members : []
        };
      }
      where = where[fnName.charAt(i)];
      where.members.push(signature);
    }
  });

  function lookup(fn) {

    var ignore = {
      isContextLost : true,
      getSupportedExtensions : true,
      getExtension : true,
      getContextAttributes : true,
      createBuffer : true,
      createFramebuffer : true,
      createRenderbuffer : true,
      createTexture : true,
      getParameter : true,
      getProgramParameter : true,
      getShaderParameter : true,
      getVertexAttribOffset : true
    };

    if (ignore[fn]) {
      console.log('warning!');
      return null;
    }

    fn = 'gl' + fn[0].toUpperCase() + fn.substring(1);
    var where = functions;
    var path = [];
    for (var i=0; i<fn.length; i++) {

      if (where[fn[i]]) {
        path.push(fn[i]);
        where = where[fn[i]];
      }
    }


    if (!where || !where.members || !where.members[0] || where.members[0].name.indexOf(fn) < 0) {
      console.log('PATH', path.join(''));
      console.log('looking for', fn, 'found', where.members[0].name)
      console.log(where)
      throw new Error('Unknown function' + fn);
    }

    return where.members[0];
  }



  // collect the latest idl
  get('https://www.khronos.org/registry/webgl/specs/latest/webgl.idl', function(e, r, body) {
    body = body.replace(/typedef.* /g, '');
    var tree = webidl.parse(body);

    // calculate declarations and params for future reference
    tree.forEach(function(item) {
      objects[item.name] = {};
    });

    tree.forEach(handleTopLevel);
    saveFiles();
  });

  function handleTopLevel(item) {

    var filename = item.name;
    var h = [
      '#ifndef _' + filename + '_H',
      '#define _' + filename + '_H',
      '',

      'class ' + filename + ' : public ObjectWrap {',
      '  public:',
      '    static void Init(Handle<Object> target);',
      ''
    ],
    cc = [
      '#include "' + filename + '.h"',
      '#include "arch_wrapper.h"', '',
      '',
      filename + '::' + filename + '() {};',
      filename + '::~' + filename + '() {};',
      ''
    ];

    // generate New
    cc.push('Handle<Value> ' + filename  + '::New(const Arguments& args) {');
    cc.push('  HandleScope scope;');
    cc.push('');
    // TODO: do arguments
    cc.push('  ' + filename + '* obj = new ' + filename + '();');
    cc.push('  obj->Wrap(args.This());');
    cc.push('  return scope.Close(args.This());')
    cc.push('}');

    // generate init
    cc.push('void ' + filename + '::Init(Handle<Object> target) {')

    var seen = {};
    item.members.forEach(function(member) {
      if (seen[member.name]) { return; }
      seen[member.name] = true;

      switch (member.type) {
        case 'operation':
          var upper = member.name[0].toUpperCase() + member.name.substring(1);

          cc.push('  SetMethod(target, "' + member.name + '", ' + upper + ');');
        break;

        case 'const':
          if (constants['GL_' + member.name]) {
            cc.push('  DEFINE_CONSTANT(target, "' + member.name + '", ' + member.value + ');');
          }
        break;
      }
    });

    cc.push('}');

    h.push('  private:');
    h.push('    ' + filename + '();');
    h.push('    ~' + filename + '();');
    h.push('    static Handle<Value> New(const Arguments& args);');
    h.push('');

    // reset seen, dirty dirty hacks
    seen = {};
    item.members.forEach(function(member) {
      if (seen[member.name]) { return; }
      seen[member.name] = true;

      var upper = member.name[0].toUpperCase() + member.name.substring(1);

      switch (member.type) {
        case 'operation':
          h.push('    static Handle<Value> ' + upper + '(const Arguments& args);');

          cc.push('Handle<Value> ' + filename + '::' + upper + '(const Arguments& args) {');
          cc.push('  HandleScope scope;');

          var functionHandle = lookup(member.name);
          console.log(functionHandle);
          functionHandle && cc.push(functionHandle.deploy());

          cc.push('}')

        break;

        case 'const':

        break;

        case 'attribute':
        break;


        default:
          console.log(member);
        break;
      }
    });


    // Suffix
    h.push('};')
    h.push('#endif');

    objects[filename].h = h;
    objects[filename].cc = cc;
  }

  function saveFiles() {
    rimraf(__dirname + '/src', function() {
      fs.mkdirSync(__dirname + '/src');

      fs.createReadStream(__dirname + '/generate/arch_wrapper.h')
        .pipe(fs.createWriteStream(__dirname + '/src/arch_wrapper.h')).on('close', function() {

        var files = ['src/webgl.cc'];
        Object.keys(objects).forEach(function(file) {
          files.push('src/' + file + '.cc')
          fs.writeFileSync(__dirname + '/src/' + file + '.h', objects[file].h.join('\n'))
          fs.writeFileSync(__dirname + '/src/' + file + '.cc', objects[file].cc.join('\n'))
        });

        fs.writeFileSync(__dirname + '/src/webgl.cc', [
          '#include <node.h>',
          'using namespace node;',
          'using namespace v8;',
          '',
          '#include "' + Object.keys(objects).join('.h"\n#include "') + '.h"',
          '',
          'void init(Handle<Object> target) {',
          '  ' + Object.keys(objects).join('::Init(target);\n  ') + '::Init(target);',
          '}',
          '',
          'NODE_MODULE(webgl, init)',
          ''
        ].join('\n'));

        var binding = JSON.parse(fs.readFileSync(__dirname + '/binding.gyp').toString());
        binding.targets[0].sources = files;
        fs.writeFileSync(__dirname + '/binding.gyp', JSON.stringify(binding, null, '  '));
      });
    });
  }
});*/