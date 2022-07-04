// Using canny edge detection determine how much money is on the table

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;

int main(void)
{
    const char *FILE = "PB4-OpenCV/B-ImageEditing/2-CannyCoins/Coins.jpg";
    Mat coins, grayed, blurred, edges, edgeImg;
    coins = imread(FILE, IMREAD_COLOR);
    cvtColor(coins, grayed, COLOR_RGB2GRAY);
    // HELP: Scale for the blur
    GaussianBlur(grayed, blurred, Size(11, 11), 0, 0);
    // HELP: Slider for the high and low threshold
    Canny(blurred, edges, 0, 100, 3);
    coins.copyTo(edgeImg, edges);
    imshow("Canny Edge with coins", edgeImg);
    waitKey(0);
    return 0;
}