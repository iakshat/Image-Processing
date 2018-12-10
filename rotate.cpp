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
	Mat img=imread("pics/joker.jpg",1), rt(3*img.rows, 3*img.cols, CV_8UC3, Scalar(255,255,255));
	cout<<"Enter angle of rotation in degrees: ";
	int angle;
	cin>>angle;

	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			int j1=(j-img.cols/2)*cos(angle*PI/180)-(i-img.rows/2)*sin(angle*PI/180) +img.cols*3/2;
			int i1=(j-img.cols/2)*sin(angle*PI/180)+(i-img.rows/2)*cos(angle*PI/180) +img.rows*3/2;
			int p=3;
			while(p--)
				rt.at<Vec3b>(i1,j1)[p]=img.at<Vec3b>(i,j)[p];			
		}
	}

	for(int i=1;i<3*img.rows-1;i++)
	{
		for(int j=1;j<3*img.cols-1;j++)
		{
			if(rt.at<Vec3b>(i,j)[0]==255&&rt.at<Vec3b>(i,j)[1]==255&&rt.at<Vec3b>(i,j)[2]==255)
			{
				int p=3;
				while(p--)
				{
					rt.at<Vec3b>(i,j)[p]=rt.at<Vec3b>(i+1,j)[p]+rt.at<Vec3b>(i,j+1)[p]+rt.at<Vec3b>(i-1,j)[p]+rt.at<Vec3b>(i,j-1)[p]+rt.at<Vec3b>(i+1,j-1)[p]+rt.at<Vec3b>(i-1,j-1)[p]+rt.at<Vec3b>(i-1,j+1)[p]+rt.at<Vec3b>(i+1,j+1)[p];
				}
			}
		}
	}

	namedWindow("win",WINDOW_NORMAL);
	imshow("win",rt);
	waitKey(0);
}