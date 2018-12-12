#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <math.h>
#include <stack>
#define PI 3.1415
using namespace cv;
using namespace std;

//Mat im=imread("",0);

int isValid(int x, int y, int row, int col, Mat img)
{
	if(x<0||y<0||x>=row||y>=col||img.at<uchar>(x,y)==0)
		return 0;
	return 1;
}

int dfs(Mat img, Point p)
{
	bool ins[img.rows][img.cols]={}, rm[img.rows][img.cols]={};
	static stack<Point> hold;
	hold.push(p);
	int i=p.x, j=p.y;
	ins[i][j]=1;
	Point right, left, top, bottom;
	right.x=p.x; right.y=p.y+1;
	if(isValid(i,j+1,img.rows, img.cols, img)&&ins[i][j+1]==0)
		dfs(img, right);
	if(isValid(i+1,j,img.rows, img.cols, img)&&ins[i+1][j]==0)
		dfs(img, bottom);
	if(isValid(i-1,j,img.rows, img.cols, img)&&ins[i-1][j]==0)
		dfs(img, top);
	if(isValid(i,j-1,img.rows, img.cols, img)&&ins[i][j-1]==0)
		dfs(img, left);
	hold.pop();
	img.at<uchar>(i,j)=0;
	rm[i][j]=1;
}

int main()
{
	Mat img=imread("pics/Binary1.png",0);
	namedWindow("w",WINDOW_NORMAL);
	
	for (int i = 0; i < img.rows; ++i)
	{
		for(int j=0;j<img.cols;++j)
		{
			if (img.at<uchar>(i,j)==255)
			{
				Point p={i,j};
				dfs(img, p);
			}
			imshow("w",img);
			waitKey(1);
		}
	}

	imshow("w",img);
	waitKey(0);

}
