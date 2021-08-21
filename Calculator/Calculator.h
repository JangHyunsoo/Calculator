#pragma once
#include "Common.h"

class CCalculator
{
public:
	CCalculator();
	~CCalculator();
private:
	bool m_bLoop;

private:
	class CInput* m_pInput;
	vector<class CToken*> m_vecPostfix;

public:
	void Run();

private:
	bool Input();
	void Render();
	void Calculation();
	void TranslatePostfix();
};
