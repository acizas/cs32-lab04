// Andrew Cizas
// table.h
// W19 - Lab04
// 1:00-1:50 pm
#ifndef table_h
#define table_h
#include <iostream>
#include <list>
#include "entry.h"
#include <sstream>
#include <vector>

class Table {
  int size;
  
 public:

  // Constructor
  Table(unsigned int max_entries = 100);

  // Constructor by input stream
  Table(unsigned int entries, std::istream& input);

  // Creates new entry and puts it in the table
  void put(unsigned int key, std::string data);

  // Creates a copy of the parameter in the table and puts it in the table
  void put(Entry e);

  // Returns a string associated with the parameter
  std::string get(unsigned int key) const;
  
  // Removes an entry with the given key
  bool remove(unsigned int key);

  // Sort the keys in the table
  void sort(std::vector<int>& bar);

  // Hashing function
  int hashingFunction(int Entry);

  // Mergesort the values of the table
  void mergeSort(std::vector<int>& left, std::vector<int>& right, std::vector<int>& bars);
  
  // Overloads the << operator to output entries on separate lines
  friend std::ostream& operator<< (std::ostream& out, const Table& t);

 private:
  std::vector<Entry> hashTable;
  
};

#endif /* table_h */
