//
// Created by Matthew Whitaker on 2019-04-10.
//

#ifndef GRAPH_MAZE_MAZE_H
#define GRAPH_MAZE_MAZE_H

#include <iostream>
#include "graph.h"
#include "graph_helpers.cpp"

class Maze {
public:
    Maze(int _mazeWidth, int _mazeBytes, char* _mazeData);
    friend std::ostream &operator<<(std::ostream &out, Maze &maze);
    void setTargetLocation(int x, int y);
    void setStartLocation(int x, int y);
    void generateShortestPath();
    bool inShortestPath(int index);
private:
    graph<int>* maze;
    char* mazeData;
    int mazeWidth;
    int mazeBytes;
    int targetLocation;
    int startLocation;
    int* shortestPath;
    int shortestPathLength;
    void generateMazeGraph();
    int coords(int x, int y);
};

inline std::ostream &operator<<(std::ostream &out, Maze &maze) {
    int numRows = maze.mazeBytes / (maze.mazeWidth / 2);

    for (int y = 0; y < numRows; ++y) {
        //Top of row
        for (int x = 0; x < maze.mazeWidth; ++x) {
            int index = (maze.mazeWidth * y + x);
            unsigned char mazeSquare = maze.mazeData[index / 2];
            if(index % 2 == 0) {
                mazeSquare = mazeSquare >> 4;
            }
            out << "█";

            if((mazeSquare & 2) == 2) {
                if(maze.inShortestPath(maze.coords(x, y - 1)) && maze.inShortestPath(index))
                    out << "•";
                else
                    out << " ";
            } else {
                out << "█";
            }

            //Print right wall if on last column
            if(x == maze.mazeWidth - 1) {
                out << "█";
            }
        }
        out << '\n';

        //Middle of row
        for (int x = 0; x < maze.mazeWidth; ++x) {
            int index = maze.coords(x, y);
            unsigned char mazeSquare = maze.mazeData[index / 2];
            if(index % 2 == 0) {
                mazeSquare = mazeSquare >> 4;
            }

            //Print left wall
            if((mazeSquare & 4) == 4) {
                if(maze.inShortestPath(maze.coords(x - 1, y)) && maze.inShortestPath(index))
                    out << "•";
                else
                    out << " ";
            } else {
                out << "█";
            }

            if(maze.targetLocation == index) {
                out << "X";
            } else if(maze.startLocation == index) {
                out << "O";
            } else if(maze.inShortestPath(index)) {
                out << "•";
            } else {
                out << ".";
            }

            //Print right wall if on last column
            if(x == maze.mazeWidth - 1) {
                if((mazeSquare & 1) == 1) {
                    out << ".";
                } else {
                    out << "█";
                }
            }
        }
        out << '\n';

        //If this is the last row, print the bottom wall.
        if(y == (numRows - 1)) {
            //Bottom of row
            for (int x = 0; x < maze.mazeWidth; ++x) {
                int index = (maze.mazeWidth * y + x);
                unsigned char mazeSquare = maze.mazeData[index / 2];
                if(index % 2 == 0) {
                    mazeSquare = mazeSquare >> 4;
                }
                out << "█";

                if((mazeSquare & 8) == 8) {
                    out << " ";
                } else {
                    out << "█";
                }

                //Print right wall if on last column
                if(x == maze.mazeWidth - 1) {
                    out << "█";
                }
            }
            out << '\n';
        }
    }

    return out;
}


#endif //GRAPH_MAZE_MAZE_H
