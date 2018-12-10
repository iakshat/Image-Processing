#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat a(320,320,CV_8UC3,Scalar(0,0,0));
	int i,j;
	for(i=0;i<320;i++)
	{
		for(j=0;j<320;j++)
		{
		    if((((i/40)%2)==((j/40)%2)))
					a.at<Vec3b>(i,j)={255,255,255};
		}

	}
	namedWindow("name",WINDOW_NORMAL);
	imshow("name",a);
	waitKey(5000);
}