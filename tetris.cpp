#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

using namespace std;

void printGameScreen(int rows, int cols, char fill){
	vector <vector<char>> gameScreen(rows, vector <char>(cols, fill));

	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			gameScreen[i][j] = fill;
			cout << gameScreen[i][j];
		}
	cout << endl;
	}
};

int main(){
	printGameScreen(20, 50, '.');

	return 0;
}
