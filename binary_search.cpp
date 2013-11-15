#include <iostream>
#include <string>

using namespace std;


class Sort {
  private:
    void Split(int *, int, int);
    void Merge(int *, int, int, int);
    void QuickSortRoutine(int *, int, int);
    void Heapify(int *, int len);
    void SiftDown(int *, int, int);
  public:
    void BubbleSort(int *, int);
    void InsertionSort(int *, int);
    void SelectionSort(int *, int);
    void MergeSort(int *, int);
    void QuickSort(int *, int);
    void HeapSort(int *, int);
};


class Search {
  private:
    Sort* sort;
  public:
    Search() {
      sort = new Sort();
    };
    int LinearSearch(int, int *, int);
    int BinarySearch(int, int *, int, int);
};


/**
 * Utility function to print an Array.
 *
 * Args:
 *     arr    The array to be printed.
 *     len    The length of the array.
 */
void PrintArr(int* arr, int len) {
  for(int i = 0; i < len; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}

int main(int argv, char** argc) {
  Search* s = new Search();
  string str = "World";
  int arr[] = {23, 45, 97, 25, 90, 48, 72, 69, 10, 80, 34, 49};
  int length = sizeof(arr) / sizeof(int);
  int value;
  cout << "Hello, " << str << "!!"  << endl;
  cout << "Please enter a value to be searched for the array: ";
  cin >> value;
  int index = s->LinearSearch(value, arr, length);
  switch (index) {
    case -1:
      cout << value << " not found." << endl;
      break;
    default:
      cout << "The index of " << value << " is: " << index << endl;
  }
  Sort* srt = new Sort();
  srt->HeapSort(arr, length);
  PrintArr(arr, length);
  index = s->BinarySearch(value, arr, 0, length - 1);
  switch (index) {
    case -1:
      cout << value << " not found." << endl;
      break;
    default:
      cout << "The index of " << value << " is: " << index << endl;
  }
}


/**
 * A function implementing binary search.
 *
 * Args:
 *     value    The value to be search for. 
 *     arr      Pointer to the array to be searched for the value.
 *     start    Start index of the array.
 *     end      End index of the array.
 *
 * Returns:
 *     The index of the element in the given array. Else returns -1.
 */
int Search::BinarySearch(int value, int* arr, int start, int end) {
  int mid = (start + end)/2;
  int index = -1;
  if (value == arr[mid]) {
    index = mid;
  } else if (value < arr[mid]) {
    index = BinarySearch(value, arr, start, mid - 1); 
  } else {
    index = BinarySearch(value, arr, mid + 1, end);
  }
  return index;
}


/**
 * A function implementing linear search.
 *
 * Args:
 *     value    The value to be search for. 
 *     arr      Pointer to the array to be searched for the value.
 *     length   Length of the array.
 *
 * Returns:
 *     The index of the element in the given array. Else returns -1.
 */
int Search::LinearSearch(int value, int* arr, int length) {
  for (int i = 0; i < length; i++) {
    if (arr[i] == value) {
      return i;
    }
  }
  return -1;
}


/**
 * An implementation of bubble Sort.
 *
 * Args:
 *     arr    The array to be sorted.
 *     len    The length of the array.
 */
void Sort::BubbleSort(int *arr, int len) {
  for(int i = len; i > 0; i--) {
    for(int j = 0; j < i; j++) {
      if (arr[j] > arr[j+1]) {
        arr[j] = arr[j] + arr[j+1];
        arr[j+1] = arr[j] - arr[j+1];
        arr[j] = arr[j] - arr[j+1];
      }
    }
  }
}


/**
 * An implementation of insertion Sort.
 *
 * Args:
 *     arr    The array to be sorted.
 *     len    The length of the array.
 */
void Sort::InsertionSort(int *arr, int len) {
  for(int i = 1; i < len; i++) {
    for(int j = i; j > 0; j--) {
      if (arr[j] < arr[j - 1]) {
        arr[j] = arr[j] + arr[j - 1];
        arr[j - 1] = arr[j] - arr[j - 1];
        arr[j] = arr[j] - arr[j - 1];
      }
    }
  }
}

/**
 * An implementation of selection Sort.
 *
 * Args:
 *     arr    The array to be sorted.
 *     len    The length of the array.
 */
void Sort::SelectionSort(int *arr, int len) {
  int min;
  for(int i = 0; i < len; i++) {
    min = i;
    for(int j = i + 1; j < len; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    if (min != i) {
      arr[i] = arr[min] + arr[i];
      arr[min] = arr[i] - arr[min];
      arr[i] = arr[i] - arr[min];
    }
  }
}


/**
 * An implementation of merge Sort.
 *
 * Args:
 *     arr    The array to be sorted.
 *     len    The length of the array.
 */
void Sort::MergeSort(int *arr, int len) {
  int start = 0;
  int end = len - 1;
  Split(arr, start, end);  
}

/**
 * An implementation of Split for merge sort.
 *
 * Args:
 *     arr    The array to be sorted.
 *     start  The start index of the array to be split.
 *     end    The end index of the array to be split.
 */
void Sort::Split(int *arr, int start, int end) {
  if(start >= end) {
    return;
  }
  int mid = (start + end) / 2;
  Split(arr, start, mid);
  Split(arr, mid + 1, end);
  Merge(arr, start, mid, end);
}


/**
 * An implementation of merge routine.
 *
 * Args:
 *     arr    The array to be sorted.
 *     start  The start index of the array.
 *     mid    The middle index of the array.
 *     end    The end index of the array.
 */
void Sort::Merge(int *arr, int start, int mid, int end) {
  int len1 = mid - start + 1;
  int len2 = end - mid;
  int* left = new int[len1];
  int* right = new int[len2];
  for(int i = 0; i < len1; i++) {
    left[i] = arr[start + i];
  }
  for(int i = 0; i < len2; i++) {
    right[i] = arr[mid + i + 1];
  }
  int i = 0;
  int j = 0;
  int k = start;
  while((start + i) <= mid && (mid + 1 + j) <= end) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }

  if (k <= end) {
    if ((start + i) > mid) {
      for (; k <= end; k++) {
        arr[k] = right[j];
        j++;
      }
    } else {
      for(;k <= end; k++) {
        arr[k] = left[i];
        i++;
      }
    }
  }
}


/**
 * An implementation of Quick Sort.
 *
 * Args:
 *     arr    The array to be sorted.
 *     len    The length of the array.
 */
void Sort::QuickSort(int* arr, int len) {
  int start = 0;
  int end = len - 1;
  QuickSortRoutine(arr, start, end);
}


/**
 * An implementation of Quick Sort routine.
 *
 * Args:
 *     arr    The array to be sorted.
 *     start  The start index of the array.
 *     end    The end index of the array.
 */
void Sort::QuickSortRoutine(int* arr, int start, int end) {
  if (end - start < 1) {
    return;
  }
  int pivot = start;
  int left = start + 1;
  int right = end;
  PrintArr(arr, 12);
  cout << "left: " << left << "::right: " << right << endl;
  while (true) {
    while(arr[left] < arr[pivot] && left <= end) {
      left++;
    }
    while(arr[right] > arr[pivot] && right >= start) {
      right--;
    }
    if (left >= right) {
      break;
    }
    if (arr[left] != arr[right]) {
      arr[left] = arr[left] + arr[right];
      arr[right] = arr[left] - arr[right];
      arr[left] = arr[left] - arr[right];
    }
  }
  if (arr[pivot] != arr[right]) {
    arr[pivot] = arr[pivot] + arr[right];
    arr[right] = arr[pivot] - arr[right];
    arr[pivot] = arr[pivot] - arr[right];
  }

  QuickSortRoutine(arr, start, right - 1);
  QuickSortRoutine(arr, right + 1, end);
}

/**
 * An implementation of selection Sort.
 *
 * Args:
 *     arr    The array to be sorted.
 *     len    The length of the array.
 */
void Sort::HeapSort(int *arr, int len) {
  Heapify(arr, len);
  while (len > 0) {
    len--;
    if (arr[len] != arr[0]) {
      arr[len] = arr[0] + arr[len];
      arr[0] = arr[len] - arr[0];
      arr[len] = arr[len] - arr[0];
    }
    SiftDown(arr, 0, len - 1);
  }
}


/**
 * An implementation of heapify routine.
 *
 * Args:
 *     arr    The array to be sorted.
 *     len    The length of the array.
 */
void Sort::Heapify(int *arr, int len) {
  int start = (len - 2) / 2;  // start is assigned the index of the last parent node.
  while (start >= 0) {
    SiftDown(arr, start, len - 1 );
    start--;
  }
}

/**
 * An implementation of the SiftDown routine.
 *
 * Args:
 *     arr    The array to be sorted.
 *     root   The root to be heaped.
 *     end    The index of the last element.
 */
void Sort::SiftDown(int *arr, int root, int end) {
  int swap;
  int child;
  while (root * 2 + 1 <= end) {
    child = root * 2 + 1;
    swap = root;
    if (arr[swap] < arr[child]) {
      swap = child;
    }
    if (child + 1 <= end and arr[swap] < arr[child + 1]) {
      swap = child + 1;
    }
    if (arr[swap] != arr[root]) {
      arr[swap] = arr[root] + arr[swap];
      arr[root] = arr[swap] - arr[root];
      arr[swap] = arr[swap] - arr[root];
      root = swap;
    } else {
      return;
    }
  }
}

