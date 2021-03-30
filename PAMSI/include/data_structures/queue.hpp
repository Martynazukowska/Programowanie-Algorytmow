#ifndef QUEUE_HPP_
#define QUEUE_HPP_
#include "list.hpp"

template <typename T>
class Queue
{
  public:
    void enqueue(const T& newElement);
    T dequeue();
    List<T> queue;
};

template <typename T>
void Queue<T>::enqueue(const T& newElement) 
{
    queue.pushBack(newElement);                // dodac element do kolejki
}

template <typename T>
T Queue<T>::dequeue()
{
  auto element=queue[0];                       // przypisujemy pierwszy element listy z wartosciami 

  queue.remove_first_elem();                   // usuwamy pierwszy element w kolejce

  return element;
}

#endif /* QUEUE_HPP_ */
