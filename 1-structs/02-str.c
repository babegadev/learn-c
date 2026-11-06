#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *data;
  size_t len;
} Str;

Str str_from(const char *s) {
  size_t len = strlen(s);
  char *data = malloc(len + 1);
  memcpy(data, s, len + 1);
  return (Str){data, len};
}

Str str_copy(Str s) {
  char *data = malloc(s.len + 1);
  memcpy(data, s.data, s.len + 1);
  return (Str){data, s.len};
}

void str_free(Str *s) {
  free(s->data);
  s->data = NULL;
  s->len = 0;
}

Str str_concat(Str a, Str b) {
  size_t len = a.len + b.len;
  char *data = malloc(len + 1);

  memcpy(data, a.data, a.len);
  memcpy(data + a.len, b.data, b.len + 1);

  return (Str){data, len};
}

bool str_eq(Str a, Str b) {
  if (a.len != b.len) return false;

  for (size_t i = 0; i < a.len; i++) {
    if (a.data[i] != b.data[i]) return false;
  }
  return true;
}

void str_print(const Str *s) { printf("%.*s\n", (int)s->len, s->data); }

int main(void) {
  Str a = str_from("Hello, ");
  Str b = str_from("World!");

  Str c = str_concat(a, b);

  Str d = str_from("Hello, ");
  Str e = str_from("hello, ");

  str_print(&a);
  str_print(&b);
  str_print(&c);
  str_print(&d);
  str_print(&e);

  printf("a, b: %s\n", str_eq(a, b) ? "equal" : "not equal");
  printf("a, d: %s\n", str_eq(a, d) ? "equal" : "not equal");
  printf("a, e: %s\n", str_eq(a, e) ? "equal" : "not equal");

  str_free(&a);
  str_free(&b);
  str_free(&c);
  str_free(&d);
  str_free(&e);

  Str x = str_from("hello");
  Str y = str_copy(x);
  str_free(&x);
  str_free(&y);

  return 0;
}
