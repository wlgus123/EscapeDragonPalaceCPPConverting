#include "Input.h"
#include "KeyManager.h"

KeyManager* KeyManager::m_Instance = nullptr;

// 생성자
KeyManager::KeyManager()
{
	this->m_Key = -1;
	this->m_KeyW = false;
	this->m_KeyA = false;
	this->m_KeyD = false;
	this->m_KeyS = false;
	this->m_KeySpace = false;
}

// 소멸자
KeyManager::~KeyManager()
{
}

// 인스턴스 가져오기
KeyManager* KeyManager::GetInstance()
{
	if (KeyManager::m_Instance == nullptr)
	{
		KeyManager::m_Instance = new KeyManager();
	}

	return KeyManager::m_Instance;
}

void KeyManager::InputKey()
{
}

// 다중 키 입력 감지
void KeyManager::CheckMultiKey()
{
	// GetAsyncKeyState 사용
	this->m_KeyW = (GetAsyncKeyState('W') & 0x8000); // W키(점프/위 이동) 입력 감지
	this->m_KeyA = (GetAsyncKeyState('A') & 0x8000); // A키(왼쪽 이동) 입력 감지
	this->m_KeyD = (GetAsyncKeyState('D') & 0x8000); // D키(오른쪽 이동) 입력 감지
	this->m_KeyS = (GetAsyncKeyState('S') & 0x8000); // S키(아래 이동) 입력 감지

	this->m_KeySpace = (GetAsyncKeyState(' ') & 0x8000); // 스페이스바(공격) 입력 감지

}

int KeyManager::GetKey()
{
	return this->m_Key;
}

bool KeyManager::GetKeyW()
{
	return this->m_KeyW;
}

bool KeyManager::GetKeyA()
{
	return this->m_KeyA;
}

bool KeyManager::GetKeyD()
{
	return this->m_KeyD;
}

bool KeyManager::GetKeyS()
{
	return this->m_KeyS;
}

bool KeyManager::GetKeySpace()
{
	return this->m_KeySpace;
}
