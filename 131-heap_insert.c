#include "binary_trees.h"

/**
 * swap_values_heap - Échange les valeurs dans le tas.
 * @v1: Pointeur vers la première valeur à échanger.
 * @v2: Pointeur vers la deuxième valeur à échanger.
 */
void swap_values_heap(heap_t *v1, heap_t *v2)
{
    int temp = v1->n;
    v1->n = v2->n;
    v2->n = temp;
}

/**
 * heapify - Construit le tas maximal en utilisant l'algorithme de tri par tas sift-up.
 * @node: Noeud à faire remonter dans le tas.
 * Return: Pointeur vers le noeud inséré.
 */
heap_t *heapify(heap_t *node)
{
    if (!node || !node->parent || node->parent->n > node->n)
        return (node);

    swap_values_heap(node, node->parent);
    return (heapify(node->parent));
}

/**
 * find_last_parent - Trouve le dernier parent dans le tas.
 * @root: Racine du tas.
 * Return: Pointeur vers le dernier élément.
 */
heap_t *find_last_parent(heap_t *root)
{
    heap_t *queue[1024];
    int start = 0, end = 0;

    if (!root)
        return (NULL);

    queue[end++] = root;
    while (start < end)
    {
        heap_t *current = queue[start++];

        if (current->left)
            queue[end++] = current->left;
        if (current->right)
            queue[end++] = current->right;
    }

    return (queue[(end + 1) / 2 - 1]);
}

/**
 * heap_insert - Insère une valeur dans un tas maximal.
 * @root: Double pointeur vers la racine du tas maximal.
 * @value: Valeur à stocker dans le noeud à insérer.
 * Return: Pointeur vers le nouveau noeud.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *node = NULL, *parent = *root;

    if (!root)
        return (NULL);

    if (!*root)
    {
        node = binary_tree_node(NULL, value);
        *root = node;
        return (node);
    }

    parent = find_last_parent(*root);
    node = binary_tree_node(parent, value);
    if (!parent->left)
        parent->left = node;
    else
        parent->right = node;

    return (heapify(node));
}