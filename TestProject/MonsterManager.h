#pragma once
#include "Input.h"
#include "IState.h"

// 몬스터 종류 및 상태
enum E_MonsterStatus
{
	// 큰 물고기
	BigFish_L = 0,	// 왼쪽
	BigFish_R,		// 오른쪽
	// 꽃게
	Crab_None,		// 기본
	Crab_Attack,	// 공격
	// 작은 물고기
	SmallFish,
	// 자라(보스)
	Turtle_L,		// 왼쪽
	Turtle_R,		// 오른쪽
};

class MonsterManager : public IState
{
private:
	static MonsterManager* m_Instance;
	
	vector<vector<string>> m_MonUI;		// 몬스터 UI

public:
	// 생성자/소멸자
	MonsterManager();
	virtual ~MonsterManager();

	// 싱글톤 사용 (인스턴스 불러오기)
	static MonsterManager* GetInstance();

	// 기본 메소드
	virtual void Init() override;		// 초기화
	virtual void Draw() override;		// 그리기
	virtual void Update() override;		// 업데이트
	virtual void Destroy() override;	// 할당 해제


	void InitMonsterUI();		// 몬스터 UI 저장하기
};

