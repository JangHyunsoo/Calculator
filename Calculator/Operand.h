#pragma once
#include "Token.h"
class COperand :
    public CToken
{
public:
    COperand(string _strOrigin = "", int _iPriority = 1);

private:
    int m_iValue;

public:
    int GetValue() {
        return m_iValue;
    }

public:
    virtual bool IsOperator();
    void Append(char _cValue);
};

