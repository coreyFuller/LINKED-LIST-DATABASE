#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct Node {
  int key;
  char code;
  string name;
  double sales;
  struct Node * next;
}Node;

class LinkedList {

private:
  
  Node * head;
  int nodeCount;
  int workerCount;
  double average;
  double minSale;
  double maxSale;
  double sum;
  ofstream output;
public:
  
  LinkedList();
  LinkedList(string );
  void push_back();
  void push_front();
  void printList();
  void at(int);
  void deleteList();
  void peek_back();
  void peek_front();
  void avg();
  void max();
  void min();
  void sumAll();
  void pop_back();
  void pop_front();
  void makeReport();
  bool isEmpty();
  ~LinkedList();
};






#endif
