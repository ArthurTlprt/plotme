// addon.cc
#include <node.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

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

void Evaluate(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

  std::system("./lexic/analyzer.out < \" mon input \"");

  Local<Object> coord = Object::New(isolate);
  Local<Array> x = Array::New(isolate);
  Local<Array> y = Array::New(isolate);

  for(unsigned int i=0; i < 100; i++) {
    x->Set(i, Number::New(isolate, i));
    y->Set(i, Number::New(isolate, i*i));
  }

  coord->Set(String::NewFromUtf8(isolate, "x"), x );
  coord->Set(String::NewFromUtf8(isolate, "y"), y );
  coord->Set(String::NewFromUtf8(isolate, "title"), String::NewFromUtf8(isolate, "y = f(x)") );

  args.GetReturnValue().Set(coord);
  std::cout << "Evaluate" << std::endl;
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "evaluate", Evaluate);
}

NODE_MODULE(plot, Init)

}  // namespace demo
