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
#include <stack>

#include "card.h"

#if !defined(__DECK_H__)
#define __DECK_H__

class CDeck
{
public:
	CDeck();
	~CDeck();

	void Initalize();

	CCard PopCard();

	void PushCard(const CCard _mCard);


private:
	std::stack<CCard> m_staDeck;

};

#endif // __DECK_H__

