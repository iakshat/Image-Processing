#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/joker.jpg",1), neg(img.rows, img.cols, CV_8UC3);

	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			int x=3;
			while(x--)
				neg.at<Vec3b>(i,j)[x]=255-img.at<Vec3b>(i,j)[x];
		}
	}

	namedWindow("win",WINDOW_NORMAL);
	imshow("win1",neg);
	waitKey(5000);
}