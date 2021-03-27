#ifndef LIST_HPP_
#define LIST_HPP_
//using namespace std;
#include <iostream>

template <typename T>
class List
{
  public:
    class Node; //mówimy że będzie , później rozpiszemy 
    T counter; 
    std::shared_ptr<Node> head =nullptr;
    std::shared_ptr<Node> tail =nullptr;
    
    class Node
    {      
      public:
        T value; //wartość
        std::shared_ptr<Node> next; //inteligetny wskaźnik na kolejny element
        std::shared_ptr<Node> before; // inteligentny wskaźnik na wcześniejszy element

        std::shared_ptr<Node> newNode(T nowa)
        {
          std::shared_ptr<Node> X = std::make_shared<Node>();
          X->value = nowa;
          X->next = nullptr;
          X->before = nullptr;
          return X;
        }
    };
    
    class Iterator
    {
      private:
      std::shared_ptr<Node> n_ptr=nullptr;

      public:
        using difference_type = long;
        using value_type = T;
        using pointer = const T*;
        using reference = const T&;
        using iterator_category = std::random_access_iterator_tag;

        Iterator(Node* node = nullptr);

        Iterator operator++();
        Iterator operator--();
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        bool operator>(const Iterator& other) const;
        bool operator<(const Iterator& other) const;
        difference_type operator-(const Iterator& other) const;
        Iterator operator+(difference_type diff) const;
        Iterator operator-(difference_type diff) const;
        Iterator operator[](std::size_t i);
        T& operator*();
    };

    class ConstIterator
    {
      private:
      std::shared_ptr<Node> n_ptr=nullptr;

    public:
      using difference_type = long;
      using value_type = T;
      using pointer = const T*;
      using reference = const T&;
      using iterator_category = std::random_access_iterator_tag;

      ConstIterator(Node* node = nullptr);

      ConstIterator operator++();
      ConstIterator operator--();
      bool operator==(const ConstIterator& other) const;
      bool operator!=(const ConstIterator& other) const;
      bool operator>(const ConstIterator& other) const;
      bool operator<(const ConstIterator& other) const;
      difference_type operator-(const ConstIterator& other) const;
      ConstIterator operator+(difference_type diff) const;
      ConstIterator operator-(difference_type diff) const;
      ConstIterator operator[](std::size_t i);
      const T& operator*();
    };

    void pushBack(const T& newElement);
    void pushFront(const T& newElement);
    void insert(const T& newElement, int index);
    void remove(const T& element);
    Iterator begin();
    Iterator end();
    ConstIterator cbegin() const;
    ConstIterator cend() const;
    T& operator[](int index);
};

