// NOTE: for image editing see OpenCVTest.cpp::imagemanip()
// Isolate a red ball from a baby yoda background

#include <vector>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    // window names + Mat declarations
    const char *FILE = "PB4-OpenCV/B-ImageEditing/1-IsolateImage/Grogu.webp";
    const char *ORIGINAL = "Original image";
    const char *MASK = "Mask using HSV scalar values";
    const char *MASKED_IMG = "Image after applying the mask";
    const char *ISOLATED = "Isolate and masked image";
    Mat original, HSVimg, mask, maskedImg, isolated;

    // original image
    original = imread(FILE, IMREAD_COLOR);
    resize(original, original, original.size() / 2, INTER_LINEAR);
    // namedWindow(ORIGINAL, WINDOW_AUTOSIZE);
    imshow(ORIGINAL, original);

    // mask image
    cvtColor(original, HSVimg, COLOR_BGR2HSV);
    Scalar LOW(0, 48, 114), HIGH(8, 255, 255); // CREATE SLIDERS
    inRange(HSVimg, LOW, HIGH, mask);
    imshow(MASK, mask);
    original.copyTo(maskedImg, mask);
    imshow(MASKED_IMG, maskedImg);

    // find largest contour
    vector<vector<Point>> contours;
    findContours(mask, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
    int largestContour = 0;
    for (int i = 1; i < contours.size(); i++)
        if (contourArea(contours[i]) > contourArea(contours[largestContour]))
            largestContour = i;
    Rect boundRect = boundingRect(contours[largestContour]);

    // isolated image
    isolated = Mat(maskedImg, boundRect);
    imshow(ISOLATED, isolated);

    // Wait and end
    waitKey(0);
    return 0;
}