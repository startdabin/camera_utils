#include <iostream>
#include "src/dahen_camera.h"

#include <opencv2/imgcodecs.hpp>

int main() {
	Camera* dh_cam = new DahenCamera((char*)"KG0210090307");
	dh_cam->camInit();

	dh_cam->setExposure(5000);
	auto img = dh_cam->getFrame();
	dh_cam->close();
	delete dh_cam;
	cv::imwrite("D:/data/test/img.png", img);
	return 0;
}