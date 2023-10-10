#include <iostream>
#include <fstream>
#include <iomanip>
#include "grafo.h"

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
    int valorArestanula = 0;
    Grafo grafo1(l,valorArestanula);
    TipoItem itemA, itemB;
    int opcao, valor, peso;
    for (int i = 0; i < l; i++)
    {
            grafo1.insereVertice(i);
    }
    for(int i=0; i<l;i++){
        for(int j=0; j<l; j++){
            arq >> itemA;
            grafo1.insereMatrizAdjacencia(itemA,i,j);
        }
    }
    arq.close();
    do{
        cout << "Digite 0 para parar o algoritmo." << endl;
        cout << "Digite 1 para inserir uma aresta." << endl;
        cout << "Digite 2 para imprimir o grau de um vertice." << endl;
        cout << "Digite 3 para imprimir o peso de uma aresta." << endl;
        cout << "Digite 4 para imprimir a matriz de adjacencias" << endl;
        cout << "Digite 5 para imprimir a lista de vertices." << endl;
        cin >> opcao;
            if(opcao == 1){

                cout << "Digite o vertice de saida:" << endl;
                cin >> itemA;
                cout << "Digite o vertice de entrada" << endl;
                cin >> itemB;
                cout << "Digite o peso desta aresta: " << endl;
                cin >> peso;
                grafo1.insereAresta(itemA,itemB,peso);

            }else if(opcao == 2){

                cout << "Digite o vertice :" << endl;
                cin >> itemA;
                valor = grafo1.obterGrau(itemA);
                cout<< "O grau desse vertice e: "<< valor << endl;

            }else if(opcao == 3){

                cout << "Digite o vertice de saida:" << endl;
                cin >> itemA;
                cout << "Digite o vertice de entrada" << endl;
                cin >> itemB;
                valor = grafo1.obterPeso(itemA,itemB);
                cout<< "O peso dessa aresta e: " << valor << endl;

            }else if(opcao == 4){

                grafo1.imprimirMatriz();

            }else if(opcao == 5){

                grafo1.imprimirVertices();

            }

    }while(opcao != 0);
    /*int m[l][c];
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
    arqA.close();*/
    return 0;
}