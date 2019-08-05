#pragma once

//Button

#include<graphics.h>
#include<string>

using namespace std;

class Button {

private:
	string button_text;
	int button_x;
	int button_y;
	int button_width;
	int button_height;
	char button_type;
	char button_visable;
	char button_centered;//1=居中

public:
	Button(int x,int y,int width,int height,char visable,string text);	//构造函数
	void set_Button_Text(string in_text);								//设置按钮文字
	string get_Button_Text();											//获取按钮文字
	void set_Button_XY(int x, int y);									//设置按钮位置
	void set_Button_WH(int width, int height);							//设置按钮大小
	int get_Button_X();													//获取按钮X
	int get_Button_Y();													//获取按钮Y
	int get_Button_Width();												//获取按钮宽度
	int get_Button_Height();											//获取按钮高度
	void set_Button_Visable(char visable);								//设置是否可见
	//void unshow_Button();												//隐藏按钮
	void show_Button();													//显示按钮
	void set_Button_Type(char type);									//设置按钮种类形态
	void set_Button_Centered(char centered);

};

Button::Button(int x, int y, int width, int height, char visable,string text) {
	button_x = x;
	button_y = y;
	button_width = width;
	button_height = height;
	button_text = "Button";
	button_type = 0;
	button_visable = visable;
	button_text = text;
	button_centered = 1;//按钮默认居中
	show_Button();
}

void Button::set_Button_Text(string text) {
	button_text = text;
}

string Button::get_Button_Text() {
	return button_text;
}

void Button::set_Button_XY(int x, int y) {
	button_x = x;
	button_y = y;
}

void Button::set_Button_WH(int width, int height) {
	button_height = height;
	button_width = width;
}

int Button::get_Button_X() {
	return button_x;
}

int Button::get_Button_Y() {
	return button_y;
}

int Button::get_Button_Height() {
	return button_height;
}

int Button::get_Button_Width() {
	return button_width;
}

void Button::show_Button() {
	if (button_visable == 1) {//如果按钮可见
		//绘制形状
		int result_button_left = button_x + button_width;
		int result_button_bottom = button_y + button_height;
		switch (button_type) {
		case 0:
			rectangle(button_x, button_y, result_button_left, result_button_bottom);
			break;
		case 1:
			break;
		}

		//绘制文字(只显示一行 不支持换行 文字过长会超出button）
		switch (button_centered) {
			TCHAR s[30];//文字长度最大30
			strcpy_s(s, button_text.c_str());
		case 0://不居中
			outtextxy(button_x, button_y, s);
			break;
		case 1://居中
			int resule_button_text_x = button_x + textwidth(s)*0.5;
			int result_button_text_y = button_y + textheight(s)*0.5;
			outtextxy(resule_button_text_x, result_button_text_y, s);
		}
	}
}

void Button::set_Button_Visable(char visable) {
	button_visable = visable;
}

void Button::set_Button_Type(char type) {
	if (type >= 0 && type <= 5) {//type总种类
		button_type = type;
	}
}

void Button::set_Button_Centered(char centered) {
	button_centered = centered;
}
