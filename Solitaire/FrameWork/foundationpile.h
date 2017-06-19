//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: foundationpile.h
// Description	: Foundation Pile header file
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

#if !defined(__FOUNDATIONPILE_H__)
#define __FOUNDATIONPILE_H__

#include <stack>

#include "card.h"
#include "PileEntity.h"

class CFoundationPile : public CPileEntity
{
public:
	CFoundationPile();
	~CFoundationPile();
	CCard* PopCard(int _iPile);
	void PushCard(CCard* _mCard, int _iPile);
	void Draw();
	std::stack<CCard*>* GetFoundation();

private:
	std::stack<CCard*> m_pFoundationPile[4];
	
};

#endif //__FOUNDATIONPILE_H__

