#include<graphics.h>
#include<string>

#include"Button.h"
#include"TrainRail.h"

using namespace std;

void screenSetup();

int main() {

	screenSetup();//初始化界面
	string teststring1 = "Railway Plan Simulator";
	strcpy_s(TCHAR s)
	TCHAR s[] = _T("Hello World");
	outtextxy(10, 20, s);
	while (1) {

		while (MouseHit()) {//这句非常重要，有消息时进行操作，鼠标操作流畅不卡顿
			//鼠标读取
		}
	}

	closegraph();          // 关闭绘图窗口

}

void screenSetup() {

	//获取屏幕大小
	int nScreenWidth, nScreenHeight;
	nScreenWidth = GetSystemMetrics(SM_CXSCREEN);
	nScreenHeight = GetSystemMetrics(SM_CYSCREEN);

	//创建绘图窗口
	initgraph(nScreenWidth*0.8, nScreenHeight*0.8);

	//界面构建
	setfillcolor(WHITE);

	//按钮构建及绘制
	string teststring = "test";
	Button testbutton(50, 50, 100, 30, 1, teststring);

	//轨道构建测试
	Rail testrail;
	testrail.set_Rail_Data(0.2, 0.5, 100, 100, 200, 200);

}