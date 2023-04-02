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
}

void tree::add_node(Node n)
{
    nodes.push_back(n);
}


string tree::evaluate(char base)
{
    int result;
    int max_index = nodes.size();
    for (int i = 1; i <= max_index; i++)
    {
        int index;
        if (i == max_index)
        {
            for (int j = 0; j < max_index; j++)
            {
            if (nodes[j].return_index() == i)
                nodes[j].operation();
                index = j;
            }
        }else
        {
           for (int j = 0; j < max_index; j++)
            {
            if (nodes[j].return_index() == i)
                nodes[j].operation();
            } 
        }
        result = nodes[index].get_output();
    }

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