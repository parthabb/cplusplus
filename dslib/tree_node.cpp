// Header file for tree node.

#include <iostream>
#include <string>

#include "node.h"
#include "node_impl.h"
#include "tree_node.h"

using namespace std;

template <class T>
TreeNode <T> :: TreeNode () : Node <T> (), parent (NULL), depth (-1), discovery (-1), finish (-1), color ("white") {
}

template <class T>
TreeNode <T> * TreeNode <T> :: getL_ptr () const {
  return reinterpret_cast <TreeNode <T> *> (this->getF_ptr ());
}

template <class T>
void TreeNode <T> :: setL_ptr (TreeNode <T> * t) {
  this->setF_ptr (reinterpret_cast <Node <T> *> (t));
}

template <class T>
TreeNode <T> * TreeNode <T> :: getR_ptr () const {
  return reinterpret_cast <TreeNode <T> *> (this->getB_ptr ());
}

template <class T>
void TreeNode <T> :: setR_ptr (TreeNode <T> * t) {
  this->setB_ptr (reinterpret_cast <Node <T> *> (t));
}

template <class T>
TreeNode <T> * TreeNode <T> :: getParent () const {
  return this->parent;
}

template <class T>
void TreeNode <T> :: setParent (TreeNode <T> * t) {
  this->parent = t;
}

template <class T>
int TreeNode <T> :: getDepth () const {
  return this->depth;
}

template <class T>
void TreeNode <T> :: setDiscovery (int d) {
  this->discovery = d;
}

template <class T>
void TreeNode <T> :: setFinish (int f) {
  this->finish = f;
}

template <class T>
string TreeNode <T> :: getColor () const {
  return this->color;
}

template <class T>
void TreeNode <T> :: setColor (string s) {
  this->color = s;
}

