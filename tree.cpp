#include "tree.hpp"
#include <algorithm>

string base_conversion(int number, int base)
{
    int quotient = 1;
    int remainder;
    string result ="";
    while (quotient != 0)
    {
        quotient = number / base;
        remainder = number % base;
        result += to_string(remainder);
        number /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

string hex_conversion(int number)
{
    int quotient = 1;
    int remainder;
    string result ="";
    while (quotient != 0)
    {
        quotient = number / 16;
        remainder = number % 16;
        if (remainder == 10)
            result += 'a';
        else if (remainder == 11)
            result += 'b';
        else if (remainder == 12)
            result += 'c';
        else if (remainder == 13)
            result += 'd';
        else if (remainder == 14)
            result += 'e';
        else if (remainder == 15)
            result += 'f';
        else
            result += to_string(remainder);

        number /= 16;
    }
    reverse(result.begin(), result.end());
    return result;
}

void tree::add_node(Node* n)
{
    nodes.push_back(n);
}


void tree::evaluate(char base)
{
    int number;
    for (int i = 0; i < nodes.size(); i++)
    {
        if (nodes[i]->return_index() == 0)
        {
            number = i;
            break;
        }
    }
    int result = nodes[number]->operation();

    string evaluation;
    if (base == 'd')
    {
        cout << result << endl;
    }else if (base == 'h')
    {
        evaluation = hex_conversion(result);
        cout << evaluation << endl;
    }else if (base == 'o')
    {
        evaluation = base_conversion(result, 8);
        cout << evaluation << endl;
    }else if (base == 'b')
    {
        evaluation = base_conversion(result, 2);
        cout << evaluation << endl;
    }



}