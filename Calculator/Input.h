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
	void Input();
	void Render();
}; 
// ÁßÀ§