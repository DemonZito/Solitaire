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

CCard CDeck::PopCard()
{
	CCard _DrawnCard = m_staDeck.top();
	m_staDeck.pop();
	return _DrawnCard;
}

void CDeck::PushCard(const CCard _mCard)
{
	m_staDeck.push(_mCard);
}
