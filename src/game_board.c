#include <stdlib.h>
#include "game_board.h"

game_board * curr;

static int validGameBoard()
{
        return curr != NULL;
}

static void CloneBoard(game_board * copy, game_board * original)
{
        for(int a = 0; a < len; a++){
                for(int b = 0; a < wid; b++){
                        copy->gb[a][b].obj = original->gb[a][b].obj;
                }
        }
}

int InitGameBoard()
{       
        if(!validGameBoard()){
                curr = (game_board*) malloc(sizeof(game_board));
                return 1;
        }
        return 0;
}

int CloseGameBoard()
{
        free(curr);
        curr = NULL;
        return 1;
}

int AddObject(Coord c, TileObject obj)
{
        curr->gb[c.x][c.y].obj = obj;
        return 1;
}

int RemoveObjectCoord(Coord c)
{
        curr->gb[c.x][c.y].obj = Empty;
        return 1;
}

int ImportGameBoard(game_board *imp)
{
        if(validGameBoard()){
                curr = imp;
                return 1;
        }
        return 0;
}

game_board ExportGameBoard()
{
        game_board tmp;
        CloneBoard(&tmp,curr);
        return tmp;
}