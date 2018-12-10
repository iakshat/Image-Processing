#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/joker.jpg",1), rs(2*img.rows+1, 2*img.cols+1, CV_8UC3, Scalar(0,0,0));
	int i1=0;
	for(int i=0;i<2*img.rows;i=i+2)
	{
		int j1=0;
		for(int j=0;j<2*img.cols;j=j+2)
		{
			int p=3;
			while(p--){
				rs.at<Vec3b>(i,j)[p]=img.at<Vec3b>(i1,j1)[p];
				rs.at<Vec3b>(i+1,j)[p]=img.at<Vec3b>(i1,j1)[p];
				rs.at<Vec3b>(i,j+1)[p]=img.at<Vec3b>(i1,j1)[p];
				rs.at<Vec3b>(i+1,j+1)[p]=img.at<Vec3b>(i1,j1)[p];
			}
			j1++;
		}
		i1++;
	}
	namedWindow("win",WINDOW_NORMAL);
	imshow("win",rs);
	waitKey(2000);
}