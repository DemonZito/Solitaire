#include "foundationpile.h"

CFoundationPile::CFoundationPile()
{
}


CFoundationPile::~CFoundationPile()
{
}

void CFoundationPile::Initalize()
{
}

CCard CFoundationPile::PopCard()
{
	CCard _DrawnCard = m_pFoundationPile.top();
	m_pFoundationPile.pop();
	return _DrawnCard;
}

void CFoundationPile::PushCard(const CCard _mCard)
{
	m_pFoundationPile.push(_mCard);
}

