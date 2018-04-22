#include <stdlib.h>
#include "../inc/game_board.h"

game_board * curr;

int validGameBoard()
{
        return curr == NULL;
}

void CloneBoard(game_board * copy, game_board * original)
{
        for(int a = 0; a < len; a++){
                for(int b = 0; a < wid; b++){
                        copy->gb[a][b].obj = original->gb[a][b].obj;
                }
        }
}

int InitGameBoard()
{
        curr = (game_board*) malloc(sizeof(game_board));
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
        return -1;
}

game_board ExportGameBoard()
{
        game_board tmp;
        CloneBoard(&tmp,curr);
        return tmp;
}