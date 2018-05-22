/* Game Board data structure and accompanying helper functions
 *
 */

#ifndef game_board_h
#define game_board_h

#ifdef __cplusplus
extern "C" {
#endif

#include "data_structures.h"


enum len { len = 3 };
enum wid { wid = 3 };

typedef struct  {
        struct Tile gb[len][wid];
} game_board;

int InitGameBoard();
int CloseGameBoard();
int AddObject(Coord c, TileObject obj);
int RemoveObjectCoord(Coord c);
int RemoveAllInstances(TileObject obj);
int ImportGameBoard(game_board *imp);
game_board ExportGameBoard();

#ifdef __cplusplus
}
#endif

#endif /* game_board_h */