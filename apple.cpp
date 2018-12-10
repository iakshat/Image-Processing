#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat img=imread("pics/fruits.png",1), ap(img.rows, img.cols, CV_8UC3, Scalar(0,0,0));
	int rm=0, rM=255, bm=0, gm=0, bM=255, gM=255;
	namedWindow("win",WINDOW_NORMAL);
	createTrackbar("redm","win",&rm ,255);
	createTrackbar("redM","win",&rM ,255);
	createTrackbar("bluem","win",&bm ,255);
	createTrackbar("blueM","win",&bM ,255);	
	createTrackbar("greenm","win",&gm ,255);
	createTrackbar("greenM","win",&gM ,255);

while(1){
	for(int i=0;i<img.rows;i++)
	{
		for(int j=0;j<img.cols;j++)
		{
			if((bm<img.at<Vec3b>(i,j)[0] && img.at<Vec3b>(i,j)[0]<bM) && (gm<img.at<Vec3b>(i,j)[1] && img.at<Vec3b>(i,j)[1]<gM) && (rm<img.at<Vec3b>(i,j)[2] && img.at<Vec3b>(i,j)[2]<rM))
				{
					int x=3;
					while(x--)
						{
							ap.at<Vec3b>(i,j)[x]=img.at<Vec3b>(i,j)[x];
						}
				}
			else
				ap.at<Vec3b>(i,j)= {255,255,255};

		}
	}
	imshow("w",ap);	
	waitKey(1);
}
}