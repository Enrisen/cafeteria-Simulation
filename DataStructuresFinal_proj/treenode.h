// TREENODE.H
// Definition of class TreeNode
#ifndef TREENODE_H
#define TREENODE_H

template< class T > class Tree;    // forward declaration

template< class NODETYPE >
class TreeNode {
   friend class Tree< NODETYPE >;
public:
   TreeNode( const NODETYPE & );  // constructor
   NODETYPE getData() const;      // return data
   TreeNode *getLeftPtr() const { return leftPtr; }
   TreeNode *getRightPtr() const { return rightPtr; }
   void setLeftPtr( TreeNode *ptr ) { leftPtr = ptr; }
   void setRightPtr( TreeNode *ptr ) { rightPtr = ptr; }
private:
   TreeNode *leftPtr;   // pointer to left subtree
   NODETYPE data;
   TreeNode *rightPtr;  // pointer to right subtree
};

// Constructor
template< class NODETYPE >
TreeNode< NODETYPE >::TreeNode( const NODETYPE &d )
{
   data = d;
   leftPtr = rightPtr = 0;
}

//Return a copy of the data value
template< class NODETYPE >
NODETYPE TreeNode< NODETYPE >::getData() const { return data; }

#endif
