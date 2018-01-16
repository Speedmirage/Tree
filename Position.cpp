//
//  Position.cpp
//  test
//
//  Created by Addiel Almonte on 11/28/17.
//  Copyright © 2017 Addiel Almonte. All rights reserved.
//

#include "Position.h"
#include "PositionList.h"
#include "TreeNode.h"
#include "Tree.h"
#include <iostream>
using namespace std;
E& Position::operator*()
{
    return u->e;
}

Position* Position::parent() const
{
    return u->parent;
}

PositionList* Position::children()
{
    return u->child;
}

bool Position::isRoot() const
{
    if (u->parent == NULL)
        return true;
    else
        return false;
}

bool Position::isExternal() const
{
    return (u->child->empty() == true);
    
}

bool Position::operator==(Position p)
{
    if (u == p.u)
        return true;
    else
        return false;
}

Position::Position(TreeNode *v)
{
    u = v;
}


Position::Position()
{
    
}

Position& Position::operator=(Position p)
{
    u = p.u;
    return p;
}

