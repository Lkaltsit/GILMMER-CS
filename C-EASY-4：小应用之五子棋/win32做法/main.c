#define UNICODE
#define _UNICODE
#include <windows.h>
#include "game.h"
#include "winproc.h"

int board[BOARD_SIZE][BOARD_SIZE] = {0};
Coord Acoord = {0, 0};
Coord grid= {0, 0};
//Coord Paintcoord={0,0};
int Move = 0;
int current_player_chess = cross_chess;
HANDLE g_hOutput=0;
HANDLE hInst=0;
wchar_t g_result[128]={0}; 
int GAMESTATE=1;
//全局变量的初始化

LRESULT CALLBACK Wndproc(HWND hWnd,UINT msgID,WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hIns,HINSTANCE hPreIns,LPSTR lpCmdLine,int nCmdShow)
{
    AllocConsole();
    //g_hOutput=GetStdHandle(STD_OUTPUT_HANDLE);
    WNDCLASS wc={0};
    wc.lpszClassName=L"Main";
    wc.lpszMenuName=NULL;//这不是名字 是菜单资源
    wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
    wc.style=CS_VREDRAW|CS_HREDRAW;
    wc.cbClsExtra=0;
    wc.cbWndExtra=0;
    wc.hInstance=hIns;
    wc.hIcon=NULL;
    wc.hCursor=NULL;
    wc.lpfnWndProc=Wndproc;
    RegisterClass(&wc);
    HWND hWnd=CreateWindowEx(0,L"Main",L"棋盘",WS_OVERLAPPEDWINDOW,0,0,700,700,NULL,NULL,hIns,NULL);
    ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);
    MSG nMsg={0};
    while(GetMessage(&nMsg,NULL,0,0))
    {
        TranslateMessage(&nMsg);
        DispatchMessage(&nMsg);
    }
    return nMsg.wParam;
}
/*WNDCLASS wc_child={0};
    wc_child.lpszClassName="Child";
    wc_child.lpszMenuName=NULL;//这不是名字 是菜单资源
    wc_child.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
    wc_child.style=CS_VREDRAW|CS_HREDRAW;
    wc_child.cbClsExtra=10;
    wc_child.cbWndExtra=10;
    wc_child.hInstance=hIns;
    wc_child.hIcon=NULL;
    wc_child.hCursor=NULL;
    wc_child.lpfnWndProc=Wndproc;*/
    //RegisterClass(&wc_child);
    /*HWND hWnd_Child=CreateWindowEx(0,"Child","欢迎来到五子棋",WS_CHILD|WS_VISIBLE,300,300,200,200,hWnd,NULL,hIns,NULL);
    UpdateWindow(hWnd_Child);*/ 
    //只是想要提示的话是不需要子窗口的
