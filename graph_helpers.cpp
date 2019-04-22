//
// Created by Matthew Whitaker on 2019-04-22.
//

#ifndef GRAPH_MAZE_HELPERS
#define GRAPH_MAZE_HELPERS

#include <iostream>
#include <queue>
#include "graph.h"

template<class Process, class Item, class SizeType>
void depth_first(Process f, graph<Item> &g, SizeType start);
// Precondition: start is a vertex number of the labeled graph g
// Postcondition: A depth-first search of g has been executed, starting at
// the start vertex. The function f has been applied to the label of each
// vertex visited by the search.


template<class Process, class Item, class SizeType>
void rec_dfs(Process f, graph<Item> &g, SizeType v, bool marked[]);
//Precondition: g is a labeled graph that is being traversed by a depth-
// first search. For each vertex x, marked[x] is true if x has already been
// visited by this search; otherwise marked[x] is false. The vertex v is an
// unmarked vertex that the search has just arrived at.
//Postcondition: The depth-first search of g has been continued through vertex v and beyond
// to all the vertices that can be reached from v via a path of unmarked vertices. The function
// f has been applied to the label of each vertex visited by the search, and each such vertex x
// has also been marked by setting marked[x] to true.
//Library facilities used: cstdlib, graph.h, set

template<class Process, class Item, class SizeType>
void breadth_first(Process f, graph<Item> &g, SizeType start);
//Same as the depth_first function, but using a breadth-first search instead
//Library facilities used: algorithm, cassert, cstdlib, graph.h, queue

template<class Item, class SizeType>
int *shortest_path(graph<Item> &g, SizeType start);

template<class Process, class Item, class SizeType>
void depth_first(Process f, graph<Item> &g, SizeType start) {
    bool marked[g.MAXIMUM];

    //Check that the start vertex is a valid vertex on the graph.
    assert(start < g.size());

    //Set all the components of marked to false.
    std::fill_n(marked, g.size(), false);

    //Call a separate function to carry out the search.
    rec_dfs(f, g, start, marked);
}

template<class Process, class Item, class SizeType>
void rec_dfs(Process f, graph<Item> &g, SizeType v, bool marked[]) {
    std::set<std::size_t> connections = g.neighbors(v);
    std::set<std::size_t>::iterator it;

    marked[v] = true;   //Mark vertex v.
    f(g[v]);            //Process the label of vertex v with the function f.

    //Traverse all the neighbors, looking for unmarked vertices:
    for (it = connections.begin(); it != connections.end(); ++it) {
        if (!marked[*it])
            rec_dfs(f, g, *it, marked);
    }
}

template<class Process, class Item, class SizeType>
void breadth_first(Process f, graph<Item> &g, SizeType start) {
    bool marked[g.MAXIMUM];
    std::set<std::size_t> connections;
    std::set<std::size_t>::iterator it;
    std::queue<std::size_t> vertex_queue;

    assert(start < g.size());

    std::fill_n(marked, g.size(), false);

    marked[start] = true;
    f(g[start]);
    vertex_queue.push(start);
    do {
        connections = g.neighbors(vertex_queue.front());
        vertex_queue.pop();
        //Mark and process the unmarked neighbors, and place them in the queue.
        for (it = connections.begin(); it != connections.end(); ++it) {
            if (!marked[*it]) {
                marked[*it] = true;
                f(g[*it]);
                vertex_queue.push(*it);
            }
        }
    } while (!vertex_queue.empty());
}

template<class Item, class SizeType>
int* shortest_path(graph<Item> &g, SizeType start) {
    int *distance = new int[g.size()];
    int *predecessors = new int[g.size()];

    assert(start < g.size());


    std::fill_n(distance, g.size(), INT32_MAX);

    distance[start] = 0;

    std::set<SizeType> allowed_vertices = std::set<SizeType>();

    //Step 3
    for (int allowed_size = 1; allowed_size <= g.size(); ++allowed_size) {
        //3a. Find the nearest neighbor to the start vertex
        SizeType next;
        int minDistance = INT32_MAX;

        //Loop to determine minimum distance.
        for (int i = 0; i < g.size(); ++i) {
            if (allowed_vertices.find(i) == allowed_vertices.end() && distance[i] <= minDistance) {
                std::cout << "New min: " << distance[i] << std::endl;
                next = i;
                minDistance = distance[i];
            }
        }

        //3b. Add the nearest neighbor to the set of allowed vertices
        if (minDistance != INT32_MAX) {
            allowed_vertices.insert(next);
        }

        //3c. Update the distance array to include paths that contain the newly added vertex.
        int sumDistance = 0;
        for (SizeType v = 0; v < g.size(); ++v) {
            if (allowed_vertices.find(v) == allowed_vertices.end() && g.is_edge(next, v)) {
                sumDistance = distance[next] + g.edge_weight(next, v);
                if (sumDistance < distance[v]) {
                    distance[v] = sumDistance;
                    predecessors[v] = next;
                }
            }
        }
    }

    return distance;
}

#endif
