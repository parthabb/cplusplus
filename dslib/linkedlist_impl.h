//  File implementing linked list data structure.

#ifndef LINKEDLIST_IMPL_H_
#define LINKEDLIST_IMPL_H_

using namespace std;

template <class T>
LinkedList <T> :: LinkedList () : length (0), head (NULL) {
}

template <class T>
void LinkedList <T> :: print () {
  Node <T> * itr = head;
  while (itr != NULL) {
    cout << itr->getData () << '\t';
    itr = itr->getF_ptr ();
  }
  cout << endl;
}

template <class T>
void LinkedList <T> :: insert (T t, int index) {
  if (index < 0 || index > this->length) {
    // Raise an exception later.
    cout << "Index " << index << " out of bounds." << endl;
    return;
  }
  Node <T> * itr = head;
  Node <T> * node = new Node <T> ();
  node->setData (t);

  for (int i = 0; i < index - 1; i++) {
    itr = itr->getF_ptr ();
  }
  switch (index) {
    case 0: node->setF_ptr (itr);
            head = node;
            break;
    default: node->setF_ptr (itr->getF_ptr ());
             itr->setF_ptr (node);
             break;
  }
  length ++;
}

template <class T>
void LinkedList <T> :: insertAtStart (T t) {
  this->insert (t, 0);
}

template <class T>
void LinkedList <T> :: insertAtEnd (T t) {
  this->insert (t, this->length);
}

template <class T>
void LinkedList <T> :: del (T t) {
  Node <T> * itr = head;
  Node <T> * prev = head;
  while (itr != NULL && itr->getData () != t) {
    prev = itr;
    itr = itr->getF_ptr ();
  }
  if (itr == NULL) {
    cout << "Item not found." << endl;
    return;
  }
  if (prev == itr) {
    head = itr->getF_ptr ();
  } else {
    prev->setF_ptr (itr->getF_ptr ());
  }
  length --;
  if (length != 0) {
    delete itr;
  }
}

template <class T>
int LinkedList <T> :: getIndexByValue (T t) {
  Node <T> * itr = head;
  int index = 0;
  while (itr != NULL && itr->getData () != t) {
    index ++;
    itr = itr->getF_ptr ();
  }
  if (itr == NULL) {
    return -1;
  }
  return index;
}

template <class T>
T LinkedList <T> :: getValueByIndex (int index) {
  if (index < 0 || index > this->length - 1) {
    return (T) -1;  // Possible error scenario.
  }
  Node <T> * itr = head;
  for (int i = 0; i < index; i++ ) {
    itr = itr->getF_ptr ();
  }
  return itr->getData ();
}

#endif
