#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>

using namespace std;

//Tetrominos starts here
vector<vector<char>> tet_O = {
    {'1','1','0'},
    {'1','1','0'},
    {'0','0','0'}
};

vector<vector<char>> tet_L = {
    {'0','0','1'},
    {'0','0','1'},
    {'0','1','1'}
};

vector<vector<char>> tet_L_reverse = {
    {'1','0','0'},
    {'1','0','0'},
    {'1','1','0'}
};

vector<vector<char>> tet_T = {
    {'0','0','0'},
    {'0','1','0'},
    {'1','1','1'}
};

vector<vector<char>> tet_I = {
    {'0','0','1'},
    {'0','0','1'},
    {'0','0','1'}
};

vector<vector<char>> tet_z = {
    {'0','0','0'},
    {'1','1','0'},
    {'0','1','1'}
};

vector<vector<char>> tet_z_reverse = {
    {'0','0','0'},
    {'0','1','1'},
    {'1','1','0'}
};

vector<vector<vector<char>>> tetronimos = {tet_O, tet_z, tet_z_reverse, tet_L, tet_L_reverse, tet_I, tet_T};

class GameScreen
{
private:
    char figureChar = '+';
public:
    vector<vector<char>> gameScreen(int rows, int cols, char fill) {
        vector<vector<char>> finalScreen(rows, vector<char>(cols, fill));

        return finalScreen;
    }
    
    void printScreen(vector<vector<char>> screen) {
        for (int i = 0; i < screen.size(); i++) {
            for (int j = 0; j < screen[i].size(); j++) {
                cout << screen[i][j];
            }
            cout << endl;
        }
    }

    vector<vector<char>>  clearScreen(vector<vector<char>> screen, char fill='.'){
        for (int i = 0; i < screen.size(); i++){
            for (int j = 0; j < screen[i].size(); j++){
                screen[i][j] = fill;
            }
        }

        return screen;
    };

    vector<vector<char>> modifyScreen(vector<vector<char>> screen, vector<vector<char>> tetronimo, int pos_x, int pos_y){
        vector<vector<char>> modifiedScreen = screen;
        for (int i = 0; i < tetronimo.size(); i++){
            for (int j = 0; j < tetronimo[i].size(); j++){
               if (tetronimo[i][j] != '0'){
                     modifiedScreen[pos_x + i][pos_y + j] = figureChar; // Changed screen to modifiedScreen
                }
            }
        }
    return modifiedScreen; // Return the modified copy
}
};

int main(){
    system("clear");

    GameScreen myScreen;
    vector<vector<char>> newScreen = myScreen.gameScreen(10, 25, '.');
//    myScreen.printScreen(newScreen);
    for (int i = 0; i < tetronimos.size(); i++){
        newScreen = myScreen.modifyScreen(newScreen, tetronimos[i], 1, 1);
        myScreen.printScreen(newScreen);
        this_thread::sleep_for(chrono::seconds(1));
        newScreen = myScreen.clearScreen(newScreen);
        myScreen.printScreen(newScreen);
        system("clear");
    };
    return 0;
};
