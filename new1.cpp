#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#define p 510
using namespace cv;
using namespace std;
int main()
{
	Mat a(p,p,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<p;j++)
		{
			/*int x1=(i-p/2)*(i-p/2);
			int x2=(j-p/2)*(j-p/2);
			int x3=x1+x2;
			float temp=2*(float)x3/(p*p);
			a.at<Vec3b>(i,j)= {temp*255,0,255-temp*255};*/
			float temp=(i*i+j*j)/(p*p);
			a.at<Vec3b>(i,j)= {temp*255,0,255-temp*255};
		}
	}
	namedWindow("w1",WINDOW_NORMAL);
	imshow("w1",a);
	waitKey(2000);
}