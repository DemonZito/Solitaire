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

void CDrawPile::Draw()
{
	CPileEntity::Draw();
}

CCard* CDrawPile::PopCard()
{
	CCard* _DrawnCard = m_listpSprite.front();
	m_listpSprite.pop_back();
	return _DrawnCard;
}

void CDrawPile::PushCard(CCard* _mCard)
{
	
	m_listpSprite.push_back(_mCard);
}

