#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;   // heap array
  size_t len;  // items in use
  size_t cap;  // current capacity to calc items fit before next resize
} IntVec;

IntVec vec_new(void) { return (IntVec){NULL, 0, 0}; }

void vec_push(IntVec *v, int x) {
  //   printf("len: %zu, cap: %zu\n", v->len, v->cap);
  if (v->len == v->cap) {
    size_t new_cap = v->cap == 0 ? 4 : v->cap * 2;
    int *bigger = realloc(v->data, new_cap * sizeof(*v->data));
    if (!bigger) {
      fprintf(stderr, "vec_push: out of memory\n");
      exit(1);
    }

    // successfull realloc, safe to switch pointer
    // printf("grow: %zu -> %zu\n", v->cap, new_cap);
    v->data = bigger;
    v->cap = new_cap;
  }
  v->data[v->len] = x;
  v->len++;
}

int vec_get(const IntVec *v, size_t i) {
  if (i >= v->len) {
    fprintf(stderr, "Error: index out of bounds\n");
    exit(1);
  }
  return v->data[i];
}

void vec_free(IntVec *v) {
  free(v->data);
  v->data = NULL;
  v->cap = 0;
  v->len = 0;
}

int main(void) {
  IntVec v = vec_new();

  for (int i = 1; i <= 20; i++) {
    vec_push(&v, i);
  }

  for (size_t i = 0; i < v.len; i++) {
    printf("%d ", vec_get(&v, i));
  }

  printf("\n");

  vec_get(&v, 20);  // should return an out of bound error

  vec_free(&v);

  return 0;
}