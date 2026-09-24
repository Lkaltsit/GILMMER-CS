#include <windows.h> 
#include "game.h"

extern HANDLE g_hOutput;
extern HANDLE hInst;


void DrawBoard(HDC hdc);
void coordget(LPARAM lParam,Coord *coord);
void coordchange(Coord coord,Coord *gird);
int chessput(Coord coord, int board[BOARD_SIZE][BOARD_SIZE],int current_player_chess);
void DrawCross_chess(HDC hdc,Coord Paintcoord);
void DrawCircle_chess(HDC hdc,Coord Paintcoord);
void DrawEmpty_chess(HDC hdc,Coord Paintcoord);
void GetPaintcoord(Coord grid,Coord *Paintcoord);
void initallstate(HWND hWnd,int ret);
//所有声明