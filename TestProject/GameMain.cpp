#include "Input.h"
#include "Monster.h"
#include "Crab.h"
#include "BigFish.h"
#include "SmallFish.h"
#include "MonsterManager.h"
#include "MapManager.h"
#include "KeyManager.h"

// 전역변수
vector<Monster*> g_Mon;
MonsterManager* g_MonMng = MonsterManager::GetInstance();
MapManager* g_MapMng = MapManager::GetInstance();
KeyManager* g_KeyMng = KeyManager::GetInstance();

// 그리기
void Draw() 
{
	g_MapMng->Draw();
	g_MonMng->DrawMonsterUI(10, 10, "BigFish_Left");	// TODO: 임시 출력
	g_MapMng->DrawFrame();
}

// 업데이트
void Update()
{
	g_MapMng->Update();
}

int main()
{
	while (true)
	{
		g_KeyMng->InputKey();	// 키 입력 받기

		Update();		// 업데이트
		_Invalidate();	// 그리기
	}

	return 0;
}