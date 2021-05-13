#include "graphs/adjacency_list_graph.hpp"
#include <iostream>


std::unique_ptr<Graph> AdjacencyListGraph::createGraph(std::istream& is)
{

    unsigned int pom_w,pom_k,pom_wp,pom_ost;

    is>>pom_w;      //pobierz liczbe wierzchołków
    is>>pom_k;      //pobierz liczbe krawędzi

    AdjacencyListGraph lista;
    
    std::vector<int> pom_krawedz(3); // tworze wektor 3 elementowy na pierwszy wierzcholek, drugi wierzcholek i wage polaczenia 
    
    std::vector<std::vector<int>> pom_pom_listy;  // pomocna chwilowa zmienna 

    unsigned int pom_pierwszy=0,pom_drugi=0,pom_waga=0;

    //tworzenie krawędzi 0 krawędzi to znaczy połączenie wierzchołka 0 i 0 o wadze 0 

    pom_krawedz[0]=pom_pierwszy;
    pom_krawedz[1]=pom_drugi;
    pom_krawedz[2]=pom_waga;

    //alokowanie pamięci 

    pom_pom_listy.push_back(pom_krawedz); 

    for(int i=0;i<pom_w;i++)
       {
           lista.element.push_back(pom_pom_listy);

           lista.polaczenia.push_back(0);
       }

    

    for (int i = 0; i < pom_k; i++)
    {
        is>>pom_pierwszy;
        is>>pom_drugi;
        is>>pom_waga;
        

        pom_krawedz[0]=pom_pierwszy;
        pom_krawedz[1]=pom_drugi;
        pom_krawedz[2]=pom_waga;
        
        if(lista.element[pom_pierwszy][0][2]==0)        //kiedy nie ma jeszcze połączeń z wierzchołkiem pom_pierwszy
        {
            lista.element[pom_pierwszy].pop_back();     
            lista.element[pom_pierwszy].push_back(pom_krawedz);

            lista.polaczenia[pom_pierwszy]=1;
            
        }

        else
        {
            lista.element[pom_pierwszy].push_back(pom_krawedz);
            lista.polaczenia[pom_pierwszy]++;
        }
    }
    
    is>>pom_wp;     //pobieranie pierwszego wierzchołka

    //przypisywanie

    lista.wierzcholki=pom_w;
    lista.krawedzie=pom_k;
    lista.pierwszy_wierz=pom_wp;

 
    return std::make_unique<AdjacencyListGraph>(lista);
}
bool AdjacencyListGraph::Czy_istnieje_polaczenie(unsigned int PierwszyW, unsigned int Drugii_W) //Funkcja do sprawdzenia czy istnieje połączenie między wierzchołkami
{
    for (int j = 0; j< polaczenia[PierwszyW]; j++)
        {
            if(element[PierwszyW][j][1]==Drugii_W)
            {
                return true;
            }
        }
        return false;

}
std::vector<int> AdjacencyListGraph::liczbaPolaczen(unsigned int I) //Funkcja zwracająca vektor zawierający wszystkie wierzcholki z którym jest połaczony wierzcholek I
{ 
    std::vector<int> pom;

    for (int j = 0; j < polaczenia[I]; j++)
        {
            if(element[I][j][2]!=0)
            {
                int wartosc=element[I][j][1];
                pom.push_back(wartosc);
            }
        }
    return pom;

}

int AdjacencyListGraph::zwroc_wage(int Pierwszy,int Drugi) //Funckcja zwracająca wage połączenia wierzchołka Pierwszy i Drugi
{
    for (int j = 0; j< polaczenia[Pierwszy]; j++)
        {
            if(element[Pierwszy][j][1]==Drugi)
            {
                return element[Pierwszy][j][2];
            }
        }
    return 99999999;
}
