#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main()
{
	Mat f=imread("pics/fruits.png",1);
	namedWindow("a",WINDOW_NORMAL);
	imshow("a",f);
	waitKey(10000);
}