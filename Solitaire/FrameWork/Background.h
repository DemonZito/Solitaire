//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: Background.h
// Description	: Background header file
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//
#pragma once

#if !defined(__BACKGROUND_H__)
#define __BACKGROUND_H__

// Library Includes

// Local Includes
#include "sprite.h"

class CBackGround
{
	// Member Functions
public:
	CBackGround();
	virtual ~CBackGround();

	virtual bool Initialise(int _iWidth, int _iHeight);

	virtual void Draw();

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