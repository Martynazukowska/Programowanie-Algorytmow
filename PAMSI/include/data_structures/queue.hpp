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
  auto element=queue[0];

  queue.remove_first_elem();

  return element;
}

#endif /* QUEUE_HPP_ */
