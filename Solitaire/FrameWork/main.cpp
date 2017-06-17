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

//Library Includes
#include <windows.h>
#include <windowsx.h>

//Local Includes
#include "Game.h"
#include "Clock.h"
#include "utils.h"
#include "card.h"

//Global Variables

#define WINDOW_CLASS_NAME L"BSENGGFRAMEWORK"

LRESULT CALLBACK
WindowProc(HWND _hWnd, UINT _uiMsg, WPARAM _wParam, LPARAM _lParam)
{
	static bool isDragging = false;
	static CCard* Draggable = nullptr;
	static RECT debug;

	HDC hdc;
	PAINTSTRUCT ps;

    switch (_uiMsg)
    {
        case WM_DESTROY:
        {
            PostQuitMessage(0);

            return(0);
        }
		case WM_PAINT:
		{
			hdc = BeginPaint(_hWnd, &ps);
			HBRUSH drawingBrush = CreateSolidBrush(RGB(0,0,0));
			FillRect(hdc, &debug, drawingBrush);

			EndPaint(_hWnd, &ps);
			// Return Success.
			return (0);

			break;
		}
		case WM_SIZING:
		{
			RECT _rect;

			GetClientRect(_hWnd, &_rect);
			CGame::SetRoomHeight(_rect.bottom);
			CGame::SetRoomWidth(_rect.right);
			CGame::SetCardWidth((_rect.right) / 11);
			CGame::SetCardHeight((_rect.bottom - (3 * CGame::GetCardWidth() / 5)) / 4.6);
			
			switch (_wParam)
			{
				case WMSZ_TOP:
				case WMSZ_BOTTOM:
				case WMSZ_TOPLEFT:
				case WMSZ_TOPRIGHT:
				{
					CGame::SetRoomWidth(_rect.bottom / 9 * 16);
					SetWindowPos(_hWnd, _hWnd, _rect.left, _rect.top, CGame::GetRoomWidth(), CGame::GetRoomHeight(), NULL);
					break;
				}
				case WMSZ_LEFT:
				case WMSZ_RIGHT:
				case WMSZ_BOTTOMLEFT:
				case WMSZ_BOTTOMRIGHT:
				{
					CGame::SetRoomHeight(_rect.right / 16 * 9);
					SetWindowPos(_hWnd, _hWnd, _rect.left, _rect.top, CGame::GetRoomWidth(), CGame::GetRoomHeight(), NULL);
					break;
				}
				default:break;
				}
		
		}
		case WM_LBUTTONDOWN:
		{
			POINT mousePos;
			GetCursorPos(&mousePos);

			if (!CGame::CheckDeckClicked(CGame::GetInstance(), mousePos))
			{
				Draggable = CGame::CheckDraggableClicked(CGame::GetInstance(), mousePos);
				//RECT _rect;
				//GetClientRect(_hWnd, &_rect);

				//debug = CGame::CheckDraggableClicked(CGame::GetInstance(), mousePos);
				//InvalidateRect(_hWnd, &_rect, false);
			}
			
			if (Draggable != nullptr)
			{
				isDragging = true;
				Draggable->SetDragging(true);
			}
			break;
		}

		case WM_MOUSEMOVE:
		{
			if (isDragging == true)
			{
				POINT mousePos;
				GetCursorPos(&mousePos);

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
				Draggable->SetDragging(false);
			}
			isDragging = false;
			Draggable = nullptr;
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
    hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
                  WINDOW_CLASS_NAME,
                  _pcTitle,
              WS_BORDER | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX,
                  CW_USEDEFAULT, CW_USEDEFAULT,
                  _iWidth, _iHeight,
                  NULL,
                  NULL,
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

	HWND DesktopWindow = GetDesktopWindow();
	RECT _rect;
	GetClientRect(DesktopWindow, &_rect);

    const int kiWidth = _rect.right;
    const int kiHeight = _rect.bottom;

    HWND hwnd = CreateAndRegisterWindow(_hInstance, kiWidth, kiHeight, L"BSENGG Framework");

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
        }
    }

    CGame::DestroyInstance();

    return (static_cast<int>(msg.wParam));
}
