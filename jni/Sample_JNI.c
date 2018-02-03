#include <stdio.h>
#include "newer_Sample_JNI.h"
#include <string.h>
JNIEXPORT jint JNICALL Java_newer_Sample_1JNI_intMethod(JNIEnv * env, jobject arg, jint  value)
{
	return value*value;
}

JNIEXPORT jboolean JNICALL Java_newer_Sample_1JNI_booleanMethod(JNIEnv * env, jobject arg, jboolean value)
{
	return !value;
}

JNIEXPORT jstring JNICALL Java_newer_Sample_1JNI_stringMethod(JNIEnv * env, jobject arg, jstring value)
{
	const jbyte* str=(*env)->GetStringUTFChars(env,value,0);
	char cap[128];
	strcpy(cap,str);
	(*env)->ReleaseStringUTFChars(env,value,str);
	return (*env)->NewStringUTF(env,cap);
}

JNIEXPORT jint JNICALL Java_newer_Sample_1JNI_intArrayMethod(JNIEnv * env, jobject arg, jintArray array)
{
	int i;
	int sum=0;
	jsize len=(*env)->GetArrayLength(env,array);
	jint *body=(*env)->GetIntArrayElements(env,array,0);
	for(i=0;i<len;i++)
	{
		sum+=body[i];
	}
	(*env)->ReleaseIntArrayElements(env,array,body,0);
	return sum;
}