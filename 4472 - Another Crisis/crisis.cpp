#include <algorithm>
#include <cctype>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>

#define IN getc ( stdin )
using namespace std;



void fastint( register int *n ){
    register char c;
    *n = 0;
    while(!isdigit(c = IN));
    do { *n = 10 * *n + c - '0'; } while(isdigit(c = IN));
}

struct Nodo
{
    int hojas;
    vector<int> hijos;
};

struct comp
{
    Nodo *nodos;
    comp(Nodo arr[]) : nodos(arr) {}
    bool operator() (const int& a, const int& b)
    {
        return nodos[a].hojas < nodos[b].hojas;
    }
};

int main()
{
    int n,t;
    while (cin>>n>>t && n)
    {
        double td = t / 100.0;
        int jefe;
        Nodo nodos[n+1];

        for (int i = 1; i <= n; i++)
        {
            fastint(&jefe);
            nodos[jefe].hijos.push_back(i);
        }

        for (int i = n; i > -1; i--)
        {
            if (nodos[i].hijos.size() == 0)
                nodos[i].hojas = 1;
            else
            {
                nodos[i].hojas = 0;
                sort(nodos[i].hijos.begin(), nodos[i].hijos.end(), comp(nodos));
                int ramas = (int) ceil(nodos[i].hijos.size() * td);
                for (int j = 0; j < ramas; j++)
                    nodos[i].hojas += nodos[nodos[i].hijos[j]].hojas;
            }
        }

        cout << nodos[0].hojas << endl;
    }
    return 0;
}


