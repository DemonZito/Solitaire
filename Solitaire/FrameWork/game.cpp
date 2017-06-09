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
#include "Clock.h"
#include "BackBuffer.h"
#include "utils.h"
#include "sprite.h"
#include "card.h"
#include "resource.h"
#include "drawpile.h"


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
    m_hApplicationInstance = _hInstance;
    m_hMainWindow = _hWnd;

    m_pClock = new CClock();
    VALIDATE(m_pClock ->Initialise());
    m_pClock->Process();

    m_pBackBuffer = new CBackBuffer();
    VALIDATE(m_pBackBuffer->Initialise(_hWnd, _iWidth, _iHeight));

	/*CCard* newCard = new CCard(13, RED, DIAMOND, true);
	VALIDATE(newCard->Initialise(IDB_KING_DIAMOND, IDB_CARD_MASK));

	m_pDrawPile->PushCard(newCard);
	

	CCard* newCard2 = new CCard(9, RED, DIAMOND, true);
	
	VALIDATE(newCard2->Initialise(IDB_9DIAMONDS, IDB_CARD_MASK));

	m_pDrawPile->PushCard(newCard2);

	m_pDrawPile->SetX(500);
	m_pDrawPile->SetY(500);*/

	
	CCard* pNewCard;

	for (size_t suit = 1; suit < 5; suit++)
	{
		for (size_t num = 1; num < 14; num++)
		{
			pNewCard = new CCard(num, (suit % 2) + 1, suit, false);
			pNewCard->Initialise((101 + num * suit), IDB_CARDMASK);
			m_pDrawPile->PushCard(pNewCard);

		}
	}

	//delete newCard;
	//newCard = 0;
	

	ShowCursor(true);

    return (true);
}

void
CGame::Draw()
{
    m_pBackBuffer->Clear();

// Do all the game’s drawing here...
	m_pDrawPile->Draw();

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