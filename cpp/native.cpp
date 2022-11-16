#include <napi.h>
#include "dsjin.h"
#include <string>
using namespace Napi;
using namespace DSJIN;

void Welcome(const CallbackInfo& info) {
  Env env = info.Env();
  if (info.Length() < 2) {
    TypeError::New(env, "two args expected").ThrowAsJavaScriptException();
  }
  if (!info[0].IsString()) {
    TypeError::New(env, "args[0]: string expected").ThrowAsJavaScriptException();
  }
  if (!info[1].IsFunction()) {
    TypeError::New(env, "args[1]: callback expected").ThrowAsJavaScriptException();
  }
  String msg = info[0].As<Napi::String>();
  Function cb = info[1].As<Napi::Function>();
  cb.Call(env.Global(), {Napi::String::New(env, std::string("Hello ") + msg.Utf8Value())});
}

Object CreateObject(const CallbackInfo& info) {
  Env env = info.Env();

  if (info.Length() < 1) {
    TypeError::New(env, "one args expected").ThrowAsJavaScriptException();
  }
  if (!info[0].IsString()) {
    TypeError::New(env, "args[0]: string expected").ThrowAsJavaScriptException();
  }
  
  Object obj = Napi::Object::New(env);
  obj.Set(Napi::String::New(env, "msg"), info[0].ToString());

  return obj;
}

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
  exports.Set("welcome", Function::New(env, Welcome));
  exports.Set("createObject", Function::New(env, CreateObject));
  return exports;
}

NODE_API_MODULE(hello, Init)