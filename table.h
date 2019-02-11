// Andrew Cizas
// table.h
// W19 - Lab04
// 1:00-1:50 pm
#ifndef table_h
#define table_h
#include "entry.h"
#include <string>
#include <iostream>
#include <vector>

class Table {
 
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

  // Hashing function
  int hashingFunction(int Entry);

  // Overloads the << operator to output entries on separate lines
  friend std::ostream& operator<< (std::ostream& out, const Table& t);

 private:
  size_t size;
  typedef std::vector<entry> entry;
  std::vector<entry> hashTable;
  size_t hashingFunction(int key){
    return key%size;
  }
  size_t hashingFunction(int key) const {
    return key%size;
  }
  
};

void mergeSort(Entry data[], size_t tableSize);
void mergeSort(Entry data[], size_t a, size_t b);

#endif /* table_h */
