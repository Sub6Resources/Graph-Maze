//
// Created by Matthew Whitaker on 2019-04-10.
//

#ifndef GRAPH_MAZE_MAZE_H
#define GRAPH_MAZE_MAZE_H

#include <iostream>

class Maze {
public:
    Maze(int _mazeWidth, int _mazeBytes, char* _mazeData);
    friend std::ostream &operator<<(std::ostream &out, Maze &maze);
private:
    char* mazeData;
    int mazeWidth;
    int mazeBytes;
};

inline std::ostream &operator<<(std::ostream &out, Maze &maze) {
    int numRows = maze.mazeBytes / (maze.mazeWidth / 2);

    for (int y = 0; y < numRows; ++y) {
        //Top of row
        for (int x = 0; x <maze.mazeWidth; ++x) {
            char mazeSquare = maze.mazeData[(maze.mazeWidth * y + x / 2)];
            out << "#";

            out << " ";

            //Print right wall if on last column
            if(x == maze.mazeWidth - 1) {
                out << "#";
            }
        }
        out << '\n';

        //Middle of row
        for (int x = 0; x < maze.mazeWidth; ++x) {
            char mazeSquare = maze.mazeData[(maze.mazeWidth * y + x / 2)];
            out << " ";

            out << mazeSquare;

            //Print right wall if on last column
            if(x == maze.mazeWidth - 1) {
                out << " ";
            }
        }
        out << '\n';

        //If this is the last row, print the bottom wall.
        if(y == (numRows - 1)) {
            //Bottom of row
            for (int x = 0; x < maze.mazeWidth; ++x) {
                char mazeSquare = maze.mazeData[(maze.mazeWidth * y + x / 2)];
                out << "# ";

                //Print right wall if on last column
                if(x == maze.mazeWidth - 1) {
                    out << "#";
                }
            }
            out << '\n';
        }
    }

    return out;
}


#endif //GRAPH_MAZE_MAZE_H
