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

#include <list>

#include "card.h"

class CTableauPile
{
public:
	CTableauPile();
	~CTableauPile();

	void Initalize();

	void PopCard(CCard* _mCard);

	void PushCard(const CCard _mCard);

private:
	std::list<CCard> m_pTableauPile;
}; 

#endif    // __TABLEAUPILE_H__

