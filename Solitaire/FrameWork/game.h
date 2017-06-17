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

#if !defined(__GAME_H__)
#define __GAME_H__

// Library Includes
#include <windows.h>
#include <vector>


// Local Includes
#include "clock.h"

// Types

// Constants

// Prototypes
class CBackBuffer;
class CDrawPile;
class CDeck;
class CTableauPile;
class CCard;
class CSprite;

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
	static void Dragging(CGame& _rGame, POINT _mousePos);

	void ShiftDeckToDraw();
	void ShiftDrawToDeck();
	


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

	std::vector<CCard*> m_vecpCards;

	
};

#endif    // __GAME_H__
