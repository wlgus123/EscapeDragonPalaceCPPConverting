#pragma once
#include "Monster.h"

class BigFish : public Monster
{
public:
	// 생성자/소멸자
	BigFish();
	virtual ~BigFish();

	// Monster을(를) 통해 상속됨
	void Init() override;
	void Reset() override;
	void Update() override;
	void Draw() override;
	void MonsterHitPlayer() override;
	void PlayerHitMonster() override;
	void Move() override;
	void Destroy() override;
};

