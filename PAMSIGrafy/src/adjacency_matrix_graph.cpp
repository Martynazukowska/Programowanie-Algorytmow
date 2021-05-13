#include "graphs/adjacency_matrix_graph.hpp"
#include <memory>

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    unsigned int pom_w,pom_k,pom_wp,pom_ost;

    is>>pom_w;      //pobieranie ilośći wierzchołków
    is>>pom_k;      //pobieranie ilości krawędzi
    
    AdjacencyMatrixGraph  macierz; 

    
    std::vector<std::vector<int>> pom_macierz;  
    std::vector<int> pom_pom_macierzy;

    //alokowanie pamięci

    for (int i = 0; i < pom_w; i++)
    {
        pom_pom_macierzy.push_back(0);
    }
    

    for(int i=0;i<pom_w;i++)
       {
           pom_macierz.push_back(pom_pom_macierzy);
       }
    
    unsigned int w1,w2,waga;

    //przypisywanie odpowiednich wartości do macierzy 

    for(int i=0; i<pom_k; i++)
        {
            is>>w1;
            is>>w2;
            is>>waga;
            pom_macierz[w1][w2]=waga;
        }
    
   is>>pom_wp;  //pobieranie pierwszego wierzchołka
    
    macierz.wierzcholki=pom_w;
    macierz.krawedzie=pom_k;
    macierz.pierwszy_wierz=pom_wp;


    macierz.elemnt=pom_macierz;

    return std::make_unique<AdjacencyMatrixGraph>(macierz);

}
bool AdjacencyMatrixGraph::Czy_istnieje_polaczenie(unsigned int PierwszyW, unsigned int Drugii_W) //Funkcja do sprawdzenia czy istnieje połączenie między wierzchołkami
{
    if(elemnt[PierwszyW][Drugii_W]!=0)
    {
        return true;

    }
    else
    {
        return false;
    }
}
std::vector<int> AdjacencyMatrixGraph::liczbaPolaczen(unsigned int J) //Funkcja zwracająca vektor zawierający wszystkie wierzcholki z którym jest połaczony wierzcholek J
{

    std::vector<int> polaczenia;

    for (int i = 0; i < wierzcholki; i++)
    {
        if(elemnt[J][i]!=0)
        {
            polaczenia.push_back(i);

        }
    }
    return polaczenia;

}

int AdjacencyMatrixGraph::zwroc_wage(int Pierwszy,int Drugi) //Funckcja zwracająca wage połączenia wierzchołka Pierwszy i Drugi
{
    return elemnt[Pierwszy][Drugi];
}

