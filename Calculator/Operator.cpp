#include "Operator.h"

COperator::COperator(string _strOrigin, int _iPriority, function<double(double, double)> _pFunction) :
    CToken(_strOrigin, _iPriority), m_pFunction(_pFunction)
{
}

bool COperator::IsOperator()
{
    return true;
}
