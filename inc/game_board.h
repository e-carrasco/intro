/* Game Board data structure and accompanying helper functions
 *
 */

#include "data_structures.h"

typedef struct {
        uint8_t x;
        uint8_t y;
} Coord;

enum len { len = 3 };
enum wid { wid = 3 };

typedef struct  {
        struct Tile gb[len][wid];
} game_board;

int AddObject(Coord c, enum TileObject obj);
int RemoveObjectCoord(Coord c);
int RemoveAllInstances(enum TileObject);
int ImportGameBoard(game_board imp);
game_board ExportGameBoard();