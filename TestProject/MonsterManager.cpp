#include <string>
#include <fstream>
#include <json/json.h>
#include "MonsterManager.h"

// TODO: cout 삭제
#include "tempInclude.h"

MonsterManager* MonsterManager::m_Instance = nullptr;

// 생성자/소멸자
MonsterManager::MonsterManager()
{
    cout << "MonsterManager 생성자" << endl;
}

MonsterManager::~MonsterManager()
{
    cout << "MonsterManager 소멸자" << endl;
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
