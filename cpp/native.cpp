#include <napi.h>
#include "dsjin.h"
using namespace Napi;
using namespace DSJIN;

Number AddNumber(const CallbackInfo& info) {
  Env env = info.Env();

  if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
    TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
  }

  Number first = info[0].As<Napi::Number>();
  Number second = info[1].As<Napi::Number>();

  return Number::New(info.Env(), Add(first.Int32Value(), second.Int32Value()));
}

String Hello(const CallbackInfo& info) {
  return String::New(info.Env(), HelloWorld());
}

Object Init(Env env, Object exports) {
  exports.Set("hello", Function::New(env, Hello));
  exports.Set("addNumber", Function::New(env, AddNumber));
  return exports;
}

NODE_API_MODULE(hello, Init)