template <typename T>
List<T>::Iterator::Iterator(typename List<T>::Node* node)
{

}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator++()
{
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator--()
{
  // TODO: implement
  return Iterator();
}

template <typename T>
bool List<T>::Iterator::operator==(const Iterator& other) const
{
  if(n_ptr == other.n_ptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
bool List<T>::Iterator::operator!=(const Iterator& other) const
{
  if(n_ptr != other.n_ptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
bool List<T>::Iterator::operator>(const Iterator& other) const
{
  return true;
}

template <typename T>
bool List<T>::Iterator::operator<(const Iterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
typename List<T>::Iterator::difference_type List<T>::Iterator::operator-(const Iterator& other) const
{
  int dodatkowa=0;
  
  return 0;
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator+(difference_type diff) const
{
  Iterator I();
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator-(difference_type diff) const
{
  // TODO: implement
  return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::Iterator::operator[](std::size_t i)
{
  std::shared_ptr<Node> dodatkowy(nullptr);
  if(i==0)
    {
      dodatkowy=n_ptr;
    }
  else
    {
      dodatkowy=n_ptr;
      for(int x=0; x<=i; x++)
      {
        dodatkowy=dodatkowy->next;
      }

    }
  return Iterator(dodatkowy);
}

template <typename T>
T& List<T>::Iterator::operator*()
{
    // TODO: implement
    static T element;
    return element;
}





template <typename T>
List<T>::ConstIterator::ConstIterator(typename List<T>::Node* node)
{
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator++()
{
  // TODO: implement
  return ConstIterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator--()
{
  // TODO: implement
  return ConstIterator();
}

template <typename T>
bool List<T>::ConstIterator::operator==(const ConstIterator& other) const
{
  if(n_ptr == other.n_ptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
bool List<T>::ConstIterator::operator!=(const ConstIterator& other) const
{
  if(n_ptr != other.n_ptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <typename T>
bool List<T>::ConstIterator::operator>(const ConstIterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
bool List<T>::ConstIterator::operator<(const ConstIterator& other) const
{
  // TODO: implement
  return true;
}

template <typename T>
typename List<T>::ConstIterator::difference_type List<T>::ConstIterator::operator-(const ConstIterator& other) const
{
  // TODO: implement
  return 0;
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator+(difference_type diff) const
{
  // TODO: implement
  return Iterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator-(difference_type diff) const
{
  // TODO: implement
  return ConstIterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::ConstIterator::operator[](std::size_t i)
{
  std::shared_ptr<Node> dodatkowy(nullptr);
  if(i==0)
    {
      dodatkowy=n_ptr;
    }
  else
    {
      dodatkowy=n_ptr;
      for(int x=0; x<i; x++)
      {
        dodatkowy=dodatkowy->next;
      }   
    }
  return Iterator(dodatkowy);
}

template <typename T>
const T& List<T>::ConstIterator::operator*()
{
    // TODO: implement
    static T element;
    return element;
}









template <typename T>
void List<T>::pushBack(const T& newElement)
{
  Node N;
  std::shared_ptr<Node> dodatkowy = N.newNode(newElement); //inteligentny wskaźnik zawierający odpowiednia wartość 
  if(head==nullptr)
  {
    head=dodatkowy;
    tail=dodatkowy;
  }
  else 
  {

    std::shared_ptr<Node> jump(nullptr);
    jump = head;
    for(int i=0; jump->next != nullptr; i++)
    {
      jump = jump->next;

    }
    jump->next = dodatkowy;
    tail=dodatkowy;
  }
  counter++;   
}
template <typename T>
void List<T>::pushFront(const T& newElement)
{
  Node N;
  std::shared_ptr<Node> dodatkowy = N.newNode(newElement);
  if(head==nullptr)
  {
    head=dodatkowy;
  }
  else
  {
    dodatkowy->next =head;
    head->before = dodatkowy;
    head = dodatkowy;
  }
  counter ++;

}
template <typename T>
void List<T>::insert(const T& newElement, int index)
{
  Node N;
  std::shared_ptr<Node> dodatkowy =N.newNode(newElement);
  if(index==0)
  {
    pushFront(newElement);
  }
  else
  {
    if(index==counter)
    {
      pushBack(newElement);
    }
    else
    {
      if(index < 0 /*|| counter-1<index*/)  //czemu to nie działa???????????????????????????????????????????????????????????????????????????????
      {
          std::cout<<"Błąd w podawaniu instrukcji \n ";
          exit(1);
      }
      else
      {
        if(head == nullptr)
        {
          head = dodatkowy;
        }
        else 
        {
         index--;
         std::shared_ptr<Node> jump(nullptr);
          jump=head;
          for(int i=0; i<index; i++)
          {
            jump=jump->next;
          }
          dodatkowy->next = jump->next;
          dodatkowy->before = jump;

          dodatkowy->next->before=dodatkowy; 

          jump->next=dodatkowy;

          ////////////////////////////////////zapytać czy można zrobić podwójny wektor -> cos -> !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1
        }
      }
    }
  }
  counter++;
}

template <typename T>
void List<T>::remove(const T& element)
{
  int Pomicniczy;
  Pomicniczy=0;
  if(head == nullptr)
  {
    std::cout<<"Lista jest juz pusta \n";
    exit(1);
  }
  std::shared_ptr<Node> jump(nullptr);
  jump =head;

  for(int i=0; jump->value != element; i++)
  {
    jump=jump->next;
    Pomicniczy++;
  }
    if(Pomicniczy==0)
    {
      head=jump->next; //zeby nie zgubic
      jump->next->before=jump->before;
      jump->next=nullptr;
      jump->before=nullptr;
    }
    else
    {
       if(Pomicniczy==counter-1)
      {
        tail=jump->before; //zeby nie zgubic
        jump->before->next=jump->next;
        jump->next=nullptr;
        jump->before=nullptr;
      }
      else
      {
        if(Pomicniczy==counter)
        {
          std::cout<<"Lista nie ma takiego elementu\n";
          exit(1);
        }
        else
        {
          /*jump->before->next= jump->next;
          jump->next->before= jump->before;
          jump->next=nullptr;
          jump->before=nullptr; ?????????????????????????????????????????????????????????????????????????????????????????????????????????????????????*/
        }
      }
    }
    counter--;
    Pomicniczy--;

}

template <typename T>
typename List<T>::Iterator List<T>::begin()
{
    // TODO: implement
    return Iterator();
}

template <typename T>
typename List<T>::Iterator List<T>::end()
{
    // TODO: implement
    return Iterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::cbegin() const
{

    // TODO: implement
    return ConstIterator();
}

template <typename T>
typename List<T>::ConstIterator List<T>::cend() const
{
    return ConstIterator();
    // TODO: implement
}

template <typename T>
T& List<T>::operator[](int index)
{
  static T element;
  std::shared_ptr<Node> dodatkowy(nullptr);
  if(index==0)
    {
      dodatkowy=head;
    }
  else
    {
      dodatkowy=head;
      for(int x=0; x<index; x++)
      {
        dodatkowy=dodatkowy->next;
      }   
    }
  element=dodatkowy->value;
  return element;
}

#endif /* LIST_HPP_ */
