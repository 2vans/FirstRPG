#include <iostream>
#include "MainClass.h"
using namespace std;


int main(int argc, char* argv[]) {

	MainClass mainClass(800, 600);

	mainClass.gameLoop();


	return 0;
}
