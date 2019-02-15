// table.cpp

#include <vector>
#include <iostream>
#include "entry.h"
#include <sstream>
#include "table.h"
#include <string>

Table::Table(unsigned int max_entries = 100) {

  size = max_entries;
  hashTable.resize(size);

}

Table::Table(unsigned int entries, std::istream& input) {

    size = entries;
    hashTable.resize(size);
    for (int i = 0; i < size; i++){
      Entry x;
      put(x);
    } 
  }
  
int Table::getSize() {

  return size;

}

void Table::put(unsigned int key, std::string data) {

  unsigned int index = hashingFunction(key);

  while (hashTable[index] != NULL && hashTable[index].get_key() != key) {
    index = (index + 1) % size;
  }
  
  if (hashTable[index] != NULL){
    delete hashTable[index];
  }
  
  hashTable[index] = new Entry(key, data);

}

void Table::put(Entry e) {

  unsigned int index = hashingFunction(e.get_key());

  while (hashTable[index] != NULL && hashTable[index]->get_key() != key) {
    index = (index + 1) % size;
  }
  
  if (hashTable[index] != NULL){
    delete hashTable[index];
  }
  
  hashTable.insert(index, new Entry(e.get_key(), e.get_data()));

}

std::string get(unsigned int key){

  unsigned int index = hashingFunction(key);
  while(hashTable[index] != NULL && hashTable[index]->get_key() != key){
    index = (index + 1)&size;
  }
  if (hashTable[index]==NULL)
    return 0;
  else
    return hashTable[index]->get_data();

}
  
void Table::remove(unsigned int key) {

  vector<list<Entry>>::iterator a;
  for (a=List.begin(); a != List.end(); a++){
    if(find((*a).begin(), (*a).end(), key) != (*a).end()){
      (*a).pop_back();
    }
  }
}
  
Void Table::mergeSort(Entry data[], size_t tableSize) {

  size_t n1;
  size_t n2;

  if (n > 1) {

    n1 = n / 2;
    n2 = n - n1;

    mergeSort(data, n1);
    mergeSort((data + n1), n2);

    merge(data, n1, n2);
    
  }
}

void Table:: merge(int data[], size_t n1, size_t n2){

  int *temp;
  size_t copied = 0;
  size_t copied1 = 0;
  size_t copied2 = 0;
  size_t i;

  temp = new int[n1 + n2];

  while((copied1 < n1) && (copied2 < n2)){

    if (data[copied] < (data + n1)[copied2])
      temp[copied++] = data[copied1++];
    else
      temp[copied++] = (data+n1)[copied2++];

  }

  while (copied1 < n1)
    temp[copied++] = data[copied1++];
  while (copied2 < n2)
    temp[copied++] = (data+n1)[copied2++];

  for (i=0; i<n1 + n2; ++1)
    data[i] = temp[i];
  delete[] temp;
  
}

std::ostream& operator<< (std::ostream out, const Table& t) {

  std::vector<Entry> vector1;
  for (int i = 0; i < t.size(); i++){
    if (t[i].empty()){
      continue;
    }
    for (int j = 0; j < t[i].size(); j++) {
      vector1.push_back(t[i]);
    }
  }
  
  Entry data[vector2.size()];
  
  for(int i = 0; i < vector1.size(); i++) {
    data[i] = vector1[i];
  }

  mergesort(data);
  
  for (int i = 0; i < data.size(); i++) {
    out << data[i] << "\n";
  }
  /*
  for (i = 0; i < size; i++) {
    out.append(hashingTable(i).get_data(), "\n");
  }
  cout << out << endl;
  */
  
}// table.cpp
