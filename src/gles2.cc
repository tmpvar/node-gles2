#include <node.h>
#include <node_buffer.h>
#include <v8.h>
#include "arch_wrapper.h"

using namespace v8;
using namespace node;


Handle<Value> GlActiveTexture(const Arguments& args) {
  HandleScope scope;

  GLenum texture = args[0]->Int32Value();

  glActiveTexture(texture);
  return scope.Close(Undefined());
}

Handle<Value> GlAttachShader(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLuint shader = args[1]->Uint32Value();

  glAttachShader(program, shader);
  return scope.Close(Undefined());
}

Handle<Value> GlBindAttribLocation(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLuint index = args[1]->Uint32Value();
  v8::String::Utf8Value string_name(args[2]);
  const GLchar* name = *string_name;

  glBindAttribLocation(program, index, name);
  return scope.Close(Undefined());
}

Handle<Value> GlBindBuffer(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLuint buffer = args[1]->Uint32Value();

  glBindBuffer(target, buffer);
  return scope.Close(Undefined());
}

Handle<Value> GlBindFramebuffer(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLuint framebuffer = args[1]->Uint32Value();

  glBindFramebuffer(target, framebuffer);
  return scope.Close(Undefined());
}

Handle<Value> GlBindRenderbuffer(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLuint renderbuffer = args[1]->Uint32Value();

  glBindRenderbuffer(target, renderbuffer);
  return scope.Close(Undefined());
}

Handle<Value> GlBindTexture(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLuint texture = args[1]->Uint32Value();

  glBindTexture(target, texture);
  return scope.Close(Undefined());
}

Handle<Value> GlBlendColor(const Arguments& args) {
  HandleScope scope;

  GLclampf red = args[0]->NumberValue();
  GLclampf green = args[1]->NumberValue();
  GLclampf blue = args[2]->NumberValue();
  GLclampf alpha = args[3]->NumberValue();

  glBlendColor(red, green, blue, alpha);
  return scope.Close(Undefined());
}

Handle<Value> GlBlendEquation(const Arguments& args) {
  HandleScope scope;

  GLenum mode = args[0]->Int32Value();

  glBlendEquation(mode);
  return scope.Close(Undefined());
}

Handle<Value> GlBlendEquationSeparate(const Arguments& args) {
  HandleScope scope;

  GLenum modeRGB = args[0]->Int32Value();
  GLenum modeAlpha = args[1]->Int32Value();

  glBlendEquationSeparate(modeRGB, modeAlpha);
  return scope.Close(Undefined());
}

Handle<Value> GlBlendFunc(const Arguments& args) {
  HandleScope scope;

  GLenum sfactor = args[0]->Int32Value();
  GLenum dfactor = args[1]->Int32Value();

  glBlendFunc(sfactor, dfactor);
  return scope.Close(Undefined());
}

Handle<Value> GlBlendFuncSeparate(const Arguments& args) {
  HandleScope scope;

  GLenum srcRGB = args[0]->Int32Value();
  GLenum dstRGB = args[1]->Int32Value();
  GLenum srcAlpha = args[2]->Int32Value();
  GLenum dstAlpha = args[3]->Int32Value();

  glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
  return scope.Close(Undefined());
}

Handle<Value> GlBufferData(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLsizeiptr size = args[1]->Uint32Value();

  // buffer
  Local<Object> obj_data = args[2]->ToObject();
  if (obj_data->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glBufferData expects a Buffer for argument 2")));
    return scope.Close(Undefined());
  }
  const GLvoid* data = static_cast<const GLvoid*>(obj_data->GetIndexedPropertiesExternalArrayData());

  GLenum usage = args[3]->Int32Value();

  glBufferData(target, size, data, usage);
  return scope.Close(Undefined());
}

Handle<Value> GlBufferSubData(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLintptr offset = args[1]->Uint32Value();
  GLsizeiptr size = args[2]->Uint32Value();

  // buffer
  Local<Object> obj_data = args[3]->ToObject();
  if (obj_data->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glBufferSubData expects a Buffer for argument 3")));
    return scope.Close(Undefined());
  }
  const GLvoid* data = static_cast<const GLvoid*>(obj_data->GetIndexedPropertiesExternalArrayData());


  glBufferSubData(target, offset, size, data);
  return scope.Close(Undefined());
}

Handle<Value> GlCheckFramebufferStatus(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();

  GLenum ret = glCheckFramebufferStatus(target);
  return scope.Close(Number::New(ret));
}

Handle<Value> GlClear(const Arguments& args) {
  HandleScope scope;

  GLbitfield mask = args[0]->Int32Value();

  glClear(mask);
  return scope.Close(Undefined());
}

Handle<Value> GlClearColor(const Arguments& args) {
  HandleScope scope;

  GLclampf red = args[0]->NumberValue();
  GLclampf green = args[1]->NumberValue();
  GLclampf blue = args[2]->NumberValue();
  GLclampf alpha = args[3]->NumberValue();

  glClearColor(red, green, blue, alpha);
  return scope.Close(Undefined());
}

Handle<Value> GlClearDepthf(const Arguments& args) {
  HandleScope scope;

  GLclampf depth = args[0]->NumberValue();

  glClearDepthf(depth);
  return scope.Close(Undefined());
}

Handle<Value> GlClearStencil(const Arguments& args) {
  HandleScope scope;

  GLint s = args[0]->Int32Value();

  glClearStencil(s);
  return scope.Close(Undefined());
}

Handle<Value> GlColorMask(const Arguments& args) {
  HandleScope scope;

  GLboolean red = (GLboolean)args[0]->Int32Value();
  GLboolean green = (GLboolean)args[1]->Int32Value();
  GLboolean blue = (GLboolean)args[2]->Int32Value();
  GLboolean alpha = (GLboolean)args[3]->Int32Value();

  glColorMask(red, green, blue, alpha);
  return scope.Close(Undefined());
}

Handle<Value> GlCompileShader(const Arguments& args) {
  HandleScope scope;

  GLuint shader = args[0]->Uint32Value();

  glCompileShader(shader);
  return scope.Close(Undefined());
}

Handle<Value> GlCompressedTexImage2D(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLint level = args[1]->Int32Value();
  GLenum internalformat = args[2]->Int32Value();
  GLsizei width = args[3]->Int32Value();
  GLsizei height = args[4]->Int32Value();
  GLint border = args[5]->Int32Value();
  GLsizei imageSize = args[6]->Int32Value();

  // buffer
  Local<Object> obj_data = args[7]->ToObject();
  if (obj_data->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glCompressedTexImage2D expects a Buffer for argument 7")));
    return scope.Close(Undefined());
  }
  const GLvoid* data = static_cast<const GLvoid*>(obj_data->GetIndexedPropertiesExternalArrayData());


  glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
  return scope.Close(Undefined());
}

Handle<Value> GlCompressedTexSubImage2D(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLint level = args[1]->Int32Value();
  GLint xoffset = args[2]->Int32Value();
  GLint yoffset = args[3]->Int32Value();
  GLsizei width = args[4]->Int32Value();
  GLsizei height = args[5]->Int32Value();
  GLenum format = args[6]->Int32Value();
  GLsizei imageSize = args[7]->Int32Value();

  // buffer
  Local<Object> obj_data = args[8]->ToObject();
  if (obj_data->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glCompressedTexSubImage2D expects a Buffer for argument 8")));
    return scope.Close(Undefined());
  }
  const GLvoid* data = static_cast<const GLvoid*>(obj_data->GetIndexedPropertiesExternalArrayData());


  glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
  return scope.Close(Undefined());
}

Handle<Value> GlCopyTexImage2D(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLint level = args[1]->Int32Value();
  GLenum internalformat = args[2]->Int32Value();
  GLint x = args[3]->Int32Value();
  GLint y = args[4]->Int32Value();
  GLsizei width = args[5]->Int32Value();
  GLsizei height = args[6]->Int32Value();
  GLint border = args[7]->Int32Value();

  glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
  return scope.Close(Undefined());
}

Handle<Value> GlCopyTexSubImage2D(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLint level = args[1]->Int32Value();
  GLint xoffset = args[2]->Int32Value();
  GLint yoffset = args[3]->Int32Value();
  GLint x = args[4]->Int32Value();
  GLint y = args[5]->Int32Value();
  GLsizei width = args[6]->Int32Value();
  GLsizei height = args[7]->Int32Value();

  glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
  return scope.Close(Undefined());
}

Handle<Value> GlCreateProgram(const Arguments& args) {
  HandleScope scope;


  GLuint ret = glCreateProgram();
  return scope.Close(Number::New(ret));
}

Handle<Value> GlCreateShader(const Arguments& args) {
  HandleScope scope;

  GLenum type = args[0]->Int32Value();

  GLuint ret = glCreateShader(type);
  return scope.Close(Number::New(ret));
}

Handle<Value> GlCullFace(const Arguments& args) {
  HandleScope scope;

  GLenum mode = args[0]->Int32Value();

  glCullFace(mode);
  return scope.Close(Undefined());
}

Handle<Value> GlDeleteBuffers(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  // list of Gluints
  Handle<Array> array_buffers = Handle<Array>::Cast(args[1]);
  int length_1 = array_buffers->Get(String::New("length"))->ToObject()->Uint32Value();
  GLuint buffers[length_1];
  for (int i=0; i<length_1; i++) {
    buffers[i] = array_buffers->Get(i)->ToObject()->Uint32Value();
  }


  glDeleteBuffers(n, buffers);
  return scope.Close(Undefined());
}

Handle<Value> GlDeleteFramebuffers(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  // list of Gluints
  Handle<Array> array_framebuffers = Handle<Array>::Cast(args[1]);
  int length_1 = array_framebuffers->Get(String::New("length"))->ToObject()->Uint32Value();
  GLuint framebuffers[length_1];
  for (int i=0; i<length_1; i++) {
    framebuffers[i] = array_framebuffers->Get(i)->ToObject()->Uint32Value();
  }


  glDeleteFramebuffers(n, framebuffers);
  return scope.Close(Undefined());
}

Handle<Value> GlDeleteProgram(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();

  glDeleteProgram(program);
  return scope.Close(Undefined());
}

Handle<Value> GlDeleteRenderbuffers(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  // list of Gluints
  Handle<Array> array_renderbuffers = Handle<Array>::Cast(args[1]);
  int length_1 = array_renderbuffers->Get(String::New("length"))->ToObject()->Uint32Value();
  GLuint renderbuffers[length_1];
  for (int i=0; i<length_1; i++) {
    renderbuffers[i] = array_renderbuffers->Get(i)->ToObject()->Uint32Value();
  }


  glDeleteRenderbuffers(n, renderbuffers);
  return scope.Close(Undefined());
}

