/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 10B

building on 10A
implements functions to add minutes to a time object

*/

#include <iostream>
#include <string>

class Time { 
public:
    int h;
    int m;
};

//@param time, a Time object
int minutesSinceMidnight(Time time){
    int minutes = time.h*60 + time.m;
    return minutes;
}
//@params earlier later, Time objects
int minutesUntil(Time earlier, Time later){
    int minutes = (later.h - earlier.h)*60 + (later.m - earlier.m);
    return minutes;
}


Time addMinutes(Time time0, int min){

    return time0;
}

int main(){
    int h{}, m{};
    /*std::cout << "Enter first time: ";
    std::cin >> h >> m;
    Time first{h, m};
    std::cout << "Enter second time: ";
    std::cin >> h >> m;
    Time second{h, m};
    //call functions to find necessary minutes
    int X = minutesSinceMidnight(first);
    int Y = minutesSinceMidnight(second);
    int Z = minutesUntil(first, second);
    std::cout << '\n';
    std::cout << "These moments of time are " << X << " and " << Y << " minutes after midnight.\n";
    std::cout << "The interval between them is " << Z << " minutes.\n";
    */
    std::cout <<"Enter minutes to add";
    int m2add{};
    std::cin >> m2add;

    std::cout << "new minutes to first: " << minutesSinceMidnight(addMinutes(first, m2add));
    return 0;
}
