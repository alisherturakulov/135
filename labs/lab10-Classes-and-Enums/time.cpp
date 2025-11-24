/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 10A

implements functions which take Time
objects and return the minutes since midnight
and minutes between them respectively 
*/

#include <iostream>
#include <string>

class Time { 
public:
    int h;
    int m;
};

int minutesSinceMidnight(Time time){
    return 0;
}
int minutesUntil(Time earlier, Time later){
    return 0;
}

int main(){
    int h{}, m{};
    std::cout << "Enter first time: ";
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
    return 0;
}
