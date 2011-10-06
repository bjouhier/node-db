// Copyright 2011 Bruno Jouhier <bjouhier@gmail.com>
#include "./cursor.h"

void node_db::Cursor::Init(v8::Handle<v8::Object> target, v8::Persistent<v8::FunctionTemplate> constructorTemplate) {
    NODE_ADD_PROTOTYPE_METHOD(constructorTemplate, "next", Next);
}

node_db::Cursor::Cursor(Query* q, Result* r): node::ObjectWrap(), cbNext(NULL) {
    this->query = q;
    this->result = r;
}

node_db::Cursor::~Cursor() {
    if (this->cbNext != NULL) {
        node::cb_destroy(this->cbNext);
    }
}

v8::Handle<v8::Value> node_db::Cursor::Next(const v8::Arguments& args) {
    v8::HandleScope scope;

    node_db::Cursor *cursor = node::ObjectWrap::Unwrap<node_db::Cursor>(args.This());
    assert(cursor);


    return scope.Close(v8::Undefined());
}
