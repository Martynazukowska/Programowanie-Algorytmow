#include <iostream>
#include <sstream>
#include <string>

#include <filesystem>
#include <fstream>

#include "graphs/adjacency_list_graph.hpp"
#include "graphs/adjacency_matrix_graph.hpp"
#include "graphs/shortest_path_algorithms.hpp"


#include "graphs/timer.hpp"
#include <cstdlib>
#include <ctime>
#include <thread>



void Wygeneruj_Graf(float gestosc)
{
    std::ofstream wpisz("/home/martyna/Studia/Sem_4/Pamsi/lab1/pamsi1/PAMSIGrafy/data/graph/a.txt"); 

    srand(time(NULL));
    int ilosc_wierzcholkow=ILOSC_WIERZCHOLKOW;
    int krawedzie;
    krawedzie=ilosc_wierzcholkow*(ilosc_wierzcholkow-1)*gestosc;
    wpisz<<ilosc_wierzcholkow<<" "<<krawedzie;

    int pierwszy_wierz=0;
    int koniec,poczatek;

    AdjacencyMatrixGraph Pom;
    std::vector<int> pom_pom_macierzy;

    for (int i = 0; i < ilosc_wierzcholkow; i++)
    {
        pom_pom_macierzy.push_back(0);
    }
    

    for(int i=0;i<ilosc_wierzcholkow;i++)
       {
           Pom.elemnt.push_back(pom_pom_macierzy);
       }

    for(int i=0;i<ilosc_wierzcholkow;i++)
    {
        for(int j=0;j<ilosc_wierzcholkow;j++)
        {
            Pom.elemnt[i][j]=0;
        }
    }
    if(gestosc<=0.5)
    {
        for(int i=0;i<ilosc_wierzcholkow;i++)
        {
            koniec=rand()%ilosc_wierzcholkow;
            if(koniec==i)
                --i;
            else
               Pom.elemnt[i][koniec]=(rand()%9)+1;

        }
        for(int j=0;j<krawedzie-ilosc_wierzcholkow;)
        {

            poczatek=rand()%ilosc_wierzcholkow;
            koniec=rand()%ilosc_wierzcholkow;
            if(poczatek!=koniec&&Pom.elemnt[poczatek][koniec]==0)
            {
               Pom.elemnt[poczatek][koniec]=(rand()%9)+1;
               j++;
            }

        }
    }
    else
    {
        for(int i=0;i<ilosc_wierzcholkow;i++)
            for(int j=0;j<ilosc_wierzcholkow;j++)
            {
                if(i!=j)
                    Pom.elemnt[i][j]=(rand()%9)+1;
            }
        for(int i=0;i<(1-gestosc)*krawedzie;i++)
        {
            poczatek=rand()%ilosc_wierzcholkow;
            koniec=rand()%ilosc_wierzcholkow;
            if(poczatek==koniec)
                --i;
            else if(Pom.elemnt[poczatek][koniec]==0)
                --i;
            else
                Pom.elemnt[poczatek][koniec]=0;
        }

    }
    wpisz<<"\n";
    for (int i = 0; i < ilosc_wierzcholkow; i++)
    {
        for (int j = 0; j < ilosc_wierzcholkow; j++)
        {
            if(Pom.Czy_istnieje_polaczenie(i,j))
            {
                wpisz<<i<<" "<<j<<" "<<Pom.elemnt[i][j]<<"\n";
            }
        }
        
    }
    wpisz<<pierwszy_wierz<<"\n";
    
    wpisz.close();

}


using namespace std::string_literals;
using namespace std::chrono_literals;


int main(int argc, char* argv[])
{
    Wygeneruj_Graf(0.25);
    
    std::ifstream inputStream{"home/martyna/Studia/Sem_4/Pamsi/lab1/pamsi1/PAMSIGrafy/data/graph/a.txt"};
    

    // auto graph = AdjacencyMatrixGraph::createGraph(inputStream); 
    auto graph = AdjacencyListGraph::createGraph(inputStream);

    ShortestPathResult result, result2;
    Timer timer, timer2;

    int sourceIndex;

    inputStream >> sourceIndex;

    timer.start();
    // dijkstra(*graph, sourceIndex, result);
    timer.stop();

    

    timer2.start();
    // bellmanFord(*graph, sourceIndex, result2);
    timer2.stop();


    return 0;
}


