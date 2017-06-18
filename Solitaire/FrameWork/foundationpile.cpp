#include "foundationpile.h"

CFoundationPile::CFoundationPile()
{
}


CFoundationPile::~CFoundationPile()
{
	for (int i = 0; i < 4; i++)
	{
		while (m_pFoundationPile[i].size() != 0)
		{
			CCard* temp = m_pFoundationPile[i].top();
			m_pFoundationPile[i].pop();
			delete temp;
		}

	}
}

void CFoundationPile::Initalize()
{
}

CCard* CFoundationPile::PopCard(int _iPile)
{
	CCard* _DrawnCard = m_pFoundationPile[_iPile].top();
	m_pFoundationPile[_iPile].pop();
	return _DrawnCard;
}

void CFoundationPile::Draw()
{
	int iXOffset = 300;

	for (int i = 0; i < 4; i++)
	{
		if (m_pFoundationPile[i].size() != 0)
		{
			if (m_pFoundationPile[i].top()->GetDragging() == false)
			{

				m_pFoundationPile[i].top()->GetSprite()->SetX(i * 100 + iXOffset);
				m_pFoundationPile[i].top()->GetSprite()->SetY(50);
				m_pFoundationPile[i].top()->GetSprite()->Draw();

			}
			else
			{
				m_pFoundationPile[i].top()->GetSprite()->Draw();
			}
		}
	}
}

void CFoundationPile::PushCard(CCard* _mCard, int _iPile)
{
	m_pFoundationPile[_iPile].push(_mCard);
}

std::stack<CCard*>* CFoundationPile::GetFoundation()
{
	return m_pFoundationPile;
}