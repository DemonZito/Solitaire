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

// Library Includes

// Local Includes
#include "card.h"
#include "utils.h"
#include "game.h"

// Static Variables

// Static Function Prototypes

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
}

bool CCard::Initialise(const int _kiSpriteID, const int _kiMaskID)
{
	m_pSprite = new CSprite();
	VALIDATE(m_pSprite->Initialise(_kiSpriteID, _kiMaskID));

	return (true);
}

bool CCard::getVisible() {
	return m_bisVisible;
}

void CCard::setVisible(bool _bisVisible) {
	m_bisVisible = _bisVisible;
}

const size_t CCard::getNumber() {
	return m_szNumber;
}

const bool CCard::getColour() 
{
	return m_bColour;
}

suit CCard::getSuit() {
	return m_Suit;
}

void CCard::setX(const int& _iX) {
	m_iX = _iX;
}

int CCard::getX() {
	return m_iX;
}

void CCard::setY(const int& _iY) {
	m_iY = _iY;
}

int CCard::getY() {
	return m_iY;
}

bool CCard::GetDragging()
{
	return m_bDragging;
}

void CCard::SetDragging(bool _state)
{
	m_bDragging = _state;
}

CSprite* CCard::GetSprite()
{
	if (m_bisVisible == false)
	{
		return CGame::GetInstance().m_pCardBack;
	}
	return m_pSprite;
}
