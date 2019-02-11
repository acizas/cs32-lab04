// table.cpp

#include <vector>
#include <iostream>
#include "entry.h"
#include <sstream>
#include "table.h"

Table::Table(unsigned int max_entries = 100) {

  hashTable(max_entries);

}

Table::Table(unsigned int entries, std::istream& input {
    for (int i = 0; i < entries && std::getline(input); ++i) {
      std::string str;
      std::getline(input, str);
      std::string a = str.substr (0,5);
      std::string b = str.substr (7,30);
      Entry newEntry;
      newEntry.set_key(a);
      newEntry.set_data(b);
      hashTable(hashingFunction(newEntry))= newEntry;
    }
    sort(hashTable);
}

void Table::put(unsigned int key, std::string data) {

  Entry newEntry;
  newEntry.set_key(key);
  newEntry.set_data(data);
  hashTable(hashingFunction(newEntry)) = newEntry;
  sort(hashTable);

}

void Table::put(Entry e) {

  Entry newEntry;
  newEntry.set_key(e.get_key());
  newEntry.set_data(e.get_data());
  hashTable(hashingFunction(newEntry)) = newEntry;
  sort(hashTable);

}

std::string get(unsigned int key){

  std::string result = hashTable.at(hashTable.begin()+hashingFunction(key)).get_data();
  return result;

}
  
void Table::remove(unsigned int key) {

  hashTable.erase(hashTable.begin()+hashingFunction(key));
  
  /*
  int index = hashingFunction(key);
  list<Entry>::iterator i;
  for (i = table[index].begin(); i != table[index].end(); i++) {
    if (*i == key)
      break;
  }
  if (i != table[index].end())
    table[index].erase(i);
  */
}
  
void Table::sort(vector<Entry>& table) {

  if (table.size() <= 1){
    return;
  }

  int middle = (table.size())/2;
  vector<Entry> left;
  left.reserve(middle);
  right.reserve(table.size() - middle);
  vector<Entry> right;

  for (size_t j = 0; j < middle; j++){
    left.push_back(table[j]);
  }

  for (size_t j = 0; j < (table.size() - middle); j++){
    right.push_back(table[middle + j]);
  }

  sort(left);
  sort(right);
  mergeSort(left, right, table);

}

void Table:: mergeSort(vector<int>& left, vector<int>& right, vector<Entry>& entries) {
  
  int nL = left.size();
  int nR = right.size();
  int i=0;
  int j=0;
  int k=0;
  while (j < nL && k < nR) {
    if (left[j] < right[k]){
      entries[i] = left[j];
      j++;
    }
    else {
      entries[i] = right[k];
      k++;
    }
    i++;
  }
  while (j < nL){
    entries[i] = left[j];
    j++;
    i++;
  }
}

int Table::hashingFunction(Entry entry) {

  return (entry.get_key()%size);
  
}

std::ostream& operator<< (std::ostream out, const Table& t) {

  sort(t);
  for (i = 0; i < size; i++) {
    out.append(hashingTable(i).get_data(), "\n");
  }
  cout << out << endl;
  
}
  
