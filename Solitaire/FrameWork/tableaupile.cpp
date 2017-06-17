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
	bool bAfterDrag = false;
	CCard* dragCard = nullptr;
	int iCardsDragged = 0;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < m_pTableauPile[i].size(); j++)
		{
			if (m_pTableauPile[i].at(j)->GetDragging() == false)
			{
				if (bAfterDrag == false)
				{
					m_pTableauPile[i].at(j)->GetSprite()->SetX(i * 100 + iXOffset);
					m_pTableauPile[i].at(j)->GetSprite()->SetY(300 + (j * 20));
					m_pTableauPile[i].at(j)->GetSprite()->Draw();
				}
				else
				{
					m_pTableauPile[i].at(j)->GetSprite()->SetX(dragCard->GetSprite()->GetX());
					m_pTableauPile[i].at(j)->GetSprite()->SetY(dragCard->GetSprite()->GetY() + 20 * iCardsDragged);
					m_pTableauPile[i].at(j)->GetSprite()->Draw();
					iCardsDragged++;
				}
			}
			else
			{
				m_pTableauPile[i].at(j)->GetSprite()->Draw();
				bAfterDrag = true;
				dragCard = m_pTableauPile[i].at(j);
				iCardsDragged = 1;
			}
		}
		
		bAfterDrag = false;
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

std::deque<CCard*>* CTableauPile::GetTableau()
{
	return m_pTableauPile;
}
