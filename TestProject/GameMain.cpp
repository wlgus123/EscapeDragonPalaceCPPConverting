#include "Input.h"
#include "Monster.h"
#include "Crab.h"
#include "BigFish.h"
#include "SmallFish.h"
#include "MonsterManager.h"
#include "MapManager.h"
#include "KeyManager.h"

using namespace std;

// 전역변수
vector<Monster*> g_Mon;
MonsterManager* g_MonMng = MonsterManager::GetInstance();
MapManager* g_MapMng = MapManager::GetInstance();
KeyManager* g_KeyMng = KeyManager::GetInstance();

// 그리기
void Draw() 
{
	g_MapMng->Draw();
}

void Update()
{
	g_MapMng->Update();
}

int main()
{
	// TODO: 맵에 따른 몬스터 정보 가져오기
	// 몬스터 데이터 JSON 파일 불러오기
	ifstream fin("MonsterData.json");
	Json::Value root;
	fin >> root;
	/*for(int i = 0; i < root.size(); i++)
	{
		cout << "===========================" << mapManager->GetMapStatusToString() << "===========================" << endl;
		cout << root[mapManager->GetMapStatusToString()] << endl;
		cout << "==========================================================" << endl;
		mapManager->SetMapStatusNext();
	}*/
	
	while (true)
	{
		g_KeyMng->InputKey();
		Update();
		_Invalidate();
	}

	// Destroy
	fin.close();

	for (Monster* m : g_Mon)
	{
		delete m;
	}

	return 0;
}