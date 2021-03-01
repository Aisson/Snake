#pragma once
#include <Windows.h>
#include"snake.h"
#include "unit.h"
class control
{
public:
	//static int score ;
	//static int level ;
	COORD m_coor;
	//static int m_iScore;
	//int m_iLevel;
	static const int KSCORE_OFFSET;
	static const int KLEVEL_OFFSET;

public:
	control();
	~control();
	void drawGameArea();
	void drawGameInfo();
	//bool checkLevel();
	//void changeInfo();


	//void setColor(unsigned short, unsigned short);
};

