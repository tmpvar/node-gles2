module.exports = {};

var gl = require('bindings')('gles2');

// ignore initialization errors on OSX
gl.glGetError();

Object.keys(gl).forEach(function(method) {
  var orig = method;
  if (method[0] === 'g') {
    method = method.substring(2);
    method = method[0].toLowerCase() + method.substring(1);

    if (typeof gl[orig] === 'function') {
      module.exports[method] = function() {
        var args = [];
        Array.prototype.push.apply(args, arguments);
console.log(args);
        var ret = gl[orig].apply(null, args);

        console.log('call:', orig + '(' + args.join(',') + ')');
        console.log('result: ', ret);
        var error = gl.glGetError();
        console.log('error:', error);
        console.log('');

        if (error) {
          throw new Error(error);
        }

        return ret;
      };
    } else {
      module.exports[method] = gl[orig];
    }
  } else {
    module.exports[method.replace('GL_', '')] = gl[method];
  }
});
