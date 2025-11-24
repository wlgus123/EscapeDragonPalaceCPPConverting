#include "Input.h"
#include "Monster.h"
#include "MonsterManager.h"

// 생성자
Monster::Monster()
{
}

// 소멸자
Monster::~Monster()
{
}

Pos::Pos()
{
	this->x = 0;
	this->y = 0;
	this->startPos = this->x;
}

Pos::Pos(int x, int y)
{
	this->x = x;
	this->y = y;
	this->startPos = x;
}

Pos::~Pos()
{
}

int Pos::getX()
{
	return this->x;
}

int Pos::getY()
{
	return this->y;
}
