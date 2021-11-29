// Definition of template class Tree
#ifndef TREE_H
#define TREE_H

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;
using std::fstream;
using std::ios;

#include<string>
using std::string;
#include<stdlib.h>
#include <assert.h>

#include "treenode.h"


template< class NODETYPE >
class Tree {
public:
   Tree();
   void insertNode(  NODETYPE & );
   void preOrderTraversal() const;
   void inOrderTraversal() const;
   void postOrderTraversal() const;
   void deleteNode(  NODETYPE & );
   TreeNode< NODETYPE > *binarySearch( NODETYPE & ) const;
   int getDepth() const;

protected:
   TreeNode< NODETYPE > *rootPtr;
private:
   // utility functions
   void insertNodeHelper(
           TreeNode< NODETYPE > **,  NODETYPE & );
   void preOrderHelper( TreeNode< NODETYPE > * ) const;
   void inOrderHelper( TreeNode< NODETYPE > * ) const;
   void postOrderHelper( TreeNode< NODETYPE > * ) const;
   void DeleteHelper( TreeNode< NODETYPE > **,  NODETYPE & );
   void FindAndDeleteMax ( TreeNode< NODETYPE > **, TreeNode< NODETYPE > ** );
   TreeNode< NODETYPE > *binarySearchHelper( TreeNode< NODETYPE > *,
                                             NODETYPE & ) const;
   void determineDepth( TreeNode< NODETYPE > *, int *, int * ) const;

};

template< class NODETYPE >
int Tree< NODETYPE >::getDepth() const
{
   int totalDepth = 0, currentDepth = 0;
    //the rest of your code goes here
    determineDepth(rootPtr, &totalDepth, &currentDepth);

    return totalDepth;
}

template< class NODETYPE >
void Tree< NODETYPE >::determineDepth( TreeNode< NODETYPE > *ptr,int *totPtr, int *currPtr ) const
{


    //your code goes here
    if (ptr != 0) {
       ++*currPtr;

       if (*currPtr > *totPtr)
          *totPtr = *currPtr;

       determineDepth(ptr->leftPtr, totPtr, currPtr);
       determineDepth(ptr->rightPtr, totPtr, currPtr);
       --*currPtr;
    }


}


template< class NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binarySearch( NODETYPE & val ) const
{
    //your code goes here
    return binarySearchHelper(rootPtr, val);


}

template< class NODETYPE >
TreeNode< NODETYPE > *Tree< NODETYPE >::binarySearchHelper(TreeNode< NODETYPE > *ptr, NODETYPE & value ) const
{

    //your code goes here
    if (ptr == 0)
          return 0;

       cout << "Comparing " << value << " to " << ptr->data;

       if ( value == ptr->data) {    // match
          cout << "; search complete" << endl;
          return ptr;
       }
       else if (value < ptr->data) { // search val less than current data
          cout << "; smaller, walk left" << endl;
          return binarySearchHelper(ptr->leftPtr, value);
       }
       else {                       // search val greater than current data
          cout << "; larger, walk right" << endl;
          return binarySearchHelper(ptr->rightPtr, value);
       }

}




template< class NODETYPE >
Tree< NODETYPE >::Tree() { rootPtr = 0; }

template< class NODETYPE >
void Tree< NODETYPE >::insertNode(  NODETYPE &value )
   { insertNodeHelper( &rootPtr, value ); }

// This function receives a pointer to a pointer so the
// pointer can be modified.
template< class NODETYPE >
void Tree< NODETYPE >::insertNodeHelper(
        TreeNode< NODETYPE > **ptr,  NODETYPE &value )
{
   if ( *ptr == 0 ) {                   // tree is empty
      *ptr = new TreeNode< NODETYPE >( value );
      assert( *ptr != 0 );
   }
   else                              // tree is not empty
      if ( value < ( *ptr )->data )
         insertNodeHelper( &( ( *ptr )->leftPtr ), value );
      else
         if ( value > ( *ptr )->data )
            insertNodeHelper( &( ( *ptr )->rightPtr ), value );
         else
            cout << value << " dup" << endl;
}


//Written by: Farshad Rabbani
template< class NODETYPE >
void Tree< NODETYPE >::deleteNode( NODETYPE &value)
    { DeleteHelper( &rootPtr, value ); }


//Written by: Farshad Rabbani
template< class NODETYPE >
void Tree< NODETYPE >::DeleteHelper(TreeNode< NODETYPE > **ptr,  NODETYPE &value)
{
    TreeNode< NODETYPE > *tempPtr;

    if ( *ptr == 0 )
        cout<<"Sorry, but that thing ain't in this tree";

    else if ( value < (*ptr)->data )
        DeleteHelper( &( ( *ptr )->leftPtr ), value );

    else if ( value > (*ptr)->data )
        DeleteHelper( &( ( *ptr )->rightPtr ), value );

    else
        {
        tempPtr = *ptr; 	//save to delete later

        if ( (*ptr)->rightPtr == 0 ) //has no children or one child
        {
            *ptr = (*ptr)->leftPtr;
            delete tempPtr;
        }

        else if ( (*ptr)->leftPtr == 0 ) //has one child
        {
            *ptr = (*ptr)->rightPtr;
            delete tempPtr;
        }

        else	//has two children
            FindAndDeleteMax ( &( ( *ptr )->leftPtr ), &tempPtr );
        }
}

//written by: Farshad Rabbani
template< class NODETYPE >
void Tree< NODETYPE >::FindAndDeleteMax( TreeNode< NODETYPE > **T, TreeNode< NODETYPE > **MaxPtr )
{
    if ( (*T)->rightPtr == 0 ) //Base case: maximum found
    {
        (*MaxPtr)->data = (*T)->data;
        TreeNode< NODETYPE > * tempPtr = *T;
        *T = (*T)->leftPtr;
        delete(tempPtr);
    }
    else	//General case: Look in right subtree
        FindAndDeleteMax( &( (*T)->rightPtr ), MaxPtr);

}

template< class NODETYPE >
void Tree< NODETYPE >::preOrderTraversal() const
   { preOrderHelper( rootPtr ); }

template< class NODETYPE >
void Tree< NODETYPE >::preOrderHelper(
                          TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) {
      cout << ptr->data << ' ';
      preOrderHelper( ptr->leftPtr );
      preOrderHelper( ptr->rightPtr );
   }
}

template< class NODETYPE >
void Tree< NODETYPE >::inOrderTraversal() const
   { inOrderHelper( rootPtr ); }

template< class NODETYPE >
void Tree< NODETYPE >::inOrderHelper(
                          TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) {
      inOrderHelper( ptr->leftPtr );
      cout << ptr->data << ' ';
      inOrderHelper( ptr->rightPtr );
   }
}

template< class NODETYPE >
void Tree< NODETYPE >::postOrderTraversal() const
   { postOrderHelper( rootPtr ); }

template< class NODETYPE >
void Tree< NODETYPE >::postOrderHelper(
                          TreeNode< NODETYPE > *ptr ) const
{
   if ( ptr != 0 ) {
      postOrderHelper( ptr->leftPtr );
      postOrderHelper( ptr->rightPtr );
      cout << ptr->data << ' ';

   }
}

#endif


