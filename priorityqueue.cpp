#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Node {
public:
  T item;
  int priority;
  Node<T>* next;
  Node<T>* prev;
  Node();
  Node(T data, int p) {
    item = data;
    priority = p;
    next = nullptr;
    prev = nullptr;
  }
};

template <class T>
class PriorityQueue {
  Node<T>* head;
  Node<T>* tail;
  int itemCount;
public:
  PriorityQueue() {
    head = nullptr;
    tail = nullptr;
  };
  bool isEmpty() {
    Node<T>* temp;
    temp = head;
    if (temp == nullptr) {
      return true;
    }
    else {
      return false;
    }
  }
  bool enqueue(T newEntry, int prior) {
    if (head == nullptr) {
      Node<T>* a = new Node<T>(newEntry, prior);
      head = a;
      tail = a;
      itemCount++;
      return true;
    }
    else {
      Node<T>* b = new Node<T>(newEntry, prior);
        if (b->priority > tail->priority) {
            Node<T>* current;
            current = tail;
            while (b->priority > current->priority) {
              current = current->prev;
            }
            Node<T>* temp;
            temp = current->prev;
            temp->next = b;
            b->prev = temp;
            b->next = current;
            current->prev = b;
            itemCount++;
            return true;
        }
        else {
          tail->next = b;
          b->prev = tail;
          tail = b;
          itemCount++;
          return true;
        }
    }
  }
  bool dequeue ()
};


/*
template <class T>
class List {
  Node<T>* head;
  Node<T>* tail;
  int itemCount = 0;
public:
  List() {
    head = nullptr;
    tail = nullptr;
  };
  bool isEmpty() {
    Node<T>* temp;
    temp = head;
    if (temp == nullptr) {
      return true;
    }
    else {
      return false;
    }
  }
  bool add(T newEntry) {
// adds to end of list
    if (head == nullptr) {
      Node<T>* a = new Node<T>(newEntry);
      head = a;
      tail = a;
      itemCount++;
      return true;
    }
    else {
      Node<T>* b = new Node<T>(newEntry);
      tail->next = b;
      b->prev = tail;
      tail = b;
      itemCount++;
      return true;
    }
  }
  bool remove(T anEntry) {
    if (head == nullptr) {
      cout << "The list is empty, cannot remove" << endl;
      return false;
    }
    else if (head->item == anEntry) {
        delete head;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
    }
    else {
      Node<T>* temp;
      temp = head;
      int counter = 0;
      while (temp->item != anEntry) {
        temp = temp->next;
        counter++;
        if (counter > itemCount) {
          cout << "The list does not contain " << anEntry << endl;
          return false;
        }
      }
      Node<T>* n;
      n = temp->prev;
      n->next = temp->next;
      if (temp->next == nullptr) {
        delete temp;
        tail = n;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
      }
      else {
        delete temp;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        temp->next->prev = n;
        return true;
      }
    }
  }
  void clear() {
    Node<T>* n;
    n = head;
    while (n) {
      cout << n->item << endl;
      if(n->prev) {
        delete n->prev;
      }
      n = n->next;
    }
    delete n;
    head = nullptr;
    tail = nullptr;
    itemCount = 0;
    cout << "The list has been successfully cleared" << endl;
  }
  int getFrequencyOf(T anEntry) {
    int counter = 0;
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            counter++;
        }
        a = a->next;
    }
    return counter;
  }
  bool contains(T anEntry) {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            return true;
        }
        a = a->next;
    }
    return false;
  }
  int returnCount() {
    return itemCount;
  }
  T returnHead() {
    return head->item;
  }
  T returnTail() {
    return tail->item;
  }

  Node<T>* getHead() {
    return head;
  }
  Node<T>* getTail() {
    return tail;
  }
  void print() {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
      cout << a->item << endl;
      a = a->next;
    }
  }
  void printReverse() {
    Node<T>* a;
    a = tail;
    for (int i = 0; i < itemCount; i++) {
      cout << a->item << endl;
      a = a->prev;
    }
  }
};
*/
