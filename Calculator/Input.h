#pragma once
#include "Common.h"

class CInput
{
public:
	CInput();
	~CInput();

private:
	vector<class CToken*> m_vecToken;
	int m_iCursor;

public:
	vector<class CToken*> GetToken() {
		return m_vecToken;
	}

public:
	bool Input();
	void Render();
}; 
// ÁßÀ§