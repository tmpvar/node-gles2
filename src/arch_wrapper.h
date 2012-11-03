#define BUILDING_NODE_EXTENSION
#ifndef _INCLUDE_ARCH_WRAPPER_
#define _INCLUDE_ARCH_WRAPPER_

  #define DEFINE_CONSTANT(target, name, constant)                            \
  (target)->Set(v8::String::NewSymbol(name),                         \
                v8::Integer::New(constant),                               \
                static_cast<v8::PropertyAttribute>(                       \
                    v8::ReadOnly|v8::DontDelete))


  #ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
    #include <OpenGLES/ES2/gl.h>
    #include <OpenGLES/ES2/glext.h>
    typedef double GLclampd;
  #else
    #ifdef __APPLE__
      #include <OpenGL/OpenGL.h>
      #include <OpenGL/gl.h>
      #define glClearDepthf glClearDepth
    #else
      #ifdef _WIN32
        #include <windows.h>
      #else
        #include <GLES2/gl2.h>
      #endif
    #endif
  #endif
#endif