package fr.myrddin.delaunay.triangulation;

public class DelaunayTriangulation
{
	static
	{
		System.loadLibrary("DelaunayTriangulation");
	}
	
	public double[] triangulate(double[] polygon)
	{
		return jniTriangulate(polygon);
	}
	
	private native double[] jniTriangulate(double[] polygon);
}
