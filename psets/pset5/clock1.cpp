#include <iostream>
#include <iomanip>

struct Clock{
    int hr, min, sec;
};

void tick(Clock *ptr);
void show(Clock *ptr);

int main(void){
    Clock clock ={14, 38, 56};

    for(int i=0;i<6;i++){
        tick(&clock);
        show(&clock);
    }
    return 0;
}

void tick(Clock *ptr){
    ptr->sec++;
    if(ptr->sec>60){
        ptr->min++;
        ptr->sec-=60;
    }
    if(ptr->min>60){
        ptr->hr++;
        ptr->min-=60;
    }
}

void show(Clock *ptr){
    std::cout.fill('0');
    std::cout << std::setw(2) << ptr->hr << ":"
              << std::setw(2) << ptr->min << ":"
              << std::setw(2) << ptr->sec << std::endl;
}