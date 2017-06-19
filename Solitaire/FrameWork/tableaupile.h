//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: tableaupile.h
// Description	: Tableau pile header file
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
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

	std::deque<CCard*> PopCard(CCard* _mCard, int _iPileDest);

	void PushCard(CCard* _mCard, int _iNum);
	std::deque<CCard*>* GetTableau();

private:
	std::deque<CCard*> m_pTableauPile[7];
}; 

#endif    // __TABLEAUPILE_H__

