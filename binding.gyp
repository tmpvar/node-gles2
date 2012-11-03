{
  "targets": [
    {
      "target_name": "gles2",
      "sources": [
        "src/gles2.cc"
      ],
      "conditions": [
        [
          "OS=='mac'",
          {
            "link_settings": {
              "libraries": [
                "-framework OpenGL",
                "-framework GLUT",
                "-framework Cocoa"
              ]
            }
          }
        ],
        [
          "OS=='linux'",
          {
            "conditions": [
              [
                "target_arch=='arm'",
                {
                  "link_settings": {
                    "libraries": [
                      "-L/opt/vc/lib",
                      "-lGLESv2",
                      "-lEGL",
                      "-lbcm_host"
                    ]
                  }
                },
                {
                  "link_settings": {
                    "libraries": [
                      "-lGLESv2"
                    ]
                  }
                }
              ]
            ]
          }
        ]
      ]
    }
  ]
}