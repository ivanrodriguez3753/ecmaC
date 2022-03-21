//
// Created by Ivan Rodriguez on 3/20/22.
//

#include "runtime.h"

void initRuntime() {
    globalRealm = CreateRealm();
    //step 2, but we haven't defined executionContext objects
    //step 3
    //step 4 globalRealm->context = whatever we got in step 2.
    //the rest of the steps need a better understanding on execution contexts
    //and JobQueues
}

realm_record* CreateRealm() {
    return new realm_record;
}