#include <cv.h>
#include <highgui.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;
using namespace cv;

IplImage* image = 0;
IplImage* src = 0;

int main(int argc, char* argv[])
{
	ofstream fout;
	fout.open("out.txt");

	// имя картинки задаётся первым параметром
	char* filename = argc == 2 ? argv[1] : "testImg.jpg";
	// получаем картинку
	image = cvLoadImage(filename,0);


	//Пробегаем по всем пикселям и смотрим их яркость
	for( int y=0; y<image->height; y++ ) {
		uchar* ptr = (uchar*) (image->imageData + y * image->widthStep);
		for( int x=0; x<image->width; x++ ) {
			// 1 канал
			int g = static_cast<int>(ptr[x]);
			char str;

				if (g >= 230.0) {
				str = ' ';
			} else if (g >= 200.0) {
				str = '.';
			} else if (g >= 180.0) {
				str = '*';
			} else if (g >= 160.0) {
				str = ':';
			} else if (g >= 130.0) {
				str = 'o';
			} else if (g >= 100.0) {
				str = '&';
			} else if (g >= 70.0) {
				str = '8';
			} else if (g >= 50.0) {
				str = '#';
			} else {
				str = '@';
			}

			fout << str;
		}
		fout << endl;
	}

	fout.close();
	return 0;
}