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
#include "Background.h"
#include "foundationpile.h"


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
	m_pFoundation = new CFoundationPile();
	cardDragging = nullptr;
	m_iCardsToDraw = 3;
}

CGame::~CGame()
{
	delete m_pBackBuffer;
	m_pBackBuffer = 0;

	delete m_pClock;
	m_pClock = 0;

	delete m_pDeck;
	m_pDeck = 0;

	delete m_pDrawPile;
	m_pDrawPile = 0;

	delete m_pTableau;
	m_pTableau = 0;

	delete m_pFoundation;
	m_pFoundation = 0;

	delete m_pBackground;
	m_pBackground = 0;
	/*
	while (m_vecpCardsToDelete.size() != 0)
	{
	CCard* tempCard = m_vecpCardsToDelete.back();
	m_vecpCardsToDelete.pop_back();
	delete tempCard;
	}
	*/
}

bool
CGame::Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight)
{
	srand(static_cast<unsigned int>(time(NULL)));

	m_hApplicationInstance = _hInstance;
	m_hMainWindow = _hWnd;

	m_pClock = new CClock();
	VALIDATE(m_pClock->Initialise());
	m_pClock->Process();

	m_pBackBuffer = new CBackBuffer();
	VALIDATE(m_pBackBuffer->Initialise(_hWnd, _iWidth, _iHeight));

	m_pBackground = new CBackGround();
	m_pBackground->Initialise(_iWidth, _iHeight);

	CCard* pNewCard;
	int iCardSpriteTrack = 102;

	for (size_t suit = 1; suit < 5; suit++)
	{
		for (size_t num = 1; num < 14; num++)
		{
			if (num == 13)
			{
				pNewCard = new CCard(0, (suit % 2) + 1, suit, false, false);
			}
			else
			{
				pNewCard = new CCard(num, (suit % 2) + 1, suit, false, false);
			}
			pNewCard->Initialise(iCardSpriteTrack, IDB_CARDMASK);
			m_vecpCards.push_back(pNewCard);
			m_vecpCardsToDelete.push_back(pNewCard);
			iCardSpriteTrack++;

		}
	}
	// Add to Tableua
	int iRand = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j > 0; j--)
		{
			iRand = rand() % m_vecpCards.size();
			CCard* tempCard = m_vecpCards.at(iRand);
			tempCard->SetPileDest(static_cast<dest>(i + 1));
			m_pTableau->PushCard(m_vecpCards.at(iRand), i);
			m_vecpCards.erase(m_vecpCards.begin() + iRand);
		}

	}

	// Add to Deck
	iRand = 0;
	while (m_vecpCards.size() != 0)
	{
		iRand = rand() % m_vecpCards.size();
		CCard* tempCard = m_vecpCards.at(iRand);
		tempCard->SetPileDest(static_cast<dest>(0));
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
	m_pBackground->Draw();
	m_pFoundation->Draw();
	m_pDeck->Draw();
	m_pDrawPile->Draw();
	m_pTableau->Draw();

	if (cardDragging != nullptr)
	{
		int iRedraw = cardDragging->GetPileDest();

		if (iRedraw > 0 && iRedraw < 8)
		{
			for (int i = 0; i < m_pTableau->GetTableau()[iRedraw - 1].size(); i++)
			{
				m_pTableau->GetTableau()[iRedraw - 1].at(i)->GetSprite()->Draw();
			}

		}
		else if (iRedraw == 0)
		{
			m_pDrawPile->Draw();
		}
		else
		{
			m_pFoundation->GetFoundation()[iRedraw - 10].top()->GetSprite()->Draw();
		}
	}

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
		//int iX = m_iX - (iW / 2);
		//int iY = m_iY - (iH / 2);

		RECT rectDeckArea;
		rectDeckArea.left = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetX() - 70 / 2;
		rectDeckArea.top = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetY() - 96 / 2;
		rectDeckArea.right = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetX() + 70 / 2;
		rectDeckArea.bottom = _rGame.m_pDeck->GetCards().top()->GetSprite()->GetY() + 96 / 2;

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
//RECT CGame::CheckDraggableClicked(CGame& _rGame, POINT _mousePos)
{
	if (_rGame.m_pDrawPile->IsEmpty() == false)
	{
		CCard* FrontCard = _rGame.m_pDrawPile->TopCard;
		RECT rectDrawPile;
		/*rectDrawPile.left = FrontCard->GetSprite()->GetX()/2+20;
		rectDrawPile.top = FrontCard->GetSprite()->GetY()/2;
		rectDrawPile.right = FrontCard->GetSprite()->GetX()/2+20 + 71;
		rectDrawPile.bottom = FrontCard->GetSprite()->GetY() + 96;*/

		rectDrawPile.left = FrontCard->GetSprite()->GetX() - 70 / 2;
		rectDrawPile.top = FrontCard->GetSprite()->GetY() - 96 / 2;

		rectDrawPile.right = FrontCard->GetSprite()->GetX() + 70 / 2;
		rectDrawPile.bottom = FrontCard->GetSprite()->GetY() + 96 / 2;

		if (PtInRect(&rectDrawPile, _mousePos))
		{
			_rGame.cardDragging = FrontCard;
			return FrontCard;
		}
	}
	

	for (int i = 0; i < 7; i++)
	{
		for (unsigned int j = 0; j < _rGame.m_pTableau->GetTableau()[i].size(); j++)
		{
			RECT rectTableau;
			rectTableau.left = _rGame.m_pTableau->GetTableau()[i].at(j)->GetSprite()->GetX() - 70 / 2;
			rectTableau.top = _rGame.m_pTableau->GetTableau()[i].at(j)->GetSprite()->GetY() - 96 / 2;
			rectTableau.right = _rGame.m_pTableau->GetTableau()[i].at(j)->GetSprite()->GetX() + 70 / 2;

			if (j == _rGame.m_pTableau->GetTableau()[i].size() - 1)
			{
				rectTableau.bottom = _rGame.m_pTableau->GetTableau()[i].at(j)->GetSprite()->GetY() + 96 / 2;
			}
			else
			{
				rectTableau.bottom = _rGame.m_pTableau->GetTableau()[i].at(j)->GetSprite()->GetY() - 96 / 2 + 20;
			}


			if (PtInRect(&rectTableau, _mousePos))
			{
				if (_rGame.m_pTableau->GetTableau()[i].at(j)->getVisible())
				{
					_rGame.cardDragging = _rGame.m_pTableau->GetTableau()[i].at(j);
					return _rGame.m_pTableau->GetTableau()[i].at(j);
					//return rectTableau;
				}
				else if (j == _rGame.m_pTableau->GetTableau()[i].size() - 1 && _rGame.m_pTableau->GetTableau()[i].at(j)->getVisible() == false)
				{
					_rGame.m_pTableau->GetTableau()[i].at(j)->setVisible(true);
				}
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (_rGame.m_pFoundation->GetFoundation()[i].size() != 0)
		{
			RECT rectFoundation;
			rectFoundation.left = _rGame.m_pFoundation->GetFoundation()[i].top()->GetSprite()->GetX() - 70 / 2;
			rectFoundation.top = _rGame.m_pFoundation->GetFoundation()[i].top()->GetSprite()->GetY() - 96 / 2;
			rectFoundation.right = _rGame.m_pFoundation->GetFoundation()[i].top()->GetSprite()->GetX() + 70 / 2;
			rectFoundation.bottom = _rGame.m_pFoundation->GetFoundation()[i].top()->GetSprite()->GetY() + 96 / 2;

			if (PtInRect(&rectFoundation, _mousePos))
			{
				return _rGame.m_pFoundation->GetFoundation()[i].top();
			}

		}
	}

	//return rectTableau;
	return nullptr;
}

void CGame::CheckWhereDropped(CGame & _rGame, POINT _mousePos, CCard* _dragged)
{
	RECT rectTableau;
	CCard* tempCard;

	for (int i = 0; i < 7; i++)
	{
		int  j = _rGame.m_pTableau->GetTableau()[i].size()-1;

		if (j == -1)
		{
			rectTableau.left = ((i * 100) + 50) - 70/2;
			rectTableau.top = 300 - 96/2;
			rectTableau.right = (i * 100) + 50 + 70/2;
			rectTableau.bottom = 300 + 96/2;
			tempCard = nullptr;

		}
		else
		{
			tempCard = _rGame.m_pTableau->GetTableau()[i].at(j);


			rectTableau.left = tempCard->GetSprite()->GetX() - 70 / 2;
			rectTableau.top = tempCard->GetSprite()->GetY() - 96 / 2;
			rectTableau.right = tempCard->GetSprite()->GetX() + 70 / 2;
			rectTableau.bottom = _rGame.m_pTableau->GetTableau()[i].at(j)->GetSprite()->GetY() + 96 / 2;
		}



		if (PtInRect(&rectTableau, _mousePos) && tempCard != nullptr && _dragged != tempCard)
		{
			colour tempCol1 = _dragged->getColour();
			colour tempCol2 = tempCard->getColour();

			if (tempCard->getVisible() && _dragged->getColour() != tempCard->getColour() && _dragged->getNumber() == tempCard->getNumber() - 1 && _dragged->GetPileDest() != tempCard->GetPileDest())
			{
				if (_dragged->GetPileDest() == 0)
				{
					_rGame.m_pTableau->GetTableau()[i].push_back(_dragged);
					_rGame.m_pDrawPile->m_vecDrawPile.pop_back();
					_rGame.m_pDrawPile->EraseCard(_dragged);
					_dragged->SetPileDest(static_cast<dest>(i + 1));
				}
				else if(_dragged->GetPileDest() > 0 && _dragged->GetPileDest() < 8)
				{
					std::deque<CCard*> tempDeque = _rGame.m_pTableau->PopCard(_dragged, _dragged->GetPileDest() - 1);
					for (unsigned int k = 0; k < tempDeque.size();)
					{
						_rGame.m_pTableau->GetTableau()[i].push_back(tempDeque.at(k));
						tempDeque.at(k)->SetPileDest(static_cast<dest>(i + 1));
						tempDeque.pop_front();
					}
				}
				else
				{
					_rGame.m_pTableau->GetTableau()[i].push_back(_dragged);
					_rGame.m_pFoundation->GetFoundation()[static_cast<int>(_dragged->GetPileDest())-10].pop();
					_dragged->SetPileDest(static_cast<dest>(i + 1));
				}
			}

		}
		else if (PtInRect(&rectTableau, _mousePos) && tempCard == nullptr)
		{
			if (_dragged->getNumber() == 12 && _dragged->GetPileDest() != 0)
			{
				std::deque<CCard*> tempDeque = _rGame.m_pTableau->PopCard(_dragged, _dragged->GetPileDest() - 1);
				for (unsigned int k = 0; k < tempDeque.size();)
				{
					_rGame.m_pTableau->GetTableau()[i].push_back(tempDeque.at(k));
					tempDeque.at(k)->SetPileDest(static_cast<dest>(i + 1));
					tempDeque.pop_front();
				}
				return;
			}
			else if (_dragged->getNumber() == 12 && _dragged->GetPileDest() == 0)
			{
				_rGame.m_pTableau->GetTableau()[i].push_back(_dragged);
				_rGame.m_pDrawPile->m_vecDrawPile.pop_back();
				_rGame.m_pDrawPile->EraseCard(_dragged);
				_dragged->SetPileDest(static_cast<dest>(i + 1));
				return;
			}
		}
	}
}

void CGame::CheckFoundationDropped(CGame & _rGame, POINT _mousePos, CCard* _dragged)
{
	RECT rectFoundation;
	CCard* tempCard = nullptr;

	for (int i = 0; i < 4; i++)
	{
		rectFoundation.left = ((i * 100) + 300) - 70/2;
		rectFoundation.top = 50 - 96/2;
		rectFoundation.right = ((i * 100)) + 300 + 70/2;
		rectFoundation.bottom = 50 + 96/2;

		if (PtInRect(&rectFoundation, _mousePos))
		{
			if (_rGame.m_pFoundation->GetFoundation()[i].size() != 0)
			{
				tempCard = _rGame.m_pFoundation->GetFoundation()[i].top();
			}
			
			if (tempCard == nullptr && _dragged->getNumber() == 0 ||
				(tempCard != nullptr && _dragged->getSuit() == tempCard->getSuit() &&
					tempCard->getNumber() == _dragged->getNumber()-1))
			{
				if (_dragged->GetPileDest() == 0)
				{
					_rGame.m_pFoundation->PushCard(_dragged, i);
					_rGame.m_pDrawPile->m_vecDrawPile.pop_back();
					_rGame.m_pDrawPile->EraseCard(_dragged);
					_dragged->SetPileDest(static_cast<dest>(i + 10));
					return;
				}
				else if (_dragged->GetPileDest() > 0 && _dragged->GetPileDest() < 8)
				{
					std::deque<CCard*> tempDeque = _rGame.m_pTableau->PopCard(_dragged, _dragged->GetPileDest() - 1);
					if(tempDeque.size() == 1)
					{
						_rGame.m_pFoundation->PushCard(tempDeque.back(),i);
						tempDeque.back()->SetPileDest(static_cast<dest>(i + 10));
						tempDeque.pop_front();
					}
					else
					{
						for (unsigned int k = 0; k < tempDeque.size();)
						{
							_rGame.m_pTableau->GetTableau()[tempDeque.at(k)->GetPileDest()-1].push_back(tempDeque.at(k));
							tempDeque.at(k)->SetPileDest(tempDeque.at(k)->GetPileDest());
							tempDeque.pop_front();
						}
					}
					return;
				}
				else
				{
					_rGame.m_pFoundation->GetFoundation()[static_cast<int>(_dragged->GetPileDest()) - 10].pop();
					_rGame.m_pFoundation->GetFoundation()[i].push(_dragged);
					_dragged->SetPileDest(static_cast<dest>(i + 10));
				}
			}
		}
	}
}

bool CGame::CheckWin(CGame& _rGame)
{
	for (int i = 0; i < 4; i++)
	{
		if (_rGame.m_pFoundation->GetFoundation()[i].size() == 0 || _rGame.m_pFoundation->GetFoundation()[i].top()->getNumber() != 12)
		{
			return false;
		}
	}
	_rGame.NewGame();
	return true;
}

void CGame::SetDragging(CGame& _rGame, CCard* _dragging)
{
	_rGame.cardDragging = _dragging;
}

void CGame::CheckEmptyDrawPile(CGame& _rGame)
{
	if (_rGame.m_pDrawPile->GetCards().size() != 0 && _rGame.m_pDrawPile->m_vecDrawPile.size() == 0)
	{
		_rGame.m_pDrawPile->m_vecDrawPile.push_back(_rGame.m_pDrawPile->GetCards().back());
		_rGame.m_pDrawPile->GetCards().pop_back();
	}
}

void CGame::ChangeBackSprite(CGame & _rGame, int _iBackIndex)
{
	if (_iBackIndex == 2)
	{
		for (int i = 0; i < 52; i++)
		{
			_rGame.m_vecpCardsToDelete.at(i)->GetBackSprite()->Initialise(IDB_MDSCARDBACK, IDB_CARDMASK);
		}
	}
}

void CGame::NewGame()
{
	delete m_pBackBuffer;
	m_pBackBuffer = 0;

	delete m_pClock;
	m_pClock = 0;

	delete m_pDeck;
	m_pDeck = 0;

	delete m_pDrawPile;
	m_pDrawPile = 0;

	delete m_pTableau;
	m_pTableau = 0;

	delete m_pFoundation;
	m_pFoundation = 0;

	delete m_pBackground;
	m_pBackground = 0;

	m_pDrawPile = new CDrawPile();
	m_pDeck = new CDeck();
	m_pTableau = new CTableauPile();
	m_pFoundation = new CFoundationPile();
	cardDragging = nullptr;
}

void CGame::ShiftDeckToDraw()
{
	int iShiftCards = m_iCardsToDraw;
	// Clear drawing vector
	while (m_pDrawPile->m_vecDrawPile.size() != 0)
	{
		m_pDrawPile->m_vecDrawPile.pop_back();
	}
	// Populate draw pile and vctor
	while (m_pDeck->IsEmpty() == false && iShiftCards != 0)
	{
		CCard* tempCard = m_pDeck->PopCard();
		m_pDrawPile->PushCard(tempCard);
		m_pDrawPile->m_vecDrawPile.push_back(tempCard);
		iShiftCards--;
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

void CGame::SetCardsToDraw(CGame& _rGame, int _iDrawAmount)
{
	_rGame.m_iCardsToDraw = _iDrawAmount;
}
