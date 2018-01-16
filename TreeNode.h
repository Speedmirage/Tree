//
//  TreeNode.h
//  test
//
//  Created by Addiel Almonte on 11/28/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <string>
class Tree;
class Position;
class PositionList;
typedef std::string E;
class TreeNode
{
    E e;
    Position *parent;
    PositionList *child;
    friend class Tree;
    friend class Position;
    
public:
    TreeNode();
    TreeNode(E,Position*, PositionList*);
    TreeNode& operator=(TreeNode &t);
};


#endif 
