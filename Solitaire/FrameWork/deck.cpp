//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: deck.cpp
// Description	: Stores hidden cards
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

#include "deck.h"



CDeck::CDeck()
{
}


CDeck::~CDeck()
{
	while (m_staDeck.size() != 0)
	{
		CCard* tempCard = m_staDeck.top();
		m_staDeck.pop();
		delete tempCard;
	}
}

void CDeck::Draw()
{

	float iOffset = 50;

	for (unsigned int i = 0; i < m_staDeck.size(); i++)
	{
		m_staDeck.top()->GetSprite()->SetX(static_cast<int>(iOffset+2.4f));
		m_staDeck.top()->GetSprite()->SetY(static_cast<int>(iOffset+2.4f));
		m_staDeck.top()->GetSprite()->Draw();
		iOffset -= 0.1f;
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

std::stack<CCard*> CDeck::GetCards()
{
	return m_staDeck;
}
