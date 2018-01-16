//
//  PositionList.h
//  test
//
//  Created by Addiel Almonte on 11/28/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//
#ifndef POSITIONLIST_H
#define POSITIONLIST_H

class Position;
class Tree;

class PositionList {                // node-based list
private:
    
    struct Node {
        Position elem;                // element value
        Node* prev;                // previous in list
        Node* next;                // next in list
    };
    
    friend class TreeNode;
public:
    
    
    class Iterator {                // an iterator for the list
    public:
        Position& operator*();            // reference to the element
        bool operator==(const Iterator& p) const;    // compare positions
        bool operator!=(const Iterator& p) const;
        Iterator& operator++();            // move to next position
        Iterator& operator--();            // move to previous position
        friend class PositionList;            // give NodeList access
    private:
        Node* v;                    // pointer to the node
        Iterator(Node* u);            // create from node
        friend class Tree;
        
    };
    
public:
    int size() const;                // list size
    bool empty() const;                // is the list empty?
    Iterator begin() const;            // beginning position
    Iterator end() const;            // (just beyond) last position
    void insertFront(const Position& e);        // insert at front
    void insertBack(const Position& e);        // insert at rear
    void insert(const Iterator& p, const Position& e); // insert e before p
    void eraseFront();                // remove first
    void eraseBack();                // remove last
    void erase(const Iterator& p);        // remove p
    PositionList(Position);                    // default constructor
    PositionList();
    PositionList& operator=( PositionList&);
    
private:                    // data members
    int     n;                    // number of items
    Node*   header;                // head-of-list sentinel
    Node*   trailer;                // tail-of-list sentinel
    
    
};
#endif
