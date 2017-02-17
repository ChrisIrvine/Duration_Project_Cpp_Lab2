/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ruw12gbu
 *
 * Created on 17 February 2017, 16:01
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Duration
{
private:
    int hours;
    int minutes;
    int seconds; 

public: 
    Duration(int inputSeconds)
    {
        minutes = (inputSeconds / 60) % 60;
        hours = inputSeconds % 3600;
        seconds = inputSeconds % 60;
    }

    Duration(int inputHours, int inputMinutes, int inputSeconds)
    {
        hours = inputHours;
        minutes = inputMinutes;
        seconds = inputSeconds;
    }

    int getHours() const
    {
            return hours;
    }

    int getMinutes() const
    {
            return minutes;
    }

    int getSeconds() const
    {
            return seconds;
    }

    void printDuration()
    {
        cout << "Duration: " << setfill('0') << hours << setw(2) 
                << ":" << minutes << ":" << seconds;
    }

    Duration addDurations(Duration dur1, Duration dur2)
    {
        /*Add and convert the hours and minutes into seconds*/
        hours = (dur1.getHours() + dur2.getHours()) * 3600;
        minutes = (dur1.getMinutes() + dur2.getMinutes()) * 60;
        seconds = dur1.getSeconds() + dur2.getSeconds();

        /*Create a new Duration object*/
        return Duration(hours + minutes + seconds);
    }

    Duration addSeconds(int addSeconds)
    {
        /*Add additional seconds to the Duration's seconds*/
        seconds = seconds + addSeconds;

        /*Re-balance the Duration object*/
        minutes = (seconds / 60) % 60;
        hours = seconds % 3600;
        seconds = seconds % 60;
    }

    int convertSeconds(Duration duration)
    {
        int convertS = (duration.getHours() * 3600) 
                + (duration.getMinutes() * 60) 
                + duration.getSeconds();

        return convertS;
    }
};


int main()
{
    using namespace std; 
    /*Test the first constructor*/
    int testSeconds = 5075; /*this should construct to 1:24:35*/
    Duration duration1 = Duration(testSeconds);

    std::cout << "Input: 5075 seconds. Expected Result 1:24:35\n"; duration1.printDuration();
}
