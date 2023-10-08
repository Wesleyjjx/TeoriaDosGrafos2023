#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int l, c;
    ofstream arq;
    arq.open("matrizDeAdjacencias.txt");
    arq << "4" << endl;
    arq << "0 1 1 0 1 0 1 0 1 1 0 1 0 0 1 0" << endl;
    /*arq << "1 0 1 0" << endl;
    arq << "1 1 0 1" << endl;
    arq << "0 0 1 0" << endl;*/
    arq.close();

    ifstream arqA;
    string linha;
    arqA.open("matrizDeAdjacencias.txt");
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
        for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j] << " - ";
        }
        cout << endl;
    }

    /*if (arqA.is_open())
    {
        while (getline(arqA, linha))
        {
            cout << linha << endl;
        }
        arqA.close();
    }
    else
    {
        cout << "Nao foi possivel abrir o arquivo" << endl;
    }*/
    return 0;
}