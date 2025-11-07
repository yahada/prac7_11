#include <iostream>

int * extend(const int * a, size_t k, size_t d, int filter) {
  int * new_arr = new int[d];
  for (size_t i = 0; i < std::min(k, d); ++i) {
    new_arr[i] = a[i];
  }

  for (size_t i = std::min(k,d); i < d; ++i) {
    new_arr[i] = filter;
  }

  return new_arr;
}

void extend(int **ptr_a, size_t k, size_t d, int fillter) {
  int * new_arr = extend(*ptr_a, k, d, fillter);
  delete[] *ptr_a;
  *ptr_a = new_arr;
}


int main() {
  int * arr = new int[5]{1, 2, 3, 4, 5};
  int ** ptr_a = &arr;
  extend(ptr_a, 5, 10, 0);
  extend(&arr, 5, 10, 0); // &arr - взятие адреса

  for (size_t i = 0; i < 10; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}