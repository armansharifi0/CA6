#ifndef __TREE_HPP__
#define __TREE_HPP__

#include "numbers.hpp"

class tree
{
public:
    void add_node(Node* n);
    void evaluate(char base);
    vector<Node*>& get_nodes() { return nodes; }
private:
    vector<Node*> nodes;
};







#endif