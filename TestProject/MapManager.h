#pragma once
#include <string>
#include <vector>

#include "IState.h"

using namespace std;

// 맵 enum
enum E_MapStatus
{
	JAIL = 0,
	DRAGON_PALACE,
	SEA1,
	SEA2,
	GROUND,
	MAX,
};

class MapManager : public IState
{
private:
	static MapManager* m_Instance;

	vector<string> m_UI;		// 맵 UI
	E_MapStatus m_mapStatus;	// 현재 맵 정보
	int m_focusX;				// 플레이어를 기준으로 하는 x좌표 이동값

public:
	// 생성자/소멸자
	MapManager();
	virtual ~MapManager();

	// 싱글톤 사용 (인스턴스 불러오기)
	static MapManager* GetInstance();

	// 기본 메소드
	virtual void Init() override;		// 초기화
	virtual void Draw() override;		// 그리기
	virtual void Update() override;		// 업데이트
	virtual void Destroy() override;	// 할당 해제

	// 현재 맵 이름 문자열로 반환
	string GetMapStatusToString();

	// 캡슐화
	int GetFocusX();						// x좌표 이동값 불러오기
	void SetFocusX(int p_x);				// x좌표 이동값 변경하기
	E_MapStatus GetMapStatus();				// 현재 맵 정보 불러오기
	bool SetMapStatusNext();				// 다음 맵으로 이동
	void ResetMapStatus();					// 맵 초기화 (플레이어 사망 시)
	vector<string> GetUI();					// 맵 UI 불러오기
};

