#include "MonsterManager.h"

MonsterManager* MonsterManager::m_Instance = nullptr;

// 생성자/소멸자
MonsterManager::MonsterManager()
{
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
