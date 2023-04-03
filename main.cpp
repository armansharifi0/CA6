#include "tree.hpp"
#include <sstream>
#include <fstream>

void parser(tree &t, string order)
{

    vector<string> pieces;
    stringstream s(order);
    string piece;
    while (s >> piece){
        pieces.push_back(piece);
    }

    if (pieces[3] == "AND")
    {
        AND* tree_node = new AND(stoi(pieces[0]));
        t.add_node(tree_node);


        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < t.get_nodes().size(); i++)
            {
                if (t.get_nodes()[i]->return_index() == stoi(pieces[1]))
                {
                    tree_node->edge_maker(t.get_nodes()[i]);
                }
            }
            
        }
        
     
    }else if (pieces[3] == "OR")
    {

        OR* tree_node = new OR(stoi(pieces[0]));
        t.add_node(tree_node);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < t.get_nodes().size(); i++)
            {
                if (t.get_nodes()[i]->return_index() == stoi(pieces[1]))
                {
                    tree_node->edge_maker(t.get_nodes()[i]);
                }
            }
            
        }

    }else if (pieces[3] == "NOT")
    {
    
        NOT* tree_node = new NOT(stoi(pieces[0]));
        t.add_node(tree_node);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < t.get_nodes().size(); i++)
            {
                if (t.get_nodes()[i]->return_index() == stoi(pieces[1]))
                {
                    tree_node->edge_maker(t.get_nodes()[i]);
                }
            }
            
        }

    }else if (pieces[3] == "XOR")
    {

        XOR* tree_node = new XOR(stoi(pieces[0]));
        t.add_node(tree_node);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < t.get_nodes().size(); i++)
            {
                if (t.get_nodes()[i]->return_index() == stoi(pieces[1]))
                {
                    tree_node->edge_maker(t.get_nodes()[i]);
                }
            }
            
        }

    }else if (pieces[2] == "input")
    {
        
        deci* tree_node = new deci(stoi(pieces[0]), pieces[3]);

        if (stoi(pieces[1]) != -1)
        {
            for (int i = 0; i < t.get_nodes().size(); i++)
            {
                if (t.get_nodes()[i]->return_index() == stoi(pieces[1]))
                {
                    tree_node->edge_maker(t.get_nodes()[i]);
                }
            }
            
        }

    }else if (pieces[0] == "evaluate")
    {

        t.evaluate(pieces[0][2]);

    }else if (pieces[0] == "rebase")
    {

        t.evaluate(pieces[0][2]);

    }

}


int main()
{
    tree t;    
    fstream newfile;
    newfile.open("../input.txt",ios::in);
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line))
        {
            if (line == "\r")
                break;
            parser(t,line);
        }
        newfile.close();   
   }

    return 0;
}