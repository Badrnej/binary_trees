/**
 * array_to_avl_recursive - Builds an AVL tree from an array recursively.
 * @array: Pointer to the first element of the array to be converted.
 * @start: Index of the first element of the subarray.
 * @end: Index of the last element of the subarray.
 * Return: Pointer to the root node of the created AVL tree,
 *         or NULL on failure.
 */
avl_t *array_to_avl_recursive(int *array, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    avl_t *root = binary_tree_node(NULL, array[mid]);
    if (!root)
        return NULL;

    root->left = array_to_avl_recursive(array, start, mid - 1);
    root->right = array_to_avl_recursive(array, mid + 1, end);

    return root;
}

/**
 * array_to_avl - Builds an AVL tree from an array.
 * @array: Pointer to the first element of the array to be converted.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created AVL tree,
 *         or NULL on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return NULL;

    return array_to_avl_recursive(array, 0, size - 1);
}