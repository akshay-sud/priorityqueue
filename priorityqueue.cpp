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
  bool dequeue () {
    bool test;
    test = isEmpty();
    if (test == true) {
      cout << "The queue is empty" << endl;
      return false;
    }
    else {
      Node<T>* temp;
      temp = head->next;
      delete head;
      head = temp;
      return true;
    }
  }
  T peekFront() {
    return head->item;
  }
};

int main() {
    PriorityQueue<string> xyz;
    bool t;
    t = xyz.isEmpty();
    if (t == true) {
    cout << "the queue is empty"<< endl;
    }
    else {
        cout << "the queue has some stuff in it" << endl;
    }
    cout << "we're now going to add some stuff into this queue" << endl;

    t = xyz.enqueue("hey", 1);
    t = xyz.enqueue("hey", 1);
    t = xyz.enqueue("you", 1);
    t = xyz.enqueue("you", 1);
    t = xyz.enqueue("i", 1);
    t = xyz.enqueue("dont", 1);
    t = xyz.enqueue("like", 1);
    t = xyz.enqueue("your", 1);
    t = xyz.enqueue("girlfriend", 1);

    t = xyz.isEmpty();
    if (t == true) {
    cout << "the queue is empty"<< endl;
    }
    else {
        cout << "the queue has some stuff in it" << endl;
    }
    cout << "the first string in this queue is: " << xyz.peekFront() << endl;
    cout << "we're now going to dequeue twice" << endl;
    t = xyz.dequeue();
    t = xyz.dequeue();
    cout << "the first string in this queue is: " << xyz.peekFront() << endl;
  return 0;
}
