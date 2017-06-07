
#ifndef CHASHTABLE_H
#define CHASHTABLE_H

#include <iostream>
#include <forward_list>
#include <functional>

template <class Key, class T>
class HashItem
{
 public:
  HashItem(Key k, T data) : key(k), val(data){};

  inline Key getKey() const { return key; }
  inline T getValue() const { return val; }

 private:
  Key key;
  T val;
};

template <class Key, class T>
class HashTable
{
 public:
  HashTable(size_t size)
  {
    if (size == 0) size = 29;  // a prime #
    table = new std::forward_list<HashItem<Key, T>>[size];

    length = size;
  }

  ~HashTable() { delete[] table; }

  void printTable()
  {
    std::cout << "[\n";
    for (int i = 0; i < length; i++)
    {
      if (!(table[i].empty()))
      {
        for (auto it = table[i].cbegin(); it != table[i].cend(); it++)
        {
          std::cout << "  " << (*it).getKey() << "\t:\t" << (*it).getValue()
                    << '\n';
        }
      }
    }
    std::cout << "]\n";
  }

  // inserts item w/ key
  void insert(Key key, T item)
  {
    int index = hash(key);

    table[index].emplace_front(HashItem<Key, T>(key, item));
  }

  // removes item w/ given key
  void remove(Key key)
  {
    int index = hash(key);

    for (auto it = table[index].begin(); it != table[index].end(); it++)
    {
      if ((*it).getKey() == key)
      {
        table[index].erase_after(it--, it++);
      }
    }
  }

  // gets item by key
  // returns nullptr if an item
  // w/ given key doesnt exist
  T get(Key key)
  {
    int index = hash(key);
    for (auto it = table[index].begin(); it != table[index].end(); it++)
    {
      if ((*it).getKey() == key)
      {
        return (*it).getValue();
      }
    }
    return nullptr;
  }

 private:
  std::forward_list<HashItem<Key, T>>* table;

  size_t length;

  std::hash<Key> prehash;

  // described as 'hacky'
  // this is not the best hash function at all
  //
  // it is best if used w/ a size that
  // isn't a factor of 2, 10, or many common #s either.
  //
  // best if length is a prime #
  int hash(Key key) { return prehash(key) % length; }
};

#endif
