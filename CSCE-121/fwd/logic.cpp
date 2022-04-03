#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    ifstream ifs;
    ifs.open(fileName);
    if(!ifs.is_open()){
        return nullptr;
    }
    ifs >> maxRow;
    if (maxRow < 1 || ifs.fail()) {
        return nullptr;
    }
    ifs >> maxCol;
    if (maxCol < 1 || ifs.fail()) {
        return nullptr;
    }
    ifs >> player.row;
    if (ifs.fail() || player.row >= maxRow || player.row < 0) {
        return nullptr;
    }
    ifs >> player.col;
    if (ifs.fail() || player.col >= maxCol || player.col < 0) {
        return nullptr;
    }
    /*
    long mult = maxRow * maxCol;
    if (mult > static_cast<long>(INT32_MAX)) {
        throw std::overflow_error("Array size too big");
    }
    */
   if (maxCol > (INT32_MAX / maxRow))
    {
        return nullptr;
    }
    bool exit = false;
    char** map = createMap(maxRow, maxCol);
    char letter;
    for(int r=0; r < maxRow; r++){
        for(int c=0; c < maxCol; c++){
            if (ifs.fail()) {
                deleteMap(map, maxRow);
                return nullptr;
            }
            ifs >> map[r][c];
            letter = map[r][c];
            if (letter == '?' || letter == '!') {
                exit = true;
            }
            if (!(letter == TILE_EXIT || 
                    letter == TILE_DOOR || 
                    letter == TILE_PILLAR || 
                    letter == TILE_MONSTER || 
                    letter == TILE_AMULET || 
                    letter == TILE_OPEN || 
                    letter == TILE_TREASURE || letter == '|') || ifs.eof()) {
                        deleteMap(map, maxRow);
                return nullptr;
            } 
        }
    }
    char newChar;
    if (ifs >> newChar){
        deleteMap(map, maxRow);
        return nullptr;
    }
    if (!exit) {
        deleteMap(map, maxRow);
        return nullptr;
    }
    map[player.row][player.col] = TILE_PLAYER;
        
    return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if (input == 'w') {
        nextRow--;
    }
    else if (input == 'd') {
        nextCol++;
    }
    else if (input == 'a') {
        nextCol--;
    }
    else if (input == 's') {
        nextRow++;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    try {
       int mult = maxRow * maxCol;
   }
   catch (const std::overflow_error& err) {
       cout << err.what() << endl;
       return nullptr;
   }
    if ((maxRow > 0) && (maxCol > 0)) {  
        char** map = new char*[maxRow];
        for (int row = 0; row < maxRow; row++) {
            map[row] = new char[maxCol];
            for (int col = 0; col < maxCol; col++) {
                map[row][col] = TILE_OPEN;
            }
        }
        return map;
    }
    else {
        return nullptr;
    }
    
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    if (map){
        for(int r = 0; r < maxRow; r++){
            delete [] map[r];
    }
    delete [] map;
}
    map = nullptr;
    maxRow = 0;
    
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
if (maxRow <= 0 || maxCol <= 0 || map == nullptr) {
        return nullptr;
    }
    
    char letter;
    
    char** newMap = createMap(maxRow*2, maxCol*2);
    int tR = maxRow;
    int rowVal;
    int colVal;
    for (int row = 0; row < maxRow * 2; ++row) {
        for (int col = 0; col < maxCol * 2; ++col) {
            rowVal = row % maxRow;
            colVal = col % maxCol;
            newMap[row][col] = map[rowVal][colVal];
            if (newMap[row][col] == 'o') {
                if (row >= maxRow || col >= maxCol) {
                    newMap[row][col] = TILE_OPEN;
                }
            }
        }
    }
    
    //map = newMap;
    deleteMap(map, maxRow);
    //map = nullptr;
    maxRow = 2 * tR;
    maxCol = 2 * maxCol;
    return newMap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    if ((player.row == nextRow) && (player.col == nextCol)) {
        return 0;
    }
    if ((nextRow >= maxRow) || (nextCol >= maxCol) || (nextCol < 0) || (nextRow < 0)) {
        return 0;
    }
    if (map[nextRow][nextCol] == TILE_PILLAR || map[nextRow][nextCol] == TILE_MONSTER) {
        return 0;
    }
    if (map[nextRow][nextCol] == TILE_OPEN) {
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
        return 1;
    }
    if (map[nextRow][nextCol] == TILE_TREASURE) {
        player.treasure++;
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
        return 2;
    }
    if (map[nextRow][nextCol] == TILE_AMULET) {
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
        return 3;
    }
    if (map[nextRow][nextCol] == TILE_DOOR) {
        map[player.row][player.col] = TILE_OPEN;
        map[nextRow][nextCol] = TILE_PLAYER;
        player.row = nextRow;
        player.col = nextCol;
        return 4;
    }
    if (map[nextRow][nextCol] == TILE_EXIT) {
        if (player.treasure > 0) {
            map[player.row][player.col] = TILE_OPEN;
            map[nextRow][nextCol] = TILE_PLAYER;
            player.row = nextRow;
            player.col = nextCol;
            return 5;
        }
        else {
            return 0;
        }
    }
    return 0;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    bool monsterAttack = false;
    int col = player.col;
    for (int currRow = player.row-1; currRow >= 0; --currRow) {
        if (map[currRow][col] == TILE_PILLAR) {
            break;
        }
        if (map[currRow][col] == TILE_MONSTER) {
            map[currRow+1][col] = TILE_MONSTER;
            map[currRow][col] = TILE_OPEN;
            if (map[player.row][player.col] == TILE_MONSTER) {
                monsterAttack = true;
            }
        }
    }
    for (int currRow = player.row+1; currRow < maxRow; ++currRow) {
        if (map[currRow][col] == TILE_PILLAR) {
            break;
        }
        if (map[currRow][col] == TILE_MONSTER) {
            map[currRow-1][col] = TILE_MONSTER;
            map[currRow][col] = TILE_OPEN;
            if (map[player.row][player.col] == TILE_MONSTER) {
                monsterAttack = true;
            }
        }       
    }
    int row = player.row;
    for (int currCol = player.col-1; currCol >= 0; --currCol) {
        if (map[row][currCol] == TILE_PILLAR) {
            break;
        }
        if (map[row][currCol] == TILE_MONSTER) {
            map[row][currCol+1] = TILE_MONSTER;
            map[row][currCol] = TILE_OPEN;
            if (map[player.row][player.col] == TILE_MONSTER) {
                monsterAttack = true;
            }
        }
    }
    for (int currCol = player.col+1; currCol < maxCol; ++currCol) {
        if (map[row][currCol] == TILE_PILLAR) {
            break;
        }
        if (map[row][currCol] == TILE_MONSTER) {
            map[row][currCol-1] = TILE_MONSTER;
            map[row][currCol] = TILE_OPEN;
            if (map[player.row][player.col] == TILE_MONSTER) {
                monsterAttack = true;
            }
        }
    }
    return monsterAttack;
}