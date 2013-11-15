#include <iostream>
#include <cstdlib>

using namespace std;

void Print(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}

class Sort {
  private:
    void quick_sort_subroutine (int *arr, int start, int end);
    int get_randomized_pivot (int *arr, int start, int end);
    void build_heap (int *arr, int size);
    void max_heapify (int *arr, int parent, int size);
    void merge_sort_subroutine (int *arr, int start, int end);
    void merge_subroutine (int *arr, int start, int mid, int end);
  public:
    void bubble_sort (int *arr, int size);
    void insertion_sort (int *arr, int size);
    void selection_sort (int *arr, int size);
    void counting_sort (int *arr, int size);
    void quick_sort (int *arr, int size);
    void heap_sort (int *arr, int size);
    void merge_sort (int *arr, int size);
    void radix_sort (int *arr, int size) {};
    void bucket_sort (int *arr, int size) {};
};

void Sort :: bubble_sort (int *arr, int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = 1; j < size - i; j++) {
      if (arr[j - 1] > arr[j]) {
        temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void Sort :: insertion_sort (int *arr, int size) {
  int temp;
  for (int i = 1; i < size; i++) {
    for (int j = i; j > 0; j--) {
      if (arr[j] < arr[j - 1]) {
        temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
      }
    }
  }
}

void Sort :: selection_sort (int *arr, int size) {
  int temp, max;
  for (int i = size; i > 0; i--) {
    max = 0;
    for (int j = 1; j < i; j++) {
      if (arr[j] > arr[max]) {
        max = j;
      }
    }
    temp = arr[max];
    arr[max] = arr[i - 1];
    arr[i - 1] = temp;
  }
}

void Sort :: counting_sort (int *arr, int size) {
  int max = arr[0];
  for (int i = 1; i < size; i++) {
    max = arr[i] > max ? arr[i] : max;
  }
  max += 1;
  int *brr = new int[size];
  int *crr = new int[max];

  for (int i = 0; i < max; i++) {
    crr[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    crr[arr[i]] += 1;
  }
  for (int i = 1; i < max; i++) {
    crr[i] += crr[i - 1];
  }
  for (int i = 0; i < size; i++) {
    brr[crr[arr[i]] - 1] = arr[i];
    crr[arr[i]] -= 1;
  }
  for (int i = 0; i < size; i++) {
    arr[i] = brr[i];
  }
}

void Sort :: quick_sort(int *arr, int size) {
  quick_sort_subroutine(arr, 0, size - 1);
}

int Sort :: get_randomized_pivot (int *arr, int start, int end) {
  srand(time(NULL));
  int size = end - start + 1;
  int pivot  = rand() % size + start;
  int temp = arr[end];
  arr[end] = arr[pivot];
  arr[pivot] = temp;
  return arr[end];
}

void Sort :: quick_sort_subroutine (int *arr, int start, int end) {
  int temp;
  if (start < end) {
    int pivot = get_randomized_pivot(arr, start, end);
    int i = start - 1;
    for (int j = start; j < end; j++) {
      if (arr[j] < pivot) {
        temp = arr[++i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    temp = arr[++i];
    arr[i] = arr[end];
    arr[end] = temp;
    quick_sort_subroutine(arr, start, i - 1);
    quick_sort_subroutine(arr, i + 1, end);
  }
}

void Sort :: heap_sort (int *arr, int size) {
  build_heap (arr, size);
  int temp;
  for (int i = size - 1; i > 0; i--) {
    temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    max_heapify (arr, 0, i);
  }
}

void Sort :: build_heap (int *arr, int size) {
  for (int i = size / 2 - 1; i >= 0; i--) {
    max_heapify(arr, i, size);
  }
}

void Sort :: max_heapify (int *arr, int parent, int size) {
  int left = (parent + 1) * 2 - 1;
  int right = (parent + 1) * 2;
  int max = parent;

  if (left < size && arr[max] < arr[left]) {
    max = left;
  }

  if (right < size && arr[max] < arr[right]) {
    max = right;
  }

  if (max != parent) {
    int temp = arr[parent];
    arr[parent] = arr[max];
    arr[max] = temp;
    max_heapify(arr, max, size);
  }
}

void Sort :: merge_sort (int *arr, int size) {
  merge_sort_subroutine (arr, 0, size - 1);
}

void Sort :: merge_sort_subroutine (int *arr, int start, int end) {
  if (end > start) {
    int mid = (start + end + 1) / 2;
    merge_sort_subroutine (arr, start, mid - 1);
    merge_sort_subroutine (arr, mid, end);
    merge_subroutine (arr, start, mid, end);
  }
}

void Sort :: merge_subroutine (int *arr, int start, int mid, int end) {
  int sizeleft = mid - start;
  int sizeright = end - mid + 1;
  int *left = new int[sizeleft];
  int *right = new int[sizeright];
  for (int i = 0; i < sizeleft; i++) {
    left[i] = arr[start + i];
  }
  for (int i = 0; i < sizeright; i++) {
    right[i] = arr[mid + i];
  }
  int i, j, k;
  i = j = 0;
  k = start;
  while (i < sizeleft && j < sizeright) {
    if (left[i] < right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  while (j < sizeright && k < end + 1) {
    arr[k++] = right[j++];
  }
  while (i < sizeleft && k < end + 1) {
    arr[k++] = left[i++];
  }
}

int main() {
  int size = 20;
  int *arr = new int[size];
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 100;
  }
  Print(arr, size);
  Sort *sort = new Sort();
  sort->merge_sort (arr, size);
  Print(arr, size);
}

