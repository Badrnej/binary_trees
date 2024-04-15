#include "binary_trees.h"

/**
 * sorted_array_to_avl_h - Construit un arbre AVL à partir d'un tableau trié.
 * @array: Pointeur vers le premier élément du tableau à convertir.
 * @start: L'indice de début du sous-tableau à convertir.
 * @end: L'indice de fin du sous-tableau à convertir.
 * Return: Pointeur vers le nœud racine de l'arbre AVL créé,
 *         ou NULL en cas d'échec.
 */
avl_t *sorted_array_to_avl_h(int *array, size_t start, size_t end)
{
    size_t mid;
    avl_t *node;

    if (start > end)
        return (NULL);

    mid = (start + end) / 2;

    node = binary_tree_node(NULL, array[mid]);
    if (!node)
        return (NULL);

    if (mid != start)
        node->left = sorted_array_to_avl_h(array, start, mid - 1);
    if (mid != end)
        node->right = sorted_array_to_avl_h(array, mid + 1, end);

    if (node->left)
        node->left->parent = node;
    if (node->right)
        node->right->parent = node;

    return (node);
}

/**
 * sorted_array_to_avl - Construit un arbre AVL à partir d'un tableau.
 * @array: Pointeur vers le premier élément du tableau à convertir.
 * @size: Le nombre d'éléments dans le tableau.
 * Return: Pointeur vers le nœud racine de l'arbre AVL créé,
 *         ou NULL en cas d'échec.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size < 1)
        return (NULL);

    return (sorted_array_to_avl_h(array, 0, size - 1));
}