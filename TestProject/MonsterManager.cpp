#include "Input.h"
#include "MonsterManager.h"
#include "MapManager.h"
#include "Crab.h"
#include "BigFish.h"
#include <json/json.h>

MonsterManager* MonsterManager::m_Instance = nullptr;

// 생성자/소멸자
MonsterManager::MonsterManager()
{
	/*m_AllMonster.insert( make_pair( "Grab", new Crab ));
	m_AllMonster.insert(make_pair("BigFish", new BigFish));*/


	this->Init();


}

MonsterManager::~MonsterManager()
{
}

// 싱글톤 사용
MonsterManager* MonsterManager::GetInstance()
{
	if (!MonsterManager::m_Instance)
	{
		MonsterManager::m_Instance = new MonsterManager();
	}

	return MonsterManager::m_Instance;
}

// 초기화
void MonsterManager::Init()
{
	this->InitMonsterUI();
}

// 업데이트
void MonsterManager::Update()
{
}

// 그리기
void MonsterManager::Draw()
{
}

// 할당 해제
void MonsterManager::Destroy()
{
}

// 몬스터 UI 저장하기 (파일 입출력)
void MonsterManager::InitMonsterUI()
{
	MapManager* mapMng = MapManager::GetInstance();
	ifstream fin1("MonsterUI.json");
	ifstream fin2("MonsterData.json");
	Json::Value UI;
	Json::Value data;
	fin1 >> UI;
	fin2 >> data;

	vector<string> tempUI;
	string tempLine = "";
	string curMap = mapMng->GetMapStatusToString();     // 현재 맵 문자열

	if (fin1.is_open())
	{
		// 현재 맵의 모든 몬스터 출력
		for (string id : UI.getMemberNames())
			for (int i = 0; i < id.size(); i++)
			{
				cout << "ID: " << id << endl;

				cout << UI[id][0]["sprite"][0] << endl;
				/*for(int j = 0; j < UI[i].size(); j++)
				{
					if (UI[id][j]["sprite"])
					{
						cout << "ID: " << id << endl;

						cout << UI[id][j]["sprite"] << endl;
					}
				}*/
			}

	}

	fin1.close();
	fin2.close();
	delete mapMng;
}

//Monster* MonsterManager::CreateClass(string p_monstclassname)
//{
//    Monster *outmonster = nullptr;
//    if (p_monstclassname == "Crab")
//    {
//        outmonster = new Crab();
//    }
//
//    m_AllCreateMonster.push_back(outmonster);
//
//    return outmonster;
//}
