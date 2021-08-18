#pragma once
#include "Token.h"
class COperator :
    public CToken
{
public:
    COperator(string _strOrigin, int _iPriority, function<int(int,int)> _pFunction);

private:
    function<int(int, int)> m_pFunction;
    
public:
    void SetFunction(function<int(int, int)> _pFunction) {
        m_pFunction = _pFunction;
    }

    int Operate(int iValue1, int iValue2) {
        return m_pFunction(iValue1, iValue2);
    }

public:
    virtual bool IsOperator();
};

