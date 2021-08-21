#include "Calculator.h"
#include "Input.h"

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


}

void CCalculator::TranslateBackwardOperation()
{
}
