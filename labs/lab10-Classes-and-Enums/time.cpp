/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 10C

building on 10AB
implements functions interacting with Movie and Enum objects

*/

#include <iostream>
#include <string>
//class and enum definitions
class Time { 
public:
    int h;
    int m;
};

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
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

//@param mv, Movie object
void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//@param time0, time to add to
//@param min, integer minutes
Time addMinutes(Time time0, int min){
    int m = min % 60;
    int h = min / 60;
    
   
    Time added = {(time0.h + h), (time0.m + m) };
    return added;
}
//output format: "title Genre (time) [starts at s, ends by s+runtime]"
// "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]"
//@param ts, a timeslot object
printTimeSlot(TimeSlot ts){

}

int main(){
    int h{}, m{};
    std::cout << "Enter first time: ";
    std::cin >> h >> m;
    Time first{h, m};
    /*std::cout << "Enter second time: ";
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
    std::cout <<"Enter minutes to add: ";
    int m2add{};
    std::cin >> m2add;

    std::cout << "new minutes to first: " << minutesSinceMidnight(addMinutes(first, m2add)) << std::endl;
    
    //morning
    Movie movie1 = {"Minecraft Movie", COMEDY, 120};
    TimeSlot morning = {movie1, {8, 30}}
    //daytime
    TimeSlot morning = {movie1, {12, 30}}
    //evening
    TimeSlot morning = {movie1, {18, 30}}

    //day - spirited away
    Movie movie2 = {"Spirited Away", DRAMA, 100};
    TimeSlot morning2 = {movie2, {12, 30}};
    //day -
    Movie movie3 = {"AOT: the Last", ACTION, 120};
    TimeSlot morning2 = {movie2, {12, 30}};

    return 0;
}
