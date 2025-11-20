#include "MapManager.h"

// TODO: cout 삭제
#include "tempInclude.h"

MapManager* MapManager::m_Instance = nullptr;

// 생성자/소멸자
MapManager::MapManager()
{
    Init();

    cout << "MapManager 생성자" << endl;
}

MapManager::~MapManager()
{
    cout << "MapManager 소멸자" << endl;
}

// 싱글톤
MapManager* MapManager::GetInstance()
{
    if (!MapManager::m_Instance)
    {
        MapManager::m_Instance = new MapManager();
    }

    return MapManager::m_Instance;
}

// 캡슐화 함수
int MapManager::GetFocusX()
{
    return this->m_focusX;
}

void MapManager::SetFocusX(int p_x)
{
    this->m_focusX = p_x;
}

E_MapStatus MapManager::GetMapStatus()
{
    return this->m_mapStatus;
}

bool MapManager::SetMapStatusNext()
{
    // 보스맵이 아닌 경우에만 다음 맵으로 이동
    // 다음 맵 이동이 성공했을 경우 true 반환
    if((int)this->m_mapStatus < (int)E_MapStatus::GROUND)
    {
        this->m_mapStatus = (E_MapStatus)((int)this->m_mapStatus + 1);
        return true;
    }
    
    return false;
}

void MapManager::ResetMapStatus()
{
    // 처음 맵인 감옥 맵으로 이동
    this->m_mapStatus = E_MapStatus::JAIL;
}

vector<string> MapManager::GetUI()
{
    return vector<string>();
}

// 일반 함수
void MapManager::Init()
{
    this->m_mapStatus = E_MapStatus::JAIL;
}

void MapManager::Update()
{

}

void MapManager::Destroy()
{

}

// 현재 맵 이름 문자열로 반환
string MapManager::GetMapStatusToString()
{
    switch (this->m_mapStatus)
    {
    case E_MapStatus::JAIL:
        return "Jail";
    case E_MapStatus::DRAGON_PALACE:
        return "DragonPalace";
    case E_MapStatus::SEA1:
        return "Sea1";
    case E_MapStatus::SEA2:
        return "Sea2";
    }

    return "";
}
