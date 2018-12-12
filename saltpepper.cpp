#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <algorithm>
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
	Mat img=imread("pics/apple.png",1);
	int a[3][9],cnt=0;
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			cnt=0;
			for(int i1=-1;i1<2;i1++)
			{
				for(int j1=-1;j1<2;j1++)
				{
					if(isValid(i+i1,j+j1,img.rows,img.cols))
					{
						int p=3;
						while(p--)
							a[p][cnt++]=img.at<Vec3b>(i,j)[p];
					}
				}
			}

			int p=3;
			while(p--){
				sort(a[p],a[p]+cnt);
				img.at<Vec3b>(i,j)[p]=a[p][cnt/2];}
		}
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",img);
	waitKey(0);
}