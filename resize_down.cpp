#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	int x=0;
	Mat img=imread("pics/lena.png",1), half(img.rows/2+1,img.cols/2+1,CV_8UC3,Scalar(0,0,0));
	for(int i=0;i<img.rows;i=i+2)
	{
		int y=0;
		for(int j=0;j<img.cols;j=j+2)
		{
			int p=3;
			while(p--)
			{
				half.at<Vec3b>(x,y)[p] = (img.at<Vec3b>(i,j)[p]+img.at<Vec3b>(i,j+1)[p]+img.at<Vec3b>(i+1,j)[p]+img.at<Vec3b>(i+1,j+1)[p])/4.0;
			}
			y++;
		}
		x++;
	}

namedWindow("win",WINDOW_NORMAL);
imshow("win",half);
waitKey(2000);

}