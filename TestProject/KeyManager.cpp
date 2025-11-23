#include "Input.h"
#include "KeyManager.h"

KeyManager* KeyManager::m_Instance = nullptr;

// 생성자/소멸자
KeyManager::KeyManager()
{
	this->m_Key = -1;
}

KeyManager::~KeyManager() { }

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
	this->m_Key = _GetKey();
}

int KeyManager::GetKey()
{
	return this->m_Key;
}