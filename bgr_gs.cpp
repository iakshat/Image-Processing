#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/fruits.png",1), gs(img.rows, img.cols, CV_8UC1,Scalar(255));

	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			gs.at<uchar>(i,j)=1.0/3*img.at<Vec3b>(i,j)[0]+1.0/3*img.at<Vec3b>(i,j)[0]+1.0/3*img.at<Vec3b>(i,j)[0];
		}
	}
	namedWindow("img",WINDOW_NORMAL);
	namedWindow("gs",WINDOW_NORMAL);
	imshow("img",img);
	waitKey(2000);
	imshow("gs",gs);
	waitKey(5000);
}