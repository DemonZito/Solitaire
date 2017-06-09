#include "tableaupile.h"



CTableauPile::CTableauPile()
{
}


CTableauPile::~CTableauPile()
{
}

void CTableauPile::Initalize()
{
}

std::list<CCard> CTableauPile::PopCard(CCard* _mCard)
{
	std::list<CCard> _liMovingCards;
	return _liMovingCards;
}

void CTableauPile::PushCard(const CCard _mCard)
{
	m_pTableauPile.push_front(_mCard);
}
