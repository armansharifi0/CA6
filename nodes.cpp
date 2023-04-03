#include "nodes.hpp"
#include <cmath>
#include <algorithm>

vector<vector<int>> int_to_bit(vector<int>& operands)
{
    int number = *(max_element(begin(operands),end(operands)));
    int number2 = 0;
    int power = 0;
    while (number2 >= 0)
    {
        number2 = number - pow(2, power);
        power++;
    }
    power--;

    vector<vector<int>> bitwise_operands;
    for (int j = 0; j < operands.size(); j++)
    {
        vector<int> element;
        for (int i = power; i >= 0; i--)
        {
            number = number - pow(2, i);
            if (number > 0)
            {
                element.push_back(1);
            }else
            {
                element.push_back(0);
                number = number + pow(2, i);
            }
        }
        bitwise_operands.push_back(element);
    }
    return bitwise_operands;
}

int bit_to_int (vector<int> output)
{
    int size = output.size();
    int number = 0;
    for (int i = 0; i < size; i++)
    {
        number += output[i] * pow(2, size - i);
    }
    return number;
}

int Node::operation()
{
    throw not_defined_exception();

    try {

    }catch (not_defined_exception ex) {
        cerr << "Operation is not defined" << endl;
    }

}

void Node::edge_maker()
{
    throw not_defined_exception();

    try {

    }catch (not_defined_exception ex) {
        cerr << "Operation is not defined" << endl;
    }

}

string Node::get_value()
{
    throw not_defined_exception();

    try {

    }catch (not_defined_exception ex) {
        cerr << "Operation is not defined" << endl;
    }

}

void Node::set_value(string v)
{
    value = v;
}

void AND::edge_maker(Node* n)
{
    edges.push_back(n);
}

int AND::operation()
{
    int output = 0;
    for (int i = 0; i < 2 ; i++)
    {
        output *= edges[i]->operation();
    }
    return output;
}

void OR::edge_maker(Node* n)
{
    edges.push_back(n);
}

int OR::operation()
{
    int output = 0;
    for (int i = 0; i < 2 ; i++)
    {
        output += edges[i]->operation();
    }
    return output;
}

void NOT::edge_maker(Node* n)
{
    edges.push_back(n);
}

int NOT::operation()
{
    int output = 0;
    output = -edges[0]->operation();
    return output;

}

void XOR::edge_maker(Node* n)
{
    edges.push_back(n);
}

int XOR::operation()
{
    vector<int> nodes_output;
    for (int i = 0; i < edges.size() ; i++)
    {
        nodes_output.push_back(edges[i]->operation());
    }
    sort(nodes_output.begin(), nodes_output.end());

    int nsize = nodes_output.size();
    int output = 0;
    if (nsize % 2 == 1)
    {
        output = nodes_output[(nsize + 1)/2];
    }else
    {
        output = (nodes_output[nsize/2] + nodes_output[(nsize + 1)/2]) / 2;
    }
    return output;
}

void BAND::edge_maker(Node* n)
{
    edges.push_back(n);
}

int BAND::operation()
{
    vector<vector<int>> bitwise;
    vector<int> nodes_output;
    int output = 0;
    for (int i = 0; i < 2 ; i++)
    {
        nodes_output.push_back(edges[i]->operation());
    }

    bitwise = int_to_bit(nodes_output);

    vector<int> result;
    for (int i = 0; i < bitwise[0].size(); i++)
    {
        int bit = 1;
        for (int j = 0; j < 2; j++)
        {
            if(bitwise[j][i] == 0)
            {
                bit = 0;
                break;
            }
        }
        result.push_back(bit);
    }
    output = bit_to_int(result);
    return output;
}

void BOR::edge_maker(Node* n)
{
    edges.push_back(n);
}

int BOR::operation()
{
    vector<vector<int>> bitwise;
    vector<int> nodes_output;
    int output = 0;
    for (int i = 0; i < 2 ; i++)
    {
        nodes_output.push_back(edges[i]->operation());
    }

    bitwise = int_to_bit(nodes_output);

    vector<int> result;
    for (int i = 0; i < bitwise[0].size(); i++)
    {
        int bit = 0;
        for (int j = 0; j < 2; j++)
        {
            if(bitwise[j][i] == 1)
            {
                bit = 1;
                break;
            }
        }
        result.push_back(bit);
    }
    output = bit_to_int(result);
    return output;
}

void BNOT::edge_maker(Node* n)
{
    edges.push_back(n);
}


int BNOT::operation()
{
    vector<vector<int>> bitwise;
    vector<int> node_output;
    node_output.push_back(edges[0]->operation());
    bitwise = int_to_bit(node_output);
    int output = 0;
    vector<int> result;
    for (int i = 0; i < bitwise[0].size(); i++)
    {
        int bit;
        if (bitwise[0][i] == 0)
            bit = 1;
        else
            bit = 0;

        result.push_back(bit);
    }
    output = bit_to_int(result);
    return output;
}


void BXOR::edge_maker(Node* n)
{
    edges.push_back(n);
}

int BXOR::operation()
{
    vector<vector<int>> bitwise;
    vector<int> nodes_output;
    int output = 0;
    for (int i = 0; i < edges.size() ; i++)
    {
        nodes_output.push_back(edges[i]->operation());
    }

    bitwise = int_to_bit(nodes_output);

    vector<int> result;
    for (int i = 0; i < bitwise[0].size(); i++)
    {
        int bit;
        int counter = 0;
        for (int j = 0; j < bitwise.size(); j++)
        {
            if(bitwise[j][i] == 1)
            {
                counter++;
            }
        }
        if (counter % 2 == 1)
            bit = 1;
        else
            bit = 0;
        result.push_back(bit);
    }
    output = bit_to_int(result);
    return output;
}