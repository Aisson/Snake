#include "pch.h"
#include "unit.h"

const int unit::KWIDTH = 70;
const int unit::KHEIGHT = 20;
const int unit::KUP = 1;
const int unit::KLEFT = 2;

unit::unit(int x,int y,char pic)
{
	m_x = x;
	m_y = y;
	m_pic = pic;
	//HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD coor;
	//coor = GetLargestConsoleWindowSize(hOut);
	//CloseHandle(hOut); // 关闭标准输出设备句柄
	///*const int KWIDTH = coor.X;
	//const int KHEIGHT = coor.Y;*/
	//m_coor = coor;
}


unit::~unit()
{

}

void unit::setColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}

void unit::gotoxy(int x, int y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	HANDLE hConsoleOut;
	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);
	csbiInfo.dwCursorPosition.X = x;
	csbiInfo.dwCursorPosition.Y = y;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
	//HANDLE hOut;
	//COORD pos = { x,y };
	//int i;
	//hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleCursorPosition(hOut, pos);
}

void unit::show()
{
	//todo;
	//todo goto();
	//setColor(12, 0);
	setColor(12, 0);
	gotoxy(m_x, m_y);
	//setColor(7, 0);
	cout << m_pic;
}

void unit::erase()
{
	gotoxy(m_x, m_y);
	cout << " ";
}

//COORD unit::getWindowInfo()
//{
//	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	COORD coor;
//	coor=GetLargestConsoleWindowSize(hOut);
//	CloseHandle(hOut); // 关闭标准输出设备句柄
//	/*const int KWIDTH = coor.X;
//	const int KHEIGHT = coor.Y;*/
//	m_coor = coor;
//}




