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
	list<class CToken*> m_listPostfix;

public:
	void Run();

private:
	void Input();
	void Render();
	void Calculation();
	void TranslatePostfix();
};
