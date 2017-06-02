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

void CTableauPile::PopCard(CCard* _mCard) 
{

}

void CTableauPile::PushCard(const CCard _mCard)
{
	m_pTableauPile.push_front(_mCard);
}
