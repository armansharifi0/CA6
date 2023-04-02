#ifndef __TREE_HPP__
#define __TREE_HPP__

#include "numbers.hpp"

class tree
{
public:
    void add_node(Node n);
    string evaluate(char base);
private:
    vector<Node*> nodes;
};







#endif