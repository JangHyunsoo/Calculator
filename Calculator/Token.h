#pragma once
#include "Common.h"
class CToken
{
public:
	CToken() = default;
	CToken(string _strOrigin, int _iPriority) : m_iPriority(_iPriority), m_strOrigin(_strOrigin) {}
	~CToken();

protected:
	int m_iPriority;
	string m_strOrigin;

public:
	string GetOrigin() {
		return m_strOrigin;
	}

public:
	virtual bool IsOperator() = 0;
};

