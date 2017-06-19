//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: card.cpp
// Description	: Cards of the game
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

// Local Includes
#include "card.h"
#include "utils.h"
#include "game.h"
#include "resource.h"


// Implementation

CCard::CCard(size_t _szNumber, size_t _bColour, size_t _Suit, bool _bisVisible, bool _bIsDragging)
{
	m_szNumber = _szNumber;
	m_bColour = static_cast<colour>(_bColour);
	m_Suit = static_cast<suit>(_Suit);
	m_bisVisible = _bisVisible;
	m_bDragging = _bIsDragging;
}


CCard::~CCard()
{
	delete m_pSprite;
	m_pSprite = 0;

	delete m_pCardBack;
	m_pCardBack = 0;
}

bool CCard::Initialise(const int _kiSpriteID, const int _kiMaskID)
{
	m_pSprite = new CSprite();
	VALIDATE(m_pSprite->Initialise(_kiSpriteID, _kiMaskID));

	m_pCardBack = new CSprite();
	m_pCardBack->Initialise(IDB_CARDBACK, IDB_CARDMASK);

	return (true);
}

bool CCard::getVisible() 
{
	return m_bisVisible;
}

void CCard::setVisible(bool _bisVisible) 
{
	m_bisVisible = _bisVisible;
}

const size_t CCard::getNumber() 
{
	return m_szNumber;
}

colour CCard::getColour() 
{
	return m_bColour;
}

suit CCard::getSuit() 
{
	return m_Suit;
}

bool CCard::GetDragging()
{
	return m_bDragging;
}

void CCard::SetDragging(bool _state)
{
	m_bDragging = _state;
}

dest CCard::GetPileDest()
{
	return m_iPileDest;
}

void CCard::SetPileDest(dest _iDest)
{
	m_iPileDest = _iDest;
}

CSprite * CCard::GetBackSprite()
{
	return m_pCardBack;
}

CSprite* CCard::GetSprite()
{
	if (m_bisVisible == false)
	{
		return m_pCardBack;
	}
	return m_pSprite;
}
