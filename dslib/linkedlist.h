// Header file for linkedlist.cpp.

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

template <class T>
class LinkedList {
  private:
    Node <T> * head;
    int length;
  public:
    // TODO raise an exception is case of an error.
    LinkedList ();
    void insert (T, int);  // insert at position int.
    void insertAtStart (T);
    void insertAtEnd (T);
    void del (T);
    int getIndexByValue (T);
    T getValueByIndex (int);
    void print ();
};
#endif
