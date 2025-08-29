#include <iostream>
#include <thread>
#include <chrono>

class GameScreen{
	private:
		const int screen_x = 50;
		const int screen_y = 20;
	public:
		char gameScreen[screen_x][screen_u];
		void PrintGameScreen(){
			for (int x = 0; x < screen_x; x++){
				for (int y = 0; y < screen_y; y++){
					gameScreen[x][y] = '.';
				}
			}
		}
}

int main(){
	std::cout << "Hello World" << std::endl;

	return 0;
}
