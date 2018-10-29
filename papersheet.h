#pragma once

#include <iostream>
#include <assert.h>

using namespace std;

class PaperSheet {
public:	 // ������������ ������� public
	PaperSheet();	// ����������� �� ���������
	PaperSheet(float wid, float hei, double thi, float x, float y);	   // ����������� �������������
	PaperSheet(const PaperSheet &other);    // ����������� �����������
	void set_dim(float wid, float hei, double thi);	// �������� ������
	void set_coord(float x, float y);	// �������� ������

	// ����������� ������
	float get_dim_w();
	float get_dim_h();
	double get_dim_t();

	float get_coord_x();
	float get_coord_y();

	void print() const;
	bool match_with(PaperSheet& ps);

	PaperSheet& operator = (const PaperSheet& ps);
	bool operator == (const PaperSheet& ps);
private: // ������������ ������� private
	double thick;
	float width,
		height,
		coord_x,
		coord_y;
};
