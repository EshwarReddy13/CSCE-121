#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

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

    ifstream file;
    file.open(fileName);

    if(file.is_open()==false){
        return nullptr;
    }

    file >> maxRow;
    if(file.fail() || maxRow<1) {
        return nullptr;
    }

    file >> maxCol;
    if(file.fail() || maxCol<1) {
        return nullptr;
    }

    file >> player.row;
    if(file.fail() || player.row>=maxRow || player.row<0) {
        return nullptr;
    }

    file >> player.col;
    if(file.fail() || player.col>=maxCol || player.col<0) {
        return nullptr;
    }

    if(maxCol > (INT32_MAX/maxRow)){
        return nullptr;
    }

    
    char** map = createMap(maxRow, maxCol);
    char tile;
    bool is_exit = false;
    char a;
    for(int i=0;i<maxRow;i++){
        for(int j=0;j<maxCol;j++){
            if(file.fail()){
                deleteMap(map, maxRow);
                return nullptr;
            }
            
            file >> map[i][j];
            tile = map[i][j];

            if(tile=='?' || tile=='!') {
                is_exit = true;
            }
            // if(file.eof() || (tile!='l' || tile!=TILE_OPEN || tile!=TILE_MONSTER || tile!=TILE_PILLAR || tile!=TILE_AMULET || tile!=TILE_DOOR || tile!=TILE_EXIT || tile!=TILE_TREASURE)){
            //     deleteMap(map,maxRow);
            //     return nullptr;
            // }
            if (!(tile == TILE_EXIT || 
                    tile == TILE_DOOR || 
                    tile == TILE_PILLAR || 
                    tile == TILE_MONSTER || 
                    tile == TILE_AMULET || 
                    tile == TILE_OPEN || 
                    tile == TILE_TREASURE || tile == '|') || file.eof()) {
                        deleteMap(map, maxRow);
                return nullptr;
            }
        }
    }


    // if(is_exit == true){
    //     is_exit = true;
    // }else{
    //     is_exit = false;
    // }

    if(is_exit == false) {
        deleteMap(map, maxRow);
        return nullptr;
    }
    //doubt
    if(file >> a){
        deleteMap(map, maxRow);
        return nullptr;
    }
    map[player.row][player.col] = TILE_PLAYER;
    return map;
    // bool exit = false;
    // char** map = createMap(maxRow, maxCol);
    // char letter;
    // for(int r=0; r < maxRow; r++){
    //     for(int c=0; c < maxCol; c++){
    //         if (file.fail()) {
    //             deleteMap(map, maxRow);
    //             return nullptr;
    //         }
    //         file >> map[r][c];
    //         letter = map[r][c];
    //         if (letter == '?' || letter == '!') {
    //             exit = true;
    //         }
    //         if (!(letter == TILE_EXIT || 
    //                 letter == TILE_DOOR || 
    //                 letter == TILE_PILLAR || 
    //                 letter == TILE_MONSTER || 
    //                 letter == TILE_AMULET || 
    //                 letter == TILE_OPEN || 
    //                 letter == TILE_TREASURE || letter == '|') || file.eof()) {
    //                     deleteMap(map, maxRow);
    //             return nullptr;
    //         } 
    //     }
    // }
    // char newChar;
    // if (file >> newChar){
    //     deleteMap(map, maxRow);
    //     return nullptr;
    // }
    // if (!exit) {
    //     deleteMap(map, maxRow);
    //     return nullptr;
    // }
    // map[player.row][player.col] = TILE_PLAYER;
        
    // return map;
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

    if(input == 'w') {
        nextRow--;
    }else if(input == 'a') {
        nextCol--;
    }else if(input == 's') {
        nextRow++;
    }else if(input == 'd') {
        nextCol++;
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
    int no_of_tiles;
    try{
       no_of_tiles = maxCol*maxRow;
    }catch(const std::overflow_error& err) {
       cout << err.what() << endl;
       return nullptr;
    }

    char** map = new char*[maxRow];
    if ((maxCol > 0) && (maxRow > 0)){  
        for(int i=0;i<maxRow;i++){
            map[i] = new char[maxCol];
            for(int j=0;j<maxCol;j++){
                map[i][j] = TILE_OPEN;
            }
        }
    }else{
        return nullptr;
    }
    return map;
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
    if(map){
        for(int i=0;i<maxRow;i++){
            delete [] map[i];
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

    if(map==nullptr||maxRow<=0||maxCol<=0) {
        return nullptr;
    }
    char** newMap = createMap(maxRow*2, maxCol*2);
        //tryy thiis
    int tR = maxRow;
    int row;
    int col;
    for(int i=0;i<maxRow*2;i++) {
        for(int j=0;j<maxCol*2;j++) {
            row = i % maxRow;
            col = j % maxCol;
            newMap[i][j] = map[row][col];
            if (newMap[i][j] == 'o') {
                if (i >= maxRow || j >= maxCol) {
                    newMap[i][j] = TILE_OPEN;
                }
            }
        }
    }
    deleteMap(map, maxRow);
    maxRow = 2 * tR;
    maxCol = 2 * maxCol;
    return newMap;
    // if (maxRow <= 0 || maxCol <= 0 || map == nullptr) {
    //     return nullptr;
    // }
    
    // char letter;
    
    // char** newMap = createMap(maxRow*2, maxCol*2);
    // int tR = maxRow;
    // int rowVal;
    // int colVal;
    // for (int row = 0; row < maxRow * 2; ++row) {
    //     for (int col = 0; col < maxCol * 2; ++col) {
    //         rowVal = row % maxRow;
    //         colVal = col % maxCol;
    //         newMap[row][col] = map[rowVal][colVal];
    //         if (newMap[row][col] == 'o') {
    //             if (row >= maxRow || col >= maxCol) {
    //                 newMap[row][col] = TILE_OPEN;
    //             }
    //         }
    //     }
    // }
    
    // //map = newMap;
    // deleteMap(map, maxRow);
    // //map = nullptr;
    // maxRow = 2 * tR;
    // maxCol = 2 * maxCol;
    // return newMap;
    
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
    
    if((nextRow >= maxRow) || (nextCol >= maxCol) || (nextCol < 0) || (nextRow < 0)) {
        return 0;
    }
    if ((player.row == nextRow) && (player.col == nextCol)) {
        return 0;
    }
    if(map[nextRow][nextCol] == TILE_PILLAR) {
        return 0;
    }
    if(map[nextRow][nextCol] == TILE_MONSTER){
        return 0;
    }


    if(map[nextRow][nextCol] == TILE_OPEN) {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        return 1;
    }
    if(map[nextRow][nextCol] == TILE_TREASURE) {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        player.treasure++;
        return 2;
    }
    if(map[nextRow][nextCol] == TILE_AMULET) {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        return 3;
    }
    if(map[nextRow][nextCol] == TILE_DOOR) {
        map[nextRow][nextCol] = TILE_PLAYER;
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        return 4;
    }
    if(map[nextRow][nextCol] == TILE_EXIT) {
        if (player.treasure > 0) {
            map[player.row][player.col] = TILE_OPEN;
            map[nextRow][nextCol] = TILE_PLAYER;
            player.row = nextRow;
            player.col = nextCol;
            return 5;
        }else {
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
    
    bool didMonsterAttack = false;

    for (int i=player.row+1;i<maxRow;i++) {

        if(map[i][player.col] == TILE_PILLAR){
            break;
        }
        if(map[i][player.col] == TILE_MONSTER){
            map[i-1][player.col] = TILE_MONSTER;
            map[i][player.col] = TILE_OPEN;
            if (map[player.row][player.col] == TILE_MONSTER){
                didMonsterAttack = true;
            }
        }

    }

    for(int i=player.row-1;i>= 0;i--){

        if(map[i][player.col] == TILE_PILLAR){
            break;
        }
        if(map[i][player.col] == TILE_MONSTER){
            map[i+1][player.col] = TILE_MONSTER;
            map[i][player.col] = TILE_OPEN;

            if(map[player.row][player.col] == TILE_MONSTER){
                didMonsterAttack = true;
            }
        }

    }

    

    for(int i=player.col+1;i<maxCol;i++){

        if(map[player.row][i] == TILE_PILLAR){
            break;
        }
        if(map[player.row][i] == TILE_MONSTER){
            map[player.row][i-1] = TILE_MONSTER;
            map[player.row][i] = TILE_OPEN;
            if(map[player.row][player.col] == TILE_MONSTER){
                didMonsterAttack = true;
            }
        }
    }
    for(int i=player.col-1;i>=0;i--){

        if (map[player.row][i] == TILE_PILLAR){
            break;
        }
        if(map[player.row][i] == TILE_MONSTER){
            map[player.row][i+1] = TILE_MONSTER;
            map[player.row][i] = TILE_OPEN;
            if(map[player.row][player.col] == TILE_MONSTER){
                didMonsterAttack = true;
            }
        }

    }

    

    return didMonsterAttack;
}
