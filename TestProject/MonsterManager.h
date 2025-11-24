#pragma once
#include "IState.h"
#include <map>
#include <string>

using namespace std;

class MonsterManager : public IState
{
private:
	static MonsterManager* m_Instance;
	
	map<string, vector<vector<string>>> m_MonUI;		// 몬스터 UI 맵

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


//protected:
//	map<string, Monster *> m_AllMonster;
//
//	map<string, vector< Monster *> m_AllCreateMonster;
//	//vector< Monster *> m_AllCreateMonster;
//
//public:
//	Monster *CreateClass(string p_monstclassname);

};

