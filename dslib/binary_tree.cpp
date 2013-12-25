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
#include "binary_tree.h"


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
  cout << t->getData () << " - (" << t->getDepth () << ")," << '\t';
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
  cout << t->getData () << " - (" << t->getDepth () << ")," << '\t';
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
  cout << t->getData () << " - (" << t->getDepth () << ")," << '\t';
}

template <class T>
void BinaryTree <T> :: bfs () {
  TreeNode <T> * itr = root;
  TreeNode <T> * u, * v;
  Queue <TreeNode <T> *> * bfsq = new Queue <TreeNode <T> *> ();
  bfsq->enqueue (itr);
  itr->setDepth (0);
  itr->setColor ("grey");
  while (!bfsq->isEmpty()) {
    u = bfsq->dequeue();
    if (u->getR_ptr () && (u->getR_ptr ())->getColor () == "white") {
      v = u->getR_ptr ();
      v->setDepth (u->getDepth () + 1);
      v->setColor ("grey");
      bfsq->enqueue (v);
    }
    if (u->getL_ptr () && (u->getL_ptr ())->getColor () == "white") {
      v = u->getL_ptr ();
      v->setDepth (u->getDepth () + 1);
      v->setColor ("grey");
      bfsq->enqueue (v);
    }
    u->setColor ("black");
  }
}

template <class T>
void BinaryTree <T> :: dfs () {
  TreeNode <T> * itr;
  itr = root;
  int t = 0;  // time.
  this->dfsRoutine (itr, t);
}

template <class T>
void BinaryTree <T> :: dfsRoutine (TreeNode <T> * itr, int &t) {
  if (itr == NULL) {
    return;
  }
  itr->setDiscovery (++t);
  this->dfsRoutine (itr->getL_ptr (), t);
  this->dfsRoutine (itr->getR_ptr (), t);
  itr->setFinish (++t);
}


template <class T>
void BinaryTree <T> :: del (T t) {
  TreeNode <T> * itr = root;
  TreeNode <T> * u, * v;
  Queue <TreeNode <T> *> * bfsq = new Queue <TreeNode <T> *> ();
  bfsq->enqueue (itr);
  while (!bfsq->isEmpty()) {
    u = bfsq->dequeue();
    if (u->getData() == t) {
      if (u->getL_ptr () != NULL && u->getR_ptr () != NULL) {
        cout << "Can't delete an internal node." << endl;
      } else {
        v = u->getParent ();
        if (v->getL_ptr() == u) {
          v->setL_ptr (u->getL_ptr () != NULL ? u->getL_ptr () : u->getR_ptr () );
          if (v->getL_ptr ()) {
            (v->getL_ptr ())->setParent (v);
          }
        } else {
          v->setR_ptr (u->getL_ptr () != NULL ? u->getL_ptr () : u->getR_ptr () );
          if (v->getR_ptr ()) {
            (v->getR_ptr ())->setParent (v);
          }
        }
      }
      delete u;
      return;
    }
    if (u->getR_ptr ()) {
      v = u->getR_ptr ();
      bfsq->enqueue (v);
    }
    if (u->getL_ptr ()) {
      v = u->getL_ptr ();
      bfsq->enqueue (v);
    }
  }
}

int main () {
  cout << "enter" << endl;
  BinaryTree <int> * bt = new BinaryTree <int> ();
  for (int i = 0; i < 10; i++) {
    bt->insert (i);
  }
  bt->bfs ();
  bt->dfs ();
  bt->del (0);
  bt->printInOrder ();
  bt->del (4);
  bt->printInOrder ();
  bt->del (9);
  bt->printInOrder ();
  bt->del (1);
  bt->printInOrder ();
  bt->del (7);
  bt->printInOrder ();
  bt->del (8);
  bt->printInOrder ();
  cout << "exit" << endl;
}
