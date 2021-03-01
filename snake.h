#pragma once
#include <conio.h>
#include <vector>
#include "unit.h"
#include"food.h"
#include"control.h"

typedef enum Dir
{
	KUP,KDOWN,KLEFT,KRIGHT,STOP
};
class snake
{
public:
	int m_HeadX;
	int m_HeadY;
	int m_Len;
	int m_Speed;
	static int speed;
	//static int score;
	//static int level;
    int m_iScore;
	int m_iLevel;
	Dir m_Dir;
	vector<unit> m_Body;
public:
	snake(int x=40,int y=10,int len=8,int speed=250, Dir dir= KRIGHT, char pic='#');
	~snake();
	void showSnake();
	void eraseSnake();
	void listen_key_borad();
	void move();
	bool eatFood(food& Food);
	bool ifDeath();
	bool ifDeathself();
	void changeInfo();
	bool checkLevel();

};

