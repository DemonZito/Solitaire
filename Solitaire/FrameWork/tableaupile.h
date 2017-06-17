//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

#if !defined(__TABLEAUPILE_H__)
#define __TABLEAUPILE_H__

#include <queue>

#include "PileEntity.h"
#include "card.h"

class CTableauPile : public CPileEntity
{
public:
	CTableauPile();
	~CTableauPile();

	void Initalize();
	void Draw();

	std::deque<CCard> PopCard(CCard* _mCard);

	void PushCard(CCard* _mCard, int _iNum);

private:
	std::deque<CCard*> m_pTableauPile[7];
}; 

#endif    // __TABLEAUPILE_H__

