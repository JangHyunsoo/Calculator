#pragma once
#include "Node.h"
class CTokenTree
{
public:
	CTokenTree();
	~CTokenTree();

private:
	CNode* m_pRoot;
	
public:
	void Add(const CToken& pToken);
	double Calculation();
};

