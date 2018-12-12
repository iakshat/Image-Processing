#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <queue>
#include <math.h>
#define PI 3.1415
using namespace cv;
using namespace std;

Mat img=imread("pics/Binary1.png",0);

bool isValid(int i,int j)
{
	if(i<0||j<0||i>=img.rows||j>=img.cols)
		return 0;
	return 1;
}

int main()
{	

	for (int i = 0; i < img.rows; ++i)
	{
		for (int j = 0; j < img.cols; ++j)
		{
			if(img.at<uchar>(i,j)==255)
			{
				Mat temp(img.rows, img.cols, CV_8UC1, Scalar(0));
				queue<Point> q;
				Point p={i,j};
				q.push(p);
				//temp.at<uchar>(i,j)=255;
				img.at<uchar>(i,j)=0;
				while(!(q.empty()))
				{
					Point pt=q.front();
					if(temp.at<uchar>(pt.x, pt.y)!=0)
					{
						q.pop();
						continue;
					}

					if(isValid(pt.x,pt.y+1)&&temp.at<uchar>(pt.x,pt.y+1)==0&&img.at<uchar>(pt.x,pt.y+1)==255)
					{
						Point pm={pt.x,pt.y+1};
						q.push(pm);
						img.at<uchar>(pt.x,pt.y+1)=0;
					}
					if(isValid(pt.x+1,pt.y)&&temp.at<uchar>(pt.x+1,pt.y)==0&&img.at<uchar>(pt.x+1,pt.y)==255)
					{
						Point pm={pt.x+1,pt.y};
						q.push(pm);
						img.at<uchar>(pt.x+1,pt.y)=0;
					}
					if(isValid(pt.x,pt.y-1)&&temp.at<uchar>(pt.x,pt.y-1)==0&&img.at<uchar>(pt.x,pt.y-1)==255)
					{
						Point pm={pt.x,pt.y-1};
						q.push(pm);
						img.at<uchar>(pt.x,pt.y-1)=0;
					}
					if(isValid(pt.x-1,pt.y)&&temp.at<uchar>(pt.x-1,pt.y)==0&&img.at<uchar>(pt.x-1,pt.y)==255)
					{
						Point pm={pt.x-1,pt.y};
						q.push(pm);
						img.at<uchar>(pt.x-1,pt.y)=0;
					}
					temp.at<uchar>(pt.x,pt.y)=255;
					q.pop();
					imshow("w",img);
					waitKey(1);
				}
			}
		}
	}

	namedWindow("w",WINDOW_NORMAL);
	imshow("w",img);
	waitKey(0);
}