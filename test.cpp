#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/joker.jpg",1), gs(img.rows, img.cols, CV_8UC1, Scalar(0));
	
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			gs.at<uchar>(i,j)=1.0/3*img.at<Vec3b>(i,j)[0]+1.0/3*img.at<Vec3b>(i,j)[0]+1.0/3*img.at<Vec3b>(i,j)[0];
		}
	}

	namedWindow("img",WINDOW_NORMAL);
	imshow("img",gs);
	//waitKey(2000);

	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			gs.at<uchar>(i,j)=0.114*img.at<Vec3b>(i,j)[0]+0.587*img.at<Vec3b>(i,j)[0]+0.299*img.at<Vec3b>(i,j)[0];
		}
	}

	namedWindow("img1",WINDOW_NORMAL);
	imshow("img1",gs);
	waitKey(2000);
}