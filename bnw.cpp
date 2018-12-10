#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int th = 80;
	namedWindow("w",WINDOW_NORMAL);
	createTrackbar("Threshold","w",&th,255);
		while(1){
	Mat img=imread("pics/joker.jpg",1), bw(img.rows, img.cols, CV_8UC1, Scalar(0));
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			float temp=(img.at<Vec3b>(i,j)[0]+img.at<Vec3b>(i,j)[1]+img.at<Vec3b>(i,j)[2])/3.0;
			if(temp<th)
				bw.at<uchar>(i,j)=0;
			else 
				bw.at<uchar>(i,j)=255;
		}
	}
	imshow("w",bw);
	waitKey(1);
	}
}