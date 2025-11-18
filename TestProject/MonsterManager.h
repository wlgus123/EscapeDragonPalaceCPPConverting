#pragma once
#include <string>
#include <vector>

using namespace std;

class MonsterManager
{
private:
	static MonsterManager* m_Instance;

public:
	// 생성자/소멸자
	MonsterManager();
	virtual ~MonsterManager();

	// 싱글톤 사용 (인스턴스 불러오기)
	static MonsterManager* GetInstance();

	// 기본 메소드
	void Init();		// 초기화
	void Update();		// 업데이트
	void Destroy();		// 할당 해제
};

