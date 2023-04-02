#include "numbers.hpp"
#include <cmath>

void NUM::edge_maker(Node* n)
{
    edges.push_back(n);
}


void dec::operation()
{
    output = stoi(value);
}

void hex::operation()
{
    int size = value.size();
    int j = 0;
    for (int i = size - 1 ; i >= 0; i--)
    {
        if ((value[i] - '0') < 10)
            output += (value[i] - '0') * pow(16 , j);
        else if (value[i] == 'a')
            output += 10 * pow(16 , j);
        else if (value[i] == 'b')
            output += 11 * pow(16 , j);
        else if (value[i] == 'c')
            output += 12 * pow(16 , j);
        else if (value[i] == 'd')
            output += 13 * pow(16 , j);
        else if (value[i] == 'e')
            output += 14 * pow(16 , j);
        else if (value[i] == 'f')
            output += 15 * pow(16 , j);
        j++;
    }
}

void oct::operation()
{
    int size = value.size();
    int j = 0;
    for (int i = size - 1 ; i >= 0; i--)
    {
        if ((value[i] - '0') < 10)
            output += (value[i] - '0') * pow(8 , j);
        j++;
    }
}

void bin::operation()
{
    int size = value.size();
    int j = 0;
    for (int i = size - 1 ; i >= 0; i--)
    {
        if ((value[i] - '0') < 10)
            output += (value[i] - '0') * pow(2 , j);
        j++;
    }
}
