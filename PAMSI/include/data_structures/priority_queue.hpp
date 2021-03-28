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
    if(Priority_Q[i]<priority)
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
  T element;
  List<T> pomocniczy;
  element=P_Queue.head->value;

  pomocniczy.head=P_Queue.head;
  P_Queue.head=P_Queue.head->next;

  //pomocniczy.head->next->before=pomocniczy.head->before;   ??????????????????????????????????????????????????????????????????????????????????????????????????????????????????/

  pomocniczy.head->before=nullptr;
  pomocniczy.head->next=nullptr;
  P_Queue.counter--;

  // TODO: implement
  return element;
}

#endif /* PRIORITY_QUEUE_HPP_ */
