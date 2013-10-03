#include "linkedlist.h"

int main(int args, char** argv) {
  std::cout << "Hello World" << std::endl;
  LinkedList *list = new LinkedList();
  list->insertAt(1, 0);
  list->insertAt(2, 0);
  list->insertAt(3, 0);
  list->print();
  list->Delete(2);
  list->print();
  list->insertBegin(12);
  list->print();
  list->insertEnd(100);
  list->print();
  list->insertAt(66, 2);
  list->print();
  list->Delete(122);
  list->print();
  std::cout << list->getLength() << std::endl;
  std::cout << list->getNth(3) << std::endl;
  //list->DeleteList();
  std::cout << list->pop() << " popped" << std::endl;
  list->print();
  std::cout << "Bye Bye World!" << std::endl;
}

