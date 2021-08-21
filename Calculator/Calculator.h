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
	stack<class COperand*> m_stackOperand;
	list<class COperator*> m_listOperator;

public:
	void Run();

private:
	void Input();
	void Render();
	void Calculation();
	void TranslateBackwardOperation();
};
