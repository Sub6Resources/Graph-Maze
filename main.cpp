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

    int x, y;
    std::cout << "Enter x-coordinate of target location: ";
    std::cin >> x;
    std::cout << "Enter y-coordinate of target location: ";
    std::cin >> y;
    std::cout << std::endl;

    maze.setTargetLocation(x, y);

    std::cout << "Maze w/ target location: " << std::endl;
    std::cout << maze << std::endl;

    std::cout << "Enter x-coordinate of start location: ";
    std::cin >> x;
    std::cout << "Enter y-coordinate of start location: ";
    std::cin >> y;
    std::cout << std::endl;

    maze.setStartLocation(x, y);

    std::cout << "Maze w/ start location: " << std::endl;
    std::cout << maze << std::endl;

    std::cin >> x;

    maze.generateShortestPath();

    std::cout << "Solved maze: " << std::endl;
    std::cout << maze << std::endl;

    delete[] newMazeData;

    return 0;
}