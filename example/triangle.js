var Window = require('glfw3-window');

var vertex = [
  "attribute vec3 vPosition;",
  "void main() {",
  " gl_Position.xyz = vPosition;",
  " gl_Position.z = 1.0;",
  "}"
].join('\n');

var frag = [
  "void main() {",
  "  gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);",
  "}"
].join('\n');

var w = new Window(800, 600, 'triangle.js - gles2');
w.eventHandler(function(ev) {
  if (ev.type === 'close') {
    clearInterval(ival);
  } else if (ev.type === 'keydown') {
    if (ev.keyCode === 27) {
      w.close();
      clearInterval(ival);
    }
  }
});

var gl = require('../gles2');

gl.getString(gl.SHADING_LANGUAGE_VERSION)


var createShader = function(str, type) {

  var shader = gl.createShader(type);

  gl.shaderSource(shader, 1, [str], null);
  gl.compileShader(shader);

  if (!gl.getShaderiv(shader, gl.COMPILE_STATUS)) {
    var length = gl.getShaderiv(shader, gl.INFO_LOG_LENGTH)
    gl.getShaderInfoLog(shader, length, null);
    throw new Error('unable to compile shader: ' + str);
  }

  return shader;

};


var vertexShader = createShader(vertex, gl.VERTEX_SHADER);

var fragmentShader = createShader(frag, gl.FRAGMENT_SHADER);


var program = gl.createProgram();
gl.attachShader(program, vertexShader);
gl.attachShader(program, fragmentShader);

gl.linkProgram(program);

var vPositionAttribLocation = gl.getAttribLocation(program, "vPosition");

var vertexBufferArray = new Float32Array([
  -1.0, -1.0, 0.0,
   1.0, -1.0, 0.0,
   0.0,  1.0, 0.0,
]);

var vertexBufferId = gl.genBuffers(1);
gl.bindBuffer(gl.ARRAY_BUFFER, vertexBufferId);
gl.bufferData(gl.ARRAY_BUFFER, vertexBufferArray.length * 4, vertexBufferArray, gl.STATIC_DRAW);
gl.bindAttribLocation(program, vPositionAttribLocation, 'vPosition');

gl.clearColor(1.0, 0, 0.0, 1.0);

var ival = setInterval(function() {
  gl.viewport(0, 0, 800, 600);

  gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
  gl.useProgram(program);

  gl.enableVertexAttribArray(vPositionAttribLocation);
  gl.bindBuffer(gl.ARRAY_BUFFER, vertexBufferId);
  gl.vertexAttribPointer(vPositionAttribLocation, 3, gl.FLOAT, gl.FALSE, 0, 0);

  gl.drawArrays(gl.TRIANGLES, 0, 3);
  gl.flush();
  w.flush();
}, 110);
