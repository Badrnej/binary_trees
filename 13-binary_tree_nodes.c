#include "binary_trees.h"

/**
 * binary_tree_nodes - Count the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: If tree is NULL, return 0. Otherwise, return the number of nodes.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return ((tree->left != NULL || tree->right != NULL) +
            binary_tree_nodes(tree->left) +
            binary_tree_nodes(tree->right));
}

