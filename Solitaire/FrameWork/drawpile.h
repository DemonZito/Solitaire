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
#include <list>

#include "card.h"
#include "PileEntity.h"

#if !defined(__DRAWPILE_H__)
#define __DRAWPILE_H__

class CDrawPile : public CPileEntity
{
public:
	CDrawPile();
	~CDrawPile();

	void Initalize();
	void Draw();

	CCard* PopCard();

	void PushCard(CCard* _mCard);




private:
	//std::list<CCard*> m_staDeck;

};
#endif // __DRAWPILE_H__

