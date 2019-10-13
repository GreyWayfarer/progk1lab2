#include "IntVector.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  IntVector vector;

  // CREATE TEST
  printf("\nCreate test\n");
  vector = *int_vector_new(10);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  // PUSH TEST #1
  printf("\nPush test #1\n");

  for (int i = 0; i < vector.capacity; ++i) {
    // vector.vec = NULL;
    int_vector_push_back(&vector, i + 1);
    printf("%d ", vector.data[i]);
  }

  printf("\ncapacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  // DELETE TEST
  printf("\nDelete test\n");
  // vector.size = 0;
  // vector.size = 11;
  int_vector_pop_back(&vector);

  for (int i = 0; i < vector.capacity; ++i) {
    // vector.vec = NULL;
    printf("%d ", vector.data[i]);
  }

  printf("\ncapacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  // PUSH TEST #2
  /*printf("\nPush test #2\n");

  for (int i = vector.size; i <= 11; ++i) {
    int_vector_push_back(&vector, i + 1);
    printf("%d ", vector.data[i]);
  }

  printf("\ncapacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);
*/
  // SET ITEM, GET SIZE AND GET CAPACITY TESTS
  printf("\nSet test\n");
  int_vector_set_item(&vector, 4, 0);
  // int_vector_set_item(&vector, 10, 1);

  // vector.capacity = 0;
  // int_vector_set_item(&vector, 10, 1);

  // int_vector_set_item(&vector, 11, 1);

  for (int i = 0; i < vector.size; ++i) {
    printf("%d ", vector.data[i]);
  }

  printf("\ncapacity: %ld, size: %ld\n", int_vector_get_capacity(&vector),
         int_vector_get_size(&vector));

  // COPY TEST
  printf("\nCopy test\n");
  IntVector copy_vector;
  // vector.vec = NULL;
  copy_vector = *int_vector_copy(&vector);
  printf("capacity: %ld, size: %ld, address vec: %p\n", copy_vector.capacity,
         copy_vector.size, copy_vector.data);

  if (copy_vector.size > 0) {

    for (int i = 0; i < copy_vector.size; ++i) {
      printf("%d ", copy_vector.data[i]);
    }

    printf("\n");
  }

  // RESERVE TEST#1
  printf("\nReserve test(less)\n");
  int_vector_reserve(&vector, 5);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  if (vector.size > 0) {

    for (int i = 0; i < vector.size; ++i) {
      printf("%d ", vector.data[i]);
    }

    printf("\n");
  }
  // RESERVE TEST#2
  printf("\nReserve test(more)\n");
  int_vector_reserve(&vector, 16);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  if (vector.size > 0) {

    for (int i = 0; i < vector.size; ++i) {
      printf("%d ", vector.data[i]);
    }

    printf("\n");
  }
  // FIT TEST
  printf("\nFit test\n");
  int_vector_shrink_to_fit(&vector);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  if (vector.size > 0) {

    for (int i = 0; i < vector.size; ++i) {
      printf("%d ", vector.data[i]);
    }

    printf("\n");
  }
  // RESIZE TEST#1
  printf("\nResize test(less)\n");
  int_vector_resize(&vector, 9);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  if (vector.size > 0) {

    for (int i = 0; i < vector.size; ++i) {
      printf("%d ", vector.data[i]);
    }

    printf("\n");
  }

  // RESIZE TEST#2 + PUSH #3 + GET ITEM + DELETE ELEMENT #2
  printf("\nResize test(more)\n");
  int_vector_resize(&vector, 12);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  if (vector.size > 0) {

    for (int i = 0; i < vector.size; ++i) {
      printf("%d ", vector.data[i]);
    }

    printf("\n");
  }

  int_vector_pop_back(&vector);

  printf("After Push\n");
  int_vector_push_back(&vector, 1);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);
  printf("num: %d\n", int_vector_get_item(&vector, 0));
  // int_vector_get_item(&vector, 1);
  // int_vector_get_item(&vector, -1);

  // FREE TEST
  printf("\nFree test\n");
  int_vector_free(&vector);
  int_vector_free(&copy_vector);
  printf("capacity: %ld, size: %ld, address vec: %p\n", vector.capacity,
         vector.size, vector.data);

  return 0;
}
