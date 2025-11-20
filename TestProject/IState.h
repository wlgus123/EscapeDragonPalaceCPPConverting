#pragma once
class IState
{
public:
	virtual void Init() = 0;		// 초기화
	virtual void Draw() = 0;		// 그리기
	virtual void Update() = 0;		// 업데이트
	virtual void Destroy() = 0;		// 할당 해제
};

