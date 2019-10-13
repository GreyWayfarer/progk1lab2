#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntVector.h"
#include <stddef.h>

int main()
{
	int mistake, size, capacity, index;
	int new_size, new_cap, pb;

	printf("Input initial capacity: ");
	scanf("%d", &new_cap);

	IntVector *v = int_vector_new(new_cap);

	IntVector *c = int_vector_copy(v);

        printf("Create IntVector v:\ncapacity: %ld\nsize: %ld\ndata: %p\n\n", v->capacity, v->size, v);

        printf("Copy IntVector v = IntVector c:\ncapacity: %ld\nsize: %ld\ndata: %p\n\n", c->capacity, c->size, c);


	capacity = int_vector_get_capacity(v);
	printf("before (reserve) capacity = %d\n", capacity);


	printf("Input new capacity: ");
	scanf("%d", &new_cap);

	mistake = int_vector_reserve(v, new_cap);
	printf("mistake (reserve) = %d\n", mistake);

	capacity = int_vector_get_capacity(v);
	printf("after (reserve) capacity = %d\n\n", capacity);




	size = int_vector_get_size(v);
	printf("before (resize) size = %d\n", size);

	printf("Input new size: ");
	scanf("%d", &new_size);

	mistake = int_vector_resize(v, new_size);
	printf("mistake (resize) = %d\n", mistake);

	size = int_vector_get_size(v);
	printf("after (resize) size = %d\n\n", size);




	capacity = int_vector_get_capacity(v);
	printf("before (shrink to fit) capacity = %d\n", capacity);

	mistake = int_vector_shrink_to_fit(v);
	printf("mistake (shrink to fit) = %d\n", mistake);

	capacity = int_vector_get_capacity(v);
	printf("after (shrink to fit) capacity = %d\n\n", capacity);



	for (index = 0; index < v->size; index++) {
		int_vector_set_item(v, index, index);
	}

	if (v->data != NULL) printf("set and get item:\n");

	for (index = 0; index < v->size && v->data != NULL; index++) {
		printf("array[%d] = %d ", index, int_vector_get_item(v, index));
	}
	printf("\n\n");

	size = int_vector_get_size(v);
	printf("before (push back) size = %d\n", size);

	capacity = int_vector_get_capacity(v);
	printf("before (push back) capacity = %d\n", capacity);

	printf("Input a number to push back: ");
	scanf("%d", &pb);
	mistake = int_vector_push_back(v, pb);
	printf("mistake (push back) = %d\n", mistake);

	size = int_vector_get_size(v);
	printf("after (push back) size = %d\n", size);

	capacity = int_vector_get_capacity(v);
	printf("after (push back) capacity = %d\n\n", capacity);

        size = int_vector_get_size(v);
	printf("before (pop back) size = %d\n", size);

	capacity = int_vector_get_capacity(v);
	printf("before (pop back) capacity = %d\n", capacity);

        int_vector_pop_back(v);
	printf("mistake (push back) = %d\n", mistake);

	size = int_vector_get_size(v);
	printf("after (pop back) size = %d\n", size);

	capacity = int_vector_get_capacity(v);
	printf("after (pop back) capacity = %d\n\n", capacity);

	int_vector_free(v);
        printf("After free v: %p\n", v->data);

	return 0;
}
