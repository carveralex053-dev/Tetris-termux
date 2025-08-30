#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void printGameScreen(int x, int y, char fill){
	vector <vector<char>> gameScreen;//(rows, vector <char>(cols, fill));

	for (int i = 0; i < x; i++){
		for (int j = 0; j < y; j++){
			gameScreen[i][j] = fill;
			cout << gameScreen[i][j];
		}
	cout << endl;
	}
};

int main(){
	printGameScreen(50, 20, '.');

	return 0;
}
