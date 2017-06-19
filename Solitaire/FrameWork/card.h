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

#if !defined(__CARD_H__)
#define __CARD_H__

//Header Files
#include "sprite.h"

enum suit 
{ 
	NOSUIT = 0, 
	HEART = 1, 
	CLUB, 
	DIAMOND,
	SPADE
};

enum colour 
{
	NOCOLOUR = 0,
	BLACK = 1,
	RED
};

enum dest
{
	DECK = 0,
	TABLEAU1,
	TABLEAU2,
	TABLEAU3,
	TABLEAU4,
	TABLEAU5,
	TABLEAU6,
	TABLEAU7,
	FOUNDATION1 = 10,
	FOUNDATION2,
	FOUNDATION3,
	FOUNDATION4
};

class CCard
{
public:
	CCard(size_t _szNumber, size_t _bColour, size_t _Suit, bool _bisVisible, bool _bIsDragging);
	~CCard();

	bool Initialise(const int _kiSpriteID, const int _kiMaskID);

	bool getVisible();
	void setVisible(bool _bisVisible);

	const size_t getNumber();
	colour getColour();

	suit getSuit();

	void setX(const int& _iX);
	int getX();
	void setY(const int& _iY);
	int getY();

	bool GetDragging();
	void SetDragging(bool);

	dest GetPileDest();
	void SetPileDest(dest);

	CSprite* GetBackSprite();
	CSprite* GetSprite();

private:

	CSprite* m_pSprite;
	bool m_bisVisible; // 0 is invisible. 1 is visible
	size_t m_szNumber;
	colour m_bColour;
	suit m_Suit;
	bool m_bDragging;
	CSprite* m_pCardBack;

	dest m_iPileDest;

	int m_iX;
	int m_iY;

}; 

#endif // __CLOCK_H__

