#include <iostream>
#include "ocam_functions.h"
#include <opencv\cv.h>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "main.h"


using namespace cv;
using namespace std;



int main(int argc, char **argv) {

	string chemin = "C:\\Users\\david.ghidalia\\Documents\\GitHub\\Challenge2\\images_Distordu\\00000-cam0.jpg";

	namedWindow("image", WINDOW_NORMAL);

	Mat image = imread(chemin, CV_LOAD_IMAGE_COLOR);

	if (!image.data)                              // Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
		return -1;
	}


	

	

	imshow("image", image);

	waitKey(0);
	return 0;

}