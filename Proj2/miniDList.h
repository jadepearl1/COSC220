#ifndef MINIDLIST_H
#define MINIDLIST_H
#include <iostream> // For cout
using namespace std;

template <class DataType>
class miniDList
{
private:
  struct DNode
  {                // doubly linked list node
    DataType data; //  data stored in node
    DNode *next;   //  next node in list
    DNode *prev;   //  previous node  in list
  };

  DNode *header; // list sentinels
  DNode *trailer;

public:
  miniDList()
  { // constructor
    header = new DNode;
    trailer = new DNode; // have them point to each other
    header->next = trailer;
    trailer->prev = header;
  }
  miniDList(const miniDList<DataType> &l);                      // Copy constructor
  ~miniDList();                                                 // Destructor
  const DataType &front() const;                                // get front element
  const DataType &back() const;                                 // get back element
  void removeFront();                                           // Remove the front
  void removeBack();                                            // Remove the back
  void addFront(const DataType &e);                             // Add to the front
  void addBack(const DataType &e);                              // Add to the back
  int size() const;                                             // Returns the number of elements in list
  bool contains(const DataType &e);                             // Tests for membership
  void display() const;                                         // Prints the elements of list
  miniDList<DataType> &operator=(const miniDList<DataType> &l); // Overloaded assignment

protected:                               // local utilities
  void add(DNode *v, const DataType &e); // insert new node  before  v
  void remove(DNode *v);                 // remove node v
};


template<class DataType>
miniDList<DataType>::miniDList(const miniDList<DataType> &l)
{
  //arrow notation needs to be used since DNode is a struct, not a class
  DNode *nodePtr = l->header->next;
	while (nodePtr != l->trailer)
		addFront(nodePtr->data);
}


template<class DataType>
miniDList<DataType>::~miniDList()
{
  DNode *nodePtr = header;
  while(nodePtr->next != trailer)
    removeBack();
}


template<class DataType>
const DataType& miniDList<DataType>::front() const
{
  return header->next->data;
}


template<class DataType>
const DataType& miniDList<DataType>::back() const
{
  return trailer->prev->data;
}


template<class DataType>
void miniDList<DataType>::removeFront()
{
  remove(header->next); //assigns new first element
}


template<class DataType>
void miniDList<DataType>::removeBack()
{
  remove(trailer->prev);
}


template<class DataType>
void miniDList<DataType>::addFront(const DataType &e)
{
  DNode *newNode = new DNode;
  DNode *nextNode = header->next;
  newNode->data = e;
  
  nextNode->prev = newNode;
  newNode->next = nextNode;
  newNode->prev = header;
  header->next = newNode;
}


template<class DataType>
void miniDList<DataType>::addBack(const DataType &e)
{
  DNode *newNode = new DNode;
  newNode->data = e;
  DNode *temp = trailer->prev;

  trailer->prev->next = newNode;
  newNode->prev = temp;
  newNode->next = trailer;
  trailer->prev = newNode;
}


template<class DataType>
int miniDList<DataType>::size() const
{
  DNode *nodePtr = header;
  int sz = 0;
  while(nodePtr->next != trailer)
  {
    nodePtr = nodePtr->next;
    sz++;
  }
  return sz;
}


template<class DataType>
bool miniDList<DataType>::contains(const DataType &e)
{
  DNode *nodePtr = header->next;
  while (nodePtr != trailer && nodePtr->data != e)
  {
    nodePtr = nodePtr->next;
  }

  if (nodePtr->data == e)
    return true;
  else
    return false;
  nodePtr = nullptr;
}


template<class DataType>
void miniDList<DataType>::display() const
{
  DNode *nodePtr = header->next;
  while (nodePtr != trailer)
  {
    cout << nodePtr->data << " ";
    nodePtr = nodePtr->next;
  }
  cout << endl;
}


template<class DataType>
miniDList<DataType> &miniDList<DataType>::operator= (const miniDList<DataType> &l)
{
  DNode *nodePtr = l.header;
  
  while(nodePtr != nullptr)
  {
    addBack(nodePtr->data);
    nodePtr = nodePtr->next;
  }
  return *this;
}


template<class DataType>
void miniDList<DataType>::add(DNode *v, const DataType &e)
{
  DNode *newNode = new DNode;
  newNode->data = e;
  newNode->prev = v->prev;
  newNode->next = v;
  v->prev = newNode;
}


template<class DataType>
void miniDList<DataType>::remove(DNode *v)
{
  v->prev->next = v->next;
  v->next->prev = v->prev;
  delete v;
}

#endif