//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

// bubble sort by idebtor@gmail.com
// The bubble sort makes multiple passes through a list. It compares adjacent 
// items and exchanges those that are out of order. Each pass through the list 
// places the next largest value in its proper place.  It is important to note 
// that once the largest value in the list is part of a pair, it will continually 
// be moved along until the pass is complete.In essence, each item “bubbles” up 
// to the location where it belongs. Its time complexity is O(n^2).
// 
// 2019/02/02: Created by idebtor@gmail.com
// 2021/01/20: comparator default argument added 
// 
// To build and run,
// Set #if 1 to activate main() function at the bottom of the file first. 
// > g++ -std=c++11 bubble.cpp -o bubble
// > ./bubble
//
// To use DEBUG or test it, compile with -D option and turn #if 1 on.
// Then build it with -D option run it as shown below:
// > g++ -std=c++11 -DDEBUG bubble.cpp -o bubble
// > ./bubble
//
// To add this function to a static library libsort.a, 
// 1. set #if 0 to deactivate main() function at the bottom of the file first. 
// 2. compile first to produce ~.o file. 
// 3. add it to libsort.a as shown below.
// > g++ -std=c++11 -c bubble.cpp         # produce bubble.o
// > ar r libsort.a bubble.o              # insert or update bubble.o in libsort.a
// > ar t libsort.a                       # list objects in libsort.a 

#include <iostream>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

#if 0
void bubblesort(int *list, int n) {
  DPRINT(cout << "BUBBLE SORTING...\n");
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;
    for (int j = 0; j < n - i - 1; j++) { // last i element is already in place
      if (list[j + 1] < list[j]) {        // hard-code comparison: works only for ascending
        swapped = true;
        swap(list[j + 1], list[j]);
      }
    }
    DPRINT(for(int x = 0; x < n; x++) cout << list[x] << " "; cout << endl);
    if (!swapped) break;
  }
}
#endif

// bubblesort using a comparator function passed as a function pointer.
void bubblesort(int *list, int n, bool (*comp)(int, int)) {
  DPRINT(cout << "BUBBLE SORTING...fp\n");

  for(int i=0;i<n-1;i++){
    bool swapped = false;
    for(int j=0;j<n-i-1;j++){
      if(comp(list[j+1],list[j])) {
        swapped=comp(list[j+1],list[j]);
        swap(list[j+1],list[j]);
      }
    }
  DPRINT(for(int x = 0; x < n; x++) cout << list[x] << " "; cout << endl);
  if (!swapped) break;
  }
}

bool more(int x, int y) { return x > y; }   // for descending order
bool less(int x, int y) { return x < y; }   // for ascending order 

bool evenfirst(int x, int y) {
  // if x(2nd element) is even and y is odd, x goes first (swap needed)
  if ((x % 2 == 0) && !(y % 2 == 0)) return true;
 
  // if x(2nd element) is odd and y is even, y goes first (no swap needed)
  if (!(x % 2 == 0) && (y % 2 == 0)) return false;
 
  // otherwise sort in ascending order (x:2nd element, y:1st element)
  return ::less(x, y);
}

void bubblesort(int *list, int n, bool (*comp)(int, int)=::less);

#if 1

int main() {

  int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8 };
  int N = sizeof(list) / sizeof(list[0]);

  cout << "UNSORTED: " << endl;
  for (auto x: list) cout << x << "  "; 
  cout << endl << endl;

  bubblesort(list, N);
  cout << "[1]BUBBLE SORTED:" << endl;
  for (auto x: list) cout << x << "  "; 
  cout << endl << endl;

  bubblesort(list, N, more);      // descending
  cout << "[2]BUBBLE SORTED - descending using fp: " << endl;
  for (auto x: list) cout << x << "  "; 
  cout << endl << endl;

  bubblesort(list, N, ::less);    // ascending
  cout << "[3]BUBBLE SORTED - ascending using fp: " << endl;
  for (auto x: list) cout << x << "  "; 
  cout << endl << endl;

  bubblesort(list, N, evenfirst);    // even first
  cout << "[4]BUBBLE SORTED - even first: " << endl;
  for (auto x: list) cout << x << "  "; 
  cout << endl << endl;
}
#endif 

#if 0
// this sort() using STL is provided for your reference. 
#include <algorithm>

int main(int argc, char *argv[]) {
  int list[] = { 3, 4, 1, 7, 0, 9, 6, 5, 2, 8 };
  int N = sizeof(list) / sizeof(list[0]);

  for (auto x: list) cout << x << " ";
  cout << endl << endl;

  sort(list, list + N);
  for (auto x: list) cout << x << " ";
  cout << endl << endl;

  sort(list, list + N, std::greater<int>();
  for (auto x: list) cout << x << " ";
  cout << endl << endl;

  sort(list, list + N, std::less<int>());
  for (auto x: list) cout << x << " ";
  cout << endl << endl;
}
#endif
