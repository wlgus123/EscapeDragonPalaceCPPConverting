#include "Input.h"
#include "MonsterManager.h"
#include "MapManager.h"
#include "Crab.h"
#include "BigFish.h"
#include "SmallFish.h"
#include <json/json.h>

MonsterManager* MonsterManager::m_Instance = nullptr;

// 생성자/소멸자
MonsterManager::MonsterManager()
{
	this->Init();
}

MonsterManager::~MonsterManager()
{
	/*for(int i = 0; i < this->m_MonList.size(); i++)
		if(this->m_MonList[i])
		{
			delete this->m_MonList[i];
		}*/

	delete this->m_Instance;
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
	MapManager* mapMng = MapManager::GetInstance();
	string mapStr = mapMng->GetMapStatusToString();		// 맵 데이터 문자열로 불러오기

}

// 할당 해제
void MonsterManager::Destroy()
{
}

// 몬스터 UI 저장하기 (파일 입출력)
void MonsterManager::InitMonsterUI()
{
	ifstream fin("MonsterUI.json");
	Json::Value UI;
	Json::Value data;
	fin >> UI;

	vector<string> tempUI;

	if (fin.is_open())
	{
		// 현재 맵의 모든 몬스터 불러오기
		for (auto mem : UI)
		{
			for (int i = 0; i < mem.size(); i++)
			{
				for (auto str : mem[i]["sprite"])
				{
					tempUI.push_back(str.asString());
				}
				this->m_MonUI.insert({ mem[i]["id"].asString(), tempUI });
				tempUI.clear();
			}
		}
	}

	fin.close();
}

// 몬스터 UI 그리기
void MonsterManager::DrawMonsterUI(int p_x, int p_y, string p_key)
{
	vector<string> tempUI = this->m_MonUI[p_key];
	// 몬스터 출력
	for (int y = 0; y < tempUI.size(); y++)
	{
		for (int x = 0; x < tempUI[y].size(); x++)
		{
			char tempChar[2] = { tempUI[y][x], 0};
			_DrawText(p_x + x, p_y + y, tempChar);
		}
	}
}

Monster* MonsterManager::CreateClass(string p_monClsName)
{
    Monster *outmonster = nullptr;
    if (p_monClsName == "Crab")
    {
        outmonster = new Crab();
    }
	else if (p_monClsName == "BigFish")
	{
		outmonster = new BigFish();
	}
	else if (p_monClsName == "BigFish")
	{
		outmonster = new SmallFish();
	}

    this->m_MonList.push_back(outmonster);

    return outmonster;
}
