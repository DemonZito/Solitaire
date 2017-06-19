#include "tableaupile.h"



CTableauPile::CTableauPile()
{
}


CTableauPile::~CTableauPile()
{
	for (int i = 0; i < 7; i++)
	{
		while (m_pTableauPile[i].size() != 0)
		{
			CCard* temp = m_pTableauPile[i].back();
			m_pTableauPile[i].pop_back();
			delete temp;
		}
		
	}
}

void CTableauPile::Initalize()
{
	for (int i = 0; i < 7; i++)
	{
		for (unsigned int j = 0; j < m_pTableauPile[i].size(); j++)
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
		for (unsigned int j = 0; j < m_pTableauPile[i].size(); j++)
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

std::deque<CCard*> CTableauPile::PopCard(CCard* _mCard, int _iPileDest)
{
	std::deque<CCard*> _liMovingCards;
	bool bCardsAfter = false;

	for (unsigned int i = 0; i < m_pTableauPile[_iPileDest].size();)
	{
		if (m_pTableauPile[_iPileDest].at(i)->GetDragging() == true || bCardsAfter == true)
		{
			_liMovingCards.push_back(m_pTableauPile[_iPileDest].at(i));
			m_pTableauPile[_iPileDest].erase(m_pTableauPile[_iPileDest].begin() + i);
			bCardsAfter = true;
		}
		else
		{
			i++;
		}
	}

	return _liMovingCards;
}

void CTableauPile::PushCard(CCard* _mCard, int _iNum)
{
	_mCard->SetPileDest(static_cast<dest>(_iNum+1));
	m_pTableauPile[_iNum].push_back(_mCard);
}

std::deque<CCard*>* CTableauPile::GetTableau()
{
	return m_pTableauPile;
}
