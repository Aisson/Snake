#include "pch.h"
#include "control.h"
#include "unit.h"

// int control::SCORE = 0;
//int control::LEVEL = 1;
const int control::KSCORE_OFFSET = 50;
const int control::KLEVEL_OFFSET = 64;


control::control()
{
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//
	//m_coor = GetLargestConsoleWindowSize(hOut);
	//CloseHandle(hOut); // 关闭标准输出设备句柄
	///*const int KWIDTH = coor.X;
	//const int KHEIGHT = coor.Y;*/
	///*m_coor = coor;*/
	/*RECT rect;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetClientRect(hOut, &rect);	*/
	HANDLE hOut;
	CONSOLE_SCREEN_BUFFER_INFO scr;
	CONSOLE_CURSOR_INFO CursorInfo;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE); /* 获取标准输出句柄 */
	GetConsoleScreenBufferInfo(hOut, &scr);
	CursorInfo.bVisible = false; //隐藏控制台光标
	m_coor.X = scr.srWindow.Right;
	m_coor.Y = scr.srWindow.Bottom;
}

control::~control()
{
}

void control::drawGameArea()
{
	//todo
	for (int i = unit::KLEFT; i <=  m_coor.X - 2*unit::KLEFT; i++)
	{
		unit::gotoxy(i, unit::KUP);
		cout << "-";
		unit::gotoxy(i, unit::KUP+2);
		cout << "-";
		unit::gotoxy(i, m_coor.Y - 2*unit::KUP);
		cout << "-";
	}

	for (int i = unit::KUP+1; i <= m_coor.Y -1- 2 * unit::KUP; i++)
	{
		unit::gotoxy(unit::KLEFT, i);
		cout << "|";
		unit::gotoxy(m_coor.X - 2 * unit::KLEFT, i);
		cout << "|";
	}
	unit::gotoxy(unit::KLEFT, unit::KUP);
	for (int j = 0; j < unit::KWIDTH; j++)
	{
		cout << "-";
	}

	for (int i = 0; i < unit::KHEIGHT; i++)
	{
		unit::gotoxy(unit::KLEFT, unit::KUP + 1 + i);
		cout << "|";
		unit::gotoxy(unit::KLEFT + unit::KWIDTH - 1, unit::KUP + 1 + i);
		cout << "|";
	}

	unit::gotoxy(unit::KLEFT, unit::KUP + unit::KHEIGHT + 1);
	for (int k = 0; k < unit::KWIDTH; k++)
	{
		cout << "-";
	}

	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 2);
	for (int i = 0; i < unit::KWIDTH - 2; i++)
	{
		cout << "-";
	}
}

void control::drawGameInfo()
{
	//todo


	unit::gotoxy(unit::KLEFT + 1, unit::KUP + 1);

	cout << "游戏名称：贪吃蛇";

	unit::gotoxy(unit::KLEFT + 20, unit::KUP + 1);

	cout << "编写者：朱鹏杰";

	unit::gotoxy(unit::KLEFT + 40, unit::KUP + 1);

	cout << "当前得分:";
	
   // unit::gotoxy(unit::KLEFT + KSCORE_OFFSET, unit::KUP + 1);

	//cout << m_iScore;

	unit::gotoxy(unit::KLEFT + 55, unit::KUP + 1);

	cout << "当前关卡:";

	//unit::gotoxy(unit::KLEFT + KLEVEL_OFFSET, unit::KUP + 1);

	//cout << m_iLevel;

}

/*bool control::checkLevel()
{
	int temp = m_iScore / 30 + 1;

	if (temp == m_iLevel)
	{
		return false;
	}

	m_iLevel = temp;

	switch (m_iLevel)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		//通关
		unit::gotoxy(0, 0);
		cout << "VERY GOOD!!!" << endl;
		return true;
		break;
	}
	return false;
}

void control::changeInfo()
{
	unit::gotoxy(KLEFT + KSCORE_OFFSET, KUP + 1);
	cout << "  ";
	unit::gotoxy(KLEFT + KSCORE_OFFSET, KUP + 1);
	cout << m_iScore;

	unit::gotoxy(KLEFT + KLEVEL_OFFSET, KUP + 1);
	cout << "  ";
	unit::gotoxy(KLEFT + KLEVEL_OFFSET, KUP + 1);
	cout << m_iLevel;
}*/

