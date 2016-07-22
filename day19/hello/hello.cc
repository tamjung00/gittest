#include <node.h>
namespace demo {

using v8::FunctionCallbackInfo;
using v8::HandleScope;
using v8::Isolate;
using v8::Local;
using v8::Object;
using v8::String;
using v8::Value;

void Method(const FunctionCallbackInfo<Value>&argv) {
    Isolate* isolate = args.GetIsolate();
    args.GetReturnValue.Set(String::NewFronUtf8(isolate,"hello"));

}

void init(Local<Object>exports) {
    NODE_SET_METHOD(exports,"Hello",Method);
}
NODE_MODULE(addon,init);
}