#include "linkedlist.h"

Node::Node(int val) {
  value = val;
  next = 0;
}

Node::Node(int val, Node *node) {
}

int Node::getValue() {
  return value;
}

void Node::setValue(int val) {
  value = val;
}

Node * Node::getNext() {
  return next;
}

void Node::setNext(Node *node) {
  next = node;
}

LinkedList::LinkedList() {
  head = 0;
  length = 0;
}
/*
int LinkedList::getLength() {
  return length;
}
*/

void LinkedList::insertAt(int val, int index) {
  if (length < index) {
    return;
  }
  if (head == 0) {
    head = new Node(val);
  } else {
    Node *newNode, *ptr = head;
    newNode = new Node(val);
    for (int i = 0; i < index - 1; i++) {
      ptr = ptr->getNext();
    }
    
    if (index == 0) {
      head = newNode;
      newNode->setNext(ptr);
    } else {
      newNode->setNext(ptr->getNext());
      ptr->setNext(newNode);
    }
  }
  length++;
}

void LinkedList::insertBegin(int val) {
  insertAt(val, 0);
}

void LinkedList::insertEnd(int val) {
  insertAt(val, length);
}

void LinkedList::print () {
  Node *ptr = head;
  while (ptr != 0) {
    std::cout << ptr->getValue() << "\t";
    ptr = ptr->getNext();
  }
  std::cout << std::endl;
}

void LinkedList::Delete(int val) {
  Node *prev, *ptr = head;
  bool hasValue = false;
  while (ptr != 0) {
    if (ptr->getValue() == val) {
      hasValue = true;
      break;
    }
    prev = ptr;
    ptr = ptr->getNext();
  }
  if (hasValue) {
    prev->setNext(ptr->getNext());
    std::cout << val << " deleted" << std::endl;
    length--;
    return;
  }
  std::cout << val <<" not present." << std::endl;
}

int LinkedList::getLength() {
  int count = 0;

  Node *ptr = head;
  while (ptr != 0) {
    count++;
    ptr = ptr->getNext();
  }
  return count;
}

int LinkedList::getNth (int val) {
  if (length < val) {
    std::cout << "Index out of bounds!" << std::endl;
    return 0;
  }
  Node *ptr = head;
  for (int i = 0; i < val; i++) {
    ptr = ptr->getNext();
  }
  return ptr->getValue();
}

void LinkedList::DeleteList() {
  Node *ptr = head;
  while (head != NULL) {
    head = head->getNext();
    free(ptr);
    ptr = head;
  }
}

int LinkedList::pop() {
  Node *ptr = head;
  head = head->getNext();
  int val = ptr->getValue();
  free(ptr);
  return val;
}

