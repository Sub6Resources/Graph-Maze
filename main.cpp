#include <fstream>
#include "maze.h"

const int MAZE_SIZE_BYTES = 8; //Size of the .maze file
const int MAZE_WIDTH = 4; //Width of the maze

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::ifstream mazeFile;
    mazeFile.open("small.maze");
    char *newMazeData = new char[MAZE_SIZE_BYTES];
    mazeFile >> *newMazeData;
    mazeFile.close();


    Maze maze = Maze(MAZE_WIDTH, MAZE_SIZE_BYTES, newMazeData);

    std::cout << "Maze: " << std::endl;
    std::cout << maze << std::endl;


    return 0;
}