#ifndef __COLOR_H__
#define __COLOR_H__
#include <string>

class Color
{
  double rgb[3];
  double a;
public:
	// if this pixel has been drawn
	bool transparent;
public:
  Color(double r = 0.0, double g = 0.0, double b = 0.0, double a = 1.0);
  void draw(const Color &o);
	void fill(double r, double g, double b);
  Color fainter(double k);
  std::string as_ppm();
	unsigned char* as_ppm(unsigned char *rgbbuf);
  // __repr__ operator<<
  // hex constructor
};
#endif //__COLOR_H__