#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char *s) {
  size_t count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

char *my_strcpy(char *dst, const char *src) {
  int i = 0;

  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }

  dst[i] = src[i];

  return dst;
}

int my_strcmp(const char *a, const char *b) {
  int i = 0;

  while (a[i] == b[i] && a[i] != '\0') {
    i++;
  }

  return a[i] - b[i];
}

char *my_strdup(const char *s) {
  char *copy = malloc(my_strlen(s) + 1);

  if (copy == NULL) {
    return NULL;
  }

  my_strcpy(copy, s);
  return copy;
}

char *my_strcat_new(const char *a, const char *b) {
  char *cat = malloc(my_strlen(a) + my_strlen(b) + 1);

  if (cat == NULL) {
    return NULL;
  }

  my_strcpy(cat, a);
  my_strcpy((cat + my_strlen(a)), b);

  return cat;
}

int main(void) {
  // char small[3];
  // my_strcpy(small, "hello world");
  // printf("%s\n", small);

  // char buf[16];
  // my_strcpy(buf, "hello");
  // printf("%s\n", buf);              // hello
  // printf("%zu\n", my_strlen(buf));  // 5

  // char x[] = "cat";
  // char y[] = "cat";
  // printf("%d\n", x == y);  // what do you predict?

  // printf("%d\n", my_strcmp("cat", "cat"));  // 0
  // printf("%d\n", my_strcmp("cat", "car"));  // > 0  ('t' comes after 'r')
  // printf("%d\n", my_strcmp("car", "cat"));  // < 0
  // printf("%d\n",
  //        my_strcmp("cat", "cats"));   // < 0  (the '\0' is smaller than 's')
  // printf("%d\n", my_strcmp("", ""));  // 0

  char *concat = my_strcat_new("hello, ", "world!");

  printf("%s\n", concat);  // Jello
  free(concat);            // whoever calls my_strdup is responsible for freeing

  return 0;
}