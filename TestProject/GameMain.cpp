#include "Input.h"
#include "Monster.h"
#include "Crab.h"
#include "BigFish.h"
#include "SmallFish.h"
#include "MonsterManager.h"
#include "MapManager.h"

using namespace std;

int main()
{
	vector<Monster*> mon;
	MonsterManager* monsterManager = MonsterManager::GetInstance();
	MapManager* mapManager = MapManager::GetInstance();

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
	mapManager->GetUI();

	
	// Destroy
	fin.close();

	for (Monster* m : mon)
	{
		delete m;
	}

	return 0;
}