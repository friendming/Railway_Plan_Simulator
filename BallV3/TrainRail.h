#pragma once

#include<cmath>
#include<graphics.h>

using namespace std;

//Train Rail
//铁轨

class Rail {
public:
	Rail();
	Rail(int stangle, int endangle, int st_x, int st_y, int end_x, int end_y);
	void set_Rail_Data(int stangle, int endangle, int st_x, int st_y, int end_x, int end_y) { Rail(stangle, endangle, st_x, st_y, end_x, end_y); }
	int get_Rail_Length();
	double get_Rail_Stangle();
	double get_Rail_Endangle();
	char get_Rail_Type();
	int show_Rail();
private:
	double rail_stangle;
	double rail_endangle;
	double rail_st_x;
	double rail_st_y;
	double rail_end_x;
	double rail_end_y;

	char result_rail_type;				//轨道类型 直的0或弯的1
	double result_rail_angle;			//铁轨弧度（几分之几）（所有铁轨都是正圆弧，且弧度小于0.5）
	int result_rail_left;
	int result_rail_top;
	int result_rail_right;
	int result_rail_bottom;
	double result_rail_width;
	double result_rail_height;
	double result_rail_d;
	double result_rail_r_nag_d;
	double result_rail_sin_st_end_distance;
	int result_rail_length;				//铁轨长度
	double result_rail_r;				//半径
	double result_rail_st_end_distance;	//起点终点距离

	void calculate_Rail_Data();			//轨道所有result数据计算
};

Rail::Rail() {

}

Rail::Rail(int stangle, int endangle, int st_x, int st_y, int end_x, int end_y) {
	rail_stangle = stangle;
	rail_endangle = endangle;
	rail_st_x = st_x;
	rail_st_y = st_y;
	rail_end_x = end_x;
	rail_end_y = end_y;
	calculate_Rail_Data();
}

void Rail::calculate_Rail_Data() {
	result_rail_angle = rail_stangle - rail_endangle;//计算角度
	if (result_rail_angle == 0) {
		result_rail_type = 0;
		result_rail_length= sqrt(fabs(rail_end_x - rail_st_x) + fabs(rail_end_y - rail_st_y));//计算长度
	}
	else {
		result_rail_type = 1;
		result_rail_st_end_distance = sqrt(fabs(rail_end_x - rail_st_x) + fabs(rail_end_y - rail_st_y));//计算起点终点间距
		result_rail_r = 0.5*result_rail_st_end_distance / sin(0.5 - result_rail_angle * 0.5);//计算半径
		result_rail_length = result_rail_r * 3.1415926 * result_rail_angle;//计算弧长 长度
		result_rail_d = 0.5*result_rail_st_end_distance / tan(0.5 - result_rail_angle * 0.5);
		result_rail_r_nag_d = result_rail_r - result_rail_d;
		result_rail_sin_st_end_distance = sin(rail_stangle - 0.5)*0.5*result_rail_st_end_distance;
		result_rail_height = sin(rail_stangle - 0.5)* (result_rail_r_nag_d + result_rail_sin_st_end_distance);
		result_rail_width = sin(rail_stangle - 0.5)*result_rail_st_end_distance; //外切矩形宽
	}
}

int Rail::get_Rail_Length() {
	return int(result_rail_length);
}

double Rail::get_Rail_Stangle() {
	return rail_endangle;
}

double Rail::get_Rail_Endangle() {
	return rail_stangle;
}

char Rail::get_Rail_Type() {
	return result_rail_type;
}

int Rail::show_Rail() {//显示轨道
	if (result_rail_length > 0) {//长度不是0
		if (result_rail_type == 0) {//直的
			line(rail_st_x, rail_st_y, rail_end_x, rail_end_y);
		}
		else {//♂van♂的

		}
		return 0;
	}
	else {//长度是0 返回1
		return 1;
	}
}