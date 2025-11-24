#include "MonsterManager.h"
#include "Crab.h"
#include "BigFish.h"


MonsterManager* MonsterManager::m_Instance = nullptr;

// 생성자/소멸자
MonsterManager::MonsterManager()
{
    m_AllMonster.insert( make_pair( "Grab", new Crab ));
    m_AllMonster.insert(make_pair("BigFish", new BigFish));


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
    ifstream fin("MonsterUI.txt");
    vector<string> tempUI;
    string tempLine = "";

    if (fin.is_open())
    {
        while (true)
        {

            CreateClass();

            getline(fin, tempLine);

            // 입력된 문자의 크기가 0일 때 (공백일 때)
            if (tempLine.size() == 0)
            {
                // 임시 UI 배열을 몬스터 배열에 넣기
                this->m_MonUI.push_back(tempUI);
                tempUI.clear();
            }
            // 입력된 문자가 있을 때
            else
            {
                // 임시 UI 배열에 넣기
                tempUI.push_back(tempLine);
            }

            if (fin.fail()) break;
        }
    }

    fin.close();
}

Monster* MonsterManager::CreateClass(string p_monstclassname)
{
    Monster *outmonster = nullptr;
    if (p_monstclassname == "Crab")
    {
        outmonster = new Crab();
    }

    m_AllCreateMonster.push_back(outmonster);

    return outmonster;
}
