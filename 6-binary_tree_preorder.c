#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverse a binary tree using pre-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    func(tree->n);  // Call the function on the current node

    // Traverse the left subtree
    if (tree->left)
        binary_tree_preorder(tree->left, func);

    // Traverse the right subtree
    if (tree->right)
        binary_tree_preorder(tree->right, func);
}
