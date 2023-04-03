#ifndef __NUMBERS_HPP__
#define __NUMBERS_HPP__

#include "nodes.hpp"


class NUM : public Node
{
public:
    NUM (int i, string v , string n) : Node(i, n) { value = v; }
    virtual void operation() = 0;
    virtual void edge_maker(Node* n);
    string get_value() { return value; }

};


class deci : public NUM
{
public:
    deci(int i, string v, string n) : NUM(i, v, n) {}
    virtual void operation();
};

class hexa : public NUM
{
public:
    hexa(int i, string v, string n) : NUM(i, v, n) {}
    virtual void operation();
};

class octa : public NUM
{
public:
    octa(int i, string v, string n) : NUM(i, v, n) {}
    virtual void operation();
};

class bina : public NUM
{
public:
    bina(int i, string v, string n) : NUM(i, v, n) {}
    virtual void operation();
};


#endif