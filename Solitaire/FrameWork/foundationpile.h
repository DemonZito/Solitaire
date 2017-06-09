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

#if !defined(__FOUNDATIONPILE_H__)
#define __FOUNDATIONPILE_H__

#include <stack>

#include "card.h"

enum colour {
	NOCOLOUR = 0,
	RED = 1,
	BLACK,
};

class CFoundationPile
{
public:
	CFoundationPile();
	~CFoundationPile();

	void Initalize();

	CCard PopCard();

	void PushCard(const CCard _mCard);

private:
	std::stack<CCard> m_pFoundationPile;
	
};

#endif //__FOUNDATIONPILE_H__