Handle<Value> GlDeleteShader(const Arguments& args) {
  HandleScope scope;

  GLuint shader = args[0]->Uint32Value();

  glDeleteShader(shader);
  return scope.Close(Undefined());
}

Handle<Value> GlDeleteTextures(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  // list of Gluints
  Handle<Array> array_textures = Handle<Array>::Cast(args[1]);
  int length_1 = array_textures->Get(String::New("length"))->ToObject()->Uint32Value();
  GLuint textures[length_1];
  for (int i=0; i<length_1; i++) {
    textures[i] = array_textures->Get(i)->ToObject()->Uint32Value();
  }


  glDeleteTextures(n, textures);
  return scope.Close(Undefined());
}

Handle<Value> GlDepthFunc(const Arguments& args) {
  HandleScope scope;

  GLenum func = args[0]->Int32Value();

  glDepthFunc(func);
  return scope.Close(Undefined());
}

Handle<Value> GlDepthMask(const Arguments& args) {
  HandleScope scope;

  GLboolean flag = (GLboolean)args[0]->Int32Value();

  glDepthMask(flag);
  return scope.Close(Undefined());
}

Handle<Value> GlDepthRangef(const Arguments& args) {
  HandleScope scope;

  GLclampf zNear = args[0]->NumberValue();
  GLclampf zFar = args[1]->NumberValue();

  glDepthRangef(zNear, zFar);
  return scope.Close(Undefined());
}

Handle<Value> GlDetachShader(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLuint shader = args[1]->Uint32Value();

  glDetachShader(program, shader);
  return scope.Close(Undefined());
}

Handle<Value> GlDisable(const Arguments& args) {
  HandleScope scope;

  GLenum cap = args[0]->Int32Value();

  glDisable(cap);
  return scope.Close(Undefined());
}

Handle<Value> GlDisableVertexAttribArray(const Arguments& args) {
  HandleScope scope;

  GLuint index = args[0]->Uint32Value();

  glDisableVertexAttribArray(index);
  return scope.Close(Undefined());
}

Handle<Value> GlDrawArrays(const Arguments& args) {
  HandleScope scope;

  GLenum mode = args[0]->Int32Value();
  GLint first = args[1]->Int32Value();
  GLsizei count = args[2]->Int32Value();

  glDrawArrays(mode, first, count);
  return scope.Close(Undefined());
}

Handle<Value> GlDrawElements(const Arguments& args) {
  HandleScope scope;

  GLenum mode = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();
  GLenum type = args[2]->Int32Value();

  // buffer
  Local<Object> obj_indices = args[3]->ToObject();
  if (obj_indices->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glDrawElements expects a Buffer for argument 3")));
    return scope.Close(Undefined());
  }
  const GLvoid* indices = static_cast<const GLvoid*>(obj_indices->GetIndexedPropertiesExternalArrayData());


  glDrawElements(mode, count, type, indices);
  return scope.Close(Undefined());
}

Handle<Value> GlEnable(const Arguments& args) {
  HandleScope scope;

  GLenum cap = args[0]->Int32Value();

  glEnable(cap);
  return scope.Close(Undefined());
}

Handle<Value> GlEnableVertexAttribArray(const Arguments& args) {
  HandleScope scope;

  GLuint index = args[0]->Uint32Value();

  glEnableVertexAttribArray(index);
  return scope.Close(Undefined());
}

Handle<Value> GlFinish(const Arguments& args) {
  HandleScope scope;


  glFinish();
  return scope.Close(Undefined());
}

Handle<Value> GlFlush(const Arguments& args) {
  HandleScope scope;


  glFlush();
  return scope.Close(Undefined());
}

Handle<Value> GlFramebufferRenderbuffer(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum attachment = args[1]->Int32Value();
  GLenum renderbuffertarget = args[2]->Int32Value();
  GLuint renderbuffer = args[3]->Uint32Value();

  glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
  return scope.Close(Undefined());
}

Handle<Value> GlFramebufferTexture2D(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum attachment = args[1]->Int32Value();
  GLenum textarget = args[2]->Int32Value();
  GLuint texture = args[3]->Uint32Value();
  GLint level = args[4]->Int32Value();

  glFramebufferTexture2D(target, attachment, textarget, texture, level);
  return scope.Close(Undefined());
}

Handle<Value> GlFrontFace(const Arguments& args) {
  HandleScope scope;

  GLenum mode = args[0]->Int32Value();

  glFrontFace(mode);
  return scope.Close(Undefined());
}

Handle<Value> GlGenBuffers(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  Handle<Array> ret = Array::New(n);
  GLuint* buffers = 0;

  glGenBuffers(n, buffers);

  for (int i_1=0; i_1 < n; i_1++) {
    ret->Set(Number::New(i_1), Number::New(buffers[i_1]));
  }
  return scope.Close(ret);
}

Handle<Value> GlGenerateMipmap(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();

  glGenerateMipmap(target);
  return scope.Close(Undefined());
}

Handle<Value> GlGenFramebuffers(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  Handle<Array> ret = Array::New(n);
  GLuint* framebuffers = 0;

  glGenFramebuffers(n, framebuffers);

  for (int i_1=0; i_1 < n; i_1++) {
    ret->Set(Number::New(i_1), Number::New(framebuffers[i_1]));
  }
  return scope.Close(ret);
}

Handle<Value> GlGenRenderbuffers(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  Handle<Array> ret = Array::New(n);
  GLuint* renderbuffers = 0;

  glGenRenderbuffers(n, renderbuffers);

  for (int i_1=0; i_1 < n; i_1++) {
    ret->Set(Number::New(i_1), Number::New(renderbuffers[i_1]));
  }
  return scope.Close(ret);
}

Handle<Value> GlGenTextures(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  Handle<Array> ret = Array::New(n);
  GLuint* textures = 0;

  glGenTextures(n, textures);

  for (int i_1=0; i_1 < n; i_1++) {
    ret->Set(Number::New(i_1), Number::New(textures[i_1]));
  }
  return scope.Close(ret);
}

Handle<Value> GlGetActiveAttrib(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLuint index = args[1]->Uint32Value();
  GLsizei bufsize = args[2]->Int32Value();
  GLsizei length_base = 0;
  GLsizei* length = &length_base;
  GLint size_base = 0;
  GLint* size = &size_base;
  GLenum type_base = 0;
  GLenum* type = &type_base;
  GLchar name[bufsize];

  glGetActiveAttrib(program, index, bufsize, length, size, type, name);

  return scope.Close(String::New(name));
}

Handle<Value> GlGetActiveUniform(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLuint index = args[1]->Uint32Value();
  GLsizei bufsize = args[2]->Int32Value();
  GLsizei length_base = 0;
  GLsizei* length = &length_base;
  GLint size_base = 0;
  GLint* size = &size_base;
  GLenum type_base = 0;
  GLenum* type = &type_base;
  GLchar name[bufsize];

  glGetActiveUniform(program, index, bufsize, length, size, type, name);

  return scope.Close(String::New(name));
}

Handle<Value> GlGetAttachedShaders(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLsizei maxcount = args[1]->Int32Value();
  GLsizei count_base = 0;
  GLsizei* count = &count_base;

  Handle<Array> ret = Array::New(maxcount);
  GLuint* shaders = 0;

  glGetAttachedShaders(program, maxcount, count, shaders);

  for (int i_3=0; i_3 < maxcount; i_3++) {
    ret->Set(Number::New(i_3), Number::New(shaders[i_3]));
  }
  return scope.Close(ret);
}

Handle<Value> GlGetAttribLocation(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  v8::String::Utf8Value string_name(args[1]);
  const GLchar* name = *string_name;

  int ret = glGetAttribLocation(program, name);
  return scope.Close(Number::New(ret));
}

Handle<Value> GlGetBooleanv(const Arguments& args) {
  HandleScope scope;

  GLenum pname = args[0]->Int32Value();
  GLboolean params_base = 0;
  GLboolean* params = &params_base;

  glGetBooleanv(pname, params);

  return scope.Close(Boolean::New(params_base));
}

