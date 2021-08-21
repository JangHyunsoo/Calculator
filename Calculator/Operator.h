#pragma once
#include "Token.h"
class COperator :
    public CToken
{
public:
    COperator(string _strOrigin, int _iPriority, function<double(double, double)> _pFunction);

private:
    function<double(double, double)> m_pFunction;
    
public:
    void SetFunction(function<double(double, double)> _pFunction) {
        m_pFunction = _pFunction;
    }

    double Operate(double iValue1, double iValue2) {
        return m_pFunction(iValue1, iValue2);
    }

public:
    virtual bool IsOperator();
};

