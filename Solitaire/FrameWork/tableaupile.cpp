#include "tableaupile.h"



CTableauPile::CTableauPile()
{
}


CTableauPile::~CTableauPile()
{
}

void CTableauPile::Initalize()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < m_pTableauPile[i].size(); j++)
		{
			if (j == m_pTableauPile[i].size() - 1)
			{
				m_pTableauPile[i].at(j)->setVisible(true);
			}
		}
	}
}

void CTableauPile::Draw()
{
	int iXOffset = 50;
	int iYOffset = 300;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < m_pTableauPile[i].size(); j++)
		{
			if (m_pTableauPile[i].at(j)->GetDragging() == false)
			{
				m_pTableauPile[i].at(j)->GetSprite()->SetX(i * 50 + iXOffset);
				m_pTableauPile[i].at(j)->GetSprite()->SetY(300 + (j*20));
				m_pTableauPile[i].at(j)->GetSprite()->Draw();
			}
			else
			{
				m_pTableauPile[i].at(j)->GetSprite()->Draw();
			}
		}
		
	}
}

std::deque<CCard> CTableauPile::PopCard(CCard* _mCard)
{
	std::deque<CCard> _liMovingCards;

	return _liMovingCards;
}

void CTableauPile::PushCard(CCard* _mCard, int _iNum)
{
	m_pTableauPile[_iNum].push_back(_mCard);
}
