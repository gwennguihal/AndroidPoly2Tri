# AndroidPoly2Tri

JNI wrapper of poly2tri, a 2D constrained Delaunay triangulation library.
Simplified version > no holes handler.
Poly2tri is based on the paper "Sweep-line algorithm for constrained Delaunay triangulation" by V. Domiter and and B. Zalik.

* [poly2tri](http://code.google.com/p/poly2tri/)

## Usage

	package fr.myrddin.delaunay.triangulation;
	
	DelaunayTriangulation clipper = new DelaunayTriangulation();

	double[] input = { -200,-200,200,-200,200,200,-200,200 };

	double[] output = clipper.triangulate(input);

	for (int i = 0; i < output.length; i++)
	{
		Log.e("", "" + output[i]);
	}
	Log.e("", "----");