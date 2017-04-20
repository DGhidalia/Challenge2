#include <iostream>
#include "ocam_functions.h"
#include <opencv\cv.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\calib3d\calib3d.hpp>
#include "main.h"


using namespace cv;
using namespace std;

void cb_trackbar1(int, void*) {

}

void affiche(Mat image) {
	imshow("image", image);
}


int main(int argc, char **argv) {

	string chemin = "C:\\Users\\david.ghidalia\\Documents\\GitHub\\Challenge2\\images_Distordu\\00000-cam0.jpg";

	namedWindow("image", WINDOW_NORMAL);

	Mat image = imread(chemin, CV_LOAD_IMAGE_COLOR);
	Mat image2 = image;

	if (!image.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}

	createTrackbar("cam", "image", 0, 250, cb_trackbar1);

	float data[3][3] = { {1,0,1},{0,1,1},{0,0,1} };

	Mat cameraMatrix = Mat(3,3,CV_32FC1, *data);

	fisheye::undistortImage(image, image2, cameraMatrix,NULL);

	CvMat cvimg = image;

	//CvMat* ptr = &cvimg;

	//create_panoramic_undistortion_LUT(ptr, ptr, 0,image.cols,image.cols/2,image.rows/2);

	Mat image2(cvimg.rows,cvimg.cols,cvimg.type,cvimg.data.ptr);

	affiche(image2);

	waitKey(0);
	return 0;

}

