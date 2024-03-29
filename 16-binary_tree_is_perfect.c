#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to root node of the tree to measure its height
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t left_height = 0, right_height = 0;

    if (!tree)
        return (0);
    if (tree->left)
        left_height = 1 + binary_tree_height(tree->left);
    if (tree->right)
        right_height = 1 + binary_tree_height(tree->right);
    return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * Return: If tree is NULL or if the tree is not perfect, return 0.
 * Otherwise, return 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return (0);
    if (!tree->left && !tree->right)
        return (1);
    if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
        return (0);
    return (binary_tree_is_perfect(tree->left) && binary_tree_is_perfect(tree->right));
}
