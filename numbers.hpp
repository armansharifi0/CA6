#ifndef __NUMBERS_HPP__
#define __NUMBERS_HPP__

#include "nodes.hpp"


class NUM : public Node
{
public:
    NUM (int i, string v) : Node(i), value(v) {}
    virtual void operation() = 0;
    virtual void edge_maker(Node* n);
protected:
    string value;
};


class dec : public NUM
{
public:
    dec(int i, string v) : NUM(i, v) {}
    virtual void operation();
};

class hex : public NUM
{
public:
    hex(int i, string v) : NUM(i, v) {}
    virtual void operation();
};

class oct : public NUM
{
public:
    oct(int i, string v) : NUM(i, v) {}
    virtual void operation();
};

class bin : public NUM
{
public:
    bin(int i, string v) : NUM(i, v) {}
    virtual void operation();
};


#endif