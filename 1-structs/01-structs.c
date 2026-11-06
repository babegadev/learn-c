#include <stdio.h>

struct Student {
  const char *name;
  int age;
  double gpa;
};

void print_student(const struct Student *s) {
  printf("%s (%d) GPA: %.1f\n", s->name, s->age, s->gpa);
}

void birthday(struct Student *s) { s->age++; }

const struct Student *best_gpa(const struct Student *arr, size_t n) {
  if (n == 0) return NULL;

  size_t max_index = 0;

  for (size_t i = 1; i < n; i++) {
    if (arr[i].gpa > arr[max_index].gpa) {
      max_index = i;
    }
  }

  return &arr[max_index];
}

int main(void) {
  struct Student students[] = {
      {"Alang", 19, 3.7}, {"Babega", 18, 3.6}, {"Mahareza", 20, 3.9}};
  size_t n = sizeof(students) / sizeof(students[0]);

  printf("sizeof(struct Student) = %zu\n", sizeof(struct Student));
  printf("name: %zu, age: %zu, gpa: %zu\n", sizeof(const char *), sizeof(int),
         sizeof(double));

  for (size_t i = 0; i < n; i++) print_student(&students[i]);

  birthday(&students[1]);

  for (size_t i = 0; i < n; i++) print_student(&students[i]);

  const struct Student *best = best_gpa(students, n);
  if (best) printf("Best student: %s\n", best->name);

  return 0;
}