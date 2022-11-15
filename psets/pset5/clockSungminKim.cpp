//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "clockSungminKim.h"

void show(pClock ptr, char end){
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":"
              << std::setw(2) << ptr->min << ":"
              << std::setw(2) << ptr->sec << end << std::flush;
}

void runs(pClock ptr, char end){
    while(true){
        sleep(1);

        tick(ptr);
        show(ptr, end);
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
