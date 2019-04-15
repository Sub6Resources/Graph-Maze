#include <fstream>
#include <vector>
#include "maze.h"

const int MAZE_SIZE_BYTES = 8; //Size of the .maze file
const int MAZE_WIDTH = 4; //Width of the maze

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::ifstream mazeFile("../small.maze", std::ifstream::binary);

    char *newMazeData = new char[MAZE_SIZE_BYTES];
    mazeFile.read(newMazeData, MAZE_SIZE_BYTES);
    mazeFile.close();


    Maze maze = Maze(MAZE_WIDTH, MAZE_SIZE_BYTES, newMazeData);

    std::cout << "Maze: " << std::endl;
    std::cout << maze << std::endl;

    delete[] newMazeData;

    return 0;
}