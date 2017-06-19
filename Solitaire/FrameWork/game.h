//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: game.h
// Description	: Game header file
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

#if !defined(__GAME_H__)
#define __GAME_H__

// Library Includes
#include <windows.h>
#include <vector>


// Local Includes
#include "clock.h"

// Prototypes
class CBackBuffer;
class CDrawPile;
class CDeck;
class CTableauPile;
class CCard;
class CSprite;
class CBackGround;
class CFoundationPile;

class CGame
{
    // Member Functions
public:
    ~CGame();

    bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);

    void Draw();
    void Process(float _fDeltaTick);

    void ExecuteOneFrame();

    CBackBuffer* GetBackBuffer();
    HINSTANCE GetAppInstance();
    HWND GetWindow();
	static int GetRoomWidth();
	static int GetRoomHeight();
	static int GetCardWidth();
	static int GetCardHeight();
	static void SetRoomWidth(int _iWidth);
	static void SetRoomHeight(int _iHeight);
	static void SetCardWidth(int _iWidth);
	static void SetCardHeight(int _iHeight);

	static bool CheckDeckClicked(CGame& _rGame, POINT _mousePos);
	static CCard* CheckDraggableClicked(CGame& _rGame, POINT _mousePos);

	static void CheckWhereDropped(CGame& _rGame, POINT _mousePos, CCard* _dragged);
	static void CheckFoundationDropped(CGame& _rGame, POINT _mousePos, CCard* _dragged);

	static bool CheckWin(CGame& _rGame);
	static void SetDragging(CGame& _rGame, CCard*);

	static void CheckEmptyDrawPile(CGame& _rGame);

	static void ChangeBackSprite(CGame& _rGame, int _iBackIndex);

	void NewGame();

	void ShiftDeckToDraw();
	void ShiftDrawToDeck();

	static void SetCardsToDraw(CGame& _rGame, int);
	


    // Singleton Methods
    static CGame& GetInstance();
    static void DestroyInstance();

protected:

private:
    CGame();
    CGame(const CGame& _kr);
    CGame& operator= (const CGame& _kr);

    // Member Variables
public:


protected:
    CClock* m_pClock;

    CBackBuffer* m_pBackBuffer;
	

    //Application data
    HINSTANCE m_hApplicationInstance;
    HWND m_hMainWindow;

    // Singleton Instance
    static CGame* s_pGame;

private:
	CDrawPile* m_pDrawPile;
	CDeck* m_pDeck;
	CTableauPile* m_pTableau;
	CBackGround* m_pBackground;
	CFoundationPile* m_pFoundation;

	std::vector<CCard*> m_vecpCards;
	std::vector<CCard*> m_vecpCardsToDelete;
	CCard* m_cardDragging;
	int m_iCardsToDraw;

	
};

#endif    // __GAME_H__
