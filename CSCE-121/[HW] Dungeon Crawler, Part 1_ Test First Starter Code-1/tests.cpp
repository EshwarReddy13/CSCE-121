#include <iostream>
#include "logic.h"

using std::cout, std::endl;

// TODO(student): Write unit tests for the functions in logic.h
//                You should end up with at least 500 lines of test code
void cannotOpen(int maxRow,int maxCol,Player player){
    loadLevel("HAHAHA.txt", maxRow, maxCol,player);
}
void testLoadlevel(const std::string& fileName,int& maxRow,int& maxCol,Player& player){
    loadLevel(fileName, maxRow, maxCol,player);
}
void testGetdirection(const char& input,int& nextRow,int& nextCol){
    getDirection(input,nextRow,nextCol);   
}
void testDeleteMap(const std::string& fileName,int& maxRow,int& maxCol,Player player){
    char** map = loadLevel(fileName,maxRow,maxCol,player);
    deleteMap(map,maxRow);
}
void testResizeMap(const std::string& fileName,int& maxRow,int& maxCol,Player player,const char&a){
    char** map = loadLevel(fileName,maxRow,maxCol,player);
    int b = 0;
    if(a == 'a'){
        map = resizeMap(map,maxRow,maxCol);    
    }else{
        map = resizeMap(map,b,maxCol);    
    }
    deleteMap(map,maxRow);
    // if (map) {
    //     for (int row = 0; row < maxRow; row++) {
    //         delete[] map[row];
    //     }
    //     delete[] map;
    // }
}
void testDoPlayerMove(const std::string& fileName,const char& input,int& maxRow,int& maxCol,Player player){
    char** map = loadLevel(fileName,maxRow,maxCol,player);
    int nextRow;
    int nextCol;
    player.treasure = 1;
    getDirection(input,nextRow,nextCol);
    doPlayerMove(map,maxRow,maxCol,player,nextRow,nextCol);
    deleteMap(map,maxRow);
    if (map) {
        for (int row = 0; row < maxRow; row++) {
            delete[] map[row];
        }
        delete[] map;
    }
}
void testDoMonsterAttack(const std::string& fileName,const char& input,int& maxRow,int& maxCol,Player player){
    char** map = loadLevel(fileName,maxRow,maxCol,player);
    int nextRow;
    int nextCol;
    getDirection(input,nextRow,nextCol);
    doPlayerMove(map,maxRow,maxCol,player,nextRow,nextCol);
    doMonsterAttack(map,maxRow,maxCol,player);
    deleteMap(map,maxRow);
    if (map) {
        for (int row = 0; row < maxRow; row++) {
            delete[] map[row];
        }
        delete[] map;
    }
}

// void testResizeMaprow(const std::string& fileName,int& maxRow,int& maxCol,Player player){
//     char** map = loadLevel(fileName,maxRow,maxCol,player);
//     int a = 0;
//     map = resizeMap(map,a,maxCol);    
//     deleteMap(map,maxRow);
//     if (map) {
//         for (int row = 0; row < maxRow; row++) {
//             delete[] map[row];
//         }
//         delete[] map;
//     }
// }
// void a(){
//     char** map;
//     map = new char*[10];
//     for(int i=0;i<10;i++){
//         map[i] = new char[0];
//     }
//     for(int i=0;i<10;i++){
//         map[i][0] = '-';
        
//     }
//     int maxRow =0;
//     deleteMap(map,maxRow);
//     maxRow =10;
//     deleteMap(map,maxRow);
//     // if (map) {
//     //     for (int row = 0; row < 10; row++) {
//     //         delete[] map[row];
//     //     }
//     //     delete[] map;
//     // }
// }

