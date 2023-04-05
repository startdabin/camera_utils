#include <iostream>
#include "src/dahen_camera.h"
#include "src/stereo_camera.h"

#include <opencv2/highgui.hpp>

int main() {
	// init camera
	DahenCamera::libInit();
	Camera* dh_cam_l = new DahenCamera((char*)"KG0210090307");
	Camera* dh_cam_r = new DahenCamera((char*)"KG0210090308");
	dh_cam_l->camInit();
	dh_cam_r->camInit();
	dh_cam_l->setExposure(5000);
	dh_cam_r->setExposure(5000);

	auto stereo_cam = StereoCamera(dh_cam_l, dh_cam_r);
	std::string left_path = "D:/PROJECT/work/camera_utils/data/stereo_imgs0/left/";
	std::string right_path = "D:/PROJECT/work/camera_utils/data/stereo_imgs0/right/";
	stereo_cam.captureImage(left_path, right_path);

	// close camera
	dh_cam_l->close();
	dh_cam_r->close();
	delete dh_cam_l;
	delete dh_cam_r;
	dh_cam_l = nullptr;
	dh_cam_r = nullptr;
	DahenCamera::libUinit();


	return 0;
}