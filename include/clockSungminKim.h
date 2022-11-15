//On my honor, I pledge that I have neither received nor provided improper assistance in the completion of this assignment.
//21900112 김성민

#ifndef CLOCKSUNGMINKIM_H
#define CLOCKSUNGMINKIM_H

struct Clock{
    int hr, min, sec;
};

using pClock = Clock*;

void tick(pClock clk);
void show(pClock clk, char end = '\n');
void runs(pClock clk, char end = '\n');

#endif