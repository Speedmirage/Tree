//
//  PositionList.cpp
//  test
//
//  Created by Addiel Almonte on 11/28/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#include "Position.h"
#include "PositionList.h"
#include <iostream>
using namespace std;
PositionList::Iterator::Iterator(Node* u)        // constructor from Node*
{ v = u; }


Position& PositionList::Iterator::operator*()        // reference to the element
{ return v->elem; }
// compare positions

bool PositionList::Iterator::operator==(const Iterator& p) const
{ return v == p.v; }


bool PositionList::Iterator::operator!=(const Iterator& p) const
{ return v != p.v; }
// move to next position


PositionList::Iterator& PositionList::Iterator::operator++()
{ v = v->next; return *this; }
// move to previous position


PositionList::Iterator& PositionList::Iterator::operator--()
{ v = v->prev; return *this; }


PositionList::Iterator PositionList::begin() const    // begin position is first item
{ return Iterator(header->next); }


PositionList::Iterator PositionList::end() const    // end position is just beyond last
{ return Iterator(trailer); }


PositionList::PositionList() {            // constructor
    n = 0;                    // initially empty
    header = new Node;                // create sentinels
    trailer = new Node;
    header->next = trailer;            // have them point to each other
    trailer->prev = header;
}


PositionList& PositionList::operator=( PositionList &pl)
{
    n = pl.n;
    header = new Node;
    trailer = new Node;
    PositionList::Iterator ours = begin();
    
    for (PositionList::Iterator ii = pl.begin(); ii != pl.end(); ++ii)
    {
        insert( ours, *ii);
        ++ours;
    }
    return pl;
}

int PositionList::size() const             // list size
{ return n; }


bool PositionList::empty() const             // is the list empty?
{ return (n == 0); }

// insert e before p

void PositionList::insert(const PositionList::Iterator& p, const Position& e) {
    Node* w = p.v;                // p's node
    Node* u = w->prev;                // p's predecessor
    Node* v = new Node;                // new node to insert
    v->elem = e;
    v->next = w;  w->prev = v;            // link in v before w
    v->prev = u;  u->next = v;            // link in v after u
    n++;
}



void PositionList::insertFront(const Position& e)    // insert at front
{ insert(begin(), e); }


void PositionList::insertBack(const Position& e)    // insert at rear
{ insert(end(), e); }



void PositionList::erase(const Iterator& p) {    // remove p
    Node* v = p.v;                // node to remove
    Node* w = v->next;                // successor
    Node* u = v->prev;                // predecessor
    u->next = w;  w->prev = u;            // unlink p
    delete v;                    // delete this node
    n--;                    // one fewer element
}


void PositionList::eraseFront()            // remove first
{ erase(begin()); }


void PositionList::eraseBack()            // remove last
{ erase(--end()); }

