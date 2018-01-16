//
//  Tree.h
//  test
//
//  Created by Addiel Almonte on 11/28/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#ifndef TREE_H
#define TREE_H
#include <cstdlib>
#include <string>
class TreeNode;
typedef std::string E;

class Position;
class PositionList;

class Tree {
    
    
    
public:                    // public functions
    Tree();
    int size() const;                // number of nodes
    bool empty() const;                // is tree empty?
    void insert(E e, Position p);
    
    Position root();
    PositionList children(Position p);
protected:
    void preorder(Position t, PositionList &pl);
private:
    TreeNode *r;
    int count;
};


#endif
