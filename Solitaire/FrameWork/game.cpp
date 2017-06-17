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
#include <time.h>

// Local Includes
#include "Clock.h"
#include "BackBuffer.h"
#include "utils.h"
#include "sprite.h"
#include "card.h"
#include "resource.h"
#include "drawpile.h"
#include "deck.h"
#include "tableaupile.h"


// This Include
#include "Game.h"
//#include "PileEntity.h"

// Static Variables
CGame* CGame::s_pGame = 0;
static int m_iRoomWidth;
static int m_iRoomHeight;
static int m_iCardWidth;
static int m_iCardHeight;

// Static Function Prototypes

// Implementation

CGame::CGame()
: m_pClock(0)
, m_hApplicationInstance(0)
, m_hMainWindow(0)
, m_pBackBuffer(0)
{
	m_pDrawPile = new CDrawPile();
	m_pDeck = new CDeck();
	m_pTableau = new CTableauPile();
}

CGame::~CGame()
{
    delete m_pBackBuffer;
    m_pBackBuffer = 0;

    delete m_pClock;
    m_pClock = 0;
}

bool
CGame::Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight)
{
	srand(time(NULL));

    m_hApplicationInstance = _hInstance;
    m_hMainWindow = _hWnd;

    m_pClock = new CClock();
    VALIDATE(m_pClock ->Initialise());
    m_pClock->Process();

    m_pBackBuffer = new CBackBuffer();
    VALIDATE(m_pBackBuffer->Initialise(_hWnd, _iWidth, _iHeight));

	CCard* pNewCard;
	int iCardSpriteTrack = 102;

	for (size_t suit = 1; suit < 5; suit++)
	{
		for (size_t num = 1; num < 14; num++)
		{
			pNewCard = new CCard(num, (suit % 2) + 1, suit, false, false);
			pNewCard->Initialise(iCardSpriteTrack, IDB_CARDMASK);
			m_vecpCards.push_back(pNewCard);
			iCardSpriteTrack++;

		}
	}

	int iRand = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j > 0; j--)
		{
			iRand = rand() % m_vecpCards.size();
			m_pTableau->PushCard(m_vecpCards.at(iRand), i);
			m_vecpCards.erase(m_vecpCards.begin() + iRand);
		}
		
	}

	iRand = 0;
	while (m_vecpCards.size() != 0)
	{
		iRand = rand() % m_vecpCards.size();
		m_pDeck->PushCard(m_vecpCards.at(iRand));
		m_vecpCards.erase(m_vecpCards.begin() + iRand);
	}


	

	m_pTableau->Initalize();

	m_pDeck->SetX(0);
	m_pDeck->SetY(0);

	ShowCursor(true);

    return (true);
}

void
CGame::Draw()
{
    m_pBackBuffer->Clear();

// Do all the game’s drawing here...
	m_pDeck->Draw();
	m_pDrawPile->Draw();
	m_pTableau->Draw();

    m_pBackBuffer->Present();
}

void
CGame::Process(float _fDeltaTick)
{
    // Process all the game’s logic here.
	//Load a new sprite.
	m_pDrawPile->Process(_fDeltaTick);
}

void 
CGame::ExecuteOneFrame()
{
    float fDT = m_pClock->GetDeltaTick();

    Process(fDT);
    Draw();

    m_pClock->Process();

    Sleep(1);
}

CGame&
CGame::GetInstance()
{
    if (s_pGame == 0)
    {
        s_pGame = new CGame();
    }

    return (*s_pGame);
}

void 
CGame::DestroyInstance()
{
    delete s_pGame;
    s_pGame = 0;
}

CBackBuffer* 
CGame::GetBackBuffer()
{
    return (m_pBackBuffer);
}

HINSTANCE 
CGame::GetAppInstance()
{
    return (m_hApplicationInstance);
}

HWND 
CGame::GetWindow()
{
    return (m_hMainWindow);
}


