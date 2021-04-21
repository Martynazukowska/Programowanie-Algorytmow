#ifndef SORTING_HPP_
#define SORTING_HPP_

#include <vector>

void bubbleSort(std::vector<int>& tab);
void insertSort(std::vector<int>& tab);
void heapSort(std::vector<int>& tab);
void quickSort(std::vector<int>& tab,int pierwszy,int ostatni);
void mergeSort(std::vector<int>& tab,int pierwszy, int ostatni);
void bucketSort(std::vector<int>& tab);
void scal_tablice(std::vector<int>& tab, int pierwszy, int srodek, int ostatni);

#endif /* SORTING_HPP_ */