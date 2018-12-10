#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/joker.jpg",1), brt(img.rows, img.cols, CV_8UC3,Scalar(0,0,0));
	int bt=10;
	namedWindow("w",WINDOW_NORMAL);
	createTrackbar("Brihtness: ", "w", &bt, 20);
	while(1)
		{
			for(int i=0;i<img.rows;i++)
			{
				for(int j=0;j<img.cols;j++)
				{
					int x=3;
					while(x--)
					{
						brt.at<Vec3b>(i,j)[x]=img.at<Vec3b>(i,j)[x]+bt-10;
					}
				}
			}

			imshow("w",bt);
			waitKey(1);
		}
}