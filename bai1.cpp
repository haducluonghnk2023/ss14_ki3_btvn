#include <stdio.h>

int linear_search(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i; 
    }
  }
  return -1; 
}

int main() {
  int arr[] = {2, 3, 4, 10, 40};
  int x = 10;
  int n = sizeof(arr) / sizeof(arr[0]);
  int result = linear_search(arr, n, x);
  if (result == -1) {
    printf("Phan tu khong tim thay trong mang\n");
  } else {
    printf("Phan tu duoc tim thay tai vi tri %d\n", result);
  }
  return 0;
}
// do phuc tap 0(n)
