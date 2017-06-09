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

enum suit { NOSUIT = 0, 
			HEART = 1, 
			DIAMOND, 
			CLUB, 
			SPADE };

enum colour {
	NOCOLOUR = 0,
	RED = 1,
	BLACK,
};

class CCard
{
public:
	CCard(const size_t& _szNumber, colour _bColour, suit _Suit, const bool& _bisVisible);
	~CCard();

	bool Initialise(const int _kiSpriteID, const int _kiMaskID);

	bool getVisible();
	void setVisible(bool _bisVisible);

	const size_t getNumber();
	const bool getColour();

	suit getSuit();

	void setX(const int& _iX);
	int getX();
	void setY(const int& _iY);
	int getY();

private:

	CSprite* m_pSprite;
	bool m_bisVisible; // 0 is invisible. 1 is visible
	size_t m_szNumber;
	colour m_bColour;
	suit m_Suit;

	int m_iX;
	int m_iY;

}; 

#endif // __CLOCK_H__

