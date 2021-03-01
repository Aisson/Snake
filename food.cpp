#include "pch.h"
#include "food.h"


food::food()
{

}

food::~food()
{

}

void food::setColor(unsigned short ForeColor = 7, unsigned short BackGroundColor = 0)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//获取当前窗口句柄
	SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//设置颜色
}

void food::CreatPos()
{
	//todo;
	//m_x = randromNum();
	//m_y = randromNum();
	srand((int)time(0));
	m_x = KLEFT+1+rand() % (KWIDTH-2);
	m_y = KUP+1+rand() % (KHEIGHT -3);
}