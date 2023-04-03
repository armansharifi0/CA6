#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    vector<int> akbar;
    for (int i = 0; i < 5; i++)
    {
        akbar.push_back(2);
    }
    akbar[2] = 3;

    cout << akbar[2] << endl;

    

}