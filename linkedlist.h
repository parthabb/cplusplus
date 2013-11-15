#include <iostream>

class Node {
  private:
    int value;
    Node *next;
  public:
    Node(int);
    Node(int, Node *);
    int getValue();
    void setValue(int);
    Node * getNext();
    void setNext(Node *);
};


class LinkedList {
  private:
    Node *head;
    int length;

  public:
    LinkedList();
    //int getLength();
    void insertAt(int, int);
    void insertBegin(int);
    void insertEnd(int);
    void print();
    void Delete(int);
    int getLength();
    int getNth(int);
    void DeleteList();
    int pop();
    void sort();
};

