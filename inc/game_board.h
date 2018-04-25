/* Game Board data structure and accompanying helper functions
 *
 */

#ifdef __cplusplus
extern "C" {
#endif

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