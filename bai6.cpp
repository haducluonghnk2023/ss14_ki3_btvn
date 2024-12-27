#include <stdio.h>

// Ham hoan doi hai phan tu
void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// Ham trien khai thuat toan sap xep chen
void insertionSort(int arr[], int n) {
  int i, key, j;
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;

    /* Di chuyen cac phan tu cua arr[0..i-1], lon hon key,
    den mot vi tri ve phia truoc so voi vi tri hien tai */
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Ham trien khai thuat toan tim kiem tuyen tinh
int linearSearch(int arr[], int n, int x) {
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      return i; // Tra ve vi tri cua phan tu neu tim thay
    }
  }
  return -1; // Tra ve -1 neu khong tim thay
}

// Ham trien khai thuat toan tim kiem nhi phan
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2;

    // Neu phan tu o giua
    if (arr[mid] == x)
      return mid;

    // Neu phan tu nho hon giua, thi no chi co the
    // hien dien trong mang con ben trai
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    // Nguoc lai, phan tu chi co the hien dien
    // trong mang con ben phai
    return binarySearch(arr, mid + 1, r, x);
  }

  // Neu phan tu khong co trong mang
  return -1;
}

// Ham de in mot mang
void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int n, x, linearResult, binaryResult;

  printf("Nhap so phan tu cua mang: "); 
  scanf("%d", &n);

  int arr[n]; 
  printf("Nhap cac phan tu cua mang:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  printf("Mang ban dau: \n");
  printArray(arr, n);

  insertionSort(arr, n); 
  printf("Mang sau khi sap xep: \n");
  printArray(arr, n);

  printf("Nhap gia tri can tim: ");
  scanf("%d", &x);

  linearResult = linearSearch(arr, n, x);
  (linearResult == -1) ? printf("Tim kiem tuyen tinh: Phan tu khong ton tai trong mang\n")
                 : printf("Tim kiem tuyen tinh: Phan tu duoc tim thay tai vi tri %d\n", linearResult);

  binaryResult = binarySearch(arr, 0, n - 1, x);
  (binaryResult == -1) ? printf("Tim kiem nhi phan: Phan tu khong ton tai trong mang\n")
                 : printf("Tim kiem nhi phan: Phan tu duoc tim thay tai vi tri %d\n", binaryResult);

  return 0;
}
