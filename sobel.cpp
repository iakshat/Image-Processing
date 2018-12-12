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
	Mat img=imread("pics/watch.jpg",0), im(img.rows, img.cols, CV_8UC3, Scalar(0,0,0));
	int sxm=0, sym=0, srm=100;
	namedWindow("win",WINDOW_NORMAL);

	createTrackbar("square root minimum", "win", &srm, 255*pow(2,0.5));

	Mat img1(img.rows, img.cols, CV_8UC1, Scalar(255));
	while(1){	
	for(int i=1;i<img.rows-1;i++)
	{
		for(int j=1;j<img.cols-1;j++)
		{
			int sx=(-1)*(img.at<uchar>(i-1,j-1)+img.at<uchar>(i+1,j-1))+(1)*(img.at<uchar>(i-1,j+1)+img.at<uchar>(i+1,j+1))+(2)*(img.at<uchar>(i,j+1))+(-2)*(img.at<uchar>(i,j-1));
			int sy=(-1)*(img.at<uchar>(i-1,j-1)+img.at<uchar>(i-1,j+1))+(1)*(img.at<uchar>(i+1,j-1)+img.at<uchar>(i+1,j+1))+(2)*(img.at<uchar>(i+1,j))+(-2)*(img.at<uchar>(i-1,j));
			
			float sr=pow(sx*sx+sy*sy,0.5);
			if(sr>=srm)
				img1.at<uchar>(i,j)=0;
			else
				img1.at<uchar>(i,j)=255;
		}
	}

	imshow("win",img1);
	waitKey(1);}
}