//
//  main.cpp
//  test
//
//  Created by Addiel Almonte, Harrison Fernandez, and Erick Reyes on 11/28/17.
//  Copyright � 2017 Addiel Almonte. All rights reserved.
//

#include <iostream>
#include "Tree.h"
#include "Position.h"
#include "PositionList.h"
#include "TreeNode.h"
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <vector>
using namespace std;

std::vector<string> director;

std::vector<string> makeVector(string d)
{
    director.push_back(d);
    return director;
}

void directory(string d)
{
    //use this line to make the root the directory (string d)
    std::vector<string> content;
    char dir = '\\';
    string period = ".";
    string period2 = "..";
    DIR *pdir = NULL;
    pdir = opendir (d.c_str());
    struct dirent *pent = NULL;
    switch (0)
    {
        case 0:
            if (pdir==NULL)
            {
                //cout<<"pdir could not be intitialized correctly"<<endl;
                break;
            }
            
            while (pent = readdir(pdir))
            {
                //cout<<pent->d_name<<endl;
                if (pent == NULL)
                {
                    break;
                }
                if(pent->d_name != period)
                {
                    if(pent->d_name != period2)
                        content.push_back(pent->d_name);
                }
            }
    }
    closedir(pdir);
    
    
    for (int i=0; i<content.size();i++)
    {
        directory (d+dir+content.at(i));
        makeVector(content.at(i));
        //cout<<content.at(i)<<endl;
        //use this line to make these the children of the root.
        //directory(dir + content.at(i));
    }
    
    /*for (int i=0;i<content.size();i++)
     makeVector(content.at(i));*/
}


int main(int argc, char** argv) {
    Tree t ;
    
    //Insert something at the root. Note that p will be pointing at NULL here
    Position p = t.root();
    t.insert("T", p); // Main root
    
    p = t.root();
    t.insert("E", p);
    t.insert("E",p);
    t.insert("U",p);
    t.insert("R",p);
    
    PositionList *pl = p.children();
    PositionList::Iterator ii = pl->begin();
    p = *ii;
    t.insert("M",p);
    t.insert("P",p);
    //////////////////////////////////////////////////////////// below this working on E Second possition
    PositionList::Iterator ii1 = pl->begin() ; ii1 != pl->end(); ++ii1; // Allows for the tree to go up
    p = *ii1;
    //cout << "Testing where we are " << **ii1 << endl << endl;
    t.insert("R", p);
    t.insert("T", p);
    ii = p.children()->begin();
    //cout << "Testing where we are " << **ii << endl << endl;
    t.insert("A", *ii);
    //////////////////////////////////////////////////////////// Below this working with child R
    
    PositionList::Iterator ii2 = pl->begin() ; ii2 != pl->end(); ++ii2; ++ii2; // incremented twice to go up 2 levels
    ++ii2; // shifts by 1 .. Allows to get to R instead of U
    p = *ii2;
    //cout << "Testing where we are " << **ii2 << endl << endl;
    t.insert("E", p);
    PositionList plist = t.children(t.root());
    
    std::cout<<"* Tree Print using pre-order Traversal *"<<std::endl;
    std::cout<<"_________________________________________"<<std::endl;
    std::cout<<" "<<std::endl; //for stetic purposes
    for(PositionList::Iterator pp = plist.begin(); pp != plist.end(); ++pp) //prints the files and folders stored on the tree
        std::cout << **pp << std::endl;
    std::cout<<" "<<std::endl;
    system("pause");
    return 0;
}



