#include <iostream>

int * extend(const int * a, size_t k, size_t d, int filler) {
  int * new_arr = new int[d];
  for (size_t i = 0; i < std::min(k, d); ++i) {
    new_arr[i] = a[i];
  }

  for (size_t i = std::min(k,d); i < d; ++i) {
    new_arr[i] = filler;
  }

  return new_arr;
}

void extend(int **ptr_a, size_t k, size_t d, int filler) {
  int * new_arr = extend(*ptr_a, k, d, filler);
  delete[] *ptr_a;
  *ptr_a = new_arr;
}

int * add_row(const int * a, size_t n, size_t m, int filler) {
  return extend(a, n * m, (n+1) * m, filler);
}


int main() {
  int * arr = new int[4]{1, 2, 3, 4};
  int * new_matrix = add_row(arr, 2, 2, 0);
  // int ** ptr_a = &arr;
  // extend(ptr_a, 5, 10, 0);
  // extend(&arr, 5, 10, 0); // &arr - взятие адреса

  // for (size_t i = 0; i < 10; ++i) {
  //   std::cout << arr[i] << " ";
  // }

  for (size_t i = 0; i < 3; ++i) {
    for (size_t j = 0; j < 2; ++j) {
      std::cout << new_matrix[i * 2 + j] << " ";
    }
    std::cout << "\n";

  }
  std::cout << "\n";
}