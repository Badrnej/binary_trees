/**
 * recursive_insert - Inserts a value into an AVL tree recursively.
 * @tree: Double pointer to the current node in the AVL tree.
 * @parent: Pointer to the parent of the current node.
 * @new_node: Double pointer to the new node to be inserted.
 * @value: Value to be stored in the node to be inserted.
 * Return: Pointer to the inserted node, or NULL on failure.
 */
avl_t *recursive_insert(avl_t **tree, avl_t *parent, avl_t **new_node, int value)
{
    int balance_factor;

    if (!*tree)
        return (*new_node = binary_tree_node(parent, value));

    if ((*tree)->n > value)
    {
        (*tree)->left = recursive_insert(&(*tree)->left, *tree, new_node, value);
        if (!(*tree)->left)
            return (NULL);
    }
    else if ((*tree)->n < value)
    {
        (*tree)->right = recursive_insert(&(*tree)->right, *tree, new_node, value);
        if (!(*tree)->right)
            return (NULL);
    }
    else
        return (*tree);

    balance_factor = binary_tree_balance(*tree);

    if (balance_factor > 1 && (*tree)->left->n > value)
        *tree = binary_tree_rotate_right(*tree);
    else if (balance_factor > 1 && (*tree)->left->n < value)
    {
        (*tree)->left = binary_tree_rotate_left((*tree)->left);
        *tree = binary_tree_rotate_right(*tree);
    }
    else if (balance_factor < -1 && (*tree)->right->n < value)
        *tree = binary_tree_rotate_left(*tree);
    else if (balance_factor < -1 && (*tree)->right->n > value)
    {
        (*tree)->right = binary_tree_rotate_right((*tree)->right);
        *tree = binary_tree_rotate_left(*tree);
    }

    return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Double pointer to the root node of the AVL tree.
 * @value: Value to be stored in the node to be inserted.
 * Return: Pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node = NULL;

    if (!*tree)
    {
        *tree = binary_tree_node(NULL, value);
        return (*tree);
    }

    recursive_insert(tree, NULL, &new_node, value);

    return (new_node);
}