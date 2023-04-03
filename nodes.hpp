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
    Node(int i, string n) : index(i), name(n) {}
    virtual int operation();
    virtual void edge_maker();
    int return_index() { return index; }
    string return_name() { return name; }
    virtual string get_value();
    virtual void set_value(string v);
protected:
    string value;
    string name;
    int index;
    vector<Node*> edges; 
};



class AND : public Node
{
public:
    AND(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};

class OR : public Node
{
public:
    OR(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};

class NOT : public Node
{
public:
    NOT(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};


class XOR : public Node
{
public:
    XOR(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};

class BAND : public Node
{
public:
    BAND(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};

class BOR : public Node
{
public:
    BOR(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};

class BNOT : public Node
{
public:
    BNOT(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};

class BXOR : public Node
{
public:
    BXOR(int i, string n) : Node(i , n) {}
    virtual int operation();
    virtual void edge_maker(Node* n);
};


vector<vector<int>> int_to_bit(vector<int>& operands);

int bit_to_int (vector<int> output);



#endif