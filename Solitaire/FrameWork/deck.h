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

#include "PileEntity.h"
#include "card.h"

#if !defined(__DECK_H__)
#define __DECK_H__

class CDeck : public CPileEntity
{
public:
	CDeck();
	~CDeck();

	void Initalize();
	void Draw();

	CCard* PopCard();
	void PushCard(CCard* _mCard);
	bool IsEmpty();

	void ShiftToDrawPile();

	std::stack<CCard*> GetCards();


private:
	std::stack<CCard*> m_staDeck;

};

#endif // __DECK_H__