Handle<Value> GlGetBufferParameteriv(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetBufferParameteriv(target, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetError(const Arguments& args) {
  HandleScope scope;


  GLenum ret = glGetError();
  return scope.Close(Number::New(ret));
}

Handle<Value> GlGetFloatv(const Arguments& args) {
  HandleScope scope;

  GLenum pname = args[0]->Int32Value();
  GLfloat params_base = 0;
  GLfloat* params = &params_base;

  glGetFloatv(pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetFramebufferAttachmentParameteriv(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum attachment = args[1]->Int32Value();
  GLenum pname = args[2]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetIntegerv(const Arguments& args) {
  HandleScope scope;

  GLenum pname = args[0]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetIntegerv(pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetProgramiv(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLenum pname = args[1]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetProgramiv(program, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetProgramInfoLog(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLsizei bufsize = args[1]->Int32Value();
  GLsizei length_base = 0;
  GLsizei* length = &length_base;
  GLchar infolog[bufsize];

  glGetProgramInfoLog(program, bufsize, length, infolog);

  return scope.Close(String::New(infolog));
}

Handle<Value> GlGetRenderbufferParameteriv(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetRenderbufferParameteriv(target, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetShaderiv(const Arguments& args) {
  HandleScope scope;

  GLuint shader = args[0]->Uint32Value();
  GLenum pname = args[1]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetShaderiv(shader, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetShaderInfoLog(const Arguments& args) {
  HandleScope scope;

  GLuint shader = args[0]->Uint32Value();
  GLsizei bufsize = args[1]->Int32Value();
  GLsizei length_base = 0;
  GLsizei* length = &length_base;
  GLchar infolog[bufsize];

  glGetShaderInfoLog(shader, bufsize, length, infolog);

  return scope.Close(String::New(infolog));
}

Handle<Value> GlGetShaderPrecisionFormat(const Arguments& args) {
  HandleScope scope;

  GLenum shadertype = args[0]->Int32Value();
  GLenum precisiontype = args[1]->Int32Value();
  GLint range_base = 0;
  GLint* range = &range_base;
  GLint precision_base = 0;
  GLint* precision = &precision_base;

  glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);

  return scope.Close(Number::New(precision_base));
}

Handle<Value> GlGetShaderSource(const Arguments& args) {
  HandleScope scope;

  GLuint shader = args[0]->Uint32Value();
  GLsizei bufsize = args[1]->Int32Value();
  GLsizei length_base = 0;
  GLsizei* length = &length_base;
  GLchar source[bufsize];

  glGetShaderSource(shader, bufsize, length, source);

  return scope.Close(String::New(source));
}

Handle<Value> GlGetString(const Arguments& args) {
  HandleScope scope;

  GLenum name = args[0]->Int32Value();

  const GLubyte* ret = glGetString(name);
  return scope.Close(String::New((const char *)ret));
}

Handle<Value> GlGetTexParameterfv(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();
  GLfloat params_base = 0;
  GLfloat* params = &params_base;

  glGetTexParameterfv(target, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetTexParameteriv(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetTexParameteriv(target, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetUniformfv(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLint location = args[1]->Int32Value();
  GLfloat params_base = 0;
  GLfloat* params = &params_base;

  glGetUniformfv(program, location, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetUniformiv(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  GLint location = args[1]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetUniformiv(program, location, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetUniformLocation(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();
  v8::String::Utf8Value string_name(args[1]);
  const GLchar* name = *string_name;

  int ret = glGetUniformLocation(program, name);
  return scope.Close(Number::New(ret));
}

Handle<Value> GlGetVertexAttribfv(const Arguments& args) {
  HandleScope scope;

  GLuint index = args[0]->Uint32Value();
  GLenum pname = args[1]->Int32Value();
  GLfloat params_base = 0;
  GLfloat* params = &params_base;

  glGetVertexAttribfv(index, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetVertexAttribiv(const Arguments& args) {
  HandleScope scope;

  GLuint index = args[0]->Uint32Value();
  GLenum pname = args[1]->Int32Value();
  GLint params_base = 0;
  GLint* params = &params_base;

  glGetVertexAttribiv(index, pname, params);

  return scope.Close(Number::New(params_base));
}

Handle<Value> GlGetVertexAttribPointerv(const Arguments& args) {
  HandleScope scope;

   ThrowException(Exception::TypeError(String::New("glGetVertexAttribPointerv is not implemented please raise an issue https://github.com/tmpvar/node-gles2/issues")));
   return scope.Close(Undefined());
}
Handle<Value> GlHint(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum mode = args[1]->Int32Value();

  glHint(target, mode);
  return scope.Close(Undefined());
}

Handle<Value> GlIsBuffer(const Arguments& args) {
  HandleScope scope;

  GLuint buffer = args[0]->Uint32Value();

  GLboolean ret = glIsBuffer(buffer);
  return scope.Close(Boolean::New(ret));
}

Handle<Value> GlIsEnabled(const Arguments& args) {
  HandleScope scope;

  GLenum cap = args[0]->Int32Value();

  GLboolean ret = glIsEnabled(cap);
  return scope.Close(Boolean::New(ret));
}

Handle<Value> GlIsFramebuffer(const Arguments& args) {
  HandleScope scope;

  GLuint framebuffer = args[0]->Uint32Value();

  GLboolean ret = glIsFramebuffer(framebuffer);
  return scope.Close(Boolean::New(ret));
}

Handle<Value> GlIsProgram(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();

  GLboolean ret = glIsProgram(program);
  return scope.Close(Boolean::New(ret));
}

Handle<Value> GlIsRenderbuffer(const Arguments& args) {
  HandleScope scope;

  GLuint renderbuffer = args[0]->Uint32Value();

  GLboolean ret = glIsRenderbuffer(renderbuffer);
  return scope.Close(Boolean::New(ret));
}

Handle<Value> GlIsShader(const Arguments& args) {
  HandleScope scope;

  GLuint shader = args[0]->Uint32Value();

  GLboolean ret = glIsShader(shader);
  return scope.Close(Boolean::New(ret));
}

Handle<Value> GlIsTexture(const Arguments& args) {
  HandleScope scope;

  GLuint texture = args[0]->Uint32Value();

  GLboolean ret = glIsTexture(texture);
  return scope.Close(Boolean::New(ret));
}

Handle<Value> GlLineWidth(const Arguments& args) {
  HandleScope scope;

  GLfloat width = args[0]->NumberValue();

  glLineWidth(width);
  return scope.Close(Undefined());
}

Handle<Value> GlLinkProgram(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();

  glLinkProgram(program);
  return scope.Close(Undefined());
}

Handle<Value> GlPixelStorei(const Arguments& args) {
  HandleScope scope;

  GLenum pname = args[0]->Int32Value();
  GLint param = args[1]->Int32Value();

  glPixelStorei(pname, param);
  return scope.Close(Undefined());
}

Handle<Value> GlPolygonOffset(const Arguments& args) {
  HandleScope scope;

  GLfloat factor = args[0]->NumberValue();
  GLfloat units = args[1]->NumberValue();

  glPolygonOffset(factor, units);
  return scope.Close(Undefined());
}

Handle<Value> GlReadPixels(const Arguments& args) {
  HandleScope scope;

  GLint x = args[0]->Int32Value();
  GLint y = args[1]->Int32Value();
  GLsizei width = args[2]->Int32Value();
  GLsizei height = args[3]->Int32Value();
  GLenum format = args[4]->Int32Value();
  GLenum type = args[5]->Int32Value();

  GLvoid* pixels = 0;

  glReadPixels(x, y, width, height, format, type, pixels);

  unsigned long buffer_length = (width - x) * (height - y);
  int pixelComponents=0, bytesPerComponent=0;
  switch (format) {
    case GL_ALPHA:
      pixelComponents = 1;
    break;
    case GL_RGB:
      pixelComponents = 3;
    break;
    case GL_RGBA:
      pixelComponents = 4;
    break;
  }

  switch (type) {
    case GL_UNSIGNED_SHORT_5_6_5:
    case GL_UNSIGNED_SHORT_4_4_4_4:
    case GL_UNSIGNED_SHORT_5_5_5_1:
      bytesPerComponent = 2;
    break;

    case GL_UNSIGNED_BYTE:
      bytesPerComponent = 1;
    break;
  }

  buffer_length *= bytesPerComponent * pixelComponents;

  Buffer *buffer = Buffer::New((char *)&pixels, buffer_length, free_buffer, 0);
  Local<v8::Object> globalObj = v8::Context::GetCurrent()->Global();
  Local<Function> bufferConstructor = v8::Local<v8::Function>::Cast(globalObj->Get(v8::String::New("Buffer")));
  Handle<Value> constructorArgs[3] = { buffer->handle_, v8::Integer::New(Buffer::Length(buffer)), v8::Integer::New(0) };
  Local<Object> actualBuffer = bufferConstructor->NewInstance(3, constructorArgs);

  return scope.Close(actualBuffer);
}

Handle<Value> GlReleaseShaderCompiler(const Arguments& args) {
  HandleScope scope;


  glReleaseShaderCompiler();
  return scope.Close(Undefined());
}

Handle<Value> GlRenderbufferStorage(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum internalformat = args[1]->Int32Value();
  GLsizei width = args[2]->Int32Value();
  GLsizei height = args[3]->Int32Value();

  glRenderbufferStorage(target, internalformat, width, height);
  return scope.Close(Undefined());
}

Handle<Value> GlSampleCoverage(const Arguments& args) {
  HandleScope scope;

  GLclampf value = args[0]->NumberValue();
  GLboolean invert = (GLboolean)args[1]->Int32Value();

  glSampleCoverage(value, invert);
  return scope.Close(Undefined());
}

Handle<Value> GlScissor(const Arguments& args) {
  HandleScope scope;

  GLint x = args[0]->Int32Value();
  GLint y = args[1]->Int32Value();
  GLsizei width = args[2]->Int32Value();
  GLsizei height = args[3]->Int32Value();

  glScissor(x, y, width, height);
  return scope.Close(Undefined());
}

Handle<Value> GlShaderBinary(const Arguments& args) {
  HandleScope scope;

  GLsizei n = args[0]->Int32Value();

  // list of Gluints
  Handle<Array> array_shaders = Handle<Array>::Cast(args[1]);
  int length_1 = array_shaders->Get(String::New("length"))->ToObject()->Uint32Value();
  GLuint shaders[length_1];
  for (int i=0; i<length_1; i++) {
    shaders[i] = array_shaders->Get(i)->ToObject()->Uint32Value();
  }

  GLenum binaryformat = args[2]->Int32Value();

  // buffer
  Local<Object> obj_binary = args[3]->ToObject();
  if (obj_binary->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glShaderBinary expects a Buffer for argument 3")));
    return scope.Close(Undefined());
  }
  const GLvoid* binary = static_cast<const GLvoid*>(obj_binary->GetIndexedPropertiesExternalArrayData());

  GLsizei length = args[4]->Int32Value();

  glShaderBinary(n, shaders, binaryformat, binary, length);
  return scope.Close(Undefined());
}

Handle<Value> GlShaderSource(const Arguments& args) {
  HandleScope scope;

  GLuint shader = args[0]->Uint32Value();
  GLsizei count = args[1]->Int32Value();

  // list of strings
  Handle<Array> array_string = Handle<Array>::Cast(args[2]);
  int length_2 = array_string->Get(String::New("length"))->ToObject()->Uint32Value();

  for (int i=0; i<length_2; i++) {
    String::AsciiValue string_2(array_string->Get(i));
    const GLchar *char_2 = *string_2;
    glShaderSource(shader, count, &char_2, NULL);

  }


  return scope.Close(Undefined());
}

Handle<Value> GlStencilFunc(const Arguments& args) {
  HandleScope scope;

  GLenum func = args[0]->Int32Value();
  GLint ref = args[1]->Int32Value();
  GLuint mask = args[2]->Uint32Value();

  glStencilFunc(func, ref, mask);
  return scope.Close(Undefined());
}

Handle<Value> GlStencilFuncSeparate(const Arguments& args) {
  HandleScope scope;

  GLenum face = args[0]->Int32Value();
  GLenum func = args[1]->Int32Value();
  GLint ref = args[2]->Int32Value();
  GLuint mask = args[3]->Uint32Value();

  glStencilFuncSeparate(face, func, ref, mask);
  return scope.Close(Undefined());
}

Handle<Value> GlStencilMask(const Arguments& args) {
  HandleScope scope;

  GLuint mask = args[0]->Uint32Value();

  glStencilMask(mask);
  return scope.Close(Undefined());
}

Handle<Value> GlStencilMaskSeparate(const Arguments& args) {
  HandleScope scope;

  GLenum face = args[0]->Int32Value();
  GLuint mask = args[1]->Uint32Value();

  glStencilMaskSeparate(face, mask);
  return scope.Close(Undefined());
}

Handle<Value> GlStencilOp(const Arguments& args) {
  HandleScope scope;

  GLenum fail = args[0]->Int32Value();
  GLenum zfail = args[1]->Int32Value();
  GLenum zpass = args[2]->Int32Value();

  glStencilOp(fail, zfail, zpass);
  return scope.Close(Undefined());
}

Handle<Value> GlStencilOpSeparate(const Arguments& args) {
  HandleScope scope;

  GLenum face = args[0]->Int32Value();
  GLenum fail = args[1]->Int32Value();
  GLenum zfail = args[2]->Int32Value();
  GLenum zpass = args[3]->Int32Value();

  glStencilOpSeparate(face, fail, zfail, zpass);
  return scope.Close(Undefined());
}

Handle<Value> GlTexImage2D(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLint level = args[1]->Int32Value();
  GLint internalformat = args[2]->Int32Value();
  GLsizei width = args[3]->Int32Value();
  GLsizei height = args[4]->Int32Value();
  GLint border = args[5]->Int32Value();
  GLenum format = args[6]->Int32Value();
  GLenum type = args[7]->Int32Value();

  // buffer
  Local<Object> obj_pixels = args[8]->ToObject();
  if (obj_pixels->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glTexImage2D expects a Buffer for argument 8")));
    return scope.Close(Undefined());
  }
  const GLvoid* pixels = static_cast<const GLvoid*>(obj_pixels->GetIndexedPropertiesExternalArrayData());


  glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
  return scope.Close(Undefined());
}

Handle<Value> GlTexParameterf(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();
  GLfloat param = args[2]->NumberValue();

  glTexParameterf(target, pname, param);
  return scope.Close(Undefined());
}

Handle<Value> GlTexParameterfv(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();

  // buffer
  Local<Object> obj_params = args[2]->ToObject();
  if (obj_params->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glTexParameterfv expects a Buffer for argument 2")));
    return scope.Close(Undefined());
  }
  const GLfloat* params = static_cast<const GLfloat*>(obj_params->GetIndexedPropertiesExternalArrayData());


  glTexParameterfv(target, pname, params);
  return scope.Close(Undefined());
}

Handle<Value> GlTexParameteri(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();
  GLint param = args[2]->Int32Value();

  glTexParameteri(target, pname, param);
  return scope.Close(Undefined());
}

Handle<Value> GlTexParameteriv(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLenum pname = args[1]->Int32Value();

  // list of Gluints
  Handle<Array> array_params = Handle<Array>::Cast(args[2]);
  int length_2 = array_params->Get(String::New("length"))->ToObject()->Uint32Value();
  GLint params[length_2];
  for (int i=0; i<length_2; i++) {
    params[i] = array_params->Get(i)->ToObject()->Uint32Value();
  }


  glTexParameteriv(target, pname, params);
  return scope.Close(Undefined());
}

Handle<Value> GlTexSubImage2D(const Arguments& args) {
  HandleScope scope;

  GLenum target = args[0]->Int32Value();
  GLint level = args[1]->Int32Value();
  GLint xoffset = args[2]->Int32Value();
  GLint yoffset = args[3]->Int32Value();
  GLsizei width = args[4]->Int32Value();
  GLsizei height = args[5]->Int32Value();
  GLenum format = args[6]->Int32Value();
  GLenum type = args[7]->Int32Value();

  // buffer
  Local<Object> obj_pixels = args[8]->ToObject();
  if (obj_pixels->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glTexSubImage2D expects a Buffer for argument 8")));
    return scope.Close(Undefined());
  }
  const GLvoid* pixels = static_cast<const GLvoid*>(obj_pixels->GetIndexedPropertiesExternalArrayData());


  glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform1f(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLfloat x = args[1]->NumberValue();

  glUniform1f(location, x);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform1fv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // buffer
  Local<Object> obj_v = args[2]->ToObject();
  if (obj_v->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glUniform1fv expects a Buffer for argument 2")));
    return scope.Close(Undefined());
  }
  const GLfloat* v = static_cast<const GLfloat*>(obj_v->GetIndexedPropertiesExternalArrayData());


  glUniform1fv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform1i(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLint x = args[1]->Int32Value();

  glUniform1i(location, x);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform1iv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // list of Gluints
  Handle<Array> array_v = Handle<Array>::Cast(args[2]);
  int length_2 = array_v->Get(String::New("length"))->ToObject()->Uint32Value();
  GLint v[length_2];
  for (int i=0; i<length_2; i++) {
    v[i] = array_v->Get(i)->ToObject()->Uint32Value();
  }


  glUniform1iv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform2f(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLfloat x = args[1]->NumberValue();
  GLfloat y = args[2]->NumberValue();

  glUniform2f(location, x, y);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform2fv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // buffer
  Local<Object> obj_v = args[2]->ToObject();
  if (obj_v->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glUniform2fv expects a Buffer for argument 2")));
    return scope.Close(Undefined());
  }
  const GLfloat* v = static_cast<const GLfloat*>(obj_v->GetIndexedPropertiesExternalArrayData());


  glUniform2fv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform2i(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLint x = args[1]->Int32Value();
  GLint y = args[2]->Int32Value();

  glUniform2i(location, x, y);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform2iv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // list of Gluints
  Handle<Array> array_v = Handle<Array>::Cast(args[2]);
  int length_2 = array_v->Get(String::New("length"))->ToObject()->Uint32Value();
  GLint v[length_2];
  for (int i=0; i<length_2; i++) {
    v[i] = array_v->Get(i)->ToObject()->Uint32Value();
  }


  glUniform2iv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform3f(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLfloat x = args[1]->NumberValue();
  GLfloat y = args[2]->NumberValue();
  GLfloat z = args[3]->NumberValue();

  glUniform3f(location, x, y, z);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform3fv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // buffer
  Local<Object> obj_v = args[2]->ToObject();
  if (obj_v->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glUniform3fv expects a Buffer for argument 2")));
    return scope.Close(Undefined());
  }
  const GLfloat* v = static_cast<const GLfloat*>(obj_v->GetIndexedPropertiesExternalArrayData());


  glUniform3fv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform3i(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLint x = args[1]->Int32Value();
  GLint y = args[2]->Int32Value();
  GLint z = args[3]->Int32Value();

  glUniform3i(location, x, y, z);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform3iv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // list of Gluints
  Handle<Array> array_v = Handle<Array>::Cast(args[2]);
  int length_2 = array_v->Get(String::New("length"))->ToObject()->Uint32Value();
  GLint v[length_2];
  for (int i=0; i<length_2; i++) {
    v[i] = array_v->Get(i)->ToObject()->Uint32Value();
  }


  glUniform3iv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform4f(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLfloat x = args[1]->NumberValue();
  GLfloat y = args[2]->NumberValue();
  GLfloat z = args[3]->NumberValue();
  GLfloat w = args[4]->NumberValue();

  glUniform4f(location, x, y, z, w);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform4fv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // buffer
  Local<Object> obj_v = args[2]->ToObject();
  if (obj_v->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glUniform4fv expects a Buffer for argument 2")));
    return scope.Close(Undefined());
  }
  const GLfloat* v = static_cast<const GLfloat*>(obj_v->GetIndexedPropertiesExternalArrayData());


  glUniform4fv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform4i(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLint x = args[1]->Int32Value();
  GLint y = args[2]->Int32Value();
  GLint z = args[3]->Int32Value();
  GLint w = args[4]->Int32Value();

  glUniform4i(location, x, y, z, w);
  return scope.Close(Undefined());
}

Handle<Value> GlUniform4iv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();

  // list of Gluints
  Handle<Array> array_v = Handle<Array>::Cast(args[2]);
  int length_2 = array_v->Get(String::New("length"))->ToObject()->Uint32Value();
  GLint v[length_2];
  for (int i=0; i<length_2; i++) {
    v[i] = array_v->Get(i)->ToObject()->Uint32Value();
  }


  glUniform4iv(location, count, v);
  return scope.Close(Undefined());
}

Handle<Value> GlUniformMatrix2fv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();
  GLboolean transpose = (GLboolean)args[2]->Int32Value();

  // buffer
  Local<Object> obj_value = args[3]->ToObject();
  if (obj_value->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glUniformMatrix2fv expects a Buffer for argument 3")));
    return scope.Close(Undefined());
  }
  const GLfloat* value = static_cast<const GLfloat*>(obj_value->GetIndexedPropertiesExternalArrayData());


  glUniformMatrix2fv(location, count, transpose, value);
  return scope.Close(Undefined());
}

Handle<Value> GlUniformMatrix3fv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();
  GLboolean transpose = (GLboolean)args[2]->Int32Value();

  // buffer
  Local<Object> obj_value = args[3]->ToObject();
  if (obj_value->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glUniformMatrix3fv expects a Buffer for argument 3")));
    return scope.Close(Undefined());
  }
  const GLfloat* value = static_cast<const GLfloat*>(obj_value->GetIndexedPropertiesExternalArrayData());


  glUniformMatrix3fv(location, count, transpose, value);
  return scope.Close(Undefined());
}

Handle<Value> GlUniformMatrix4fv(const Arguments& args) {
  HandleScope scope;

  GLint location = args[0]->Int32Value();
  GLsizei count = args[1]->Int32Value();
  GLboolean transpose = (GLboolean)args[2]->Int32Value();

  // buffer
  Local<Object> obj_value = args[3]->ToObject();
  if (obj_value->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glUniformMatrix4fv expects a Buffer for argument 3")));
    return scope.Close(Undefined());
  }
  const GLfloat* value = static_cast<const GLfloat*>(obj_value->GetIndexedPropertiesExternalArrayData());


  glUniformMatrix4fv(location, count, transpose, value);
  return scope.Close(Undefined());
}

Handle<Value> GlUseProgram(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();

  glUseProgram(program);
  return scope.Close(Undefined());
}

Handle<Value> GlValidateProgram(const Arguments& args) {
  HandleScope scope;

  GLuint program = args[0]->Uint32Value();

  glValidateProgram(program);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib1f(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();
  GLfloat x = args[1]->NumberValue();

  glVertexAttrib1f(indx, x);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib1fv(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();

  // buffer
  Local<Object> obj_values = args[1]->ToObject();
  if (obj_values->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glVertexAttrib1fv expects a Buffer for argument 1")));
    return scope.Close(Undefined());
  }
  const GLfloat* values = static_cast<const GLfloat*>(obj_values->GetIndexedPropertiesExternalArrayData());


  glVertexAttrib1fv(indx, values);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib2f(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();
  GLfloat x = args[1]->NumberValue();
  GLfloat y = args[2]->NumberValue();

  glVertexAttrib2f(indx, x, y);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib2fv(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();

  // buffer
  Local<Object> obj_values = args[1]->ToObject();
  if (obj_values->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glVertexAttrib2fv expects a Buffer for argument 1")));
    return scope.Close(Undefined());
  }
  const GLfloat* values = static_cast<const GLfloat*>(obj_values->GetIndexedPropertiesExternalArrayData());


  glVertexAttrib2fv(indx, values);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib3f(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();
  GLfloat x = args[1]->NumberValue();
  GLfloat y = args[2]->NumberValue();
  GLfloat z = args[3]->NumberValue();

  glVertexAttrib3f(indx, x, y, z);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib3fv(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();

  // buffer
  Local<Object> obj_values = args[1]->ToObject();
  if (obj_values->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glVertexAttrib3fv expects a Buffer for argument 1")));
    return scope.Close(Undefined());
  }
  const GLfloat* values = static_cast<const GLfloat*>(obj_values->GetIndexedPropertiesExternalArrayData());


  glVertexAttrib3fv(indx, values);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib4f(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();
  GLfloat x = args[1]->NumberValue();
  GLfloat y = args[2]->NumberValue();
  GLfloat z = args[3]->NumberValue();
  GLfloat w = args[4]->NumberValue();

  glVertexAttrib4f(indx, x, y, z, w);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttrib4fv(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();

  // buffer
  Local<Object> obj_values = args[1]->ToObject();
  if (obj_values->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glVertexAttrib4fv expects a Buffer for argument 1")));
    return scope.Close(Undefined());
  }
  const GLfloat* values = static_cast<const GLfloat*>(obj_values->GetIndexedPropertiesExternalArrayData());


  glVertexAttrib4fv(indx, values);
  return scope.Close(Undefined());
}

Handle<Value> GlVertexAttribPointer(const Arguments& args) {
  HandleScope scope;

  GLuint indx = args[0]->Uint32Value();
  GLint size = args[1]->Int32Value();
  GLenum type = args[2]->Int32Value();
  GLboolean normalized = (GLboolean)args[3]->Int32Value();
  GLsizei stride = args[4]->Int32Value();

  // buffer
  Local<Object> obj_ptr = args[5]->ToObject();
  if (obj_ptr->GetIndexedPropertiesExternalArrayDataType() != kExternalFloatArray) {
    ThrowException(Exception::TypeError(String::New("glVertexAttribPointer expects a Buffer for argument 5")));
    return scope.Close(Undefined());
  }
  const GLvoid* ptr = static_cast<const GLvoid*>(obj_ptr->GetIndexedPropertiesExternalArrayData());


  glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
  return scope.Close(Undefined());
}

Handle<Value> GlViewport(const Arguments& args) {
  HandleScope scope;

  GLint x = args[0]->Int32Value();
  GLint y = args[1]->Int32Value();
  GLsizei width = args[2]->Int32Value();
  GLsizei height = args[3]->Int32Value();

  glViewport(x, y, width, height);
  return scope.Close(Undefined());
}
void init(Handle<Object> target) {

  // Methods
  SetMethod(target, "glActiveTexture", GlActiveTexture);
  SetMethod(target, "glAttachShader", GlAttachShader);
  SetMethod(target, "glBindAttribLocation", GlBindAttribLocation);
  SetMethod(target, "glBindBuffer", GlBindBuffer);
  SetMethod(target, "glBindFramebuffer", GlBindFramebuffer);
  SetMethod(target, "glBindRenderbuffer", GlBindRenderbuffer);
  SetMethod(target, "glBindTexture", GlBindTexture);
  SetMethod(target, "glBlendColor", GlBlendColor);
  SetMethod(target, "glBlendEquation", GlBlendEquation);
  SetMethod(target, "glBlendEquationSeparate", GlBlendEquationSeparate);
  SetMethod(target, "glBlendFunc", GlBlendFunc);
  SetMethod(target, "glBlendFuncSeparate", GlBlendFuncSeparate);
  SetMethod(target, "glBufferData", GlBufferData);
  SetMethod(target, "glBufferSubData", GlBufferSubData);
  SetMethod(target, "glCheckFramebufferStatus", GlCheckFramebufferStatus);
  SetMethod(target, "glClear", GlClear);
  SetMethod(target, "glClearColor", GlClearColor);
  SetMethod(target, "glClearDepthf", GlClearDepthf);
  SetMethod(target, "glClearStencil", GlClearStencil);
  SetMethod(target, "glColorMask", GlColorMask);
  SetMethod(target, "glCompileShader", GlCompileShader);
  SetMethod(target, "glCompressedTexImage2D", GlCompressedTexImage2D);
  SetMethod(target, "glCompressedTexSubImage2D", GlCompressedTexSubImage2D);
  SetMethod(target, "glCopyTexImage2D", GlCopyTexImage2D);
  SetMethod(target, "glCopyTexSubImage2D", GlCopyTexSubImage2D);
  SetMethod(target, "glCreateProgram", GlCreateProgram);
  SetMethod(target, "glCreateShader", GlCreateShader);
  SetMethod(target, "glCullFace", GlCullFace);
  SetMethod(target, "glDeleteBuffers", GlDeleteBuffers);
  SetMethod(target, "glDeleteFramebuffers", GlDeleteFramebuffers);
  SetMethod(target, "glDeleteProgram", GlDeleteProgram);
  SetMethod(target, "glDeleteRenderbuffers", GlDeleteRenderbuffers);
  SetMethod(target, "glDeleteShader", GlDeleteShader);
  SetMethod(target, "glDeleteTextures", GlDeleteTextures);
  SetMethod(target, "glDepthFunc", GlDepthFunc);
  SetMethod(target, "glDepthMask", GlDepthMask);
  SetMethod(target, "glDepthRangef", GlDepthRangef);
  SetMethod(target, "glDetachShader", GlDetachShader);
  SetMethod(target, "glDisable", GlDisable);
  SetMethod(target, "glDisableVertexAttribArray", GlDisableVertexAttribArray);
  SetMethod(target, "glDrawArrays", GlDrawArrays);
  SetMethod(target, "glDrawElements", GlDrawElements);
  SetMethod(target, "glEnable", GlEnable);
  SetMethod(target, "glEnableVertexAttribArray", GlEnableVertexAttribArray);
  SetMethod(target, "glFinish", GlFinish);
  SetMethod(target, "glFlush", GlFlush);
  SetMethod(target, "glFramebufferRenderbuffer", GlFramebufferRenderbuffer);
  SetMethod(target, "glFramebufferTexture2D", GlFramebufferTexture2D);
  SetMethod(target, "glFrontFace", GlFrontFace);
  SetMethod(target, "glGenBuffers", GlGenBuffers);
  SetMethod(target, "glGenerateMipmap", GlGenerateMipmap);
  SetMethod(target, "glGenFramebuffers", GlGenFramebuffers);
  SetMethod(target, "glGenRenderbuffers", GlGenRenderbuffers);
  SetMethod(target, "glGenTextures", GlGenTextures);
  SetMethod(target, "glGetActiveAttrib", GlGetActiveAttrib);
  SetMethod(target, "glGetActiveUniform", GlGetActiveUniform);
  SetMethod(target, "glGetAttachedShaders", GlGetAttachedShaders);
  SetMethod(target, "glGetAttribLocation", GlGetAttribLocation);
  SetMethod(target, "glGetBooleanv", GlGetBooleanv);
  SetMethod(target, "glGetBufferParameteriv", GlGetBufferParameteriv);
  SetMethod(target, "glGetError", GlGetError);
  SetMethod(target, "glGetFloatv", GlGetFloatv);
  SetMethod(target, "glGetFramebufferAttachmentParameteriv", GlGetFramebufferAttachmentParameteriv);
  SetMethod(target, "glGetIntegerv", GlGetIntegerv);
  SetMethod(target, "glGetProgramiv", GlGetProgramiv);
  SetMethod(target, "glGetProgramInfoLog", GlGetProgramInfoLog);
  SetMethod(target, "glGetRenderbufferParameteriv", GlGetRenderbufferParameteriv);
  SetMethod(target, "glGetShaderiv", GlGetShaderiv);
  SetMethod(target, "glGetShaderInfoLog", GlGetShaderInfoLog);
  SetMethod(target, "glGetShaderPrecisionFormat", GlGetShaderPrecisionFormat);
  SetMethod(target, "glGetShaderSource", GlGetShaderSource);
  SetMethod(target, "glGetString", GlGetString);
  SetMethod(target, "glGetTexParameterfv", GlGetTexParameterfv);
  SetMethod(target, "glGetTexParameteriv", GlGetTexParameteriv);
  SetMethod(target, "glGetUniformfv", GlGetUniformfv);
  SetMethod(target, "glGetUniformiv", GlGetUniformiv);
  SetMethod(target, "glGetUniformLocation", GlGetUniformLocation);
  SetMethod(target, "glGetVertexAttribfv", GlGetVertexAttribfv);
  SetMethod(target, "glGetVertexAttribiv", GlGetVertexAttribiv);
  SetMethod(target, "glHint", GlHint);
  SetMethod(target, "glIsBuffer", GlIsBuffer);
  SetMethod(target, "glIsEnabled", GlIsEnabled);
  SetMethod(target, "glIsFramebuffer", GlIsFramebuffer);
  SetMethod(target, "glIsProgram", GlIsProgram);
  SetMethod(target, "glIsRenderbuffer", GlIsRenderbuffer);
  SetMethod(target, "glIsShader", GlIsShader);
  SetMethod(target, "glIsTexture", GlIsTexture);
  SetMethod(target, "glLineWidth", GlLineWidth);
  SetMethod(target, "glLinkProgram", GlLinkProgram);
  SetMethod(target, "glPixelStorei", GlPixelStorei);
  SetMethod(target, "glPolygonOffset", GlPolygonOffset);
  SetMethod(target, "glReadPixels", GlReadPixels);
  SetMethod(target, "glReleaseShaderCompiler", GlReleaseShaderCompiler);
  SetMethod(target, "glRenderbufferStorage", GlRenderbufferStorage);
  SetMethod(target, "glSampleCoverage", GlSampleCoverage);
  SetMethod(target, "glScissor", GlScissor);
  SetMethod(target, "glShaderBinary", GlShaderBinary);
  SetMethod(target, "glShaderSource", GlShaderSource);
  SetMethod(target, "glStencilFunc", GlStencilFunc);
  SetMethod(target, "glStencilFuncSeparate", GlStencilFuncSeparate);
  SetMethod(target, "glStencilMask", GlStencilMask);
  SetMethod(target, "glStencilMaskSeparate", GlStencilMaskSeparate);
  SetMethod(target, "glStencilOp", GlStencilOp);
  SetMethod(target, "glStencilOpSeparate", GlStencilOpSeparate);
  SetMethod(target, "glTexImage2D", GlTexImage2D);
  SetMethod(target, "glTexParameterf", GlTexParameterf);
  SetMethod(target, "glTexParameterfv", GlTexParameterfv);
  SetMethod(target, "glTexParameteri", GlTexParameteri);
  SetMethod(target, "glTexParameteriv", GlTexParameteriv);
  SetMethod(target, "glTexSubImage2D", GlTexSubImage2D);
  SetMethod(target, "glUniform1f", GlUniform1f);
  SetMethod(target, "glUniform1fv", GlUniform1fv);
  SetMethod(target, "glUniform1i", GlUniform1i);
  SetMethod(target, "glUniform1iv", GlUniform1iv);
  SetMethod(target, "glUniform2f", GlUniform2f);
  SetMethod(target, "glUniform2fv", GlUniform2fv);
  SetMethod(target, "glUniform2i", GlUniform2i);
  SetMethod(target, "glUniform2iv", GlUniform2iv);
  SetMethod(target, "glUniform3f", GlUniform3f);
  SetMethod(target, "glUniform3fv", GlUniform3fv);
  SetMethod(target, "glUniform3i", GlUniform3i);
  SetMethod(target, "glUniform3iv", GlUniform3iv);
  SetMethod(target, "glUniform4f", GlUniform4f);
  SetMethod(target, "glUniform4fv", GlUniform4fv);
  SetMethod(target, "glUniform4i", GlUniform4i);
  SetMethod(target, "glUniform4iv", GlUniform4iv);
  SetMethod(target, "glUniformMatrix2fv", GlUniformMatrix2fv);
  SetMethod(target, "glUniformMatrix3fv", GlUniformMatrix3fv);
  SetMethod(target, "glUniformMatrix4fv", GlUniformMatrix4fv);
  SetMethod(target, "glUseProgram", GlUseProgram);
  SetMethod(target, "glValidateProgram", GlValidateProgram);
  SetMethod(target, "glVertexAttrib1f", GlVertexAttrib1f);
  SetMethod(target, "glVertexAttrib1fv", GlVertexAttrib1fv);
  SetMethod(target, "glVertexAttrib2f", GlVertexAttrib2f);
  SetMethod(target, "glVertexAttrib2fv", GlVertexAttrib2fv);
  SetMethod(target, "glVertexAttrib3f", GlVertexAttrib3f);
  SetMethod(target, "glVertexAttrib3fv", GlVertexAttrib3fv);
  SetMethod(target, "glVertexAttrib4f", GlVertexAttrib4f);
  SetMethod(target, "glVertexAttrib4fv", GlVertexAttrib4fv);
  SetMethod(target, "glVertexAttribPointer", GlVertexAttribPointer);
  SetMethod(target, "glViewport", GlViewport);

  // Constants
  DEFINE_CONSTANT(target, "GL_ES_VERSION_2_0", 1);
  DEFINE_CONSTANT(target, "GL_DEPTH_BUFFER_BIT", 0x00000100);
  DEFINE_CONSTANT(target, "GL_STENCIL_BUFFER_BIT", 0x00000400);
  DEFINE_CONSTANT(target, "GL_COLOR_BUFFER_BIT", 0x00004000);
  DEFINE_CONSTANT(target, "GL_FALSE", 0);
  DEFINE_CONSTANT(target, "GL_TRUE", 1);
  DEFINE_CONSTANT(target, "GL_POINTS", 0x0000);
  DEFINE_CONSTANT(target, "GL_LINES", 0x0001);
  DEFINE_CONSTANT(target, "GL_LINE_LOOP", 0x0002);
  DEFINE_CONSTANT(target, "GL_LINE_STRIP", 0x0003);
  DEFINE_CONSTANT(target, "GL_TRIANGLES", 0x0004);
  DEFINE_CONSTANT(target, "GL_TRIANGLE_STRIP", 0x0005);
  DEFINE_CONSTANT(target, "GL_TRIANGLE_FAN", 0x0006);
  DEFINE_CONSTANT(target, "GL_ZERO", 0);
  DEFINE_CONSTANT(target, "GL_ONE", 1);
  DEFINE_CONSTANT(target, "GL_SRC_COLOR", 0x0300);
  DEFINE_CONSTANT(target, "GL_ONE_MINUS_SRC_COLOR", 0x0301);
  DEFINE_CONSTANT(target, "GL_SRC_ALPHA", 0x0302);
  DEFINE_CONSTANT(target, "GL_ONE_MINUS_SRC_ALPHA", 0x0303);
  DEFINE_CONSTANT(target, "GL_DST_ALPHA", 0x0304);
  DEFINE_CONSTANT(target, "GL_ONE_MINUS_DST_ALPHA", 0x0305);
  DEFINE_CONSTANT(target, "GL_DST_COLOR", 0x0306);
  DEFINE_CONSTANT(target, "GL_ONE_MINUS_DST_COLOR", 0x0307);
  DEFINE_CONSTANT(target, "GL_SRC_ALPHA_SATURATE", 0x0308);
  DEFINE_CONSTANT(target, "GL_FUNC_ADD", 0x8006);
  DEFINE_CONSTANT(target, "GL_BLEND_EQUATION", 0x8009);
  DEFINE_CONSTANT(target, "GL_BLEND_EQUATION_RGB", 0x8009);
  DEFINE_CONSTANT(target, "GL_BLEND_EQUATION_ALPHA", 0x883D);
  DEFINE_CONSTANT(target, "GL_FUNC_SUBTRACT", 0x800A);
  DEFINE_CONSTANT(target, "GL_FUNC_REVERSE_SUBTRACT", 0x800B);
  DEFINE_CONSTANT(target, "GL_BLEND_DST_RGB", 0x80C8);
  DEFINE_CONSTANT(target, "GL_BLEND_SRC_RGB", 0x80C9);
  DEFINE_CONSTANT(target, "GL_BLEND_DST_ALPHA", 0x80CA);
  DEFINE_CONSTANT(target, "GL_BLEND_SRC_ALPHA", 0x80CB);
  DEFINE_CONSTANT(target, "GL_CONSTANT_COLOR", 0x8001);
  DEFINE_CONSTANT(target, "GL_ONE_MINUS_CONSTANT_COLOR", 0x8002);
  DEFINE_CONSTANT(target, "GL_CONSTANT_ALPHA", 0x8003);
  DEFINE_CONSTANT(target, "GL_ONE_MINUS_CONSTANT_ALPHA", 0x8004);
  DEFINE_CONSTANT(target, "GL_BLEND_COLOR", 0x8005);
  DEFINE_CONSTANT(target, "GL_ARRAY_BUFFER", 0x8892);
  DEFINE_CONSTANT(target, "GL_ELEMENT_ARRAY_BUFFER", 0x8893);
  DEFINE_CONSTANT(target, "GL_ARRAY_BUFFER_BINDING", 0x8894);
  DEFINE_CONSTANT(target, "GL_ELEMENT_ARRAY_BUFFER_BINDING", 0x8895);
  DEFINE_CONSTANT(target, "GL_STREAM_DRAW", 0x88E0);
  DEFINE_CONSTANT(target, "GL_STATIC_DRAW", 0x88E4);
  DEFINE_CONSTANT(target, "GL_DYNAMIC_DRAW", 0x88E8);
  DEFINE_CONSTANT(target, "GL_BUFFER_SIZE", 0x8764);
  DEFINE_CONSTANT(target, "GL_BUFFER_USAGE", 0x8765);
  DEFINE_CONSTANT(target, "GL_CURRENT_VERTEX_ATTRIB", 0x8626);
  DEFINE_CONSTANT(target, "GL_FRONT", 0x0404);
  DEFINE_CONSTANT(target, "GL_BACK", 0x0405);
  DEFINE_CONSTANT(target, "GL_FRONT_AND_BACK", 0x0408);
  DEFINE_CONSTANT(target, "GL_TEXTURE_2D", 0x0DE1);
  DEFINE_CONSTANT(target, "GL_CULL_FACE", 0x0B44);
  DEFINE_CONSTANT(target, "GL_BLEND", 0x0BE2);
  DEFINE_CONSTANT(target, "GL_DITHER", 0x0BD0);
  DEFINE_CONSTANT(target, "GL_STENCIL_TEST", 0x0B90);
  DEFINE_CONSTANT(target, "GL_DEPTH_TEST", 0x0B71);
  DEFINE_CONSTANT(target, "GL_SCISSOR_TEST", 0x0C11);
  DEFINE_CONSTANT(target, "GL_POLYGON_OFFSET_FILL", 0x8037);
  DEFINE_CONSTANT(target, "GL_SAMPLE_ALPHA_TO_COVERAGE", 0x809E);
  DEFINE_CONSTANT(target, "GL_SAMPLE_COVERAGE", 0x80A0);
  DEFINE_CONSTANT(target, "GL_NO_ERROR", 0);
  DEFINE_CONSTANT(target, "GL_INVALID_ENUM", 0x0500);
  DEFINE_CONSTANT(target, "GL_INVALID_VALUE", 0x0501);
  DEFINE_CONSTANT(target, "GL_INVALID_OPERATION", 0x0502);
  DEFINE_CONSTANT(target, "GL_OUT_OF_MEMORY", 0x0505);
  DEFINE_CONSTANT(target, "GL_CW", 0x0900);
  DEFINE_CONSTANT(target, "GL_CCW", 0x0901);
  DEFINE_CONSTANT(target, "GL_LINE_WIDTH", 0x0B21);
  DEFINE_CONSTANT(target, "GL_ALIASED_POINT_SIZE_RANGE", 0x846D);
  DEFINE_CONSTANT(target, "GL_ALIASED_LINE_WIDTH_RANGE", 0x846E);
  DEFINE_CONSTANT(target, "GL_CULL_FACE_MODE", 0x0B45);
  DEFINE_CONSTANT(target, "GL_FRONT_FACE", 0x0B46);
  DEFINE_CONSTANT(target, "GL_DEPTH_RANGE", 0x0B70);
  DEFINE_CONSTANT(target, "GL_DEPTH_WRITEMASK", 0x0B72);
  DEFINE_CONSTANT(target, "GL_DEPTH_CLEAR_VALUE", 0x0B73);
  DEFINE_CONSTANT(target, "GL_DEPTH_FUNC", 0x0B74);
  DEFINE_CONSTANT(target, "GL_STENCIL_CLEAR_VALUE", 0x0B91);
  DEFINE_CONSTANT(target, "GL_STENCIL_FUNC", 0x0B92);
  DEFINE_CONSTANT(target, "GL_STENCIL_FAIL", 0x0B94);
  DEFINE_CONSTANT(target, "GL_STENCIL_PASS_DEPTH_FAIL", 0x0B95);
  DEFINE_CONSTANT(target, "GL_STENCIL_PASS_DEPTH_PASS", 0x0B96);
  DEFINE_CONSTANT(target, "GL_STENCIL_REF", 0x0B97);
  DEFINE_CONSTANT(target, "GL_STENCIL_VALUE_MASK", 0x0B93);
  DEFINE_CONSTANT(target, "GL_STENCIL_WRITEMASK", 0x0B98);
  DEFINE_CONSTANT(target, "GL_STENCIL_BACK_FUNC", 0x8800);
  DEFINE_CONSTANT(target, "GL_STENCIL_BACK_FAIL", 0x8801);
  DEFINE_CONSTANT(target, "GL_STENCIL_BACK_PASS_DEPTH_FAIL", 0x8802);
  DEFINE_CONSTANT(target, "GL_STENCIL_BACK_PASS_DEPTH_PASS", 0x8803);
  DEFINE_CONSTANT(target, "GL_STENCIL_BACK_REF", 0x8CA3);
  DEFINE_CONSTANT(target, "GL_STENCIL_BACK_VALUE_MASK", 0x8CA4);
  DEFINE_CONSTANT(target, "GL_STENCIL_BACK_WRITEMASK", 0x8CA5);
  DEFINE_CONSTANT(target, "GL_VIEWPORT", 0x0BA2);
  DEFINE_CONSTANT(target, "GL_SCISSOR_BOX", 0x0C10);
  DEFINE_CONSTANT(target, "GL_COLOR_CLEAR_VALUE", 0x0C22);
  DEFINE_CONSTANT(target, "GL_COLOR_WRITEMASK", 0x0C23);
  DEFINE_CONSTANT(target, "GL_UNPACK_ALIGNMENT", 0x0CF5);
  DEFINE_CONSTANT(target, "GL_PACK_ALIGNMENT", 0x0D05);
  DEFINE_CONSTANT(target, "GL_MAX_TEXTURE_SIZE", 0x0D33);
  DEFINE_CONSTANT(target, "GL_MAX_VIEWPORT_DIMS", 0x0D3A);
  DEFINE_CONSTANT(target, "GL_SUBPIXEL_BITS", 0x0D50);
  DEFINE_CONSTANT(target, "GL_RED_BITS", 0x0D52);
  DEFINE_CONSTANT(target, "GL_GREEN_BITS", 0x0D53);
  DEFINE_CONSTANT(target, "GL_BLUE_BITS", 0x0D54);
  DEFINE_CONSTANT(target, "GL_ALPHA_BITS", 0x0D55);
  DEFINE_CONSTANT(target, "GL_DEPTH_BITS", 0x0D56);
  DEFINE_CONSTANT(target, "GL_STENCIL_BITS", 0x0D57);
  DEFINE_CONSTANT(target, "GL_POLYGON_OFFSET_UNITS", 0x2A00);
  DEFINE_CONSTANT(target, "GL_POLYGON_OFFSET_FACTOR", 0x8038);
  DEFINE_CONSTANT(target, "GL_TEXTURE_BINDING_2D", 0x8069);
  DEFINE_CONSTANT(target, "GL_SAMPLE_BUFFERS", 0x80A8);
  DEFINE_CONSTANT(target, "GL_SAMPLES", 0x80A9);
  DEFINE_CONSTANT(target, "GL_SAMPLE_COVERAGE_VALUE", 0x80AA);
  DEFINE_CONSTANT(target, "GL_SAMPLE_COVERAGE_INVERT", 0x80AB);
  DEFINE_CONSTANT(target, "GL_NUM_COMPRESSED_TEXTURE_FORMATS", 0x86A2);
  DEFINE_CONSTANT(target, "GL_COMPRESSED_TEXTURE_FORMATS", 0x86A3);
  DEFINE_CONSTANT(target, "GL_DONT_CARE", 0x1100);
  DEFINE_CONSTANT(target, "GL_FASTEST", 0x1101);
  DEFINE_CONSTANT(target, "GL_NICEST", 0x1102);
  DEFINE_CONSTANT(target, "GL_GENERATE_MIPMAP_HINT", 0x8192);
  DEFINE_CONSTANT(target, "GL_BYTE", 0x1400);
  DEFINE_CONSTANT(target, "GL_UNSIGNED_BYTE", 0x1401);
  DEFINE_CONSTANT(target, "GL_SHORT", 0x1402);
  DEFINE_CONSTANT(target, "GL_UNSIGNED_SHORT", 0x1403);
  DEFINE_CONSTANT(target, "GL_INT", 0x1404);
  DEFINE_CONSTANT(target, "GL_UNSIGNED_INT", 0x1405);
  DEFINE_CONSTANT(target, "GL_FLOAT", 0x1406);
  DEFINE_CONSTANT(target, "GL_FIXED", 0x140C);
  DEFINE_CONSTANT(target, "GL_DEPTH_COMPONENT", 0x1902);
  DEFINE_CONSTANT(target, "GL_ALPHA", 0x1906);
  DEFINE_CONSTANT(target, "GL_RGB", 0x1907);
  DEFINE_CONSTANT(target, "GL_RGBA", 0x1908);
  DEFINE_CONSTANT(target, "GL_LUMINANCE", 0x1909);
  DEFINE_CONSTANT(target, "GL_LUMINANCE_ALPHA", 0x190A);
  DEFINE_CONSTANT(target, "GL_UNSIGNED_SHORT_4_4_4_4", 0x8033);
  DEFINE_CONSTANT(target, "GL_UNSIGNED_SHORT_5_5_5_1", 0x8034);
  DEFINE_CONSTANT(target, "GL_UNSIGNED_SHORT_5_6_5", 0x8363);
  DEFINE_CONSTANT(target, "GL_FRAGMENT_SHADER", 0x8B30);
  DEFINE_CONSTANT(target, "GL_VERTEX_SHADER", 0x8B31);
  DEFINE_CONSTANT(target, "GL_MAX_VERTEX_ATTRIBS", 0x8869);
  DEFINE_CONSTANT(target, "GL_MAX_VERTEX_UNIFORM_VECTORS", 0x8DFB);
  DEFINE_CONSTANT(target, "GL_MAX_VARYING_VECTORS", 0x8DFC);
  DEFINE_CONSTANT(target, "GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS", 0x8B4D);
  DEFINE_CONSTANT(target, "GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS", 0x8B4C);
  DEFINE_CONSTANT(target, "GL_MAX_TEXTURE_IMAGE_UNITS", 0x8872);
  DEFINE_CONSTANT(target, "GL_MAX_FRAGMENT_UNIFORM_VECTORS", 0x8DFD);
  DEFINE_CONSTANT(target, "GL_SHADER_TYPE", 0x8B4F);
  DEFINE_CONSTANT(target, "GL_DELETE_STATUS", 0x8B80);
  DEFINE_CONSTANT(target, "GL_LINK_STATUS", 0x8B82);
  DEFINE_CONSTANT(target, "GL_VALIDATE_STATUS", 0x8B83);
  DEFINE_CONSTANT(target, "GL_ATTACHED_SHADERS", 0x8B85);
  DEFINE_CONSTANT(target, "GL_ACTIVE_UNIFORMS", 0x8B86);
  DEFINE_CONSTANT(target, "GL_ACTIVE_UNIFORM_MAX_LENGTH", 0x8B87);
  DEFINE_CONSTANT(target, "GL_ACTIVE_ATTRIBUTES", 0x8B89);
  DEFINE_CONSTANT(target, "GL_ACTIVE_ATTRIBUTE_MAX_LENGTH", 0x8B8A);
  DEFINE_CONSTANT(target, "GL_SHADING_LANGUAGE_VERSION", 0x8B8C);
  DEFINE_CONSTANT(target, "GL_CURRENT_PROGRAM", 0x8B8D);
  DEFINE_CONSTANT(target, "GL_NEVER", 0x0200);
  DEFINE_CONSTANT(target, "GL_LESS", 0x0201);
  DEFINE_CONSTANT(target, "GL_EQUAL", 0x0202);
  DEFINE_CONSTANT(target, "GL_LEQUAL", 0x0203);
  DEFINE_CONSTANT(target, "GL_GREATER", 0x0204);
  DEFINE_CONSTANT(target, "GL_NOTEQUAL", 0x0205);
  DEFINE_CONSTANT(target, "GL_GEQUAL", 0x0206);
  DEFINE_CONSTANT(target, "GL_ALWAYS", 0x0207);
  DEFINE_CONSTANT(target, "GL_KEEP", 0x1E00);
  DEFINE_CONSTANT(target, "GL_REPLACE", 0x1E01);
  DEFINE_CONSTANT(target, "GL_INCR", 0x1E02);
  DEFINE_CONSTANT(target, "GL_DECR", 0x1E03);
  DEFINE_CONSTANT(target, "GL_INVERT", 0x150A);
  DEFINE_CONSTANT(target, "GL_INCR_WRAP", 0x8507);
  DEFINE_CONSTANT(target, "GL_DECR_WRAP", 0x8508);
  DEFINE_CONSTANT(target, "GL_VENDOR", 0x1F00);
  DEFINE_CONSTANT(target, "GL_RENDERER", 0x1F01);
  DEFINE_CONSTANT(target, "GL_VERSION", 0x1F02);
  DEFINE_CONSTANT(target, "GL_EXTENSIONS", 0x1F03);
  DEFINE_CONSTANT(target, "GL_NEAREST", 0x2600);
  DEFINE_CONSTANT(target, "GL_LINEAR", 0x2601);
  DEFINE_CONSTANT(target, "GL_NEAREST_MIPMAP_NEAREST", 0x2700);
  DEFINE_CONSTANT(target, "GL_LINEAR_MIPMAP_NEAREST", 0x2701);
  DEFINE_CONSTANT(target, "GL_NEAREST_MIPMAP_LINEAR", 0x2702);
  DEFINE_CONSTANT(target, "GL_LINEAR_MIPMAP_LINEAR", 0x2703);
  DEFINE_CONSTANT(target, "GL_TEXTURE_MAG_FILTER", 0x2800);
  DEFINE_CONSTANT(target, "GL_TEXTURE_MIN_FILTER", 0x2801);
  DEFINE_CONSTANT(target, "GL_TEXTURE_WRAP_S", 0x2802);
  DEFINE_CONSTANT(target, "GL_TEXTURE_WRAP_T", 0x2803);
  DEFINE_CONSTANT(target, "GL_TEXTURE", 0x1702);
  DEFINE_CONSTANT(target, "GL_TEXTURE_CUBE_MAP", 0x8513);
  DEFINE_CONSTANT(target, "GL_TEXTURE_BINDING_CUBE_MAP", 0x8514);
  DEFINE_CONSTANT(target, "GL_TEXTURE_CUBE_MAP_POSITIVE_X", 0x8515);
  DEFINE_CONSTANT(target, "GL_TEXTURE_CUBE_MAP_NEGATIVE_X", 0x8516);
  DEFINE_CONSTANT(target, "GL_TEXTURE_CUBE_MAP_POSITIVE_Y", 0x8517);
  DEFINE_CONSTANT(target, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Y", 0x8518);
  DEFINE_CONSTANT(target, "GL_TEXTURE_CUBE_MAP_POSITIVE_Z", 0x8519);
  DEFINE_CONSTANT(target, "GL_TEXTURE_CUBE_MAP_NEGATIVE_Z", 0x851A);
  DEFINE_CONSTANT(target, "GL_MAX_CUBE_MAP_TEXTURE_SIZE", 0x851C);
  DEFINE_CONSTANT(target, "GL_TEXTURE0", 0x84C0);
  DEFINE_CONSTANT(target, "GL_TEXTURE1", 0x84C1);
  DEFINE_CONSTANT(target, "GL_TEXTURE2", 0x84C2);
  DEFINE_CONSTANT(target, "GL_TEXTURE3", 0x84C3);
  DEFINE_CONSTANT(target, "GL_TEXTURE4", 0x84C4);
  DEFINE_CONSTANT(target, "GL_TEXTURE5", 0x84C5);
  DEFINE_CONSTANT(target, "GL_TEXTURE6", 0x84C6);
  DEFINE_CONSTANT(target, "GL_TEXTURE7", 0x84C7);
  DEFINE_CONSTANT(target, "GL_TEXTURE8", 0x84C8);
  DEFINE_CONSTANT(target, "GL_TEXTURE9", 0x84C9);
  DEFINE_CONSTANT(target, "GL_TEXTURE10", 0x84CA);
  DEFINE_CONSTANT(target, "GL_TEXTURE11", 0x84CB);
  DEFINE_CONSTANT(target, "GL_TEXTURE12", 0x84CC);
  DEFINE_CONSTANT(target, "GL_TEXTURE13", 0x84CD);
  DEFINE_CONSTANT(target, "GL_TEXTURE14", 0x84CE);
  DEFINE_CONSTANT(target, "GL_TEXTURE15", 0x84CF);
  DEFINE_CONSTANT(target, "GL_TEXTURE16", 0x84D0);
  DEFINE_CONSTANT(target, "GL_TEXTURE17", 0x84D1);
  DEFINE_CONSTANT(target, "GL_TEXTURE18", 0x84D2);
  DEFINE_CONSTANT(target, "GL_TEXTURE19", 0x84D3);
  DEFINE_CONSTANT(target, "GL_TEXTURE20", 0x84D4);
  DEFINE_CONSTANT(target, "GL_TEXTURE21", 0x84D5);
  DEFINE_CONSTANT(target, "GL_TEXTURE22", 0x84D6);
  DEFINE_CONSTANT(target, "GL_TEXTURE23", 0x84D7);
  DEFINE_CONSTANT(target, "GL_TEXTURE24", 0x84D8);
  DEFINE_CONSTANT(target, "GL_TEXTURE25", 0x84D9);
  DEFINE_CONSTANT(target, "GL_TEXTURE26", 0x84DA);
  DEFINE_CONSTANT(target, "GL_TEXTURE27", 0x84DB);
  DEFINE_CONSTANT(target, "GL_TEXTURE28", 0x84DC);
  DEFINE_CONSTANT(target, "GL_TEXTURE29", 0x84DD);
  DEFINE_CONSTANT(target, "GL_TEXTURE30", 0x84DE);
  DEFINE_CONSTANT(target, "GL_TEXTURE31", 0x84DF);
  DEFINE_CONSTANT(target, "GL_ACTIVE_TEXTURE", 0x84E0);
  DEFINE_CONSTANT(target, "GL_REPEAT", 0x2901);
  DEFINE_CONSTANT(target, "GL_CLAMP_TO_EDGE", 0x812F);
  DEFINE_CONSTANT(target, "GL_MIRRORED_REPEAT", 0x8370);
  DEFINE_CONSTANT(target, "GL_FLOAT_VEC2", 0x8B50);
  DEFINE_CONSTANT(target, "GL_FLOAT_VEC3", 0x8B51);
  DEFINE_CONSTANT(target, "GL_FLOAT_VEC4", 0x8B52);
  DEFINE_CONSTANT(target, "GL_INT_VEC2", 0x8B53);
  DEFINE_CONSTANT(target, "GL_INT_VEC3", 0x8B54);
  DEFINE_CONSTANT(target, "GL_INT_VEC4", 0x8B55);
  DEFINE_CONSTANT(target, "GL_BOOL", 0x8B56);
  DEFINE_CONSTANT(target, "GL_BOOL_VEC2", 0x8B57);
  DEFINE_CONSTANT(target, "GL_BOOL_VEC3", 0x8B58);
  DEFINE_CONSTANT(target, "GL_BOOL_VEC4", 0x8B59);
  DEFINE_CONSTANT(target, "GL_FLOAT_MAT2", 0x8B5A);
  DEFINE_CONSTANT(target, "GL_FLOAT_MAT3", 0x8B5B);
  DEFINE_CONSTANT(target, "GL_FLOAT_MAT4", 0x8B5C);
  DEFINE_CONSTANT(target, "GL_SAMPLER_2D", 0x8B5E);
  DEFINE_CONSTANT(target, "GL_SAMPLER_CUBE", 0x8B60);
  DEFINE_CONSTANT(target, "GL_VERTEX_ATTRIB_ARRAY_ENABLED", 0x8622);
  DEFINE_CONSTANT(target, "GL_VERTEX_ATTRIB_ARRAY_SIZE", 0x8623);
  DEFINE_CONSTANT(target, "GL_VERTEX_ATTRIB_ARRAY_STRIDE", 0x8624);
  DEFINE_CONSTANT(target, "GL_VERTEX_ATTRIB_ARRAY_TYPE", 0x8625);
  DEFINE_CONSTANT(target, "GL_VERTEX_ATTRIB_ARRAY_NORMALIZED", 0x886A);
  DEFINE_CONSTANT(target, "GL_VERTEX_ATTRIB_ARRAY_POINTER", 0x8645);
  DEFINE_CONSTANT(target, "GL_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING", 0x889F);
  DEFINE_CONSTANT(target, "GL_IMPLEMENTATION_COLOR_READ_TYPE", 0x8B9A);
  DEFINE_CONSTANT(target, "GL_IMPLEMENTATION_COLOR_READ_FORMAT", 0x8B9B);
  DEFINE_CONSTANT(target, "GL_COMPILE_STATUS", 0x8B81);
  DEFINE_CONSTANT(target, "GL_INFO_LOG_LENGTH", 0x8B84);
  DEFINE_CONSTANT(target, "GL_SHADER_SOURCE_LENGTH", 0x8B88);
  DEFINE_CONSTANT(target, "GL_SHADER_COMPILER", 0x8DFA);
  DEFINE_CONSTANT(target, "GL_SHADER_BINARY_FORMATS", 0x8DF8);
  DEFINE_CONSTANT(target, "GL_NUM_SHADER_BINARY_FORMATS", 0x8DF9);
  DEFINE_CONSTANT(target, "GL_LOW_FLOAT", 0x8DF0);
  DEFINE_CONSTANT(target, "GL_MEDIUM_FLOAT", 0x8DF1);
  DEFINE_CONSTANT(target, "GL_HIGH_FLOAT", 0x8DF2);
  DEFINE_CONSTANT(target, "GL_LOW_INT", 0x8DF3);
  DEFINE_CONSTANT(target, "GL_MEDIUM_INT", 0x8DF4);
  DEFINE_CONSTANT(target, "GL_HIGH_INT", 0x8DF5);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER", 0x8D40);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER", 0x8D41);
  DEFINE_CONSTANT(target, "GL_RGBA4", 0x8056);
  DEFINE_CONSTANT(target, "GL_RGB5_A1", 0x8057);
  DEFINE_CONSTANT(target, "GL_RGB565", 0x8D62);
  DEFINE_CONSTANT(target, "GL_DEPTH_COMPONENT16", 0x81A5);
  DEFINE_CONSTANT(target, "GL_STENCIL_INDEX8", 0x8D48);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_WIDTH", 0x8D42);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_HEIGHT", 0x8D43);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_INTERNAL_FORMAT", 0x8D44);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_RED_SIZE", 0x8D50);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_GREEN_SIZE", 0x8D51);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_BLUE_SIZE", 0x8D52);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_ALPHA_SIZE", 0x8D53);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_DEPTH_SIZE", 0x8D54);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_STENCIL_SIZE", 0x8D55);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE", 0x8CD0);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME", 0x8CD1);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL", 0x8CD2);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE", 0x8CD3);
  DEFINE_CONSTANT(target, "GL_COLOR_ATTACHMENT0", 0x8CE0);
  DEFINE_CONSTANT(target, "GL_DEPTH_ATTACHMENT", 0x8D00);
  DEFINE_CONSTANT(target, "GL_STENCIL_ATTACHMENT", 0x8D20);
  DEFINE_CONSTANT(target, "GL_NONE", 0);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_COMPLETE", 0x8CD5);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT", 0x8CD6);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT", 0x8CD7);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_INCOMPLETE_DIMENSIONS", 0x8CD9);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_UNSUPPORTED", 0x8CDD);
  DEFINE_CONSTANT(target, "GL_FRAMEBUFFER_BINDING", 0x8CA6);
  DEFINE_CONSTANT(target, "GL_RENDERBUFFER_BINDING", 0x8CA7);
  DEFINE_CONSTANT(target, "GL_MAX_RENDERBUFFER_SIZE", 0x84E8);
  DEFINE_CONSTANT(target, "GL_INVALID_FRAMEBUFFER_OPERATION", 0x0506);
}

NODE_MODULE(gles2, init)
