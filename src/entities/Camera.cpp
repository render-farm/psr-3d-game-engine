#include "Camera.h"


Camera::Camera(int cameraViewAngle1)
        : cameraViewAngle(cameraViewAngle1),
          position(glm::vec3(0, 0, 0)),
          orientation(glm::vec3(0, 0, 1)) {}

glm::vec3 Camera::getPosition() {
    return position;
}

void Camera::setPosition(glm::vec3 newPosition) {
    position = newPosition;
}

glm::vec3 Camera::getOrientation() {
    return orientation;
}

void Camera::setOrientation(glm::vec3 newOrientation) {
    orientation = newOrientation;
}

int Camera::getCameraViewAngle() {
    return cameraViewAngle;
}

void Camera::setCameraViewAngle(int newCameraViewAngle) {
    cameraViewAngle = newCameraViewAngle;
}

