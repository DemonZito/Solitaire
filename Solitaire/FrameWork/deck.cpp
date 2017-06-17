#include "deck.h"



CDeck::CDeck()
{
}


CDeck::~CDeck()
{
}

void CDeck::Initalize()
{
}

void CDeck::Draw()
{

	float iOffset = 50;

	for (int i = 0; i < m_staDeck.size(); i++)
	{

		m_staDeck.top()->GetSprite()->SetX(iOffset);
		m_staDeck.top()->GetSprite()->SetY(iOffset);
		m_staDeck.top()->GetSprite()->Draw();
		iOffset -= 0.1;

	}
}

CCard* CDeck::PopCard()
{
	CCard* _DrawnCard = m_staDeck.top();
	_DrawnCard->setVisible(true);
	m_staDeck.pop();
	return _DrawnCard;
}

void CDeck::PushCard(CCard* _mCard)
{
	m_staDeck.push(_mCard);
}

bool CDeck::IsEmpty()
{
	return m_staDeck.empty();
}

void CDeck::ShiftToDrawPile()
{
	while (m_staDeck.size() != 0)
	{
		
	}
}

std::stack<CCard*> CDeck::GetCards()
{
	return m_staDeck;
}
