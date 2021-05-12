#include "graphs/shortest_path_algorithms.hpp"
#include <algorithm>

int Minimum(int wierzcholek,ShortestPathResult& result,std::vector<bool> odwiedzony)
{
    int min=-MAX;
    int wartosc=MAX;

    for (int i = 0; i < wierzcholek; i++)
    {
        if ((!odwiedzony[i]) && (result[i].cost < wartosc))
        {

            min = i;
            wartosc = result[i].cost;
        }
    }
    return min;
}

void dijkstra(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    std::vector<bool> odwiedzony(graph.wierzcholki);

    for(int i=0;i<graph.wierzcholki;i++) //poczatkowe ustawienia koszt na MAX i wszystkie wierzcholki nie nieodwiedzone
    {
        if(i==graph.pierwszy_wierz)
        {
            result[graph.pierwszy_wierz].cost=0;

            odwiedzony[i]=false;
        }
        else
        {
            result[i].cost=MAX;
            odwiedzony[i]=false;
        }   
    }

    int minimum=Minimum(graph.wierzcholki,result,odwiedzony);

    std::vector<int> Poprzedni2(graph.wierzcholki); // wektor poprzednich wierzcholkow

    for (int i = 0; i < graph.wierzcholki; i++)
    {
        Poprzedni2[i]=-1;
    }
    
  
    while(minimum!=-MAX)
    {   
        odwiedzony[minimum]=true;
        std::vector<int> pol;

        pol=graph.liczbaPolaczen(minimum); //wektor z polaczonymi wierzcholami z wierzcholkiem i 

            for (int j = 0; j < pol.size(); j++)
            {
                if(graph.Czy_istnieje_polaczenie(minimum,pol[j])&&( result[pol[j]].cost > result[minimum].cost+graph.zwroc_wage(minimum,pol[j])))
                {                    
                    result[pol[j]].cost=graph.zwroc_wage(minimum,pol[j])+result[minimum].cost;

                    Poprzedni2[pol[j]]=minimum;
                }

            }
            minimum=Minimum(graph.wierzcholki,result,odwiedzony);
    }
    //utawianie sciezki najszybszego dojscia
    for (int i = 0; i < graph.wierzcholki; i++)
    {
        result[i].path.push_back(i);
        int aktualny =i;
        while (aktualny!=graph.pierwszy_wierz)
        {
            result[i].path.push_back(Poprzedni2[aktualny]);
            aktualny=Poprzedni2[aktualny];
        }
        std::reverse(result[i].path.begin(),result[i].path.end());
        
    }
    
}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    std::vector<bool> odwiedzony(graph.wierzcholki);
    int poprzedni;

    for(int i=0;i<graph.wierzcholki;i++)
    {
        if(i==graph.pierwszy_wierz)
        {
            result[graph.pierwszy_wierz].cost=0;

            odwiedzony[i]=false;
        }
        else
        {
            result[i].cost=MAX;
            odwiedzony[i]=false;
        }   
    }


    for(int c = 1; c < graph.wierzcholki; c++)
    {
        
        for (int i=0; i<graph.wierzcholki; i++)
        {
            std::vector<int> pom=graph.liczbaPolaczen(i);
            
            for (int j=0; j<pom.size(); j++)
            {
                if( result[j].cost != MAX && graph.Czy_istnieje_polaczenie(i,pom[j])  && result[pom[j]].cost > result[i].cost+graph.zwroc_wage(i,pom[j]))
                {
                    // std::cout<<"aaaa\n";
                    result[pom[j]].cost=result[i].cost+graph.zwroc_wage(i,pom[j]);
                    // result[i].path.push_back(j);
                }
            }
        }
    }

    return true;
}
