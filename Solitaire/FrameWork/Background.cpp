//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: Background.cpp
// Description	: Background of the game
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

// Local Includes
#include "resource.h"
#include "utils.h"
#include "game.h"
// This Include
#include "background.h"

// Implementation

CBackGround::CBackGround()
{

}

CBackGround::~CBackGround()
{
	delete m_pSprite;
	m_pSprite = 0;

	delete m_pDeckSlot;
	m_pDeckSlot = 0;

	delete m_pFoundationOne;
	m_pFoundationOne = 0;

	delete m_pFoundationTwo;
	m_pFoundationTwo = 0;

	delete m_pFoundationThree;
	m_pFoundationThree = 0;

	delete m_pFoundationFour;
	m_pFoundationFour = 0;

	delete m_pTableauPile1;
	m_pTableauPile1 = 0;

	delete m_pTableauPile2;
	m_pTableauPile2 = 0;

	delete m_pTableauPile3;
	m_pTableauPile3 = 0;

	delete m_pTableauPile4;
	m_pTableauPile4 = 0;

	delete m_pTableauPile5;
	m_pTableauPile5 = 0;

	delete m_pTableauPile6;
	m_pTableauPile6 = 0;

	delete m_pTableauPile7;
	m_pTableauPile7 = 0;
}

bool
CBackGround::Initialise(int _iWidth, int _iHeight)
{
	m_pSprite = new CSprite();
	VALIDATE(m_pSprite->Initialise(IDB_BACKGROUND, IDB_BACKGROUNDMAP));

	m_pDeckSlot = new CSprite();
	VALIDATE(m_pDeckSlot->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));

	m_pFoundationOne = new CSprite();
	VALIDATE(m_pFoundationOne->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));

	m_pFoundationTwo = new CSprite();
	VALIDATE(m_pFoundationTwo->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));

	m_pFoundationThree = new CSprite();
	VALIDATE(m_pFoundationThree->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));

	m_pFoundationFour = new CSprite();
	VALIDATE(m_pFoundationFour->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));

	m_pTableauPile1 = new CSprite();
	m_pTableauPile2 = new CSprite();
	m_pTableauPile3 = new CSprite();
	m_pTableauPile4 = new CSprite();
	m_pTableauPile5 = new CSprite();
	m_pTableauPile6 = new CSprite();
	m_pTableauPile7 = new CSprite();

	VALIDATE(m_pTableauPile1->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));
	VALIDATE(m_pTableauPile2->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));
	VALIDATE(m_pTableauPile3->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));
	VALIDATE(m_pTableauPile4->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));
	VALIDATE(m_pTableauPile5->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));
	VALIDATE(m_pTableauPile6->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));
	VALIDATE(m_pTableauPile7->Initialise(IDB_EMPTYSLOT, IDB_EMPTYSLOTMASK));
	
	m_pSprite->SetX((int)_iWidth/2);
	m_pSprite->SetY((int)_iHeight / 2);

	m_pDeckSlot->SetX(static_cast<int>(50 + 2.4));
	m_pDeckSlot->SetY(static_cast<int>(50 + 2.4));

	m_pFoundationOne->SetX(300);
	m_pFoundationOne->SetY(50);

	m_pFoundationTwo->SetX(400);
	m_pFoundationTwo->SetY(50);

	m_pFoundationThree->SetX(500);
	m_pFoundationThree->SetY(50);

	m_pFoundationFour->SetX(600);
	m_pFoundationFour->SetY(50);

	m_pTableauPile1->SetX(50);
	m_pTableauPile2->SetX(150);
	m_pTableauPile3->SetX(250);
	m_pTableauPile4->SetX(350);
	m_pTableauPile5->SetX(450);
	m_pTableauPile6->SetX(550);
	m_pTableauPile7->SetX(650);

	m_pTableauPile1->SetY(300);
	m_pTableauPile2->SetY(300);
	m_pTableauPile3->SetY(300);
	m_pTableauPile4->SetY(300);
	m_pTableauPile5->SetY(300);
	m_pTableauPile6->SetY(300);
	m_pTableauPile7->SetY(300);

	return (true);
}

void
CBackGround::Draw()
{
	m_pSprite->Draw();
	m_pDeckSlot->Draw();
	m_pFoundationOne->Draw();
	m_pFoundationTwo->Draw();
	m_pFoundationThree->Draw();
	m_pFoundationFour->Draw();
	m_pTableauPile1->Draw();
	m_pTableauPile2->Draw();
	m_pTableauPile3->Draw();
	m_pTableauPile4->Draw();
	m_pTableauPile5->Draw();
	m_pTableauPile6->Draw();
	m_pTableauPile7->Draw();
}
