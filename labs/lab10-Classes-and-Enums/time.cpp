/*
Author: Alisherjon Turakulov
Course: CS 135
Instructor: Tong Yi
Assignment: Lab 10D

building on 10ABC
implements functions interacting with Movie and Enum objects and timeslots

*/

#include <iostream>
#include <string>
using namespace std;
//class and enum definitions
class Time { 
public:
    int h;
    int m;
};

void printTime(Time time) {
    std::cout << time.h << ":" << time.m;
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
    int extra = 0;
    if(time0.m+ m > 60 ){
        extra = time0.m+m -60;
        h++;
    }
   
    Time added = {(time0.h + h), (time0.m + extra) };
    return added;
}
//output format: "title Genre (time) [starts at s, ends by s+runtime]"
// "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]"
//@param ts, a timeslot object
void printTimeSlot(TimeSlot ts){
    printMovie(ts.movie);
    std::cout << " [starts at ";
    printTime(ts.startTime);
    std::cout << ", ends by ";
    printTime(addMinutes(ts.startTime, ts.movie.duration));
    std::cout << "]\n";
}

//return a new timeslot for nextMovie scheduled at the end time of
//the timeslot ts
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    Time nextTime = addMinutes(ts.startTime, ts.movie.duration);
    TimeSlot next = {nextMovie, nextTime};
    return next;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    int interval_start;
    bool over = false;
    if(minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)){
        interval_start = minutesUntil(ts1.startTime, ts2.startTime);
        
        if(minutesSinceMidnight(ts2.startTime) < (minutesSinceMidnight(ts1.startTime)+ts1.movie.duration) ){
            over = true;
        }
    }else{
        interval_start = minutesUntil(ts2.startTime, ts1.startTime);
        if(minutesSinceMidnight(ts1.startTime) < (minutesSinceMidnight(ts2.startTime)+ts2.movie.duration)  ){
            over = true;
        }
    }
    return over;
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
    
    std::cout <<"Enter minutes to add: ";
    int m2add{};
    std::cin >> m2add;

    std::cout << "new minutes to first: " << minutesSinceMidnight(addMinutes(first, m2add)) << std::endl;
    */
    //morning
    Movie movie1 = {"Minecraft Movie", COMEDY, 120};
    TimeSlot morning = {movie1, {8, 30}};
    printTimeSlot(morning);
    //daytime
    TimeSlot morning2 = {movie1, {12, 30}};
    printTimeSlot(morning2);
    //evening
    TimeSlot morning3 = {movie1, {18, 30}};
    printTimeSlot(morning3);

    //day - spirited away
    Movie movie2 = {"Spirited Away", DRAMA, 90};
    TimeSlot day2 = {movie2, {10, 0}};
    printTimeSlot(day2);
    //day -
    Movie movie3 = {"AOT: the Last", ACTION, 120};
    TimeSlot day3 = {movie3, {11, 30}};
    printTimeSlot(day3);

    std::cout <<timeOverlap(day2, day3) << std::endl;
    day3.startTime.m = 29;
   std::cout << timeOverlap(day3, day2) << std::endl;
    


    return 0;
}
