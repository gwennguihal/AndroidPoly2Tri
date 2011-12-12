package fr.myrddin.delaunay.triangulation;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class Jni_delaunay_triangulationActivity extends Activity
{
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);

		DelaunayTriangulation clipper = new DelaunayTriangulation();

		int[] input = { -200,-200,200,-200,200,200,-200,200 };

		int[] output = clipper.triangulate(input);

		for (int i = 0; i < output.length; i++)
		{
			Log.e("", "" + output[i]);
		}
		Log.e("", "----");
	}
}