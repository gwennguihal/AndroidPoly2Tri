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

using namespace std;
using namespace p2t;

JNIEXPORT jdoubleArray JNICALL Java_fr_myrddin_delaunay_triangulation_DelaunayTriangulation_jniTriangulate( JNIEnv *env, jobject obj, jdoubleArray polygonArray) {
	jint polygonCount;
	vector<Triangle*> triangles;
	list<Triangle*> map;
	vector<p2t::Point*> polyline;

	polygonCount = env->GetArrayLength(polygonArray);

	jdouble buffer[polygonCount];
	env->GetDoubleArrayRegion(polygonArray, 0, polygonCount, buffer);

	jint i;
	for (i = 0; i < polygonCount; i += 2) {
		polyline.push_back(new Point(buffer[i], buffer[i + 1]));
	}

	CDT* cdt = new CDT(polyline);
	cdt->Triangulate();

	triangles = cdt->GetTriangles();

	jdoubleArray result;
	result = env->NewDoubleArray((int) triangles.size() * 3 * 2);

	if (result == NULL) {
		return NULL; // out of memory error thrown
	}

	jdouble fill[(int) triangles.size() * 3 * 2];
	for (int i = 0; i < triangles.size(); i++) {
		Triangle& t = *triangles[i];
		Point& a = *t.GetPoint(0);
		Point& b = *t.GetPoint(1);
		Point& c = *t.GetPoint(2);

		fill[i * 6] = a.x;
		fill[i * 6 + 1] = a.y;
		fill[i * 6 + 2] = b.x;
		fill[i * 6 + 3] = b.y;
		fill[i * 6 + 4] = c.x;
		fill[i * 6 + 5] = c.y;
	}

	env->SetDoubleArrayRegion(result, 0, (int) triangles.size() * 3 * 2, fill);
	return result;

	return NULL;
}
