//
// Created by Matthew Whitaker on 2019-04-10.
//

#ifndef GRAPH_MAZE_MAZE_H
#define GRAPH_MAZE_MAZE_H


#include <string>

class Maze {
public:
    Maze();
    std::string printMaze();
private:
    char* mazeData;
};


#endif //GRAPH_MAZE_MAZE_H
