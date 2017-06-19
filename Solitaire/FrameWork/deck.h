//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: deck.h
// Description	: Deck header file
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
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

	void Draw();

	CCard* PopCard();
	void PushCard(CCard* _mCard);
	bool IsEmpty();

	std::stack<CCard*> GetCards();


private:
	std::stack<CCard*> m_staDeck;

};

#endif // __DECK_H__

