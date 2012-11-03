module.exports = {};

var gl = require('bindings')('gles2');

Object.keys(gl).forEach(function(method) {
  var orig = method;
  if (method[0] === 'g') {
    method = method.substring(2);
    method = method[0].toLowerCase() + method.substring(1);
    module.exports[method] = gl[orig];
  } else {
    module.exports[method.replace('GL_', '')] = gl[method];
  }
});
