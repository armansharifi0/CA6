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
     
    }else if (pieces[0] == "create_account")
    {

        vector<int> temp;
        for (int i = 1; i < pieces.size() - 1; i++)
            temp.push_back(stoi(pieces[i]));
        b.make_account(temp,stod(pieces[pieces.size() - 1]));

    }else if (pieces[0] == "add_owner")
    {
    
        b.add_owner(stoi(pieces[1]),stoi(pieces[2]));

    }else if (pieces[0] == "book_transaction")
    {

        b.book_transaction(stoi(pieces[1]), stoi(pieces[2]), stod(pieces[3]));

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