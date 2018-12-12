#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <math.h>
#define PI 3.1415
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/lowcontrast.PNG",0), rs(256,256, CV_8UC1, Scalar(255));
	int a[256]={};

	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			a[img.at<uchar>(i,j)]++;
		}
	}

	int max=a[0];
	for(int i=0;i<256;i++)
		if(a[i]>max)
			max=a[i];

	for(int i=0;i<256;i++)
		a[i]=a[i]*250.0/max;


	for(int i=0;i<256;i++)
	{
		for(int j=250-a[i];j<256;j++)
			rs.at<uchar>(j,i)=0;
	}

	namedWindow("win",WINDOW_NORMAL);
	imshow("win",rs);
	waitKey(0);
}