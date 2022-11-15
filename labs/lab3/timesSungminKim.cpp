//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include<iostream>
#include<vector>
using namespace std;

#if 0
// mulitply even number elements in the list by 10
// without using reference variable.
int main(int argc, char *argv[]) {
    vector<int> list = {0, 1, 2, 2, 4, 5, 6, 7, 8, 8, 10};

    for (size_t i = 0; i < list.size(); i++) {
        if(list[i]%2==0){
            int temp=list[i];
            list[i]=temp*10;
        }
    }

    for (auto x: list) cout << x << " ";
    cout<<endl;
    return 0;
}
#else 
// mulitply even number elements in the list by 10
// using reference variable.
int main(int argc, char *argv[]) {
    vector<int> list = {0,1,2,2,4,5,6,7,8,8,10};

    for (size_t i = 0; i < list.size(); i++) {
        if(list[i]%2==0){
            int& temp=list[i];
            list[i]=temp*10;
        }
    }

    for (auto x: list) cout << x << " ";
    cout<<endl;
    return 0;
}
#endif