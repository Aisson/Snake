// DemoSnake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "food.h"
#include "control.h"
#include "snake.h"

int main()
{
    /*std::cout << "Hello World!\n"; */
	food MyFood;
	MyFood.CreatPos();
	MyFood.show();
	Sleep(250);
	//MyFood.erase();
	//system("pause");
	control MyControl;
	MyControl.drawGameArea();
	MyControl.drawGameInfo();

	snake mySnake;
	mySnake.showSnake();
	Sleep(250);
	mySnake.eraseSnake();
	//getchar();
	//隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息
	CursorInfo.bVisible = false; //隐藏控制台光标
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态


	while (true)
	{
		mySnake.move();
		if (mySnake.ifDeathself() == 1 || mySnake.ifDeath() == 1) {
			cout << "游戏结束" << endl;
			return 0;
		}

		mySnake.eatFood(MyFood);
	}
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
