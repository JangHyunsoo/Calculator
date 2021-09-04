#include "Operand.h"

COperand::COperand(string _strOrigin, int _iPriority) : CToken(_strOrigin, _iPriority)
{
	m_dValue = stod(_strOrigin);
}

bool COperand::IsOperator()
{
	return false;
}

void COperand::Append(char _cValue)
{
	if (m_strOrigin.size() >= 14) return;
	m_strOrigin += _cValue;
	m_dValue = stod(m_strOrigin);
}

///test//