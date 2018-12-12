#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int isValid(int x, int y, int row, int col)
{
	if(x<0||y<0||x>=row||y>=col)
		return 0;
	return 1;
}
int main()
{
	Mat img=imread("pics/lenaTest3.jpg",1), img1(img.rows, img.cols, CV_8UC1, Scalar(0)), img2(img.rows, img.cols, CV_8UC1, Scalar(0));

	int sz=3;
	namedWindow("win",WINDOW_NORMAL);
	//createTrackbar("kernel size","win",&sz,100);
	//while(1){
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			int sum[3]={};
			int cnt=0;
			for(int i1=-sz/2;i1<sz/2+1;i1++)
			{
				for(int j1=-sz/2;j1<sz/2+1;j1++)
				{
					if(isValid(i+i1,j+j1,img.rows,img.cols))
					{
						int p=3;
						while(p--)
							sum[p]+=img.at<Vec3b>(i+i1,j+j1)[p];
						cnt++;
					}
				}
			}
			int p=3;
			while(p--)
				img.at<Vec3b>(i,j)[p]=sum[p]/cnt;
		}
	}

	cvtColor(img, img1, cv::COLOR_RGB2GRAY);
	Canny(img1,img2,15,85,3);

	imshow("win",img2);
	waitKey(0);//}
}