int main() {
    
    // example
    /*testDoPlayerMove
    - + -
    - + !
    - - -
    @ - $
    */
    ////////////////////
    // this is the only code _required_ to get coverage points on part 1 (test first)
    //   invocation --> coverage
    int maxRow;
    int maxCol;
    Player player;
    
    ////////////////////
    cannotOpen(maxRow,maxCol,player);

    //Testing loadLevel
    testLoadlevel("loadlevel1.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel2.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel3.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel4.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel5.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel6.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel7.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel8.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel9.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel10.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel11.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel12.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel13.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel14.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel15.txt",maxRow,maxCol,player);
    testLoadlevel("loadlevel16.txt",maxRow,maxCol,player);


    //Testing getDirection
    int nextRow;
    int nextCol;
    testGetdirection('w',nextRow,nextCol);
    testGetdirection('-',nextRow,nextCol);
    testGetdirection(' ',nextRow,nextCol);
    testGetdirection('5',nextRow,nextCol);
    testGetdirection('t',nextRow,nextCol);
    testGetdirection('T',nextRow,nextCol);

    //Testing deleteMap
    testDeleteMap("example.txt",maxRow,maxCol,player);
    testDeleteMap("ha.txt",maxRow,maxCol,player);

    //Testing ResizedMap
    testResizeMap("example.txt",maxRow,maxCol,player,'a');
    testResizeMap("hahaa.txt",maxRow,maxCol,player,'a');
    testResizeMap("example.txt",maxRow,maxCol,player,'a');
    //testResizeMap("example.txt",maxRow,maxCol,player,'b');

    //Testing doPlayerMove
    testDoPlayerMove("example.txt",'w',maxRow,maxCol,player);
    testDoPlayerMove("test.txt",'s',maxRow,maxCol,player);
    testDoPlayerMove("move1.txt",'d',maxRow,maxCol,player);
    testDoPlayerMove("move1.txt",'a',maxRow,maxCol,player);
    // testDoPlayerMove("test.txt",'d',maxRow,maxCol,player);
    // testDoPlayerMove("test.txt",'a',maxRow,maxCol,player);
    // testDoPlayerMove("move1.txt",'w',maxRow,maxCol,player);
    // testDoPlayerMove("move1.txt",'s',maxRow,maxCol,player);

    //Testing doMonsterAttack
    testDoMonsterAttack("example.txt",'w',maxRow,maxCol,player);
    testDoMonsterAttack("test.txt",'w',maxRow,maxCol,player);
    testDoMonsterAttack("monster1.txt",'w',maxRow,maxCol,player);
    testDoMonsterAttack("monster2.txt",'w',maxRow,maxCol,player);
    testDoMonsterAttack("monster3.txt",'w',maxRow,maxCol,player);
    
    ////////////////////
    char** level = loadLevel("example.txt", maxRow, maxCol, player);
    // this is optional but STRONGLY recommended for preparing for part 2 (development)
    //   coverage -/-> correctness
    // note: there are _many_ ways to do this part, including ways that are more elegant and efficient than this way demonstrated here
    if (level == nullptr) {
        cout << "FAIL: level is nullptr" << endl;
    } else {
        cout << " OK : level is not nullptr" << endl;
        if (maxRow == 5) {
            cout << " OK : maxRow is 5" << endl;
        } else {
            cout << "FAIL: expected maxRow to be 5, got " << maxRow << endl; 
        }
        if (maxCol == 3) {
            cout << " OK : maxCol is 3" << endl;
        } else {
            cout << "FAIL: expected maxCol to be 3, got " << maxCol << endl; 
        }
        if (player.row == 3) {
            cout << " OK : player.row is 3" << endl;
        } else {
            cout << "FAIL: expected player.row to be 3, got " << player.row << endl; 
        }
        if (player.col == 0) {
            cout << " OK : player.col is 0" << endl;
        } else {
            cout << "FAIL: expected player.col to be 0, got " << player.col << endl; 
        }
        if (level[0][0] == 'M') {
            cout << " OK : level[0][0] is M" << endl;
        } else {
            cout << "FAIL: expected level[0][0] to be M, got " << level[0][0] << endl; 
        }
        if (level[0][1] == '+') {
            cout << " OK : level[0][1] is +" << endl;
        } else {
            cout << "FAIL: expected level[0][1] to be +, got " << level[0][1] << endl; 
        }
        if (level[0][2] == '-') {
            cout << " OK : level[0][2] is -" << endl;
        } else {
            cout << "FAIL: expected level[0][2] to be -, got " << level[0][2] << endl; 
        }
        if (level[1][0] == '-') {
            cout << " OK : level[1][0] is -" << endl;
        } else {
            cout << "FAIL: expected level[1][0] to be -, got " << level[1][0] << endl; 
        }
        if (level[1][1] == '+') {
            cout << " OK : level[1][1] is +" << endl;
        } else {
            cout << "FAIL: expected level[1][1] to be +, got " << level[1][1] << endl; 
        }
        if (level[1][2] == '-') {
            cout << " OK : level[1][2] is -" << endl;
        } else {
            cout << "FAIL: expected level[1][2] to be -, got " << level[1][2] << endl; 
        }
        if (level[2][0] == '-') {
            cout << " OK : level[2][0] is -" << endl;
        } else {
            cout << "FAIL: expected level[2][0] to be -, got " << level[2][0] << endl; 
        }
        if (level[2][1] == '+') {
            cout << " OK : level[2][1] is +" << endl;
        } else {
            cout << "FAIL: expected level[2][1] to be +, got " << level[2][1] << endl; 
        }
        if (level[2][2] == '!') {
            cout << " OK : level[2][2] is !" << endl;
        } else {
            cout << "FAIL: expected level[2][2] to be !, got " << level[2][2] << endl; 
        }
        if (level[3][0] == 'o') {
            cout << " OK : level[3][0] is o" << endl;
        } else {
            cout << "FAIL: expected level[3][0] to be o, got " << level[3][0] << endl; 
        }
        if (level[3][1] == '-') {
            cout << " OK : level[3][1] is -" << endl;
        } else {
            cout << "FAIL: expected level[3][1] to be -, got " << level[3][1] << endl; 
        }
        if (level[3][2] == '-') {
            cout << " OK : level[3][2] is -" << endl;
        } else {
            cout << "FAIL: expected level[3][2] to be -, got " << level[3][2] << endl; 
        }
        if (level[4][0] == '@') {
            cout << " OK : level[4][0] is @" << endl;
        } else {
            cout << "FAIL: expected level[4][0] to be @, got " << level[4][0] << endl; 
        }
        if (level[4][1] == '-') {
            cout << " OK : level[4][1] is -" << endl;
        } else {
            cout << "FAIL: expected level[4][1] to be -, got " << level[4][1] << endl; 
        }
        if (level[4][2] == '$') {
            cout << " OK : level[4][2] is $" << endl;
        } else {
            cout << "FAIL: expected level[4][2] to be $, got " << level[4][2] << endl; 
        }
    }
    ////////////////////
    
    ////////////////////
    // this is required to prevent memory leaks on part 1 (test first)
    if (level) {
        for (int row = 0; row < 5; row++) {
            delete[] level[row];
        }
        delete[] level;
    }
    ////////////////////
    
    return 0;
}
