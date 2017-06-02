#include "drawpile.h"



CDrawPile::CDrawPile()
{
}


CDrawPile::~CDrawPile()
{
}

void CDrawPile::Initalize()
{
}

CCard CDrawPile::PopCard()
{
	CCard _DrawnCard = m_staDeck.top();
	m_staDeck.pop();
	return _DrawnCard;
}

void CDrawPile::PushCard(const CCard _mCard)
{
	m_staDeck.push(_mCard);
}