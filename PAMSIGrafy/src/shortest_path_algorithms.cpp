#include "graphs/shortest_path_algorithms.hpp"
#define MAX 2147483647

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
    int poprzedni;

    for(int i=0;i<graph.wierzcholki;i++)
    {
        if(i==graph.pierwszy_wierz)
        {
            result[0].cost=0;

            result[0].path.push_back(graph.pierwszy_wierz);

            odwiedzony[i]=false;
            poprzedni=0;
        }
        else
        {
            result[i].cost=MAX;
            odwiedzony[i]=false;
            result[i].path.push_back(graph.pierwszy_wierz);
        }   
    }

    // int pom=graph.pierwszy_wierz;
    // int minimum=Minimum(graph.wierzcholki,result,odwiedzony);


    // std::cout<<minimum;
    // while(minimum!=-MAX)
    // {        
    //     odwiedzony[poprzedni]=true;
    //     std::vector<int> pol;
    //     pol=graph.liczbaPolaczen(minimum); //wektor z polaczonymi wierzcholami z wierzcholkiem i 

    //         for (int j = 0; j < pol.size(); j++)
    //         {
    //             if(graph.Czy_istnieje_polaczenie(minimum,pol[j])&&( result[pol[j]].cost > result[minimum].cost+graph.zwroc_wage(minimum,pol[j])))
    //             {
    //                 //Nie wchodzi mi do tego if z powodu tego, że to esult[pol[j]].cost>result[minimum].cost+graph.zwroc_wage(minimum,pol[j])) jest zawsze fajszywe
                    
    //                 result[pol[j]].cost=graph.zwroc_wage(minimum,pol[j])+result[minimum].cost;
    //                 std::cout<<result[pol[j]].cost;

    //                 result[pol[j]].path.push_back(poprzedni);

    //                 poprzedni=minimum;
    //             }

    //         }
    //         minimum=Minimum(graph.wierzcholki,result,odwiedzony);
    // }

}

bool bellmanFord(Graph& graph, int sourceIndex, ShortestPathResult& result)
{
    // TODO: implement
    return true;
}
