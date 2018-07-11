#include <iostream>
#include <string>
#include <sstream>
#include "draw_shape.h"
using namespace std;

int main() {
	int a = 0, b = 0;
	string shape_type;
	string command;
	Canvas *c ;
	int center_x, center_y, max_row, max_col;
	char shape_char;

	while (1) {
		string str;
		cin>>command;
		getline(cin,str);
	
		if (command == "quit") {break;}
		else if (command == "add") {	
			Shape shape;	
			stringstream ss(str);
			ss >> shape_type;
			if (shape_type == "rect") {
				ss >> center_y >> center_x >> max_col >> max_row >> shape_char;
				shape.type = 0;
				shape.x = center_x;
				shape.y = center_y;
				shape.width = max_row;
				shape.height = max_col;
				shape.brush = shape_char;
				c->AddShape(shape);

			}
			else if (shape_type == "tri_up") {
				ss >> center_y >> center_x >> max_row >> shape_char;
				shape.type = 1;
				shape.x = center_x;
				shape.y = center_y;
				shape.height = max_row;
				shape.brush = shape_char;
				c->AddShape(shape);
			}
			else if (shape_type == "tri_down") {
				ss >> center_y >> center_x >> max_row >> shape_char;
				shape.type = 2;
				shape.x = center_x;
				shape.y = center_y;
				shape.height = max_row;
				shape.brush = shape_char;
				c->AddShape(shape);
			}
			else if (shape_type == "diamond"){
				ss >> center_y >> center_x >> max_row >> shape_char;
				shape.type = 3;
				shape.x = center_x;
				shape.y = center_y;
				shape.height = max_row;
				shape.brush = shape_char;
				c->AddShape(shape);
			}
		}
		else if (command == "draw") {c->Draw(cout);}
		else if (command == "delete") {
			int key = 0;
			stringstream ss(str);
			ss >> key;
			c->DeleteShape(key);
		}
		else if (command == "dump") {c->Dump(cout);}
		else if (command == "resize"){
			stringstream ss(str);
			ss >> b >>a;
			c->Resize(a, b);
			
		}
		else {
			stringstream ss(command+ str);
			ss >> b >> a;
			c = new Canvas(a, b);
			c->Draw(cout);
		}
	}
	return 0;
}
