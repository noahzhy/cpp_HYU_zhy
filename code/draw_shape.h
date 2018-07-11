#ifndef __draw_shape__
#define __draw_shape__
#include <iostream>
#include <vector>
using namespace std;

enum {RECTANGLE, TRIANGLE_UP, TRIANGLE_DOWN};
enum {ERROR_OUT_OF_CANVAS = -1, ERROR_INVALID_INPUT = -2};

struct Shape {
	int type;
	int x, y;
	int width, height;
	char brush;
};

class Canvas {
public:
	Canvas();
	Canvas(size_t row, size_t col);
	~Canvas();
	int AddShape(const Shape &s);
	void DeleteShape(int index);
	void Draw(ostream& os);
	void Dump(ostream& os);
	void Resize(size_t row, size_t col);
private:
	size_t row_, col_;
	vector<Shape> shapes_;
};

#endif
