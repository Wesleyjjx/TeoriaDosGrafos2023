#include <iostream>

using namespace std;

typedef int TipoItem;

class Grafo{
    private:
    int arestaNula;
    int maxVertices;
    int numVertices;
    TipoItem* vertices;
    int** matrizAdjcencias;

    public:
    Grafo(int max, int arestaNula);
    ~Grafo();
    int obterIndice(TipoItem item);
    bool grafoCheio();
    void insereVertice(TipoItem item);
    void insereAresta(TipoItem NoSaida,TipoItem noEntrada, int peso);
    int obterPeso(TipoItem NoSaida, TipoItem NoEntrada);
    int obterGrau(TipoItem);
    void imprimirMatriz();
    void imprimirVertices();
};