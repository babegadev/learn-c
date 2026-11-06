#include <stdio.h>
#include <stdlib.h>

size_t my_strlen(const char *s) {
  size_t count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

int my_strcmp(const char *a, const char *b) {
  size_t i = 0;

  while (a[i] == b[i] && a[i] != '\0') {
    i++;
  }

  return a[i] - b[i];
}

char *my_strcpy(char *dst, const char *src) {
  size_t i = 0;

  while (src[i] != '\0') {
    dst[i] = src[i];
    i++;
  }

  dst[i] = '\0';

  return dst;
}

char *my_strdup(const char *s) {
  char *copy = malloc(my_strlen(s) + 1);

  if (copy == NULL) {
    return NULL;
  }

  my_strcpy(copy, s);
  return copy;
}

size_t count_char(const char *s, char c) {
  size_t count = 0;

  for (size_t i = 0; s[i] != '\0'; i++) {
    if (s[i] == c) {
      count++;
    }
  }

  return count;
}

void my_strrev(char *s) {
  size_t length = my_strlen(s);

  for (size_t i = 0; i < length / 2; i++) {
    char temp = s[i];

    s[i] = s[length - i - 1];
    s[length - i - 1] = temp;
  }
}

char to_upper(char c) { return (c >= 'a' && c <= 'z') ? c - ('a' - 'A') : c; }

char *my_strupper_new(const char *s) {
  const size_t len = my_strlen(s);
  char *upper = malloc(len + 1);

  if (upper == NULL) {
    return NULL;
  }

  for (size_t i = 0; s[i] != '\0'; i++) {
    upper[i] = to_upper(s[i]);
  }

  upper[len] = '\0';

  return upper;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    fprintf(stderr, "usage: ./words word...\n");
    return 1;
  }

  int lowest_index = 1;

  for (int i = 1; i < argc; i++) {
    const char *word = argv[i];
    size_t len = my_strlen(word);
    size_t a_count = count_char(word, 'a');
    char *reverse = my_strdup(word);
    char *upper = my_strupper_new(word);
    if (upper == NULL || upper == NULL) {
      free(upper);
      free(reverse);
      return 1;
    }
    my_strrev(reverse);

    if (my_strcmp(word, argv[lowest_index]) < 0) {
      lowest_index = i;
    }

    printf("%s: len=%zu reversed=%s upper=%s a=%zu\n", word, len, reverse,
           upper, a_count);

    free(upper);
    free(reverse);
  }

  printf("first: %s\n", argv[lowest_index]);

  return 0;
}