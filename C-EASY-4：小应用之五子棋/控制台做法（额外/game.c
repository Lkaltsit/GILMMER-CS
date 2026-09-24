#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "game.h"
#include "winproc.h"



int wincheck(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber)
{
    int ret=0;
    if(
    wincheck_row(coord,board,keynumber)||
    wincheck_column(coord,board,keynumber)||
    wincheck_main_diagonal(coord,board,keynumber)||
    wincheck_anti_diagonal(coord,board,keynumber)
    )
    {
        ret=1;
    }
    return ret;
   
}
int wincheck_row(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber)
{
    int ret=0;
    int cnt_1=0,cnt_2=0;
    while(!isBoardoutcheck((Coord){coord.x-cnt_1,coord.y})&&board[coord.x-cnt_1][coord.y]==keynumber)
    {
        cnt_1++;
    }
    while(!isBoardoutcheck((Coord){coord.x+cnt_2,coord.y})&&board[coord.x+cnt_2][coord.y]==keynumber)
    {
        cnt_2++;
    }
    if(cnt_1+cnt_2-1>=WIN_LENGTH)
    {
        ret=1;
    }
    return ret;
}
int wincheck_column(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber)
{
    int ret=0;
    int cnt_1=0,cnt_2=0;
    while(!isBoardoutcheck((Coord){coord.x,coord.y-cnt_1})&&board[coord.x][coord.y-cnt_1]==keynumber)
    {
        cnt_1++;
    }
    while(!isBoardoutcheck((Coord){coord.x,coord.y+cnt_2})&&board[coord.x][coord.y+cnt_2]==keynumber)
    {
        cnt_2++;
    }
    if(cnt_1+cnt_2-1>=WIN_LENGTH)
    {
        ret=1;
    }
    return ret;
}
int wincheck_main_diagonal(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber)
{
    int ret=0;
    int cnt_1=0,cnt_2=0;
    while(!isBoardoutcheck((Coord){coord.x-cnt_1,coord.y-cnt_1})&&board[coord.x-cnt_1][coord.y-cnt_1]==keynumber)
    {
        cnt_1++;
    }
    while(!isBoardoutcheck((Coord){coord.x+cnt_2,coord.y+cnt_2})&&board[coord.x+cnt_2][coord.y+cnt_2]==keynumber)
    {
        cnt_2++;
    }
    if(cnt_1+cnt_2-1>=WIN_LENGTH)
    {
        ret=1;
    }
    return ret;
}
int wincheck_anti_diagonal(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber)
{
    int ret=0;
    int cnt_1=0,cnt_2=0;
    while(!isBoardoutcheck((Coord){coord.x+cnt_1,coord.y-cnt_1})&&board[coord.x+cnt_1][coord.y-cnt_1]==keynumber)
    {
        cnt_1++;
    }
    while(!isBoardoutcheck((Coord){coord.x-cnt_2,coord.y+cnt_2})&&board[coord.x-cnt_2][coord.y+cnt_2]==keynumber)
    {
        cnt_2++;
    }
    if(cnt_1+cnt_2-1>=WIN_LENGTH)
    {
        ret=1;
    }
    return ret;
}
int isBoardoutcheck(Coord coord)
{
    int ret=0;
    if(coord.x<0||coord.x>=BOARD_SIZE||coord.y<0||coord.y>=BOARD_SIZE)
    {
        ret=1;
    }
    return ret;

}
int fullDrawcheck(int board[BOARD_SIZE][BOARD_SIZE])
{
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            if(board[i][j]==emptykey)
            {
                return 0;
            }
        }
    }
    return 1;
}
int chesskeycheck(Coord Acoord,int board[BOARD_SIZE][BOARD_SIZE])
{
    int ret=0;
    if(board[Acoord.x][Acoord.y]!=emptykey)
    {
        ret=1;
    }
    return ret;
}
