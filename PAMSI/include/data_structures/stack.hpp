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
  stack.pushFront(newElement);              //dodac element do stosu 
}

template <typename T>
T Stack<T>::pop()
{
  auto element=stack[0];                       // przypisujemy pierwszy element stosu z wartosciami 

  stack.remove_first_elem();                  // usuwamy pierwszy element w stosie

  return element;
}

#endif /* STACK_HPP_ */
