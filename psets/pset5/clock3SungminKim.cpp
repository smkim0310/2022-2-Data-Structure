//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <iomanip>

struct Clock{
    int hr, min, sec;
};

using pClock = Clock*;
void tick(Clock *ptr);
void show(Clock *ptr);

int main(void){
    pClock ptr =new Clock {14, 38, 56};

    for(int i=0;i<6;i++){
        tick(ptr);
        show(ptr);
    }
    return 0;
}

void tick(pClock ptr){
    ptr->sec++;
    if(ptr->sec>=60){
        ptr->min++;
        ptr->sec-=60;
    }
    if(ptr->min>=60){
        ptr->hr++;
        ptr->min-=60;
    }
}

void show(pClock ptr){
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":"
              << std::setw(2) << ptr->min << ":"
              << std::setw(2) << ptr->sec << std::endl;
}