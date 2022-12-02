{
  "targets": [
    {
      "target_name": "native",
      "sources": [
        "./cpp/native.cpp",
        "./cpp/dsjin.cpp"
      ],
      # Header paths
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")",
        "./cpp/lib/include"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').gyp\")"
      ],
      # Library object paths
      "libraries": [
        "/home/hri-jp2998/Desktop/test/cpp-nodejs-ts/cpp/lib/liblibrary.so"
      ],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "defines": ["NAPI_CPP_EXCEPTIONS"]
    }
  ]
}