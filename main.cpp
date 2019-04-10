#include <iostream>
#include <fstream>

const int MAZE_SIZE_BYTES = 8;
const int MAZE_WIDTH = 4;

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::ifstream mazeFile;
    mazeFile.open("small.maze");
    char *maze = new char[MAZE_SIZE_BYTES];
    mazeFile >> *maze;
    for (int i = 0; i < MAZE_SIZE_BYTES; ++i) {
        std::cout << maze[i];
    }


    return 0;
}