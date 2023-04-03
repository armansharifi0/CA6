#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class ashkan 
{
public:
    ashkan(int a) : asghar(a) {};
    void akbar();
private:
    int asghar;
};

void ashkan::akbar()
{
    cout << "farhad" << endl;
}

class shayan : public ashkan 
{
public:
    shayan(int a , int b) : ashkan(a), hooshang(b) {}
    void asghar();
private:
    int hooshang;
};

void shayan::asghar()
{
    cout << "farshad" << endl;
}

class arman
{
public:
    void add(ashkan ashi);
private:
    vector<ashkan> naderi_ha;
};

void arman::add(ashkan ashi)
{
    naderi_ha.push_back(ashi);
}

int main()
{
    ashkan ashi(2);
    shayan shayi(5, 7);
    arman armi;

    armi.add(shayi);

    cout << "shayan instance: " << sizeof(shayi) << endl;
    cout << "ashkan instance: " << sizeof(ashi) << endl;
    cout << "shayan class: " << sizeof(shayan) << endl;
    cout << "ashkan class: " << sizeof(ashkan) << endl;
    cout << "integer: " << sizeof(int) << endl;

    

}