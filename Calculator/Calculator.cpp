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
		Input();
		Calculation();
		Render();
	}
}

void CCalculator::Input()
{
	m_pInput->Input();
}

void CCalculator::Render()
{
	system("cls");
	m_pInput->Render();
	// do something
}

void CCalculator::Calculation()
{
	stack<CToken*> Tokens;
	for (int n = 0; n < m_listPostfix.size(); n++) {
		if (m_listPostfix.front()->IsOperator()) {
			double b = static_cast<COperand*>(Tokens.top())->GetValue();
			Tokens.pop();
			double a = static_cast<COperand*>(Tokens.top())->GetValue();
			Tokens.pop();
			double c = static_cast<COperator*>(m_listPostfix.front())->Operate(a, b);
			m_listPostfix.pop_front();
			Tokens.push(new COperand(to_string(c),0)); //제대로 생성해서 넣었는가?
		}
		else {
			Tokens.push(m_listPostfix.front());
			m_listPostfix.pop_front();
		}
	}
	cout << static_cast<COperand*>(Tokens.top())->GetValue() << endl;

}

void CCalculator::TranslatePostfix()
{
}
