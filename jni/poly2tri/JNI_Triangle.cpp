#ifdef ANDROID
#include <android/log.h>
#endif

#include "JNI_Triangle.h"
#include "poly2tri.h"
#include "common/shapes.cc"
#include "sweep/cdt.cc"
#include "sweep/sweep_context.cc"
#include "sweep/advancing_front.cc"
#include "sweep/sweep.cc"

JNIEXPORT jintArray JNICALL Java_fr_myrddin_delaunay_triangulation_DelaunayTriangulation_jniTriangulate (JNIEnv *env, jobject obj, jintArray polygonArray)
{
	jint polygonCount; 
	polygonCount = env->GetArrayLength(polygonArray);

	return NULL;
}
