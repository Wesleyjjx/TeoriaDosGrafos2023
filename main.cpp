#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    int l, c;
    fstream arq;
    arq.open("dadosGrafo1.txt",ios::in);
    //arq << "10 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1 0 1 0 1 1 0 1 0 0 1" << endl;
    //arq.close();
    //ifstream arqA;
    string linha;
    //arqA.open("dadosGrafo1.txt");
    arq >> l;
    c = l;
    int m[l][c];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arq >> m[i][j];
        }
        cout << endl;
    }
    arq.close();
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << m[i][j] << " - ";
        }
        cout << endl;
    }
    ofstream arqA;
    arqA.open("matrizDeAdjacencias.txt");
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arqA << m[i][j] << " - ";
        }
        arqA << "\n";
    }
    arqA.close();
    return 0;
}