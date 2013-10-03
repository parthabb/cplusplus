#include <iostream>

using namespace std;

int main(int argv, char **argc) {
  cout << "Please enter 5 numbers:" << endl;
  int* arr = new int(5);
  char c;
  for (int i = 0; i < 5; i++) {
    cin >> arr[i];
  }
  cout << "The numbers you entered are:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr[i] << '\t';
  }
  cout << endl;
}
