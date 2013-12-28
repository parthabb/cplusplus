// Header file for bst.cpp

#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

template <class T>
class BinarySearchTree {
  private:
    TreeNode <T> * root;
    LinkedList <TreeNode <T> *> * in_order_list;
    void inOrderReplacement (TreeNode <T> *);
    int getBalancingFactor (TreeNode <T> *) const;
    int getHeight (TreeNode <T> *) const;
    void rotateLeft (TreeNode <T> *);
    void rotateRight (TreeNode <T> *);
    void balanceTree (TreeNode <T> *);
  public:
    BinarySearchTree ();
    void insert (T);
    void search (T);
    void del (T);
    TreeNode <T> * getRoot () const;
    void printPreOrder (TreeNode <T> *);
};
#endif
