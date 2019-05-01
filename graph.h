//
// Created by 59485 on 3/5/19.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <cstdlib>
#include <set>

template<class Item>
class graph {
public:
    //Member Constants
    static const std::size_t MAXIMUM = 4096;

    //Constructor
    graph() { many_vertices = 0; }

    //Modification memeber functions
    void add_vertex(const Item &label);

    void add_edge(std::size_t source, std::size_t target);

    void remove_edge(std::size_t source, std::size_t target);

    Item &operator[](std::size_t vertex);

    //Constant Member Functions
    std::size_t size() const { return many_vertices; }

    bool is_edge(std::size_t source, std::size_t target) const;

    std::set<std::size_t> neighbors(std::size_t vertex) const;

    Item operator[](std::size_t vertex) const;

private:
//    int edges[MAXIMUM][MAXIMUM];
    bool edges[MAXIMUM][MAXIMUM];
    Item labels[MAXIMUM];
    std::size_t many_vertices;
};

#include "graph.template"

#endif //GRAPH_GRAPH_H
