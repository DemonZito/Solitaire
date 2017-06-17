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
#include <vector>

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

	CCard* PopCard(bool);

	void PushCard(CCard* _mCard);
	bool IsEmpty();

	std::list<CCard*> GetCards();

	CCard* TopCard;
	std::vector<CCard*> m_vecDrawPile;

private:
	std::list<CCard*> m_staDeck;
	

};
#endif // __DRAWPILE_H__

