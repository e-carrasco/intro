#include <stdlib.h>
#include "game_board.h"

game_board * curr;

static int validGameBoard()
{
        return curr != NULL;
}

static int validTileObject(TileObject obj)
{
	return (obj <= Item) && (obj >= Empty); // This expression may change
}

static int validImportedBoard(game_board * imp)
{
        for(int l = 0; l < len; l++){
                for(int w = 0; w < wid; w++){
                        if(!validTileObject(imp->gb[l][w].obj))
                                return 0;
                }
        }
        return 1;
}

static int validCoord(Coord c)
{
        return (c.x <= len) && (c.y <= wid);
}

static void CloneBoard(game_board * copy, game_board * original)
{
        for(int a = 0; a < len; a++){
                for(int b = 0; b < wid; b++){
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

int RemoveAllInstances(TileObject obj)
{
	//TODO: Method Stub
	return 0;
}

int ImportGameBoard(game_board *imp)
{
        if(validGameBoard() && validImportedBoard(imp)){
                CloneBoard(curr,imp);
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