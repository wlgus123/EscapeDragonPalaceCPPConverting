#pragma once
#include "IState.h"

// 위치 클래스
class Pos
{
private:
	int x;
	int y;
	int startPos = x;

public:
	Pos();
	Pos(int x, int y);
	virtual ~Pos();
	int getX();
	int getY();
};

// 몬스터 인터페이스 클래스
class IMonster
{
public:
	virtual void Reset() = 0;				// 몬스터 리셋
	virtual void MonsterHitPlayer() = 0;	// 몬스터 피격 처리 함수
	virtual void PlayerHitMonster() = 0;	// 플레이어 -> 몬스터 피격 처리 함수
};

// 몬스터 클래스
class Monster : public IMonster, public IState
{
protected:
	Pos pos;					// 몬스터 위치
	bool alive;					// 생존 여부
	int hp;						// 몬스터 체력
	float speed;				// 이동 속도
	bool isDamaged;				// 피격 상태
	unsigned long lastHitTime;	// 몬스터 마지막 피격 시간

public:
	// 생성자
	Monster();
	virtual ~Monster();

	virtual void Reset() override = 0;				// 리셋
	virtual void MonsterHitPlayer() override = 0;	// 몬스터 피격 처리 함수
	virtual void PlayerHitMonster() override = 0;	// 플레이어 -> 몬스터 피격 처리 함수

	virtual void Init() override = 0;				// 초기화
	virtual void Update() override = 0;				// 업데이트
	virtual void Draw() override = 0;				// 그리기
	virtual void Destroy() override = 0;			// 할당 해제
};

	 

