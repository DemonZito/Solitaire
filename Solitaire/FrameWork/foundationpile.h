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
#include "PileEntity.h"

class CFoundationPile : public CPileEntity
{
public:
	CFoundationPile();
	~CFoundationPile();
	void Initalize();
	CCard* PopCard(int _iPile);
	void PushCard(CCard* _mCard, int _iPile);
	void Draw();
	std::stack<CCard*>* GetFoundation();

private:
	std::stack<CCard*> m_pFoundationPile[4];
	
};

#endif //__FOUNDATIONPILE_H__

