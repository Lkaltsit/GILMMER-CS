#ifndef GAME_H  
#define GAME_H 

#define BOARD_SIZE 9
#define WIN_LENGTH 5
#define CELL 40
#define MARGIN 50



enum  {empty_chess,cross_chess,circle_chess};//棋子的枚举
enum  {emptykey,cross_key,circle_key};

typedef struct coord
{
    int x;
    int y;
}Coord;//坐标

extern int current_player_chess;
extern int board[BOARD_SIZE][BOARD_SIZE];
extern Coord Acoord;
extern Coord grid;
//extern Coord Paintcoord; 
extern int Move;
extern wchar_t g_result[128];
extern int GAMESTATE;//所有全局变量


int chesskeycheck(Coord coord,int board[BOARD_SIZE][BOARD_SIZE]);
int fullDrawcheck(int board[BOARD_SIZE][BOARD_SIZE]);
int isBoardoutcheck(Coord coord);
int wincheck_anti_diagonal(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber);
int wincheck_main_diagonal(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber);
int wincheck_column(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber);
int wincheck_row(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber);
int wincheck(Coord coord,int board[BOARD_SIZE][BOARD_SIZE],int keynumber);
int chessput(Coord coord, int board[BOARD_SIZE][BOARD_SIZE], int current_player_chess); //胜利条件声明

#endif