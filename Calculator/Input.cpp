#include "Input.h"
#include "Operand.h"
#include "Operator.h"

CInput::CInput() : m_iCursor(0)
{
	m_vecToken.push_back(new COperand("0"));
}

CInput::~CInput()
{
	SafeDeleteVec(m_vecToken);
}

void CInput::Input()
{
	char cInput = _getch();

	if (isdigit(cInput)) {
		// operand
		if (!m_vecToken[m_iCursor]->IsOperator()) {
			((COperand*)m_vecToken[m_iCursor])->Append(cInput);
		}
		else {
			m_vecToken.push_back(new COperand(string(1, cInput)));
			m_iCursor++;
		}
	}
	else {
		// operator
		switch (cInput)
		{
		case '+':
			m_vecToken.push_back(new COperator(string(1, cInput), 1, 
				[](int value1, int value2) { return value1 + value2;})
			);
			m_iCursor++;
			break;
		case '-':
			m_vecToken.push_back(new COperator(string(1, cInput), 1,
				[](int value1, int value2) { return value1 - value2; })
			);
			m_iCursor++;
			break;
		case '*':
			m_vecToken.push_back(new COperator(string(1, cInput), 1,
				[](int value1, int value2) { return value1 * value2; })
			);
			m_iCursor++;
			break;
		case '/':
			m_vecToken.push_back(new COperator(string(1, cInput), 1,
				[](int value1, int value2) { return (int)(value1 / value2);})
			);
			m_iCursor++;
			break;
		default:
			cout << "Unknown Operator";
			break;
		}
	}
}

void CInput::Render()
{
	for (auto token : m_vecToken) {
		cout << token->GetOrigin();
	}
	cout << endl;
}
