#ifndef STACK_HPP_
#define STACK_HPP_
#include "list.hpp"

template <typename T>
class Stack
{
  public:
    void push(const T& newElement);
    T pop();
    List<T> stack;
};

template <typename T>
void Stack<T>::push(const T& newElement)
{
  stack.pushFront(newElement);
}

template <typename T>
T Stack<T>::pop()
{
  auto element=stack[0];

  stack.remove_first_elem();

  return element;
}

#endif /* STACK_HPP_ */
