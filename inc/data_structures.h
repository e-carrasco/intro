/* Structures and defintions used by the rest of the program
 *
 */

#ifndef data_structs_h
#define data_structs_h

#include <stdint.h>

/* Any object that can occupy a tile.
 * 0 : Empty
 * 1 : Player
 * 2 : Enemy
 * 3 : Blocked
 * 4 : KeyLocation
 * 5 : Item
 */

typedef enum { 
        Empty,
        Player,
        Enemy,
        Blocked,
        KeyLocation,
        Item
} TileObject;

typedef struct {
	uint8_t x;
	uint8_t y;
} Coord;

typedef struct {
        uint32_t health;
        uint32_t attack;
        uint32_t defense;
        uint32_t magic;
} CharacterStats;

struct Tile {
        TileObject obj;
};

#endif /* data_structs_h */