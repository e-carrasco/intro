#include <stdlib.h>
#include "game_board.h"

game_board * curr;

static int validGameBoard()
{
        return curr != NULL;
}

static int validTileObject(obj)
{
        return (obj <= Item) && (obj >= Empty); // This expression may change
}

static int validCoord(Coord c)
{
        return (c.x <= len) && (c.y <= wid);
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
                return validGameBoard();
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
        if(validCoord(c) && validTileObject(obj)){
                curr->gb[c.x][c.y].obj = obj;
                return 1 > 0;
        } else {
                return 1 < 0;
        }
}

int RemoveObjectCoord(Coord c)
{
        if(validCoord(c)){
                curr->gb[c.x][c.y].obj = Empty;
                return 1;
        } else {
                return 0;
        }
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