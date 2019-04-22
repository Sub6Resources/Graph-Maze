//
// Created by Matthew Whitaker on 2019-04-10.
//

#include "maze.h"

Maze::Maze(int _mazeWidth, int _mazeBytes, char *_mazeData) {
    mazeWidth = _mazeWidth;
    mazeBytes = _mazeBytes;
    mazeData = _mazeData;
    maze = new graph<int>();
    generateMazeGraph();
}

void Maze::generateMazeGraph() {

    for (int i = 0; i < (mazeBytes * 2); ++i) {
        maze->add_vertex(i);
    }

    int numRows = mazeBytes / (mazeWidth / 2);
    for (int y = 0; y < numRows; ++y) {
        for (int x = 0; x < mazeWidth; ++x) {
            int index = (mazeWidth * y + x);
            unsigned char mazeSquare = mazeData[index / 2];
            if(index % 2 == 0) {
                mazeSquare = mazeSquare >> 4;
            }

            //Bottom
            if((mazeSquare & 8) != 0) {
                if(coords(x, y+1) < maze->size())
                    maze->add_edge(coords(x, y), coords(x, y + 1));
            }

            //Left
            if((mazeSquare & 4) != 0) {
                if(x-1 >= 0)
                    maze->add_edge(coords(x, y), coords(x - 1, y));
            }

            //Top
            if((mazeSquare & 2) != 0) {
                if(y-1 >= 0)
                    maze->add_edge(coords(x, y), coords(x, y - 1));
            }

            //Right
            if((mazeSquare & 1) != 0) {
                if(x + 1 < mazeWidth)
                    maze->add_edge(coords(x, y), coords(x + 1, y));
            }
        }
    }
}

/**
 * Calculates one-dimensional coordinate from an x and a y position in the maze.
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 * @return An integer with the index of the point in a one-dimensional array.
 */
int Maze::coords(int x, int y) {
    return (y * mazeWidth) + x;
}
