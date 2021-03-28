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
    List<T> P_Queue;
    List<T> Priority_Q;

};


template <typename T>
void PriorityQueue<T>::enqueue(const T& newElement, int priority)
{
  int pomocniczy=0;
  Priority_Q.pushBack(priority);
  
  std::sort(Priority_Q.begin(), Priority_Q.end());

  for(int i=0; i<Priority_Q.counter; i++)
  {
    if(Priority_Q[i]>priority)
    {
      pomocniczy++;
    }

  }

  if(P_Queue.counter==0)
  {
    P_Queue.pushBack(newElement);
  }
  else
  {
    P_Queue.insert(newElement, pomocniczy);
  }
  
}

template <typename T>
T PriorityQueue<T>::dequeue()
{
  
  auto element=P_Queue[0];

  P_Queue.remove_first_elem();

  return element;
}

#endif /* PRIORITY_QUEUE_HPP_ */
