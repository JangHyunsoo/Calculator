#include "Operator.h"

COperator::COperator(string _strOrigin, int _iPriority, function<int(int,int)> _pFunction) :
    CToken(_strOrigin, _iPriority), m_pFunction(_pFunction)
{
}

bool COperator::IsOperator()
{
    return true;
}
