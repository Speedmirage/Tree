//
//  Tree.cpp
//  test
//
//  Created by Addiel Almonte on 11/28/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#include "Tree.h"
#include "Position.h"
#include "PositionList.h"
#include "TreeNode.h"
#include <iostream>
#include <string>
using namespace std;

TreeNode::TreeNode()
{
    e = " ";
}

TreeNode::TreeNode(std::string value, Position *p, PositionList *pl)
{
    e = value;
    parent = p;
    child = pl;
}
TreeNode& TreeNode::operator=(TreeNode &t)
{
    e = t.e;
    parent = t.parent;
    child = t.child;
    return t;
}

Tree::Tree()
{
    r = NULL;
}

Position Tree::root()
{
    return Position(r);
}
int Tree::size() const
{
    return count;
}
bool Tree::empty() const
{
    if (r == NULL)
        return 1;
    
    return 0;
}

void Tree::insert(E e, Position p)
{
    TreeNode *v = new TreeNode();
    v->e= e;
    if (!empty() )
    {
        v->parent = &p;
        
        v->child =  new PositionList();
        p.u->child->insertBack(v);
    }
    else
    {
        v->parent = NULL;
        
        v->child = new PositionList();
        r = v;
    }
    
}

PositionList Tree::children(Position p)
{
    PositionList pl;
    preorder(p, pl);
    return pl;
}

void Tree::preorder(Position p, PositionList &pl)
{
    pl.insertBack(p);
    if (p.children()->empty()==false)
        for(PositionList::Iterator ii = p.children()->begin(); ii!= p.children()->end(); ++ii)
            preorder(*ii, pl);
}
