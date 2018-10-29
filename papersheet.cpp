#include "papersheet.h"

PaperSheet::PaperSheet(){
	width = 0;
	thick = 0;
	height = 0;
	coord_x = 0;
	coord_y = 0;
}

// Конструктор инициализации
PaperSheet::PaperSheet(float wid, float hei, double thi, float x, float y){
	set_dim(wid, hei, thi);
	set_coord(x, y);
}

// Конструктор копирования
PaperSheet::PaperSheet(const PaperSheet &other){
	width = other.width;
	height = other.height;
	thick = other.thick;
	coord_x = other.coord_x;
	coord_y = other.coord_y;
	//cout << "\nClass is copied\n";
}

// Селектор класса
void PaperSheet::set_dim(float wid, float hei, double thi){
	width = wid;
	height = hei;
	thick = thi;
}

// Селектор класса
void PaperSheet::set_coord(float x, float y){
	coord_x = x;
	coord_y = y;
}

// Модификкатор класса
float PaperSheet::get_dim_w(){ return width; }

float PaperSheet::get_dim_h(){ return height; }

double PaperSheet::get_dim_t(){ return thick; }

// Модификатор класса
float PaperSheet::get_coord_x(){ return coord_x; }

float PaperSheet::get_coord_y(){ return coord_y; }

void PaperSheet::print() const{
	cout << "width: " << width << "\nheigh: " << height << "\nthick" << thick << endl;
	cout << "x coordinate: " << coord_x << "\ny_coordinate: " << coord_y << endl;
}

bool PaperSheet::match_with(PaperSheet& ps){
	return (ps.coord_x - ps.width / 2 < coord_x && coord_x < ps.coord_x + ps.width / 2 && ps.coord_y - ps.height / 2 < coord_y && coord_y < coord_y + ps.height / 2);
}

PaperSheet& PaperSheet::operator = (const PaperSheet& ps){
	set_dim(ps.width, ps.height, ps.thick);
	set_coord(ps.coord_x, ps.coord_y);
	return *this;
}

bool PaperSheet::operator == (const PaperSheet& ps){
	if (coord_x == ps.coord_x && coord_y == ps.coord_y){
		if (width == ps.width && height == ps.height && thick == ps.thick) return true;
		else return false;
	}
	else return false;
}
