#include "Calculator.h"
#include "Input.h"
#include "Operand.h"
#include "Operator.h"

CCalculator::CCalculator() :
	m_bLoop(true)
{
	m_pInput = new CInput();
}

CCalculator::~CCalculator()
{
	SAFE_DELETE(m_pInput)
}

void CCalculator::Run()
{
	while (m_bLoop) {
		if(Input())
			Calculation();
		Render();
	}
}

bool CCalculator::Input()
{
	return m_pInput->Input();
}

void CCalculator::Render()
{
	system("cls");
	if (!m_vecPostfix.empty()) {
		for (auto token : m_vecPostfix) {
			cout << token->GetOrigin();
		}
	}
	else {
		m_pInput->Render();
	}
	// do something
}

void CCalculator::Calculation()
{
	TranslatePostfix();
	stack<CToken*> Tokens;
	for (int n = 0; n < m_vecPostfix.size(); n++) {
		if (m_vecPostfix.front()->IsOperator()) {
			double b = static_cast<COperand*>(Tokens.top())->GetValue();
			Tokens.pop();
			double a = static_cast<COperand*>(Tokens.top())->GetValue();
			Tokens.pop();
			double c = static_cast<COperator*>(m_vecPostfix.front())->Operate(a, b);
			m_vecPostfix.erase(m_vecPostfix.begin());
			Tokens.push(new COperand(to_string(c),0)); //제대로 생성해서 넣었는가?
		}
		else {
			Tokens.push(m_vecPostfix.front());
			m_vecPostfix.erase(m_vecPostfix.begin());
		}
	}
	cout << static_cast<COperand*>(Tokens.top())->GetValue() << endl;

}

void CCalculator::TranslatePostfix()
{
	// 1*2-3+4/2 -> (1*2)-3+(4/2)
	vector<CToken*> vecToken = m_pInput->GetToken();
	/*
	for (int i = 0; i < vecToken.size(); i++)
	{
		if (vecToken[i]->GetPriority() == 2) {
			vecToken.insert(vecToken.begin() + i + 2,new COperator(string(1, ')'), 1,
				[](int value1, int value2) { return NULL; })
			);
			vecToken.insert(vecToken.begin() + i - 1, new COperator(string(1, '('), 1,
				[](int value1, int value2) { return NULL; })
			);
			i++;
		}
	}*/

	// (1*2)-3+(4/2) -> 12*3-
	stack<CToken*> sToken;

	for (int i = 0; i < vecToken.size(); i++) {
		if (!vecToken[i]->IsOperator()) {
			m_vecPostfix.push_back(vecToken[i]);
		}
		else {
			if (vecToken[i]->GetOrigin() == "(") {
				sToken.push(vecToken[i]);
			}
			else if (vecToken[i]->GetOrigin() == ")") {
				while (!(sToken.top()->GetOrigin() == "("))
				{
					m_vecPostfix.push_back(sToken.top()); sToken.pop();
				}
				sToken.pop();
			}
			else if (vecToken[i]->GetOrigin() == "+" || vecToken[i]->GetOrigin() == "-")
			{
				while (true)
				{
					if (sToken.empty()) {
						break;
					}
					if (sToken.top()->GetOrigin() == "(") {
						break;
					}
					m_vecPostfix.push_back(sToken.top()); sToken.pop();
				}
				sToken.push(vecToken[i]);
			}
			else if (vecToken[i]->GetOrigin() == "*" || vecToken[i]->GetOrigin() == "/")
			{
				sToken.push(vecToken[i]);
			}
		}
	}

	while (!sToken.empty()) {
		m_vecPostfix.push_back(sToken.top()); sToken.pop();
	}

}
