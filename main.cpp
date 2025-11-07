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

int * add_col(const int * a, size_t n, size_t m, int filler) {
  int * new_arr = new int[n * (m+1)];
  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      new_arr[i * (m + 1) + j] = a[i * m + j];
    }
    new_arr[i * (m + 1) + m] = filler;
  }
  return new_arr;
}


void show_mtx(const int * a, size_t k, size_t d) {
  for (size_t i = 0; i < k; ++i) {
    for (size_t j = 0; j < d; ++j) {
      std::cout << a[i * d + j] << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";

}

int main() {
  int * arr = new int[4]{1, 2, 3, 4};
  int * new_matrix = add_col(arr, 2, 2, 0);
  show_mtx( new_matrix, 2, 3);
  // int ** ptr_a = &arr;
  // extend(ptr_a, 5, 10, 0);
  // extend(&arr, 5, 10, 0); // &arr - взятие адреса

  // for (size_t i = 0; i < 10; ++i) {
  //   std::cout << arr[i] << " ";
  // }


}