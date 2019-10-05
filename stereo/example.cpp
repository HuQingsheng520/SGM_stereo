#include"SGMStereo.h"
#include<iostream>
#include<cstdlib>

int main() {
	Mat lImg = imread("left.png", IMREAD_COLOR);
	Mat rImg = imread("right.png", IMREAD_COLOR);
	if (!lImg.data || !rImg.data) {
		printf("Error: can not open image\n");
		printf("\nPress any key to continue...\n");
		getchar();
		return -1;
	}
	int hei = lImg.rows;
	int wid = rImg.cols;
	Mat lDis = Mat::zeros(hei, wid, CV_32FC1);
	SGMStereo sgm;
	sgm.compute(lImg, rImg, lDis);
	imwrite("view_test.png", lDis);
	printf("ÕºœÒ∆•≈‰ÕÍ≥…\n");
	system("pause");
	return 0;

}
