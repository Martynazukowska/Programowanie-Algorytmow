#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <fstream>
#include <iostream>
#include <vector>
#include <memory>

class Graph
{ 
  public:
  unsigned int krawedzie;
  unsigned int wierzcholki;
  unsigned int pierwszy_wierz;

  static std::unique_ptr<Graph> createGraph(std::istream& is);

  virtual std::vector<int> liczbaPolaczen(unsigned int intex)=0; 
  virtual bool Czy_istnieje_polaczenie(unsigned int PierwszyW, unsigned int Drugii_W)=0;
  virtual int zwroc_wage(int Pierwszy,int Drugi) = 0;
  


};



#endif /* GRAPH_HPP_ */
