#pragma once
#include "data_structures.h"

struct {
        CharacterStats max_stats;
        CharacterStats cur_stats;
        CharacterStats mod_stats;
        int items[4]; // placeholder until actual items are introduced
        Coord loc;
} player_character;