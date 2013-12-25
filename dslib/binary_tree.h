// Header file for binary tree ADT.

#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_


template <class T>
class BinaryTree {
  private:
    TreeNode <T> * root;
    Queue <TreeNode <T> *> * q;
    void inOrder (TreeNode <T> *);
    void preOrder (TreeNode <T> *);
    void postOrder (TreeNode <T> *);
    void dfsRoutine (TreeNode <T> *, int &);
  public:
    BinaryTree ();
    void insert (T);
    void del (T);
    void printInOrder ();
    void printPreOrder ();
    void printPostOrder ();
    void bfs ();
    void dfs ();
};
#endif
