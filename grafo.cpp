#include <iostream>
#include "grafo.h"

using namespace std;

Grafo::Grafo(int v, int arestaNula) // construtor
{
    numVertices = 0;
    maxVertices = v;
    arestaNula = arestaNula;

    vertices = new TipoItem[maxVertices];
    matrizAdjcencias = new int *[maxVertices];
    for (int i = 0; i < maxVertices; i++)
    {
        matrizAdjcencias[i] = new int[maxVertices];
    }
    for (int i = 0; i < maxVertices; i++)
    {
        for (int j = 0; j < maxVertices; j++)
        {
            matrizAdjcencias[i][j] = arestaNula;
        }
    }
}

Grafo::~Grafo() // destrutor
{
    delete[] vertices;
    for (int i = 0; i < maxVertices; i++)
    {
        delete[] matrizAdjcencias[i];
    }
    delete[] matrizAdjcencias;
}
int Grafo::retornaAdjacencia(TipoItem i, TipoItem j)
{
    
    return matrizAdjcencias[i][j];

}
void Grafo::insereMatrizAdjacencia(TipoItem item, TipoItem i, TipoItem j)
{

    matrizAdjcencias[i][j] = item;
}
int Grafo::obterIndice(TipoItem item)
{
    int indice = 0;
    while (item != vertices[indice])
    {
        indice++;
    }
    if (item == vertices[indice])
    {
        return indice;
    }
    else
    {
        return -1;
    }
}

bool Grafo::grafoCheio()
{
    return (numVertices == maxVertices);
}

void Grafo::insereVertice(TipoItem item)
{
    if (grafoCheio())
    {
        cout << "Grafo cheio" << endl;
    }
    else
    {
        vertices[numVertices] = item;
        numVertices++;
    }
}

void Grafo::insereAresta(TipoItem NoSaida, TipoItem NoEntrada, int peso)
{
    int linha = obterIndice(NoSaida);
    int coluna = obterIndice(NoEntrada);
    if (linha != -1 && coluna != -1)
    {
        matrizAdjcencias[linha][coluna] = peso;
        matrizAdjcencias[coluna][linha] = peso;
    }
    else
    {
        cout << "Vertice nao existe no grafo" << endl;
    }
}

int Grafo::obterPeso(TipoItem NoSaida, TipoItem NoEntrada)
{
    int linha = obterIndice(NoSaida);
    int coluna = obterIndice(NoEntrada);
    if (linha != -1 && coluna != -1)
    {
        return (matrizAdjcencias[linha][coluna]);
    }
    else
    {
        cout << "Vertice nao existe no grafo" << endl;
    }
}

int Grafo::obterGrau(TipoItem item)
{
    int linha = obterIndice(item);
    if (linha != -1)
    {
        int grau = 0;
        for (int i = 0; i < maxVertices; i++)
        {
            if (matrizAdjcencias[linha][i] != arestaNula)
            {
                grau++;
            }
        }
        return grau;
    }
    else
    {
        cout << "Vertice nao existe no grafo" << endl;
    }
}

void Grafo::imprimirMatriz()
{
    cout << "Matriz de adjacencias: " << endl;
    for (int i = 0; i < maxVertices; i++)
    {
        for (int j = 0; j < maxVertices; j++)
        {
            cout << matrizAdjcencias[i][j] << " ";
        }
        cout << endl;
    }
}

void Grafo::imprimirVertices()
{
    cout << "Lista de Vertices: " << endl;
    for (int i = 0; i < numVertices; i++)
    {
        cout << i << ": " << vertices[i] << endl;
    }
}