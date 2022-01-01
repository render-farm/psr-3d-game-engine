#include <opencv2/opencv.hpp>

#include "Game.h"

void MouseCallback(int event, int x, int y, int flags, void *userdata) {
    if (event == cv::EVENT_LBUTTONDOWN) {
        std::cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    } else if (event == cv::EVENT_RBUTTONDOWN) {
        std::cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    } else if (event == cv::EVENT_MBUTTONDOWN) {
        std::cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << std::endl;
    } else if (event == cv::EVENT_MOUSEMOVE) {
        std::cout << "Mouse move over the window - position (" << x << ", " << y << ")" << std::endl;
    }
}

Game::Game(CameraSystem& cameraSystem1,
           EntitySystem& entitySystem1,
           RenderSystem& renderSystem1) : renderSystem(cameraSystem1, entitySystem1) { // TODO: WHAT???? why is this needed even when passing by ref?
    this->cameraSystem = cameraSystem1;
    this->entitySystem = entitySystem1;
}

bool Game::runGameLoop(std::string backgroundImagePath) {
    cv::Mat imageBackground;
    imageBackground = cv::imread(backgroundImagePath, cv::IMREAD_UNCHANGED);

    if (!imageBackground.data) {
        std::cout << "Could not open or find the background image" << std::endl;
        return false;
    }

    cv::namedWindow("Display window", cv::WINDOW_AUTOSIZE);
    cv::setMouseCallback("Display window", MouseCallback, NULL); // TODO: how can we get mousePosition from this

    int key;
    while (key != 27) {
        renderSystem.renderScene(imageBackground);

        cv::imshow("Display window", imageBackground);

        key = cv::waitKey(1);
        std::cout << "Key pressed: " << key << std::endl;
        // TODO: Need to use actual mouse position from MouseCallback, we need to figure that out.
        cameraSystem.updateCamera(key, glm::vec2(0, 0));
        entitySystem.updateGame(key);
    }

    return true;
}


