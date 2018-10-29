#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class PaperSheet {
public:	 // спецификатор доступа public
	PaperSheet();	// Конструктор по умолчанию
	PaperSheet(float wid, float hei, double thi, float x, float y);	   // Конструктор инициализации
	PaperSheet(const PaperSheet &other);    // Конструктор копирования
	void set_dim(float wid, float hei, double thi);	// Селектор класса
	void set_coord(float x, float y);	// Селектор класса

	// Модификатор класса
	float get_dim_w();
	float get_dim_h();
	double get_dim_t();

	float get_coord_x();
	float get_coord_y();

	void print() const;
	bool match_with(PaperSheet& ps);

	PaperSheet& operator = (const PaperSheet& ps);
	bool operator == (const PaperSheet& ps);
private: // спецификатор доступа private
	double thick;
	float width,
		height,
		coord_x,
		coord_y;
};
