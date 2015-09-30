/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements. See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#define DEBUG

#include <jni.h>
jclass submitClass = NULL;
jmethodID callbackMethod = NULL;


jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    } else {

        submitClass = (*env)->FindClass(env, "org/apache/activemq/artemis/bug/SubmitInformation");
        if (submitClass == NULL) {
           return JNI_ERR;
        }

        submitClass = (jclass)(*env)->NewGlobalRef(env, (jobject)submitClass);

        callbackMethod = (*env)->GetMethodID(env, submitClass, "callbackMethod", "(Ljava/lang/String;)V");
        if (callbackMethod == NULL) {
           return JNI_ERR;
        }

        // This following line works fine on Sun JDK and generates a core dumped on IBM JDK
        callbackMethod = (jmethodID)(*env)->NewGlobalRef(env, (jobject)callbackMethod);


        return JNI_VERSION_1_6;
    }
}

void JNI_OnUnload(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if ((*vm)->GetEnv(vm, (void**) &env, JNI_VERSION_1_6) != JNI_OK) {
        // Something is wrong but nothing we can do about this :(
        return;
    } else {
        // delete global references so the GC can collect them
        if (submitClass != NULL) {
            (*env)->DeleteGlobalRef(env, (jobject)submitClass);
        }
    }
}

JNIEXPORT void JNICALL Java_org_apache_activemq_artemis_bug_BugContext_hello
  (JNIEnv * env, jobject thisObject, jobject submitObj) {
    fprintf (stderr, "method inside\n");

    (*env)->CallVoidMethod(env, submitObj, callbackMethod, (*env)->NewStringUTF(env, "This is a callback coming from the C World"));
}

