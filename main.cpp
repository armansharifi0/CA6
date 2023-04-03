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
        AND* tree_node = new AND(stoi(pieces[0]), pieces[3]);
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

        OR* tree_node = new OR(stoi(pieces[0]), pieces[3]);
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
    
        NOT* tree_node = new NOT(stoi(pieces[0]), pieces[3]);
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

        XOR* tree_node = new XOR(stoi(pieces[0]), pieces[3]);
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
        
        deci* tree_node = new deci(stoi(pieces[0]), pieces[3] , pieces[2]);

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


    }else if (pieces[0] == "remode")
    {
        for (int i = 0; i < t.get_nodes().size(); i++)
            {
                if (t.get_nodes()[i]->return_index() == stoi(pieces[2]))
                {
                    delete t.get_nodes()[i];
                    if(t.get_nodes()[i]->return_name() == "AND")
                    {
                        BAND* tree_node = new BAND(stoi(pieces[2]), "BAND");
                        t.get_nodes()[i] = tree_node;
                    }else if (t.get_nodes()[i]->return_name() == "OR")
                    {
                        BOR* tree_node = new BOR(stoi(pieces[2]), "BOR");
                        t.get_nodes()[i] = tree_node;
                    }else if (t.get_nodes()[i]->return_name() == "XOR")
                    {
                        BXOR* tree_node = new BXOR(stoi(pieces[2]), "BXOR");
                        t.get_nodes()[i] = tree_node;
                    }else if (t.get_nodes()[i]->return_name() == "NOT")
                    {
                        BNOT* tree_node = new BNOT(stoi(pieces[2]), "BNOT");
                        t.get_nodes()[i] = tree_node;
                    }else if(t.get_nodes()[i]->return_name() == "BAND")
                    {
                        AND* tree_node = new AND(stoi(pieces[2]), "AND");
                        t.get_nodes()[i] = tree_node;
                    }else if (t.get_nodes()[i]->return_name() == "BOR")
                    {
                        OR* tree_node = new OR(stoi(pieces[2]), "OR");
                        t.get_nodes()[i] = tree_node;
                    }else if (t.get_nodes()[i]->return_name() == "BXOR")
                    {
                        XOR* tree_node = new XOR(stoi(pieces[2]), "XOR");
                        t.get_nodes()[i] = tree_node;
                    }else if (t.get_nodes()[i]->return_name() == "BNOT")
                    {
                        NOT* tree_node = new NOT(stoi(pieces[2]), "NOT");
                        t.get_nodes()[i] = tree_node;
                    }
                }
            }
    }else if (pieces[0] == "rebase")
    {
        for (int i = 0; i < t.get_nodes().size(); i++)
            {
                
                if (t.get_nodes()[i]->return_index() == stoi(pieces[2]))
                {
                    string node_value = t.get_nodes()[i]->get_value();
                    delete t.get_nodes()[i];
                    if (pieces[1][1] == 'b')
                    {
                        bina* tree_node = new bina(stoi(pieces[2]), node_value, "input");
                        t.get_nodes()[i] = tree_node;
                    }else if (pieces[1][1] == 'h')
                    {
                        hexa* tree_node = new hexa(stoi(pieces[2]), node_value, "input");
                        t.get_nodes()[i] = tree_node;
                    }else if (pieces[1][1] == 'o')
                    {
                        octa* tree_node = new octa(stoi(pieces[2]), node_value, "input");
                        t.get_nodes()[i] = tree_node;
                    }else if (pieces[1][1] == 'd')
                    {
                        deci* tree_node = new deci(stoi(pieces[2]), node_value, "input");
                        t.get_nodes()[i] = tree_node;
                    }
                }
            }
    }else if (pieces[0] == "reset")
    {
        for (int i = 0; i < t.get_nodes().size(); i++)
            {
                if (t.get_nodes()[i]->return_index() == stoi(pieces[1]))
                {
                    t.get_nodes()[i]->set_value(pieces[2]);
                }
            }
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