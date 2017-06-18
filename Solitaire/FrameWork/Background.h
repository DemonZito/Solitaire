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

#pragma once

#if !defined(__BACKGROUND_H__)
#define __BACKGROUND_H__

// Library Includes

// Local Includes
#include "sprite.h"
// Types

// Constants

// Prototypes
//class CSprite;

class CBackGround
{
	// Member Functions
public:
	CBackGround();
	virtual ~CBackGround();

	virtual bool Initialise(int _iWidth, int _iHeight);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

private:
	CSprite* m_pSprite;
	CSprite* m_pDeckSlot;
	CSprite* m_pFoundationOne;
	CSprite* m_pFoundationTwo;
	CSprite* m_pFoundationThree;
	CSprite* m_pFoundationFour;
	CSprite* m_pTableauPile1;
	CSprite* m_pTableauPile2;
	CSprite* m_pTableauPile3;
	CSprite* m_pTableauPile4;
	CSprite* m_pTableauPile5;
	CSprite* m_pTableauPile6;
	CSprite* m_pTableauPile7;


};

#endif