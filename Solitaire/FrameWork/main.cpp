//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: main.cpp
// Description	: Main entry point
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

//Library Includes
#include <windows.h>
#include <windowsx.h>

//Local Includes
#include "Game.h"
#include "Clock.h"
#include "utils.h"
#include "card.h"
#include "resource.h"

//Global Variables
HMENU g_hMenu;
bool g_bResetVar;

#define WINDOW_CLASS_NAME L"BSENGGFRAMEWORK"

LRESULT CALLBACK
WindowProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
{
	static bool isDragging = false;
	static CCard* Draggable = nullptr;
	static int s_iCurMouseX;
	static int s_iCurMouseY;

    switch (_uiMsg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);

            return(0);
			break;
        }
		case WM_LBUTTONDOWN:
		{
			POINT mousePos;
			mousePos.x = s_iCurMouseX;
			mousePos.y = s_iCurMouseY;

			if (!CGame::CheckDeckClicked(CGame::GetInstance(), mousePos))
			{
				Draggable = CGame::CheckDraggableClicked(CGame::GetInstance(), mousePos);
			}
			
			if (Draggable != nullptr)
			{
				isDragging = true;
				Draggable->SetDragging(true);
				CGame::SetDragging(CGame::GetInstance(), Draggable);
			}
			break;
		}

		case WM_MOUSEMOVE:
		{
			s_iCurMouseX = static_cast<int>(LOWORD(_lParam));
			s_iCurMouseY = static_cast<int>(HIWORD(_lParam));

			if (isDragging == true)
			{
				POINT mousePos;
				mousePos.x = s_iCurMouseX;
				mousePos.y = s_iCurMouseY;

				if (Draggable != nullptr)
				{
					Draggable->GetSprite()->SetX(mousePos.x);
					Draggable->GetSprite()->SetY(mousePos.y);
				}
			}
			break;
		}
		case WM_LBUTTONUP:
		{
			if (Draggable != nullptr)
			{
				//Check where dropped
				POINT mousePos;
				mousePos.x = s_iCurMouseX;
				mousePos.y = s_iCurMouseY;

				CGame::CheckWhereDropped(CGame::GetInstance(), mousePos, Draggable);
				CGame::CheckFoundationDropped(CGame::GetInstance(), mousePos, Draggable);
				Draggable->SetDragging(false);
			}
			isDragging = false;
			Draggable = nullptr;
			CGame::SetDragging(CGame::GetInstance(), nullptr);
			CGame::CheckEmptyDrawPile(CGame::GetInstance());
			break;
		}
		case WM_COMMAND:
		{
			switch (LOWORD(_wParam))
			{
			case ID_DRAWAMOUNT_1:
			{
				CGame::SetCardsToDraw(CGame::GetInstance(), 1);
				break;
			}
			case ID_DRAWAMOUNT_3:
			{
				CGame::SetCardsToDraw(CGame::GetInstance(), 3);
				break;
			}
			case ID_CARDBACKS_MDS:
			{
				CGame::ChangeBackSprite(CGame::GetInstance(), 2);
				break;
			}
			case ID_CARDBACKS_KING:
			{
				CGame::ChangeBackSprite(CGame::GetInstance(), 1);
				break;
			}
			case ID_GAME_QUIT:
			{
				PostQuitMessage(0);

				return(0);
				break;
			}
			case ID_GAME_RESET:
			{
				g_bResetVar = true;
				break;
			}

			default:break;
			}
			break;
		}
        break;

        default:break;
    } 

    return (DefWindowProc(_hWnd, _uiMsg, _wParam, _lParam));
}

HWND 
CreateAndRegisterWindow(HINSTANCE _hInstance, int _iWidth, int _iHeight, LPCWSTR _pcTitle)
{
    WNDCLASSEX winclass;

    winclass.cbSize = sizeof(WNDCLASSEX);
    winclass.style = CS_HREDRAW | CS_VREDRAW;
    winclass.lpfnWndProc = WindowProc;
    winclass.cbClsExtra = 0;
    winclass.cbWndExtra = 0;
    winclass.hInstance = _hInstance;
    winclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    winclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    winclass.hbrBackground = static_cast<HBRUSH> (GetStockObject(NULL_BRUSH));
    winclass.lpszMenuName = NULL;
    winclass.lpszClassName = WINDOW_CLASS_NAME;
    winclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&winclass))
    {
        // Failed to register.
        return (0);
    }

    HWND hwnd; 
	g_hMenu = LoadMenu(_hInstance, MAKEINTRESOURCE(IDR_MENU1));

    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
                  WINDOW_CLASS_NAME,
                  _pcTitle,
              WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
                  CW_USEDEFAULT, CW_USEDEFAULT,
                  _iWidth, _iHeight,
                  NULL,
                  g_hMenu,
                  _hInstance,
                  NULL);
    
    if (!hwnd)
    {
        // Failed to create.
        return (0);
    }

    return (hwnd);
}

int WINAPI
WinMain(HINSTANCE _hInstance, HINSTANCE _hPrevInstance, LPSTR _lpCmdline, int _iCmdshow)
{
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));


    const int kiWidth = 720;
    const int kiHeight = 960;

	g_bResetVar = false;

    HWND hwnd = CreateAndRegisterWindow(_hInstance, kiWidth, kiHeight, L"Solitaire");

    CGame& rGame = CGame::GetInstance();

    if (!rGame.Initialise(_hInstance, hwnd, kiWidth, kiHeight))
    {
        // Failed
        return (0);
    }

    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            rGame.ExecuteOneFrame();
			if (rGame.CheckWin(rGame))
			{
				MessageBoxA(hwnd, "Congratulations, you actually won Solitaire!", "WINNER!", MB_OK);
				rGame.Initialise(_hInstance, hwnd, kiWidth, kiHeight);
			}
			else if (g_bResetVar == true)
			{
				rGame.NewGame();
				rGame.Initialise(_hInstance, hwnd, kiWidth, kiHeight);
				g_bResetVar = false;
			}
        }
    }

    CGame::DestroyInstance();

    return (static_cast<int>(msg.wParam));
}
