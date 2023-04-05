#pragma once
#include "camera.h"

class StereoCamera{
public:
	StereoCamera()=default;
	StereoCamera(Camera* camera_left, Camera* camera_right) : cam_l(camera_left),cam_r(camera_right){}
	~StereoCamera()=default;

private:
	Camera* cam_l;
	Camera* cam_r;
};
