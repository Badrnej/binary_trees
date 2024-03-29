#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverse a binary tree using post-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    // Traverse the left subtree
    if (tree->left)
        binary_tree_postorder(tree->left, func);

    // Traverse the right subtree
    if (tree->right)
        binary_tree_postorder(tree->right, func);

    // Call the function on the current node
    func(tree->n);
}
