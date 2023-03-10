#ifndef LIST_H
#define LIST_H
/* List.h
 *
 * doubly-linked, double-ended list with Iterator interface
 * Project UID c1f28c309e55405daf00c565d57ff9ad
 * EECS 280 Project 4
 */

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
    List(): first(nullptr),last(nullptr){
        
    }

    // Copy constructor
    List(const List &other): first(nullptr),last(nullptr){
        copy_all(other);
    }
    ~List(){
        clear();
    }
    
    List &operator=(const List &rhs){
        if (this!= &rhs){
            clear();
            copy_all(rhs);
        }
        return *this;
    }
  //EFFECTS:  returns true if the list is empty
  bool empty() const{
      return first == nullptr;
      
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow.  Instead, keep track of the size
  //         with a private member variable.  That's how std::list does it.
    int size() const {
        return sizeOfList;
        
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
    T & front(){
        return first->datum;
        assert(!empty());
    }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
    T & back(){
        assert(!empty());
        return last->datum;
    }

  //EFFECTS:  inserts datum into the front of the list
    void push_front(const T &datum){
        Node *p = new Node;
        p->datum = datum;
        
        if(!empty()){
        p ->next = first;
        //sets the next part of the new node equal to the original first in the list
        p ->prev = first -> prev;
        //sets the prev of the new node equal to the original prev (aka null)
        first -> prev = p;
                    
        first = p;
    }
                
        else{
            p->next = nullptr;
            p->prev = nullptr;
                    
            first = p;
            last = p;
                    
        }
                
        sizeOfList++;
    }

  //EFFECTS:  inserts datum into the back of the list
    void push_back(const T &datum){
        Node *p = new Node;
        p->datum = datum;
        
        if(!empty()){
            p->next = nullptr;
            p->prev = last;
                   
            last -> next = p;
                    
                last = p;
        }
                
        else{
            p->next = nullptr;
            p->prev = nullptr;
                    
            first = p;
            last = p;
        }
                
            
            sizeOfList++;
}

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
    void pop_front(){
        if (sizeOfList == 1){
            first = nullptr;
        }
        else{
            Node *new_first = first->next;
            delete first;
            first = new_first;
                
            first->prev = nullptr;
        }
            sizeOfList--;
            
    }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
    void pop_back(){
        Node *new_last = last->prev;
        delete last;
       last = new_last;
        
        if (sizeOfList == 1){
            first = nullptr;
        }
        else{
            last->next = nullptr;
    }
        sizeOfList--;
        
}
//        assert(!empty());
//        if (first == last){
//            Node *p = new Node;
//            p = first;
//
//            first = NULL;
//            last = NULL;
//            delete p;
//        }
//        else{
//            Node *p = new Node;
//            p = last;
//            last = last->prev;
//            delete p;
//        }
//        sizeOfList--;
//    }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
    void clear(){
        
        for(int x = sizeOfList; x > 0; x--){
            pop_back();
        }
    }
//        while(!empty()){
//            pop_front();
//        }
//    }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you can omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
    void copy_all(const List<T> &other){

    for (Node *n = other.first; n != nullptr; n = n->next){
            push_back(n->datum);
        }
    }
    
    
    Node *first;   // points to first Node in list, or nullptr if list is empty
    Node *last;    // points to last Node in list, or nullptr if list is empty
      int sizeOfList = 0;
    
public:
  ////////////////////////////////////////
  class Iterator {
    //OVERVIEW: Iterator interface to List

    // You should add in a default constructor, destructor, copy constructor,
    // and overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you can omit them. A user
    // of the class must be able to create, copy, assign, and destroy Iterators.

    // Your iterator should implement the following public operators: *,
    // ++ (prefix), default constructor, == and !=.

  public:
      
    // This operator will be used to test your code. Do not modify it.
    // Requires that the current element is dereferenceable.
    Iterator& operator--() {
      assert(node_ptr);
      node_ptr = node_ptr->prev;
      return *this;
    }
    
      bool operator==(const Iterator &rhs) const {
          return node_ptr == rhs.node_ptr;
      }
      
      bool operator!=(const Iterator &rhs) const {
          return node_ptr != rhs.node_ptr;
      }
      
      Iterator& operator++() {
          assert(node_ptr);
          node_ptr = node_ptr->next;
          return *this;
      }
      
      T operator*() {
          assert(node_ptr != nullptr);
          return node_ptr->datum;
      }
// default constructor (no parameters) and custom constructor(parameters)
      
      
  private:
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
      friend class List;
    // construct an Iterator at a specific position
      Iterator(Node *p) {
          node_ptr = p;
      }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
    Iterator begin() const{
    return Iterator(first);
}
    
  // return an Iterator pointing to "past the end"
    Iterator end() const{
        return nullptr;
    }
     
  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container
    void erase(Iterator i){
        if (sizeOfList == 0) {
            return;
        }
        else if (i == Iterator(first)){
            pop_front();
        }
        else if(i == Iterator(last)){
            pop_back();
        }
        else{
        Node *n = i.node_ptr;
        n->prev->next = i.node_ptr->next;
        n->next->prev = i.node_ptr->prev;
            delete n;
            assert(false);
        }
    }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: inserts datum before the element at the specified position.
    void insert(Iterator i, const T &datum){
       
        if (i.node_ptr != NULL){
            Node *newfirst_node = new Node;
            newfirst_node->datum = datum;
            newfirst_node->prev = i.node_ptr->prev;
            i.node_ptr->prev = newfirst_node;
            newfirst_node->next = i.node_ptr;
            
            if (newfirst_node->prev != NULL){
                newfirst_node->prev->next = newfirst_node;
            }
            else{
                first = newfirst_node;
            }
        }
        else {
            push_back(datum);
        }
}

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.



#endif // Do not remove this. Write all your code above this line.
