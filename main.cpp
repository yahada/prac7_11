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


int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int * new_arr = extend(arr, 5, 10, 0);

  for (size_t i = 0; i < 10; ++i) {
    std::cout << new_arr[i] << " ";
  }
}