#include "Input.h"
#include "MapManager.h"
#include "KeyManager.h"

MapManager* MapManager::m_Instance = nullptr;
KeyManager* g_KeyManager = KeyManager::GetInstance();   // 키 매니저 불러오기
vector<string> g_Frame; // 맵 틀

// 생성자/소멸자
MapManager::MapManager()
{
    this->Init();
}

MapManager::~MapManager()
{
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
        this->m_focusX = 0;     // x좌표 이동값 0으로 초기화
        return true;
    }
    
    return false;
}

void MapManager::ResetMapStatus()
{
    // 처음 맵인 감옥 맵으로 이동
    this->m_mapStatus = E_MapStatus::JAIL;
    this->UpdateUI();     // UI 업데이트
}

// 맵 틀 저장하기
void MapManager::InitFrame()
{
    g_Frame = this->GetUI("MapFrame.txt");
}

// 맵 UI 업데이트
void MapManager::UpdateUI()
{
    string mapName = "Map_" + this->GetMapStatusToString() + ".txt";   // 현재 맵에 따라 맵 파일 불러오기
    string flatformName = "Flatform_" + this->GetMapStatusToString() + ".txt";  // 현재 맵에 따라 발판 파일 불러오기
    this->m_BG = this->GetUI(mapName);
    this->m_Flatform = this->GetUI(flatformName);
}

// 맵 UI 불러오기
vector<string> MapManager::GetUI(string p_fileName)
{
    vector<string> fileStr;
    string tempMapLine = "";
    ifstream fin(p_fileName);     // 파일 열기

    if (fin.is_open())
    {
        while (true)
        {
            getline(fin, tempMapLine);      // 줄 단위로 읽기

            if (fin.fail())
            {
                break;
            }
            fileStr.push_back(tempMapLine);
        }
    }
    else
    {
        cout << "파일을 열 수 없습니다." << endl;
    }

    fin.close();

    return fileStr;
}

void MapManager::UpdateX()
{
    // TODO: 임시 코드
    // A or <-, D or ->: 좌, 우 맵 이동
    // N: 다음 스테이지
    // R: 스테이지 리셋
    
    switch (g_KeyManager->GetKey())
    {
    case 'A': case 'a':
        if (this->m_focusX > 0)
            this->m_focusX -= this->m_speed;

        // 맵 처음에 정확하게 닿도록 설정
        if (this->m_focusX - this->m_speed <= 0)
            this->m_focusX = 0;
        break;

    case 'D': case 'd':
        if (this->m_focusX <= this->m_BG[0].size() - MAP_WIDTH)
            this->m_focusX += this->m_speed;
        
        // 맵 끝에 정확하게 닿도록 설정
        if (this->m_focusX + MAP_WIDTH + this->m_speed >= this->m_BG[0].size())
            this->m_focusX = this->m_BG[0].size() - MAP_WIDTH;
        break;

    case 'N': case 'n':
        this->SetMapStatusNext();
        break;

    case 'R': case 'r':
        this->ResetMapStatus();
        break;
    }
}

// 맵 틀 그리기
void MapManager::DrawFrame()
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            // 공백이 아닐 경우만 그리기
            if (g_Frame[y][x] != ' ')
            {
                char tempStr[2] = { g_Frame[y][x], 0 };
                _DrawText(x, y, tempStr);
            }
        }
    }
}

// 배경 그리기
void MapManager::DrawBG()
{
    for (int y = 0; y < MAP_HEIGHT - 1; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            char tempStr[2] = { this->m_BG[y][x + this->GetFocusX()], 0 };
            _DrawTextColor(x, y, tempStr, E_CMDColor::Gray);
        }
    }
}

// 발판 그리기
void MapManager::DrawFlatform()
{
    for (int y = 0; y < MAP_HEIGHT - 1; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if(this->m_Flatform[y][x + this->GetFocusX()] != ' ')
            {
                char tempStr[2] = { this->m_Flatform[y][x + this->GetFocusX()], 0 };
                _DrawText(x, y, tempStr);
            }
        }
    }
}

// 일반 함수
// 초기화
void MapManager::Init()
{
    this->m_speed = 5;     // TODO: 이동속도 설정
    this->m_mapStatus = E_MapStatus::JAIL;
    this->InitFrame();
    this->UpdateUI();
}

// 그리기
void MapManager::Draw()
{
    this->DrawBG();
    this->DrawFlatform();
    this->DrawFrame();
}

// 업데이트
void MapManager::Update()
{
    this->UpdateX();
    this->UpdateUI();   // 변경 후 맵 업데이트
}

// 할당 해제
void MapManager::Destroy() {}

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
    case E_MapStatus::GROUND:
        return "Ground";
    }

    return "";
}
