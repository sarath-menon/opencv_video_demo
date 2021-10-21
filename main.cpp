#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]) {
  // open the video file for reading
  cv::VideoCapture cap("IMG_1307.mp4");

  // if not success, exit program

  if (cap.isOpened() == false) {
    std::cout << "Cannot open the video file" << std::endl;
    std::cin.get(); // wait for any key press
    return -1;
  }

  // Uncomment the following line if you want to start the video in the middle
  // cap.set(CAP_PROP_POS_MSEC, 300);

  // get the frames rate of the video
  double fps = cap.get(cv::CAP_PROP_FPS);
  std::cout << "Frames per seconds : " << fps << std::endl;

  cv::String window_name = "My First Video";

  cv::namedWindow(window_name, cv::WINDOW_NORMAL); // create a window

  while (true) {
    cv::Mat frame;
    bool bSuccess = cap.read(frame); // read a new frame from video

    // Breaking the while loop at the end of the video
    if (bSuccess == false) {
      std::cout << "Found the end of the video" << std::endl;
      break;
    }

    // show the frame in the created window
    cv::imshow(window_name, frame);

    // wait for for 1 ms until any key is pressed.
    // If the 'Esc' key is pressed, break the while loop.
    if (cv::waitKey(1) == 27) {
      std::cout << "Esc key is pressed by user. Stoppig the video" << std::endl;
      std::cout << "Frame size" << frame.size() << std::endl;
      std::cout << "Number of channels" << frame.channels() << std::endl;
      break;
    }
  }

  return 0;
}