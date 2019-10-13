#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity) {
	IntVector *v = malloc(sizeof(*v));
	if (v != NULL &&  initial_capacity > 0) {
		v->data = malloc(sizeof(int) * initial_capacity);
		v->size = 0;
		v->capacity = initial_capacity;
		if (v->data == NULL) {
                    printf("Array is NULL\n");
                    return NULL;
                }
	}
	return v;
}

IntVector *int_vector_copy(const IntVector *v) {
	IntVector *c = int_vector_new(v->capacity);
	for (int i = 0; i < v->size; i++) {
		c->data[i] = v->data[i];
	}
	c->size = v->size;
	return c;
}

void int_vector_free(IntVector *v) {
	free(v);
        free(v->data);
}

int int_vector_get_item(const IntVector *v, size_t index) {
	if (v->data == NULL) {
		printf("Vector is NULL, return -1\n");
	}
        if (index > v->size) {
                printf("Index more then size of vector, return -1\n");
        }
        if (v->size == 0 || v->capacity == 0) {
                printf("Size or capacity is 0, return -1\n");
        }
        if (index < v->size) {
                return v->data[index];
        }
        return -1;
}

void int_vector_set_item(IntVector *v, size_t index, int item) {
	if (v->data == NULL) {
		printf("Vector is NULL\n");
		return;
	}
        if (v->size == 0 || v->capacity == 0) {
                printf("Size or capacity is 0\n");
                return;
        }
        if (index > v->capacity || index > v->size) {
                printf("Index more than size or capacity\n");
                return;
        }
        if (index <= v->size) {
	        v->data[index] = item;
        }
        return;
}

size_t int_vector_get_size(const IntVector *v) {
	return v->size;
}

size_t int_vector_get_capacity(const IntVector *v) {
	return v->capacity;
}

int int_vector_push_back(IntVector *v, int item) {
	if (v->data == NULL) {
                printf("Vector is NULL, return -1\n");
                return -1;
        }
        if (v->capacity == 0) v->capacity = 2;
        if (v->size == v->capacity) {
                v->capacity = v->capacity * 2;
                v->data = realloc(v->data, v->capacity * sizeof(int));
        }
        if (v->size > v->capacity) {
                printf("Size > capacity, return -1\n");
                return -1;
        }
	v->size++;
	v->data[v->size] = item;
	return 0;
}

void int_vector_pop_back(IntVector *v) {
	if (v->data == NULL) {
            printf("Vector is NULL\n");
            return;
        }
        if (v->size == 0 || v->capacity == 0) {
    printf("Size or capacity is 0\n");
    return;
  }

  if (v->size > v->capacity) {
    printf("Size more than capacity\n");
    return;
  }
  if (v->size == 0) {
    return;
  }

  if (v->size <= v->capacity) {
    v->data[v->size - 1] = 0;
    v->size--;
  }
  return;
}

int int_vector_shrink_to_fit(IntVector *v) {
        if (v->data == NULL) {
            printf("Vector is NULL, return -1\n");
            return -1;
        }
        if (v->size >= v->capacity) {
            printf ("Size >= capacity, return -1\n");
            return -1;
        }
        if (v->size < v->capacity) {
            v->data = realloc(v, sizeof(int) * v->size);
            v->capacity = v->size;
            return 0;
  }

  return -1;
}

int int_vector_resize(IntVector *v, size_t new_size) {
  if (v->data == NULL) {
    printf("Vector is NULL, return -1\n");
    return -1;
  }
  if (v->size == new_size) {
    printf("New size is right prev.size, return -1\n");
    return -1;
  }

  if (new_size <= v->capacity && new_size > v->size) {
    for (int i = v->size; i < new_size; i++) {
      v->data[i] = 0;
    }

    v->size = new_size;

    return 0;
  }

  if (new_size <= v->capacity && new_size < v->size) {
    for (int i = new_size; i < v->size; i++) {
      v->data[i] = 0;
    }
    v->size = new_size;

    return 0;
  }

  return -1;
}

int int_vector_reserve(IntVector *v, size_t new_capacity) {

  if (v->data == NULL) {
    printf("Vector is NULL, return -1\n");
    return -1;
  }

  if (new_capacity <= v->capacity) {
    printf("New capacity less than old capacity or the same, return -1\n");
    return -1;
  }

  if (new_capacity > v->capacity) {
    v->capacity = new_capacity;
    v->data = realloc(v->data, new_capacity * sizeof(int));
    return 0;
  }

  return -1;
}
