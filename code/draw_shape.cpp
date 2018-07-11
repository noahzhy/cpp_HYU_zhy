#include <iostream>
#include "draw_shape.h"
#include <vector>
using namespace std;

Canvas::Canvas() {}

Canvas::Canvas(size_t row, size_t col) {
	this->row_ = row;
	this->col_ = col;

}
Canvas::~Canvas() {
//	delete row_;
//	delete col_;
//	delete shapes_;
}

int Canvas::AddShape(const Shape &s) {
	//rect
//	if((s.x<0||s.x>this->row_)||(s.y<0||s.y>this->col_)) {
//
//
//	} else {
//		if(s.type==0) {
//			if(s.x+s.width-1 > this->row_-1||s.y+s.height-1 > this->col_-1) {
//				error_canvas = true;
//			}
//		} else if(s.type==1) {
//			if(s.x+s.height-1 > this->row_-1||(s.y+s.height-1 > this->col_-1||s.y-s.height+1<0)) {
//				error_canvas = true;
//			}
//		} else if(s.type==2) {
//			if(s.x-s.height+1 < 0||(s.y+s.width-1 > this->col_-1||s.y-s.width+1<0)) {
//				error_canvas = true;
//			}
//		} else if(s.type == 3) {
//			if(s.x+s.height*2 > this->row_-1||(s.y+s.height > this->col_-1||s.y-s.height<0)) {
//				error_canvas = true;
//			}
//		}
//	}

	this->shapes_.push_back(s);
	return this->shapes_.size() - 1;

}

void Canvas::DeleteShape(int index) {
	int q = 0;
	vector<Shape>::iterator it = this->shapes_.begin();
	for (q=0; q<this->shapes_.size() ; it++) {
		if (q == index) {
			this->shapes_.erase(it);
		}
		q++;
	}
}

void Canvas::Resize(size_t row, size_t col){
	this->row_ = row;
	this->col_ = col;
}

void Canvas::Draw(ostream& os) {
	int p = row_;
	int q = col_;
	char matrix[p][q];

	for (int i = 0; i < p; i++) {
		for (int j = 0; j < q; j++) {
			matrix[i][j] = '.';
		}
	}

	if (this->shapes_.size()>0) {

		for (int i = 0; i < shapes_.size(); i++) {
			if (shapes_[i].type == 0) {
				int shape_star_x, shape_star_y;
				shape_star_x = shapes_[i].x;
				shape_star_y = shapes_[i].y;

				for (int ii = shape_star_x; ii < shapes_[i].width + shape_star_x; ii++) {
					for (int jj = shape_star_y; jj < shapes_[i].height + shape_star_y; jj++) {
						if((ii>=0&&ii<this->row_)&&(jj>=0&&jj<this->col_)) {
							matrix[ii][jj] = shapes_[i].brush;
						}
					}
				}
			} else if (shapes_[i].type == 1) {
				int shape_star_x = shapes_[i].x;
				int	shape_star_y = shapes_[i].y;
				int reduce = 0;
				for (int ii = shape_star_x; ii < shape_star_x + shapes_[i].height; ii++) {
					for (int jj = shape_star_y - reduce; jj < shape_star_y - reduce + (ii - shape_star_x) * 2 + 1; jj++) {
						if((ii>=0&&ii<this->row_)&&(jj>=0&&jj<this->col_)) {
							matrix[ii][jj] = shapes_[i].brush;
						}
					}
					reduce ++;
				}
			} else if (shapes_[i].type == 2) {
				int shape_star_x = shapes_[i].x;
				int	shape_star_y = shapes_[i].y;
				int reduce = 0;
				for (int ii = shape_star_x; ii > shape_star_x - shapes_[i].height; ii--) {
					for (int jj = shape_star_y - reduce; jj < shape_star_y - reduce + (shape_star_x - ii ) * 2 + 1; jj++) {
						if((ii>=0&&ii<this->row_)&&(jj>=0&&jj<this->col_)) {
							matrix[ii][jj] = shapes_[i].brush;
						}
					}
					reduce ++;
				}
			} else if (shapes_[i].type == 3) {
				int shape_star_x = shapes_[i].x;
				int	shape_star_y = shapes_[i].y;
				int reduce = 0;
				int mini_h = shapes_[i].height +1;
				for (int ii = shape_star_x; ii < shape_star_x + mini_h; ii++) {
					for (int jj = shape_star_y - reduce; jj < shape_star_y - reduce + (ii - shape_star_x) * 2 + 1; jj++) {
						if((ii>=0&&ii<this->row_)&&(jj>=0&&jj<this->col_)) {
							matrix[ii][jj] = shapes_[i].brush;
						}
					}
					reduce ++;
				}
				reduce = 0;
				shape_star_x = shapes_[i].x + mini_h * 2 -2;
				for (int ii = shape_star_x; ii > shape_star_x - mini_h; ii--) {
					for (int jj = shape_star_y - reduce; jj < shape_star_y - reduce + (shape_star_x - ii ) * 2 + 1; jj++) {
						if((ii>=0&&ii<this->row_)&&(jj>=0&&jj<this->col_)) {
							matrix[ii][jj] = shapes_[i].brush;
						}
					}
					reduce ++;
				}

			}
		}
	}
	int i = 0, j = 0;

	for (i = -1; i < p; i++) {
		if (i >= 0) {
			os << i%10;
		}
		for (j = -1; j < q; j++) {
			if (i == -1 && j == -1) {
				os << ' ';
			}
			if (i == -1 && j >= 0) {
				os << j%10;
			} else {
				if (i >= 0 && j >= 0) {
					os << matrix[i][j];
				}
			}
		}
		os << endl;
	}
}

void Canvas::Dump(ostream& os) {
	int i = 0;
	vector<Shape>::iterator it = shapes_.begin();
	for (it; it != this->shapes_.end(); it++) {
		switch (it->type) {
			case 0: {
				os << i << " rect ";
				os << it->y << " " << it->x << " " << it->width << " " << it->height << " " << it->brush << endl;
				break;
			}
			case 1: {
				os << i << " tri_up ";
				os << it->y << " " << it->x << " " << it->height << " " << it->brush << endl;
				break;
			}
			case 2: {
				os << i << " tri_down ";
				os << it->y << " " << it->x << " " << it->height << " " << it->brush << endl;
				break;
			}
			case 3: {
				os << i << " diamond ";
				os << it->y << " " << it->x << " " << it->height << " " << it->brush << endl;
				break;
			}
		}
		i++;
	}
}
