/**
 * heap_to_sorted_array - Convert a max heap into a sorted array (DESC).
 * @heap: Pointer to the root of the heap.
 * @size: Pointer to store the size of the array.
 * Return: Pointer to the sorted array.
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t i, base_size = 1024;
	int *sorted = malloc(sizeof(int) * base_size);

	if (!sorted)
		return (NULL);

	for (i = 0; heap; i++)
	{
		if (i >= base_size - 1)
		{
			base_size *= 2;
			int *new_sorted = realloc(sorted, sizeof(int) * base_size);
			if (!new_sorted)
			{
				free(sorted);
				return (NULL);
			}
			sorted = new_sorted;
		}
		sorted[i] = heap_extract(&heap);
	}
	*size = i;
	sorted = realloc(sorted, sizeof(int) * *size);
	return (sorted);
}