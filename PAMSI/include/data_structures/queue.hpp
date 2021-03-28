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
    queue.pushBack(newElement);
}

template <typename T>
T Queue<T>::dequeue()
{
    T element;
    List<T> pomocniczy;
    element=queue.head->value;

    pomocniczy.head=queue.head;
    queue.head=queue.head->next;

  //pomocniczy.head->next->before=pomocniczy.head->before;

    pomocniczy.head->before=nullptr;
    pomocniczy.head->next=nullptr;
    queue.counter--;

    return element;
}

#endif /* QUEUE_HPP_ */
