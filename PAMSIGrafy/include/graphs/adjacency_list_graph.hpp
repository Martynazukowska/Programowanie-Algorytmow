#ifndef ADJACENCY_LIST_GRAPH_HPP_
#define ADJACENCY_LIST_GRAPH_HPP_

#include <memory>

#include "graphs/graph.hpp"


class AdjacencyListGraph : public Graph
{

  public:
  std::vector<int> polaczenia; // vektor przehowujacy ilosc polaczenien z odpowiednim wierzcholkiem

  std::vector<std::vector<std::vector<int>>> element;

  std::vector<int> liczbaPolaczen(unsigned int intex) override;
  bool Czy_istnieje_polaczenie(unsigned int PierwszyW, unsigned int Drugii_W)override;
  
  int zwroc_wage(int Pierwszy,int Drugi) override;


  static std::unique_ptr<Graph> createGraph(std::istream& is);
};

#endif /* ADJACENCY_LIST_GRAPH_HPP_ */

