#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/lena.png",1), mr(img.rows, 2*img.cols+1, CV_8UC3, Scalar(0,0,0));
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<2*img.cols;j++)
		{
			int p=3;
			while(p--)
			{
				if(j<img.cols)
					mr.at<Vec3b>(i,j)[p]=img.at<Vec3b>(i,j)[p];
				else
					mr.at<Vec3b>(i,j)[p]=img.at<Vec3b>(i,2*img.cols-j-1)[p];
			}
		}
	}

	namedWindow("win",WINDOW_NORMAL);
	imshow("win",mr);
	waitKey(2000);
}