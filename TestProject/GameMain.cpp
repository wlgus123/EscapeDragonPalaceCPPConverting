#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <json/json.h>
#include "Monster.h"
#include "Crab.h"
#include "BigFish.h"
#include "SmallFish.h"
#include "MonsterManager.h"

using namespace std;

int main()
{
	vector<Monster*> mon;
	MonsterManager* monsterManager = MonsterManager::GetInstance();


	// 몬스터 데이터 JSON 파일 불러오기
	/*ifstream fin("MonsterData.json");
	Json::Value root;
	fin >> root;
	cout << "Jail-Crab: " << root["Jail"]["Crab"][0] << endl;

	fin.close();*/

	for (Monster* m : mon)
	{
		delete m;
	}
	
	return 0;
}