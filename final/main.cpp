#include <Image.tpp>
#include <Pixel.tpp>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char** argv)
{
	Image<double> img0;
	cout << img0.Width() << " " << img0.Height() << " " << img0.Size() << endl;
	
	Image<double> img1(256, 256);
	cout << img1.Width() << " " << img1.Height() << " " << img1.Size() << endl;
	RGB<int> rgb0(2, 2, 2);
	cout << rgb0.Red() << " " << rgb0.Blue() << " " << rgb0.Green() << endl;
	
	HSV hzv0(2.0);
	cout << hzv0.Hue() << " " << hzv0.Saturation() << " " << hzv0.Value() << endl;
	
	RGB<int> rgbDbl0(0, 257, 300);
	RGB<int> rgbDbl1(1, 257, 300);
	RGB<int> rgbDbl2(2, 257, 300);
	RGB<int> rgbDbl3(3, 257, 300);
	HSV hsvDbl0(rgbDbl0);
	cout << rgbDbl0.Red() << " " << rgbDbl0.Blue() << " " << rgbDbl0.Green() << endl;
	cout << hsvDbl0.Hue() << " " << hsvDbl0.Saturation() << " " << hsvDbl0.Value() << endl;
	
	
	HSV hsvDbl1(rgbDbl1);
	cout << rgbDbl1.Red() << " " << rgbDbl1.Blue() << " " << rgbDbl1.Green() << endl;
	cout << hsvDbl1.Hue() << " " << hsvDbl1.Saturation() << " " << hsvDbl1.Value() << endl;
	
	
	HSV hsvDbl2(rgbDbl2);
	cout << rgbDbl2.Red() << " " << rgbDbl2.Blue() << " " << rgbDbl2.Green() << endl;
	cout << hsvDbl2.Hue() << " " << hsvDbl2.Saturation() << " " << hsvDbl2.Value() << endl;
	
	
	HSV hsvDbl3(rgbDbl3);
	cout << rgbDbl3.Red() << " " << rgbDbl3.Blue() << " " << rgbDbl3.Green() << endl;
	cout << hsvDbl3.Hue() << " " << hsvDbl3.Saturation() << " " << hsvDbl3.Value() << endl;
	cout << img1(0, 128) << endl;
	
	Image<int> img2();
	std::shared_ptr<Image> img_ptr();
	fill(img_ptr.begin(), img_ptr.end());
	cout << img1(0, 128) << endl;
}