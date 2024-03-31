#include "org_example_Main.h"
#include <iostream>

#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_example_Main
 * Method:    sayHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_org_example_Main_sayHello
  (JNIEnv *, jobject) {
    std::cout << "Hello from C++!" << std::endl;
  }

 /*
  * Class:     org_example_Main
  * Method:    sayHello2
  * Signature: ()V
  */
 JNIEXPORT void JNICALL Java_org_example_Main_sayHello2
   (JNIEnv *, jobject) {
    std::cout << "we made it here too!" << std::endl;
   }

#ifdef __cplusplus
}
#endif
