// Header file for tree node.

#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <string>

#include "node.h"

using namespace std;

template <class T>
class TreeNode : public Node <T> {
  private:
    TreeNode <T> * parent;
    int depth, discovery, finish;
    string color;
  public:
    TreeNode ();
    TreeNode <T> * getL_ptr () const;
    void setL_ptr (TreeNode <T> *);
    TreeNode <T> * getR_ptr () const;
    void setR_ptr (TreeNode <T> *);
    TreeNode <T> * getParent() const;
    void setParent (TreeNode <T> *);
    int getDepth () const;
    void setDepth (int);
    void setDiscovery (int);
    void setFinish (int);
    string getColor () const;
    void setColor (string);
};
#endif
