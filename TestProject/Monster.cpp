#include "Monster.h"
#include "tempInclude.h"

// 생성자
Monster::Monster()
{
	cout << "몬스터 생성자" << endl;
}

// 소멸자
Monster::~Monster()
{
	cout << "몬스터 소멸자" << endl;
}

Pos::Pos()
{
	this->x = 0;
	this->y = 0;
	this->startPos = this->x;

	cout << "Pos 생성자(x: " << this->x << ", y: " << this->y << ", startPos: " << this->startPos << ")" << endl;
}

Pos::Pos(int x, int y)
{
	this->x = x;
	this->y = y;
	this->startPos = x;

	cout << "Pos 생성자(x: " << this->x << ", y: " << this->y << ", startPos: " << this->startPos << endl;
}

Pos::~Pos()
{
	cout << "Pos 소멸자" << endl;
}

int Pos::getX()
{
	return this->x;
}

int Pos::getY()
{
	return this->y;
}
