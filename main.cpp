#include "numbers.hpp"
#include <sstream>
#include <fstream>
#include <algorithm>


string base_conversion(int number, int base)
{
    int quotient = 1;
    int remainder;
    string result ="";
    if (number < 0)
    {
        number = -number;
        while (quotient != 0)
        {
            quotient = number / base;
            remainder = number % base;
            result += to_string(remainder);
            number /= base;
        }
        reverse(result.begin(), result.end());
        string negative_result = "-" + result;
        return negative_result;
    }else
    {
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

void parser(vector<Node*> &nodes, string order)
{

    vector<string> pieces;
    stringstream s(order);
    string piece;
    while (s >> piece){
        pieces.push_back(piece);
    }

    if (pieces[0] == "evaluate")
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
        if (pieces[1][1] == 'd')
        {
            cout << result << endl;
        }else if (pieces[1][1] == 'h')
        {
            evaluation = hex_conversion(result);
            cout << evaluation << endl;
        }else if (pieces[1][1] == 'o')
        {
            evaluation = base_conversion(result, 8);
            cout << evaluation << endl;
        }else if (pieces[1][1] == 'b')
        {
            evaluation = base_conversion(result, 2);
            cout << evaluation << endl;
        }

    }else if (pieces[0] == "remode")
    {
        for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->return_index() == stoi(pieces[2]))
                {
                    vector<Node*> node_edges = nodes[i]->get_edges();
                    delete nodes[i];
                    if(nodes[i]->return_name() == "AND")
                    {
                        BAND* tree_node = new BAND(stoi(pieces[2]), "BAND");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }else if (nodes[i]->return_name() == "OR")
                    {
                        BOR* tree_node = new BOR(stoi(pieces[2]), "BOR");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }else if (nodes[i]->return_name() == "XOR")
                    {
                        BXOR* tree_node = new BXOR(stoi(pieces[2]), "BXOR");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }else if (nodes[i]->return_name() == "NOT")
                    {
                        BNOT* tree_node = new BNOT(stoi(pieces[2]), "BNOT");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }else if(nodes[i]->return_name() == "BAND")
                    {
                        AND* tree_node = new AND(stoi(pieces[2]), "AND");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }else if (nodes[i]->return_name() == "BOR")
                    {
                        OR* tree_node = new OR(stoi(pieces[2]), "OR");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }else if (nodes[i]->return_name() == "BXOR")
                    {
                        XOR* tree_node = new XOR(stoi(pieces[2]), "XOR");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }else if (nodes[i]->return_name() == "BNOT")
                    {
                        NOT* tree_node = new NOT(stoi(pieces[2]), "NOT");
                        nodes[i] = tree_node;
                        nodes[i]->set_edges(node_edges);
                        break;
                    }
                }
            }
    }else if (pieces[0] == "rebase")
    {
        for (int i = 0; i < nodes.size(); i++)
            {
                
                if (nodes[i]->return_index() == stoi(pieces[2]))
                {
                    string node_value = nodes[i]->get_value();
                    delete nodes[i];
                    if (pieces[1][1] == 'b')
                    {
                        bina* tree_node = new bina(stoi(pieces[2]), node_value, "input");
                        nodes[i] = tree_node;
                    }else if (pieces[1][1] == 'h')
                    {
                        hexa* tree_node = new hexa(stoi(pieces[2]), node_value, "input");
                        nodes[i] = tree_node;
                    }else if (pieces[1][1] == 'o')
                    {
                        octa* tree_node = new octa(stoi(pieces[2]), node_value, "input");
                        nodes[i] = tree_node;
                    }else if (pieces[1][1] == 'd')
                    {
                        deci* tree_node = new deci(stoi(pieces[2]), node_value, "input");
                        nodes[i] = tree_node;
                    }
                }
            }
    }else if (pieces[0] == "reset")
    {
        for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->return_index() == stoi(pieces[1]))
                {
                    nodes[i]->set_value(pieces[2]);
                }
            }
    }else if (pieces[3] == "AND")
    {
        AND* tree_node = new AND(stoi(pieces[0]), pieces[3]);
        nodes.push_back(tree_node);


        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->return_index() == stoi(pieces[1]))
                {
                    nodes[i]->edge_maker(tree_node);
                }
            }
            
        }
        
     
    }else if (pieces[3] == "OR")
    {

        OR* tree_node = new OR(stoi(pieces[0]), pieces[3]);
        nodes.push_back(tree_node);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->return_index() == stoi(pieces[1]))
                {
                    nodes[i]->edge_maker(tree_node);
                }
            }
            
        }

    }else if (pieces[3] == "NOT")
    {
    
        NOT* tree_node = new NOT(stoi(pieces[0]), pieces[3]);
        nodes.push_back(tree_node);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->return_index() == stoi(pieces[1]))
                {
                    nodes[i]->edge_maker(tree_node);
                }
            }
            
        }

    }else if (pieces[3] == "XOR")
    {

        XOR* tree_node = new XOR(stoi(pieces[0]), pieces[3]);
        nodes.push_back(tree_node);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->return_index() == stoi(pieces[1]))
                {
                    nodes[i]->edge_maker(tree_node);
                }
            }
            
        }

    }else if (pieces[2] == "input")
    {
        
        deci* tree_node = new deci(stoi(pieces[0]), pieces[3] , pieces[2]);
        nodes.push_back(tree_node);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < nodes.size(); i++)
            {
                if (nodes[i]->return_index() == stoi(pieces[1]))
                {
                    nodes[i]->edge_maker(tree_node);
                }
            }
            
        }

    }

}


int main()
{
    fstream newfile;
    vector<Node*> nodes;
    newfile.open("../input.txt",ios::in);
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line))
        {
            if (line == "\r")
                break;
            parser(nodes,line);
        }
        newfile.close();   
   }

    return 0;
}