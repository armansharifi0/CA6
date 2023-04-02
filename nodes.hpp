#ifndef __NODES_HPP__
#define __NODES_HPP__

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class not_defined_exception {};

class Node
{
public:
    Node(int i) : index(i),output(0) {}
    virtual void operation();
    virtual void edge_maker();
    int get_output() { return output; }
    int return_index() { return index; }
protected:
    int output;
    int index;
    vector<Node*> edges; 
};



class AND : public Node
{
public:
    AND(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};

class OR : public Node
{
public:
    OR(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};

class NOT : public Node
{
public:
    NOT(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};


class XOR : public Node
{
public:
    XOR(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};

class BAND : public Node
{
public:
    BAND(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};

class BOR : public Node
{
public:
    BOR(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};

class BNOT : public Node
{
public:
    BNOT(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};

class BXOR : public Node
{
public:
    BXOR(int i) : Node(i) {}
    virtual void operation();
    virtual void edge_maker(Node* n);
};


vector<vector<int>> int_to_bit(vector<int>& operands);

int bit_to_int (vector<int> output);



#endif