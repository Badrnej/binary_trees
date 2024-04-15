#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: pointer to node in the tree to measure its depth
 * Return: depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (!tree)
        return (0);

    while (tree->parent)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth);
}

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: If either node is NULL, or if no common ancestor was found,
 *         return NULL. Otherwise, return a pointer to the lowest common
 *         ancestor node of the two given nodes.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
                                     const binary_tree_t *second)
{
    size_t first_depth, second_depth;

    if (!first || !second)
        return (NULL);

    first_depth = binary_tree_depth(first);
    second_depth = binary_tree_depth(second);

    while (first_depth > second_depth)
    {
        first = first->parent;
        first_depth--;
    }

    while (second_depth > first_depth)
    {
        second = second->parent;
        second_depth--;
    }

    while (first && second && first != second)
    {
        first = first->parent;
        second = second->parent;
    }

    return ((binary_tree_t *)first);
}
