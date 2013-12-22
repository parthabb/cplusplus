#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void PrintArr (int *arr, int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}

class RandomizedSelect {
  private:
    int *arr;
    int size;
    void randomize_pivot (int start, int end);
    int randomized_partition ( int start, int end);
    int randomized_select (int start, int end, int index);
  public:
    RandomizedSelect (int *arr, int size);
    int getElement (int index);
};

RandomizedSelect :: RandomizedSelect (int *a, int s) {
  arr = new int[s];
  size = s;
  for (int i = 0; i < s; i++) {
    arr[i] = a[i];
  }
}

void RandomizedSelect :: randomize_pivot (int start, int end) {
  srand(time(NULL));
  int s = end - start + 1;
  int pivot = rand () % s + start;
  int temp = arr[end];
  arr[end] = arr[pivot];
  arr[pivot] = temp;
}

int RandomizedSelect :: randomized_partition (int start, int end) {
  int pivot = arr[end];
  int i, j;
  i = j = start;
  int temp;
  for (; i < end; i++) {
    if (arr[i] < pivot) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j++;
    }
  }
  temp = arr[end];
  arr[end] = arr[j];
  arr[j] = temp;
  return j;
}

int RandomizedSelect :: randomized_select (int start, int end, int index) {
  if (start == end) {
    return arr[start];
  }

  randomize_pivot (start, end);
  int pivot_index = randomized_partition (start, end);

  if (pivot_index == index) {
    return arr[index];
  } else if (index < pivot_index) {
    return randomized_select (start, pivot_index - 1, index);
  } else {
    return randomized_select (pivot_index + 1, end, index);
  }
}

int RandomizedSelect :: getElement (int index) {
  return randomized_select (0, size - 1, index);
}

int main () {
  int size = 20;
  int *arr = new int[size];
  srand(time(NULL));
  for (int i = 0; i < size; i++) {
    arr[i] = rand () % 100;
  }
  PrintArr (arr, size);
  RandomizedSelect *rs = new RandomizedSelect(arr, size);
  cout << rs->getElement (size - 1) << endl;
  cout << rs->getElement (0) << endl;
  cout << rs->getElement (size / 2) << endl;
}
