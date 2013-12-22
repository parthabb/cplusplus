// Header file for dll.cpp.

#ifndef DOUBLE_LINKEDLIST_H_
#define DOUBLE_LINKEDLIST_H_

template <class T>
class DoubleLinkedList {
  private:
    Node <T> * head;
    Node <T> * tail;
    int length;
  public:
    // TODO raise an exception is case of an error.
    DoubleLinkedList ();
    void insert (T, int);  // insert at position int.
    void insertAtStart (T);
    void insertAtEnd (T);
    void del (T);
    void getIndexByValue (T);
    void getValueByIndex (int);
    void printFront ();
    void printBack ();
};
#endif
