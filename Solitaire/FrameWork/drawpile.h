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

#if !defined(__DRAWPILE_H__)
#define __DRAWPILE_H__

class CDrawPile
{
public:
	CDrawPile();
	~CDrawPile();

	void Initalize();

	CCard PopCard();

	void PushCard(const CCard _mCard);


private:
	std::stack<CCard> m_staDeck;

};
#endif // __DRAWPILE_H__

