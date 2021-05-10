#ifndef ADJACENCY_MATRIX_GRAPH_HPP_
#define ADJACENCY_MATRIX_GRAPH_HPP_
#define ILOSC_WIERZCHOLKOW 10


#include <memory>
#include <fstream>
#include <iostream>
#include <vector>

#include "graphs/graph.hpp"

class AdjacencyMatrixGraph : public Graph
{
  public:
  std::vector<std::vector<int>> elemnt;

  std::vector<int> liczbaPolaczen(unsigned int intex) override;
  bool Czy_istnieje_polaczenie(unsigned int PierwszyW, unsigned int Drugii_W)override;
  
  int zwroc_wage(int Pierwszy,int Drugi) override;
  
  static std::unique_ptr<Graph> createGraph(std::istream& is);

        
};

#endif /* ADJACENCY_MATRIX_GRAPH_HPP_ */
