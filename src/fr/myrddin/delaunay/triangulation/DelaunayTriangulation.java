package fr.myrddin.delaunay.triangulation;

public class DelaunayTriangulation
{
	static
	{
		System.loadLibrary("DelaunayTriangulation");
	}
	
	public int[] triangulate(int[] polygon)
	{
		return jniTriangulate(polygon);
	}
	
	private native int[] jniTriangulate(int[] polygon);
}
