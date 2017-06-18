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

	int iXOffset = 150;
	int iPrintCards = 3;


	//fix

	for (int i = 0; i < m_vecDrawPile.size(); i++)
	{
		if (m_vecDrawPile.at(i)->GetDragging() == false)
		{
			m_vecDrawPile.at(i)->GetSprite()->SetX(iXOffset);
			m_vecDrawPile.at(i)->GetSprite()->SetY(50);
			m_vecDrawPile.at(i)->GetSprite()->Draw();
			iXOffset += 10;
		}
		else
		{
			m_vecDrawPile.at(i)->GetSprite()->Draw();
		}

		TopCard = m_vecDrawPile.at(m_vecDrawPile.size()-1);
	}

	
}

CCard* CDrawPile::PopCard(bool _Visibility)
{
	CCard* _DrawnCard = m_staDeck.back();
	_DrawnCard->setVisible(_Visibility);
	m_staDeck.pop_back();
	return _DrawnCard;
}

void CDrawPile::EraseCard(CCard* _toDelete)
{
	for (auto it = m_staDeck.begin(); it != m_staDeck.end();)
	{
		if ((*it) == _toDelete)
		{
			it = m_staDeck.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void CDrawPile::PushCard(CCard* _mCard)
{
	m_staDeck.push_back(_mCard);
}

bool CDrawPile::IsEmpty()
{
	return m_staDeck.empty();
}

std::list<CCard*> CDrawPile::GetCards()
{
	return m_staDeck;
}

