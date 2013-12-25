// File implementing binary tree ADT.

#include <iostream>
#include <string>

#include "node.h"
#include "node_impl.h"
#include "linkedlist.h"
#include "linkedlist_impl.h"
#include "queue.h"
#include "queue_impl.h"
#include "tree_node.h"
#include "tree_node_impl.h"

template <class T>
class BinaryTree {
  private:
    TreeNode <T> * root;
    Queue <TreeNode <T> *> * q;
    void inOrder (TreeNode <T> *);
    void preOrder (TreeNode <T> *);
    void postOrder (TreeNode <T> *);
    TreeNode <T> * bfs ();
    TreeNode <T> * dfs ();
  public:
    BinaryTree ();
    void insert (T);
    void del (T);
    void printInOrder ();
    void printPreOrder ();
    void printPostOrder ();
};

template <class T>
BinaryTree <T> :: BinaryTree () : root (NULL) {
  q = new Queue <TreeNode <T> *> ();
}

template <class T>
void BinaryTree <T> :: insert (T t) {
  TreeNode <T> * node = new TreeNode <T> ();
  TreeNode <T> * parent = root;
  node->setData (t);
  if (q->isEmpty()) {
    root = node;
  } else {
    parent = q->dequeue ();
    if (parent->getL_ptr () == NULL) {
      parent->setL_ptr (node);
    } else {
      parent->setR_ptr (node);
    }
  }
  q->enqueue (node);
  q->enqueue (node);
  node->setParent (parent);
}

template <class T>
void BinaryTree <T> ::  printInOrder () {
  TreeNode <T> * itr = root;
  this->inOrder (root);
  cout << endl;
}

template <class T>
void BinaryTree <T> :: inOrder (TreeNode <T> *t) {
  if (t == NULL) {
    return;
  }
  this->inOrder (t->getL_ptr ());
  cout << t->getData () << '\t';
  this->inOrder (t->getR_ptr ());
}

template <class T>
void BinaryTree <T> ::  printPreOrder () {
  TreeNode <T> * itr = root;
  this->preOrder (root);
  cout << endl;
}

template <class T>
void BinaryTree <T> :: preOrder (TreeNode <T> *t) {
  if (t == NULL) {
    return;
  }
  cout << t->getData () << '\t';
  this->preOrder (t->getL_ptr ());
  this->preOrder (t->getR_ptr ());
}

template <class T>
void BinaryTree <T> ::  printPostOrder () {
  TreeNode <T> * itr = root;
  this->postOrder (root);
  cout << endl;
}

template <class T>
void BinaryTree <T> :: postOrder (TreeNode <T> *t) {
  if (t == NULL) {
    return;
  }
  this->postOrder (t->getL_ptr ());
  this->postOrder (t->getR_ptr ());
  cout << t->getData () << '\t';
}

template <class T>
TreeNode <T> * BinaryTree <T> :: bfs () {

}

template <class T>
TreeNode <T> * BinaryTree <T> :: dfs () {
}

template <class T>
void BinaryTree <T> :: del (T t) {
}

int main () {
  cout << "enter" << endl;
  BinaryTree <int> * bt = new BinaryTree <int> ();
  for (int i = 0; i < 10; i++) {
    bt->insert (i);
  }
  bt->printInOrder ();
  bt->printPreOrder ();
  bt->printPostOrder ();
  cout << "exit" << endl;
}
