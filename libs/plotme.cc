#include <node.h>

namespace demo {

using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;

void getPoints(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  Local<Array> points = Array::New(isolate, 10);

  Local<Object> obj = Object::New(isolate);
  obj->Set(String::NewFromUtf8(isolate, "x"), Number::New(isolate, 42 ));
  obj->Set(String::NewFromUtf8(isolate, "y"), Number::New(isolate, 43 ));

  points->Set(obj);

  args.GetReturnValue().Set(points);

}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "getPoints", getPoints);
}

NODE_MODULE(plotme, init)

}  // namespace demo
