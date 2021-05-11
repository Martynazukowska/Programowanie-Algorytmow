#include "graphs/adjacency_matrix_graph.hpp"
#include <memory>

std::unique_ptr<Graph> AdjacencyMatrixGraph::createGraph(std::istream& is)
{
    unsigned int pom_w,pom_k,pom_wp,pom_ost;

    is>>pom_w;
    is>>pom_k;
    
    AdjacencyMatrixGraph  macierz; 

    
    std::vector<std::vector<int>> pom_macierz; 
    std::vector<int> pom_pom_macierzy;

    for (int i = 0; i < pom_w; i++)
    {
        pom_pom_macierzy.push_back(0);
    }
    

    for(int i=0;i<pom_w;i++)
       {
           pom_macierz.push_back(pom_pom_macierzy);
       }
    
    unsigned int w1,w2,waga;

    for(int i=0; i<pom_k; i++)
        {
            is>>w1;
            is>>w2;
            is>>waga;
            pom_macierz[w1][w2]=waga;
        }
    
   is>>pom_wp;
    
    macierz.wierzcholki=pom_w;
    macierz.krawedzie=pom_k;
    macierz.pierwszy_wierz=pom_wp;


    macierz.elemnt=pom_macierz;
    // macierz.ostatni_wierz=pom_ost;

    return std::make_unique<AdjacencyMatrixGraph>(macierz);

}
bool AdjacencyMatrixGraph::Czy_istnieje_polaczenie(unsigned int PierwszyW, unsigned int Drugii_W)
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
std::vector<int> AdjacencyMatrixGraph::liczbaPolaczen(unsigned int intex)
{

    std::vector<int> polaczenia;

    for (int i = 0; i < wierzcholki; i++)
    {
        if(elemnt[intex][i]!=0)
        {
            polaczenia.push_back(i);

        }
    }
    return polaczenia;

}

int AdjacencyMatrixGraph::zwroc_wage(int Pierwszy,int Drugi)
{
    return elemnt[Pierwszy][Drugi];
}

