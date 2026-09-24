#ifndef WINPROC_H
#define WINPROC_H
#define UNICODE
#define _UNICODE 
#define WM_CREATE_CHILD ( WM_USER + 100 )


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include "winproc.h"
#include "game.h"

LRESULT CALLBACK ChildWndproc(HWND hWnd,UINT msgID,WPARAM wParam,LPARAM lParam);

LRESULT CALLBACK Wndproc(HWND hWnd,UINT msgID,WPARAM wParam,LPARAM lParam)
{
    switch(msgID)
    {
        case WM_LBUTTONDOWN:
        {
            if(!GAMESTATE)
            {
                break;
            }           
            coordget(lParam,&Acoord);
            coordchange(Acoord,&grid);
            if(!isBoardoutcheck(grid))
            {
                if(board[grid.x][grid.y]==empty_chess)
                {
                    /*char szText[256]={0};
                    sprintf(szText,"你点击了:x=%d y=%d \n",grid.x,grid.y);
                    MessageBox(hWnd, szText, "坐标调试", MB_OK); */
                    chessput(grid,board,current_player_chess);
                    Move++;
                    if(wincheck(grid,board,current_player_chess))
                    {
                        swprintf(g_result,(size_t)128,L"玩家 %s 获胜！ 共走了%d 步\n\n是否重来",current_player_chess==cross_chess? L"X":L"O",Move);//相当于把内容存到这个宽字节符里面 然后再用WritrConsole或者MessageBoxW来输出（前者终端后者窗口提示）
                        int ret=MessageBoxW(hWnd,g_result,L"游戏已结束",MB_YESNO|MB_ICONINFORMATION);
                        initallstate(hWnd,ret); 
                    }
                    else
                    {
                        if(fullDrawcheck(board))
                        {
                            swprintf(g_result,(size_t)128,L"平局\n\n是否重来",0,0);  
                            int ret=MessageBoxW(hWnd,g_result,L"游戏已结束",MB_YESNO|MB_ICONINFORMATION);
                            initallstate(hWnd,ret);
                        }
                        current_player_chess = (current_player_chess == cross_chess) ? circle_chess : cross_chess;//三元运算符来切换玩家
                        
                    }     
                    InvalidateRect(hWnd,NULL,FALSE);
                }
            }
            break;
        }
        case WM_PAINT:
        {
            PAINTSTRUCT ps={0};
            HDC hdc=BeginPaint(hWnd,&ps);
            DrawBoard(hdc);
            for(int i=0;i<BOARD_SIZE;i++)
            {
                for(int j=0;j<BOARD_SIZE;j++)
                {
                    Coord Nowgrid={i,j};
                    Coord Paintcoord = {0, 0};
                    GetPaintcoord(Nowgrid,&Paintcoord);
                    if(board[i][j]==empty_chess)
                    {
                        DrawEmpty_chess(hdc,Paintcoord);
                    }
                    else if(board[i][j]==cross_chess)
                    {
                        
                        DrawCross_chess(hdc,Paintcoord);
                        
                    }
                    else if(board[i][j]==circle_chess)
                    {
                            
                        DrawCircle_chess(hdc,Paintcoord);
                        
                    }

                }
            }
            swprintf(g_result,(size_t)128,L"当前玩家：%lc 已走步数：%d",(current_player_chess==cross_chess)?L'X':L'O',Move);
            TextOutW(hdc,MARGIN,MARGIN+(BOARD_SIZE+1)*CELL,g_result,14);

        EndPaint(hWnd,&ps);    
        break;
        
        
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_SYSCOMMAND:
            if(wParam==SC_CLOSE)
            {
                int nRet=MessageBox(hWnd,L"是否关闭",L"Information",MB_YESNO);
                if(nRet==IDNO)
                {
                    return 0;
                }
                else
                {

                }
            }

        default:
            break;
    }
    return DefWindowProc(hWnd,msgID,wParam,lParam);
}



void coordget(LPARAM lParam,Coord *coord)
{
    coord->x=LOWORD(lParam);
    coord->y=HIWORD(lParam);
}
void coordchange(Coord coord,Coord *grid)
{
    grid->x=(coord.x-MARGIN)/CELL;
    grid->y=(coord.y-MARGIN)/CELL;
    if(coord.x<MARGIN)grid->x--;
    if(coord.y<MARGIN)grid->y--;//防止c语言负数时归为0 这个好阴
}

int chessput(Coord coord, int board[BOARD_SIZE][BOARD_SIZE],int current_player_chess)
{
    board[coord.x][coord.y]=current_player_chess;
    return 1;
}

void DrawBoard(HDC hdc)
{
    for(int i=0;i<BOARD_SIZE+1;i++)
    {
        MoveToEx(hdc,MARGIN,MARGIN+i*CELL,NULL);
        LineTo(hdc,MARGIN+BOARD_SIZE*CELL,MARGIN+i*CELL);
    }
    for(int i=0;i<BOARD_SIZE+1;i++)
    {
        MoveToEx(hdc,MARGIN+i*CELL,MARGIN,NULL);
        LineTo(hdc,MARGIN+i*CELL,MARGIN+BOARD_SIZE*CELL);//起点与终点画线
    }
}

void GetPaintcoord(Coord grid,Coord *Paintcoord)
{
    Paintcoord->x=grid.x*CELL+MARGIN+CELL/2;
    Paintcoord->y=grid.y*CELL+MARGIN+CELL/2;
}

void DrawCross_chess(HDC hdc,Coord Paintcoord)
{
    int r=CELL/2-5;
    MoveToEx(hdc,Paintcoord.x+r,Paintcoord.y+r,NULL);
    LineTo(hdc,Paintcoord.x-r,Paintcoord.y-r);
    MoveToEx(hdc,Paintcoord.x+r,Paintcoord.y-r,NULL);
    LineTo(hdc,Paintcoord.x-r,Paintcoord.y+r);
    
}

void DrawCircle_chess(HDC hdc,Coord Paintcoord)
{
    int r=CELL/2-5;
    Ellipse(hdc,Paintcoord.x-r,Paintcoord.y-r,Paintcoord.x+r,Paintcoord.y+r);
}

void DrawEmpty_chess(HDC hdc,Coord Paintcoord)
{
    int r=1;
    Ellipse(hdc,Paintcoord.x-r,Paintcoord.y-r,Paintcoord.x+r,Paintcoord.y+r);//画圆
}
void initallstate(HWND hWnd,int ret)
{
    if(ret==IDYES)
    {
        for(int i=0;i<BOARD_SIZE;i++)
        {
            for(int j=0;j<BOARD_SIZE;j++)
            {
                board[i][j]=empty_chess;//重置
                        
            }
                    
        }
        current_player_chess=cross_chess;
        Move=0;//初始化
        GAMESTATE=1;
        InvalidateRect(hWnd,NULL,TRUE);//直接全部重绘
    }
    else
    {
        PostMessage(hWnd,WM_CLOSE,0,0);
        PostQuitMessage(0);//关闭后直接关
    }
}
/*void initcheckboard(int board[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            board[i][j]=empty_chess;
        }
    }
}
void printcheckboard(int board[9][9])
{
    for(int i=0;i<9;i++)
    {
        printf("+---+---+---+---+----+---+---+---+---+\n");
        for(int j=0;j<9;j++)
        {
            if(board[i][j]==empty_chess)
            {
                printf("| · ");
            }
            else if(board[i][j]==circle_chess)
            {
                printf("|  O ");
            }
            else if(board[i][j]==cross_chess)
            {
                printf("| X ");
            }
            if(j==8)
            {
                printf("\n");
            }
        }
    }
    printf("+---+---+---+---+---+---+---+---+---+");
}*/ //相当没用的打印法
#endif