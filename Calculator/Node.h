#pragma once
#include "Token.h"
class CNode
{
public:
	CNode();
	~CNode();
private:
	CToken* m_pValue;
	CNode* m_pLeft;
	CNode* m_pRight;
public:
	double Calculation();
};

