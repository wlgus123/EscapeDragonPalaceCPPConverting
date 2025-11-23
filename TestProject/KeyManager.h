#pragma once
#include "IState.h"

class KeyManager
{
private:
	static KeyManager* m_Instance;
	int m_Key;
	
public:
	KeyManager();
	virtual ~KeyManager();

	static KeyManager* GetInstance();

	void InputKey();		// 키 입력
	int GetKey();			// 키 받아오기
};

