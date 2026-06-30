#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int V = 11;
string ten[V] = {"Ha Noi","Son Tay","Hoa Binh","Phu Ly","Hung Yen",
                 "Hai Duong","Hai Phong","Uong Bi","Bac Ninh","Bac Giang","Thai Nguyen"};

struct Canh { int u, v, w; };
Canh canh[] = {
    {0,5,1},{5,4,2},{4,3,3},{0,3,4},{0,2,5},
    {0,1,6},{0,10,7},{0,8,8},{8,9,9},{9,7,10},
    {8,7,11},{7,6,12},{5,6,13}
};
const int E = 13;
