#include <iostream>
#include <algorithm>

void arrayToHeap(int array[]){
  int swaps = 0;
  
  for (int i = array.size() - 1; i > 0; i--){
    if ( array.size() >= 2i + 1 && array[2i + 1] < array[i]){
        swap(array[i], array[2i + 1]);
        swap++;
    }
    if ( array.size() >= 2i + 2 &&  array[i]){
        swap(array[i], array[2i + 2]);
    }
  
  }
}

int main(int argv, int* argc){
  
  int n;
  cin >> n;
  int array[n];
  for (i = 0; i < n; i++){
    cin >> array[i];
  }
  heapToArray(array);
}


