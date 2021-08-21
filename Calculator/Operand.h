#pragma once
#include "Token.h"
class COperand :
    public CToken
{
public:
    COperand(string _strOrigin = "", int _iPriority = 1);

private:
    double m_dValue;

public:
    double GetValue() {
        return m_dValue;
    }

public:
    virtual bool IsOperator();
    void Append(char _cValue);
};

