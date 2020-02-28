#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

void average(Mat src)	//均值滤波
{
	int height = src.rows;
	int width = src.cols;
	int max = 0;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int b = src.at<Vec3b>(i, j)[0];
			int g = src.at<Vec3b>(i, j)[1];
			int r = src.at<Vec3b>(i, j)[2];
			int average = (b + g + r) / 3;

			src.at<Vec3b>(i, j)[0] = average;
			src.at<Vec3b>(i, j)[1] = average;
			src.at<Vec3b>(i, j)[2] = average;
		}
	}
}

void threshold(Mat src)  //二值
{
	int height = src.rows;
	int width = src.cols;
	uchar threShold = 100;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int b = src.at<Vec3b>(i, j)[0];
			int g = src.at<Vec3b>(i, j)[1];
			int r = src.at<Vec3b>(i, j)[2];
			int average = (b + g + r) / 3;
			
			if (average > threShold)
			{
				average = 255;
			}
			else
				average = 0;
			src.at<Vec3b>(i, j)[0] = average;
			src.at<Vec3b>(i, j)[1] = average;
			src.at<Vec3b>(i, j)[2] = average;
		}
	}
}

int main()
{
	Mat src = imread("w5.png");
	Mat	shalloMat = src;
	Mat deepMat;

	src.copyTo(deepMat);

	Mat src_gray = imread("w5.png", 0);

	average(src);
	threshold(deepMat);

	imshow("average", src);
	imshow("threshold", deepMat);
	imshow("gray", src_gray);

	waitKey(0);
	return 0;
}