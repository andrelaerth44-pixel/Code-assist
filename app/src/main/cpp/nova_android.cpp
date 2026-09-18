#include <jni.h>
#include <string>
#include <mutex>
static std::string native_text;
static std::mutex native_mutex;
extern "C" JNIEXPORT jstring JNICALL Java_org_nova_notes_NovaRuntime_nativeVersion(JNIEnv* env,jobject){return env->NewStringUTF("NOVA Android backend 0.1");}
extern "C" JNIEXPORT void JNICALL Java_org_nova_notes_NovaRuntime_nativeSetText(JNIEnv* env,jobject,jstring value){const char* c=env->GetStringUTFChars(value,nullptr);{std::lock_guard<std::mutex> l(native_mutex);native_text=c?c:"";}env->ReleaseStringUTFChars(value,c);}
extern "C" JNIEXPORT jstring JNICALL Java_org_nova_notes_NovaRuntime_nativeGetText(JNIEnv* env,jobject){std::lock_guard<std::mutex> l(native_mutex);return env->NewStringUTF(native_text.c_str());}
