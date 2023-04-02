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
                    tree_node->edge_maker()
                }
            }
            
        }
        
     
    }else if (pieces[3] == "OR")
    {

        OR* tree_node = new OR(stoi(pieces[0]));
        t.add_node(tree_node);

    }else if (pieces[3] == "NOT")
    {
    
        NOT* tree_node = new NOT(stoi(pieces[0]));
        t.add_node(tree_node);

    }else if (pieces[3] == "xor")
    {

        XOR* tree_node = new XOR(stoi(pieces[0]));
        t.add_node(tree_node);

    }else if (pieces[0] == "approve_transaction" || pieces[0] == "decline_transaction")
    {
        Status reply;
        if (pieces[0] == "approve_transaction")
            reply = ACCEPTED;
        else
            reply = REJECTED;

        b.inquiry_transaction(reply,stoi(pieces[1]),stoi(pieces[2]));


    }else if (pieces[0] == "show_account")
    {

        b.show_account(stoi(pieces[1]));

    }

}


int main()
{

    bank b;    
    fstream newfile;
    newfile.open("../input.txt",ios::in);
    if (newfile.is_open()){
        string line;
        while(getline(newfile, line))
        {
            if (line == "\r")
                break;
            parser(b,line);
        }
        newfile.close();   
   }

    return 0;
}