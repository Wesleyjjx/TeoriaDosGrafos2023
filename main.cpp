#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int l, c;
    ofstream arq;
    arq.open("dadosGrafo.txt");
    arq << "4 0 1 1 0 1 0 1 0 1 1 0 1 0 0 1 0" << endl;
    arq.close();
    ifstream arqA;
    string linha;
    arqA.open("dadosGrafo.txt");
    arqA >> l;
    c = l;
    int m[l][c];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arqA >> m[i][j];
        }
        cout << endl;
    }
    arqA.close();
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j] << " - ";
        }
        cout << endl;
    }
    ofstream arqB;
    arqB.open("matrizDeAdjacencias.txt");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arqB << m[i][j] << " - ";
        }
        arqB << "\n";
    }
    arqB.close();
    return 0;
}