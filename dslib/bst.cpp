// Binary Search Tree.

#include <iostream>
#include <cstdlib>

#include "node.h"
#include "node_impl.h"
#include "linkedlist.h"
#include "linkedlist_impl.h"
#include "tree_node.h"
#include "tree_node_impl.h"

using namespace std;


template <class T>
class BinarySearchTree {
  private:
    TreeNode <T> * root;
    LinkedList <TreeNode <T> *> * in_order_list;
    void inOrderReplacement (TreeNode <T> *);
  public:
    BinarySearchTree ();
    void insert (T);
    void search (T);
    void del (T);
    TreeNode <T> * getRoot () const;
    void printPreOrder (TreeNode <T> *);
};

template <class T>
BinarySearchTree <T> :: BinarySearchTree () : root (NULL), in_order_list (new LinkedList <TreeNode <T> *> ()) {
}

template <class T>
void BinarySearchTree <T> :: insert (T t) {
  TreeNode <T> * itr = root;
  TreeNode <T> * node = new TreeNode <T> ();
  node->setData (t);
  if (itr == NULL) {
    root = node;
  } else {
    while (true) {
      if (itr->getData () > t) {
        if (itr->getL_ptr () == NULL) {
          break;
        }
        itr = itr->getL_ptr ();
      } else {
        if (itr->getR_ptr () == NULL) {
          break;
        }
        itr = itr->getR_ptr ();
      }
    }

    if (itr->getData () > t) {
      itr->setL_ptr (node);
    } else {
      itr->setR_ptr (node);
    }

    node->setParent (itr);
  }
}

template <class T>
void BinarySearchTree <T> :: search (T t) {
  TreeNode <T> * itr = root;
  while (itr != NULL) {
    if (itr->getData () == t) {
      cout << t << ": Element found." << endl;
      return;
    } else if (itr->getData () > t) {
      itr = itr->getL_ptr ();
    } else {
      itr = itr->getR_ptr ();
    }
  }
  cout << t << ": Element not found." << endl;
}

template <class T>
void BinarySearchTree <T> :: del (T t) {
  TreeNode <T> * itr = root;
  while (itr != NULL) {
    if (itr->getData () == t) {
      break;
    } else if (itr->getData () > t) {
      itr = itr->getL_ptr ();
    } else {
      itr = itr->getR_ptr ();
    }
  }
  if (itr == NULL) {
    cout << t <<": Element not found." << endl;
    return;
  }

  // if leaf node or element has two children then find in-order replacement,
  // replace with in-order replacement and delete the replacement.
  if (itr->getL_ptr () != NULL && itr->getR_ptr () != NULL) {
    this->inOrderReplacement(itr);
    int index = this->in_order_list->getIndexByValue (itr);
    TreeNode <T> * replacement = this->in_order_list->getValueByIndex (index - 1);
    itr->setData (replacement->getData ());
    itr = replacement;
    int len = this->in_order_list->getLength ();
    for (int i = len - 1; i >= 0; i--) {
      this->in_order_list->deleteByIndex (i);
    }
  }

  TreeNode <T> * parent = itr->getParent ();
  if (parent == NULL) {
    this->root = itr->getL_ptr () != NULL ? itr->getL_ptr () : itr->getR_ptr ();
  } else {
    if (parent->getL_ptr () == itr) {
      parent->setL_ptr (itr->getL_ptr () != NULL ? itr->getL_ptr () : itr->getR_ptr ());
    } else {
      parent->setR_ptr (itr->getL_ptr () != NULL ? itr->getL_ptr () : itr->getR_ptr ());
    }
  }

  if (itr->getL_ptr ()) {
    (itr->getL_ptr ())->setParent (parent);
  }
  if (itr->getR_ptr ()) {
    (itr->getR_ptr ())->setParent (parent);
  }
  delete itr;
  cout << t << ": Element deleted" << endl;
}

template <class T>
void BinarySearchTree <T> :: inOrderReplacement (TreeNode <T> * itr) {
  if (itr == NULL) {
    return;
  }
  this->inOrderReplacement (itr->getL_ptr ());
  this->in_order_list->insertAtEnd (itr);
  this->inOrderReplacement (itr->getR_ptr ());
}

template <class T>
void BinarySearchTree <T> :: printPreOrder (TreeNode <T> * itr) {
  if (itr == NULL) {
    return;
  }
  cout << itr->getData () << '\t';
  this->printPreOrder (itr->getL_ptr ());
  this->printPreOrder (itr->getR_ptr ());
}

template <class T>
TreeNode <T> * BinarySearchTree <T> :: getRoot () const {
  return this->root;
}

/*
int main () {
  BinarySearchTree <int> * bst = new BinarySearchTree <int> ();
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    bst->insert (rand () % 10 + 1);
  }
  bst->printPreOrder (bst->getRoot ());
  cout << endl;
  bst->search (rand () % 10 + 1);
  for (int i = 0; i < 10; i++) {
    bst->del (rand () % 10 + 1);
    bst->printPreOrder (bst->getRoot ());
    cout << endl;
  }
}
*/
