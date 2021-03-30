#ifndef PRIORITY_QUEUE_HPP_
#define PRIORITY_QUEUE_HPP_
#include "queue.hpp"

#include <iostream>
template <typename T>
class PriorityQueue
{
  public:
    void enqueue(const T& newElement, int priority);
    T dequeue();
    List<T> P_Queue; //wiekszy nacisk na kolejke -> tablia z wartościami kolejki 
    List<T> Priority_Q; // wiekszy nacisk na wage -> tablica z wartościami wagi działania

};


template <typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{
  int pomocniczy=0;
  Priority_Q.pushBack(priority);                       //dodajemy element do tablicy z wagami elementow
  
  std::sort(Priority_Q.begin(), Priority_Q.end());     // sortujemy liste z wagami 

  for(int i=0; i<=Priority_Q.counter; i++)             // szukamy dodanego przez nas wczesiej elementu gdzie sie znajduje po przesortowaniu 
  {
    if(Priority_Q[i]>priority)
    {
      pomocniczy++;
    }

  }
  P_Queue.insert(newElement, pomocniczy);           //dodajemy odpowiedni element w odowiednie miejsce juz do listy z wartosciami 
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
  
  auto element=P_Queue[0];                       // przypisujemy pierwszy element kolejki z wartosciami 

  P_Queue.remove_first_elem();                   // usuwamy ten element w kolejce

  return element;
}

#endif /* PRIORITY_QUEUE_HPP_ */
