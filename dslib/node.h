// Header file for node.cpp
#ifndef NODE_H_
#define NODE_H_

template <class T>
class Node {
  private: 
    T data;  // defaults to default constructor call.
    Node <T> * f_ptr;  // defaults to NULL
    Node <T> * b_ptr;  // defaults to NULL
  public:
    Node ();
    T getData () const;
    void setData (T);
    Node <T> * getF_ptr () const;
    void setF_ptr (Node <T> *);
    Node <T> * getB_ptr () const;
    void setB_ptr (Node <T> *);
};
#endif
