//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

// gets the max value in the list and returns its index
int getmax(vector<int> vec) {
    assert(vec.size() > 0);
    auto max = vec[0];
    size_t idx = 0;
    for (size_t i = 0; i < vec.size(); i++) {
        if(vec[i]>max) {
            max=vec[i];
            idx=i; 
        }
    }
    return idx;
}

// sets the max value in the list to 99
void setmax(vector<int> vec) {
    size_t idx = getmax(vec);
    vec[idx]=99;
}

// With a given list, find the max value, then set it to 99 in setmax()
// In main(), we do not see the max value change that was made in setmax(), 
// since functions are using pass-by-value on purpose.
int main(int argc, char *argv[]) {
    vector<int> list1 = {43, 10, 20, 75, 22, 33};
    vector<int> list2 = {33, 13, 45, 19, 39, 22};

    cout << ">list1: "; 
    for (auto x: list1) cout << x << " "; 
    cout << endl; 
    setmax(list1);
    cout << "<list1: "; 
    for (auto x: list1) cout << x << " "; 
    cout << endl << endl;

    cout << ">list2: "; 
    for (auto x: list2) cout << x << " "; 
    cout << endl; 
    setmax(list2);
    cout << "<list2: "; 
    for (auto x: list2) cout << x << " "; 
    cout << endl; 

    return 0;
}
