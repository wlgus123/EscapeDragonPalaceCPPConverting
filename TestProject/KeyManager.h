#pragma once
#include "IState.h"

class KeyManager
{
private:
	static KeyManager* m_Instance;
	int m_Key;
	bool m_KeyW; // W키 입력 여부
	bool m_KeyA; // A키 입력 여부
	bool m_KeyD; // D키 입력 여부
	bool m_KeyS; // S키 입력 여부
	bool m_KeySpace; // 스페이스바 입력 여부
	
public:
	KeyManager();
	virtual ~KeyManager();

	static KeyManager* GetInstance();

	void InputKey();		// 키 입력
	void CheckMultiKey();	// 다중 키 입력 감지
	int GetKey();			// 키 받아오기
	bool GetKeyW();
	bool GetKeyA();
	bool GetKeyD();
	bool GetKeyS();
	bool GetKeySpace();
};

