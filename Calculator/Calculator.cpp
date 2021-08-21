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
