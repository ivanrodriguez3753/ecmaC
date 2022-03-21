//
// Created by Ivan Rodriguez on 3/20/22.
//

#ifndef ECMAC_RUNTIME_H
#define ECMAC_RUNTIME_H

#include <map>
#include <set>
#include <string>

class record;
class env_record;
class compl_record;
class realm_record;



//6.1 ECMAScript Language Types
class js_value; //base class, not in the spec
class js_undefined;
class js_null;
class js_boolean;
class js_string;
class js_number;
class js_object;

class data_property;

class lexical_env;

std::map<void*, js_value*> heapObjects;

//for now we're assuming a single realm
realm_record* globalRealm;


class lexical_env {
    lexical_env* outer;
    env_record* globalEnv;
};

class js_value {

};

class realm_record {
    js_object* globalObject;
    lexical_env* globalEnv;
    std::map<std::string, js_object> intrinsics;
};

class record {

};




class env_record : record {


    virtual compl_record* CreateMutableBinding() = 0;
};

class object_record : env_record {
    js_object* binding_object;





    compl_record* CreateMutableBinding();


};

class decl_record : env_record {

};


//6.1.7.1 A data property associates a key value with the attributes listed in Table 3.
class data_property {
    js_value* value;
    bool writable, enumerable, configurable;
};

//umm, it only has one possible value so it doesn't actually need to track anything?
class js_undefined : js_value {

};

//same as js_undefined
class js_null : js_value {

};

class js_bool : js_value {
    bool value;
};

class js_string : js_value {
    std::string value;
};

class js_number : js_value {
    double value;
};

class js_object : js_value {
    std::map<std::string, data_property> data_properties;



public:


};

//8.5 ECMAScript Initialization
void initRuntime();
static realm_record* CreateRealm();




#endif //ECMAC_RUNTIME_H
