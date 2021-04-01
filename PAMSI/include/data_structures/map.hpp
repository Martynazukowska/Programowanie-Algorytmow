#ifndef MAP_HPP_
#define MAP_HPP_
#include "list.hpp"
#include <string>
#include "priority_queue.hpp"


/*****************************************************************
/     Drugi sposob 
/*****************************************************************/

//template<typename Key>                    // dodatkowo
//using Hashfunction = int(*)(const Key&);  // dodatkowo

//template<typename  KeyType, typename ValueType, typename Hashfunction>


template <typename KeyType, typename ValueType>
class Map
{ 
private:
  std::array<ValueType,100> tab; 
public:
  Map(){ }
  Map(const Map& otherMap) { }

  void insert(const KeyType& key ,const ValueType& value);
  ValueType& operator[](const KeyType& key);
  void remove(const KeyType& key);

};


//template <typename KeyType, typename ValueType, typename Hashfunction>
//void Map<KeyType, ValueType,Hashfunction>::insert(const KeyType& key, const ValueType& value)
template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::insert(const KeyType& key, const ValueType& value)
{
  auto index = hash(key);

  tab[index]=value;

}

//template <typename KeyType, typename ValueType, typename Hashfunction>
//ValueType &Map<KeyType, ValueType,Hashfunction>::operator[](const KeyType &key) {

template <typename KeyType, typename ValueType>
ValueType &Map<KeyType, ValueType>::operator[](const KeyType &key) {

  return tab[hash(key)];

}
//template <typename KeyType, typename ValueType, typename Hashfunction>
//void Map<KeyType, ValueType, Hashfunction>::remove(const KeyType &key)
template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::remove(const KeyType &key)
    {
      tab[hash(key)]=nullptr;
    }

#endif /* MAP_HPP_ */