int CGame::GetRoomWidth() 
{
	return (m_iRoomWidth);
}
int CGame::GetRoomHeight() 
{
	return(m_iRoomHeight);
}
int CGame::GetCardWidth() 
{
	return(m_iCardWidth);
}
int CGame::GetCardHeight() 
{
	return(m_iCardHeight);
}

void CGame::SetRoomWidth(int _iWidth)
{
	m_iRoomWidth = _iWidth;
}
void CGame::SetRoomHeight(int _iHeight)
{
	m_iRoomHeight = _iHeight;
}
void CGame::SetCardWidth(int _iWidth)
{
	m_iCardWidth = _iWidth;
}
void CGame::SetCardHeight(int _iHeight)
{
	m_iCardHeight = _iHeight;
}

bool CGame::CheckDeckClicked(CGame& _rGame, POINT _mousePos)
{
	if (_rGame.m_pDeck->IsEmpty() == false)
	{
		RECT rectDeckArea;
		rectDeckArea.left = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetX()/2;
		rectDeckArea.top = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetY()/2;
		rectDeckArea.right = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetX()/2 + 71;
		rectDeckArea.bottom = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetY()/2 + 96;

		if (PtInRect(&rectDeckArea, _mousePos))
		{
			_rGame.ShiftDeckToDraw();
			return true;
		}
	}
	else
	{
		RECT rectDeckArea;
		rectDeckArea.left = 50 / 2;
		rectDeckArea.top = 50 / 2;
		rectDeckArea.right = 50 / 2 + 71;
		rectDeckArea.bottom = 50 / 2 + 96;

		if (PtInRect(&rectDeckArea, _mousePos))
		{
			_rGame.ShiftDrawToDeck();
			return true;
		}
	}
	
	return false;
}

CCard* CGame::CheckDraggableClicked(CGame& _rGame, POINT _mousePos)
{
	if (_rGame.m_pDrawPile->IsEmpty() == false)
	{
		CCard* FrontCard = _rGame.m_pDrawPile->TopCard;
		RECT rectDrawPile;
		/*rectDrawPile.left = FrontCard->GetSprite()->GetX()/2+20;
		rectDrawPile.top = FrontCard->GetSprite()->GetY()/2;
		rectDrawPile.right = FrontCard->GetSprite()->GetX()/2+20 + 71;
		rectDrawPile.bottom = FrontCard->GetSprite()->GetY() + 96;*/

		rectDrawPile.left = FrontCard->GetSprite()->GetX();
		rectDrawPile.top = FrontCard->GetSprite()->GetY()/2;

		rectDrawPile.right = FrontCard->GetSprite()->GetX()+100;
		rectDrawPile.bottom = FrontCard->GetSprite()->GetY() + 96;

		if (PtInRect(&rectDrawPile, _mousePos))
		{
			return FrontCard;
		}
		else
		{
			return nullptr;
		}
	}

	return nullptr;
}

void CGame::Dragging(CGame & _rGame, POINT _mousePos)
{

}

void CGame::ShiftDeckToDraw()
{
	int iCardsToDraw = 3;

	// Clear drawing vector
	while (m_pDrawPile->m_vecDrawPile.size() != 0)
	{
		m_pDrawPile->m_vecDrawPile.pop_back();
	}
	// Populate draw pile and vctor
	while (m_pDeck->IsEmpty() == false && iCardsToDraw != 0)
	{
		CCard* tempCard = m_pDeck->PopCard();
		m_pDrawPile->PushCard(tempCard);
		m_pDrawPile->m_vecDrawPile.push_back(tempCard);
		iCardsToDraw--;
	}
}

void CGame::ShiftDrawToDeck()
{
	while (m_pDrawPile->m_vecDrawPile.size() != 0)
	{
		m_pDrawPile->m_vecDrawPile.pop_back();
	}

	while (m_pDrawPile->IsEmpty() == false)
	{
		m_pDeck->PushCard(m_pDrawPile->PopCard(false));
	}
}
