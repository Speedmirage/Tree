//
//  Position.h
//  test
//
//  Created by Addiel Almonte on 11/28/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//


#ifndef POSITION_H
#define POSITION_H
#include <string>
class TreeNode;
class Tree;
class PositionList;
typedef std::string E;
class Position {                // a node position
    
public:
    E& operator*();                // get element
    Position*  parent() const;            // get parent
    PositionList* children();
    bool isRoot() const;             // root node?
    bool isExternal() const;             // external node?
    bool operator==(Position p);
    Position& operator = (Position p); //& on the second possition was causing problems... Removed. 
    Position();
private:
    Position(TreeNode *v);
    
    
    TreeNode *u;
    friend class Tree;
    friend class TreeNode;
    friend class PositionList;
};

#endif
