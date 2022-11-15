//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <iomanip>
#include <unistd.h>

struct Clock{
    int hr, min, sec;
};

using pClock = Clock*;
void tick(Clock *ptr);
void runs(Clock *ptr);

int main(void){
    pClock ptr =new Clock {14, 38, 56};

    runs(ptr);

    return 0;
}

void runs(pClock ptr){
    while(true){
        sleep(1);

        tick(ptr);
        std::cout.fill('0');
        std::cout << std::setw(2) << ptr->hr << ":"
                << std::setw(2) << ptr->min << ":"
                << std::setw(2) << ptr->sec << '\r' << std::flush;
    }
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
