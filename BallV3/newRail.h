#pragma once
#include<graphics.h>
#include<cmath>

//newRail 一个新的铁轨生成算法

class newRail {
private:
	double newRail_stx, newRail_sty, newRail_endx, newRail_endy;
	double newRail_stangle, newRail_endangle;
	void calculate_newRail_Data();

	double result_newRail_angle;
	char result_newRail_type;//轨道种类 0直
	int result_newRail_length;//轨道长度
	double result_newRail_st_end_d;//起终点间距
	double result_newRail_r;//半径
	int result_newRail_x;
	int result_newRail_y;//圆心x,y

public:
	newRail();
	void init_newRail_Data(double stx, double sty, double endx, double endy, double stangle, double endangle);
	void show_newRail();
};

inline newRail::newRail(){

}

void newRail::init_newRail_Data(double stx, double sty, double endx, double endy, double stangle, double endangle) {
	newRail_stx = stx;
	newRail_sty = sty;
	newRail_endx = endx;
	newRail_endy = endy;
	newRail_stangle = stangle;
	newRail_endangle = endangle;
}

void newRail::calculate_newRail_Data() {
	result_newRail_angle = fabs(newRail_stangle - newRail_endangle);//计算角度
	if (result_newRail_angle == 1) {//直的
		result_newRail_type = 0;
		result_newRail_length = sqrt(fabs(newRail_endx - newRail_stx)*fabs(newRail_endx - newRail_stx) + fabs(newRail_endy - newRail_sty)*fabs(newRail_endy - newRail_sty));//计算长度
	}
	else {//弯的
		result_newRail_type = 1;
		result_newRail_st_end_d = sqrt(fabs(newRail_endx - newRail_stx)*fabs(newRail_endx - newRail_stx) + fabs(newRail_endy - newRail_sty)*fabs(newRail_endy - newRail_sty));//计算起点终点间距
		result_newRail_r = 0.5*result_newRail_st_end_d / sin(0.5 - result_newRail_angle * 0.5);//计算半径
		result_newRail_length = result_newRail_r * 3.1415926 * (1-result_newRail_angle);//计算弧长 长度
	}
}

void newRail::show_newRail() {

}