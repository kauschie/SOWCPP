#ifndef INTBINARYTREE_H
#define INTBINARYTREE_H


class IntBinaryTree
{

private:
    struct TreeNode
    {
        int value;  // the value in the node
        TreeNode *left; // pointer to the left child node
        TreeNode *right; // pointer to the right child node
    };

    TreeNode *root; // pointer to the root node

    // private member functions
    void insert(TreeNode *&, TreeNode *&);
    void destroySubTree(TreeNode *);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;

public:
    // constructor
    IntBinaryTree()
    { root = nullptr; }

    // destructor
    ~IntBinaryTree()
    { destroySubTree(root); }

    // Binary Tree Operations
    void insertNode(int);
    bool searchNode(int);
    void remove(int);
    void displayInOrder() const
    { displayInOrder(root); }

    void displayPreOrder() const
    { displayPreOrder(root); }

    void displayPostOrder() const
    { displayPostOrder(root); }
};

#endif
