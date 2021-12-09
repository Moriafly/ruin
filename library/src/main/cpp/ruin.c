/**
 * Copyright (C) 2021 Moriafly
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <jni.h>
#include <stdbool.h>

JNIEXPORT jboolean JNICALL
Java_com_moriafly_ruin_core_Ruin_checkXposed(JNIEnv *env, jobject thiz) {
    jclass classloaderClass = (*env)->FindClass(env, "java/lang/ClassLoader");
    jmethodID getSysLoaderMethod = (*env)->GetStaticMethodID(env, classloaderClass,
                                                             "getSystemClassLoader",
                                                             "()Ljava/lang/ClassLoader;");
    jobject classLoader = (*env)->CallStaticObjectMethod(env, classloaderClass, getSysLoaderMethod);
    jclass dexLoaderClass = (*env)->FindClass(env, "dalvik/system/DexClassLoader");
    jmethodID loadClass = (*env)->GetMethodID(env, dexLoaderClass, "loadClass",
                                              "(Ljava/lang/String;)Ljava/lang/Class;");
    jstring dir = (*env)->NewStringUTF(env, "de.robv.android.xposed.XposedBridge");
    jclass targetClass = (jclass) (*env)->CallObjectMethod(env, classLoader, loadClass, dir);
    if ((*env)->ExceptionCheck(env)) {
        (*env)->ExceptionDescribe(env);
        (*env)->ExceptionClear(env);
        return false;
    }
    if (targetClass != NULL) {
        jfieldID disableHooksFiled = (*env)->GetStaticFieldID(env, targetClass, "disableHooks",
                                                              "Z");
        (*env)->SetStaticBooleanField(env, targetClass, disableHooksFiled, true);
        jfieldID runtimeFiled = (*env)->GetStaticFieldID(env, targetClass, "runtime", "I");
        (*env)->SetStaticIntField(env, targetClass, runtimeFiled, 2);
        return true;
    } else {
        return false;
    }
}