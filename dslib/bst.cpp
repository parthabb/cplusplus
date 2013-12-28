// Binary Search Tree.

#include <iostream>
#include <cstdlib>

#include "node.h"
#include "node_impl.h"
#include "linkedlist.h"
#include "linkedlist_impl.h"
#include "tree_node.h"
#include "tree_node_impl.h"
#include "bst.h"

using namespace std;


template <class T>
BinarySearchTree <T> :: BinarySearchTree () : root (NULL), in_order_list (new LinkedList <TreeNode <T> *> ()) {
}

template <class T>
void BinarySearchTree <T> :: insert (T t) {
  TreeNode <T> * itr = root;
  TreeNode <T> * node = new TreeNode <T> ();
  node->setData (t);
  if (itr == NULL) {
    this->root = node;
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
  this->balanceTree (this->root);
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
  this->balanceTree (this->root);
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
  cout << itr->getData () << " - ( " << (itr->getParent () != NULL ? (itr->getParent ())->getData () : -1) << ") " << '\t';
  this->printPreOrder (itr->getL_ptr ());
  this->printPreOrder (itr->getR_ptr ());
}

template <class T>
TreeNode <T> * BinarySearchTree <T> :: getRoot () const {
  return this->root;
}

template <class T>
int BinarySearchTree <T> :: getBalancingFactor (TreeNode <T> * t) const {
  if (t == NULL) {
    return 0;
  }
  if (t->getL_ptr () == NULL && t->getR_ptr () == NULL) {
    return 1;
  }
  int heightOfLeftSubTree, heightOfRightSubTree;
  heightOfLeftSubTree = this->getHeight (t->getL_ptr ());
  heightOfRightSubTree = this->getHeight (t->getR_ptr ());
  return heightOfLeftSubTree - heightOfRightSubTree;
}

template <class T>
int BinarySearchTree <T> :: getHeight (TreeNode <T> * t) const {
  // Can be improved using DP.
  if (t == NULL) {
    return 0;
  }
  int lh = this->getHeight (t->getL_ptr ());
  int rh = this->getHeight (t->getR_ptr ());
  return 1 + (lh > rh ? lh : rh);
}

template <class T>
void BinarySearchTree <T> :: rotateLeft (TreeNode <T> * t) {
  if (t == NULL || t->getParent () == NULL) {
    return;
  }
  TreeNode <T> * temp = t->getParent ();
  TreeNode <T> * parent = temp->getParent ();
  t->setParent (parent);
  if (parent != NULL) {
    parent->getL_ptr () == temp ? parent->setL_ptr (t) : parent->setR_ptr (t);
  } else {
    this->root = t;
  }
  temp->setR_ptr (t->getL_ptr ());
  if (t->getL_ptr () != NULL) {
    (t->getL_ptr ())->setParent (temp);
  }
  t->setL_ptr (temp);
  temp->setParent (t);
}

template <class T>
void BinarySearchTree <T> :: rotateRight (TreeNode <T> * t) {
  if (t == NULL || t->getParent () == NULL) {
    return;
  }
  TreeNode <T> * temp = t->getParent ();
  TreeNode <T> * parent = temp->getParent ();
  t->setParent (parent);
  if (parent != NULL) {
    parent->getL_ptr () == temp ? parent->setL_ptr (t) : parent->setR_ptr (t);
  } else {
    this->root = t;
  }
  temp->setL_ptr (t->getR_ptr ());
  if (t->getR_ptr () != NULL) {
    (t->getR_ptr ())->setParent (temp);
  }
  t->setR_ptr (temp);
  temp->setParent (t);
}

template <class T>
void BinarySearchTree <T> :: balanceTree (TreeNode <T> * t) {
  if (t == NULL) {
    return;
  }
  this->balanceTree (t->getL_ptr ());
  this->balanceTree (t->getR_ptr ());
  int bf = this->getBalancingFactor (t);
  if (bf > 1) {
    bf = this->getBalancingFactor (t->getL_ptr ());
    if (bf < 0) {
      this->rotateLeft ((t->getL_ptr ())->getR_ptr ());
    }
    this->rotateRight (t->getL_ptr ());
  }
  if (bf < -1) {
    bf = this->getBalancingFactor (t->getR_ptr ());
    if (bf > 0) {
      this->rotateRight ((t->getR_ptr ())->getL_ptr ());
    }
    this->rotateLeft (t->getR_ptr ());
  }
}

/*
int main () {
  BinarySearchTree <int> * bst = new BinarySearchTree <int> ();
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    bst->insert (rand () % 10 + 1);
//    bst->insert (i + 1);
  }
  bst->printPreOrder (bst->getRoot ());
  cout << endl;
  bst->search (rand () % 10 + 1);
//  bst->search (5);
  for (int i = 0; i < 10; i++) {
    bst->del (rand () % 10 + 1);
    bst->printPreOrder (bst->getRoot ());
    cout << endl;
  }
}
*/
