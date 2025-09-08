#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

//Tetrominos starts here
vector <vector<char>> tet_O = {
	{'0','0','0','0'},
	{'0','1','1','0'},
	{'0','1','1','0'},
	{'0','0','0','0'}
};

vector <vector<char>> tet_I = {
    {'0','0','1','0'},
    {'0','0','1','0'},
    {'0','0','1','0'},
    {'0','0','1','0'}
};

vector <vector<char>> tet_L = {
    {'0','0','1','0'},
    {'0','0','1','0'},
    {'0','0','1','0'},
    {'0','0','1','1'}
};

class GameScreen
{
private:
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

    vector<vector<char>> modifyScreen(vector<vector<char>> screen, vector<vector<char>> tetronimo, int pos_x, int pos_y){
        vector<vector<char>> modifiedScreen = screen;
        for (int i = 0; i < tetronimo.size(); i++){
            for (int j = 0; j < tetronimo[i].size(); j++){
               if (tetronimo[i][j] != '0'){
                     modifiedScreen[pos_x + i][pos_y + j] = tetronimo[i][j]; // Changed screen to modifiedScreen
                }
            }
        }
    return modifiedScreen; // Return the modified copy
}
};

int main(){
    GameScreen myScreen;
    vector<vector<char>> newScreen = myScreen.gameScreen(10, 25, '*');
    myScreen.printScreen(newScreen);

    newScreen = myScreen.modifyScreen(newScreen, tet_L, 1, 1);
    myScreen.printScreen(newScreen);

    return 0;
};
