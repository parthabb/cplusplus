// Header file for stack.cpp

#ifndef STACK_H_
#define STACK_H_

template <class T>
class Stack {
  private:
    LinkedList <T> * ll;
  public: 
    Stack (); 
    void push (T);
    T pop ();
};
#endif
