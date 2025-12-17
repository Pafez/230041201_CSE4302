#include <iostream>

using namespace std;

class StopWatch
{
private:
    int hours;
    int minutes;
    int seconds;
public:
    StopWatch() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    StopWatch(int hour, int minute, int second) {
        hours = hour;
        minutes = minute;
        seconds = second;
        if (hours < 0) hours = 0;
        if (minutes < 0) minutes = 0;
        if (seconds < 0) seconds = 0;
        if (seconds > 59) {
            minutes += seconds/60;
            seconds %= 60;
        }
        if (minutes > 59) {
            hours += minutes/60;
            minutes %= 60;
        }
        if (hours > 99) {
            hours %= 100;
        }
    }
    ~StopWatch() {}

    int get_hours() const {
        return hours;
    }
    int get_minutes() const {
        return minutes;
    }
    int get_seconds() const {
        return seconds;
    }

    void set_hours(int hour) {
        hours = hour;
        if (hours < 0) hours = 0;
    }
    void set_minutes(int minute) {
        minutes = minute;
        if (minutes < 0) minutes = 0;
        if (minutes > 59) {
            hours += minutes/60;
            minutes %= 60;
        }
        if (hours > 99) {
            hours %= 100;
        }
    }
    void set_seconds(int second) {
        seconds = second;
        if (seconds < 0) seconds = 0;
        if (seconds > 59) {
            minutes += seconds/60;
            seconds %= 60;
        }
        if (minutes > 59) {
            hours += minutes/60;
            minutes %= 60;
        }
        if (hours > 99) {
            hours %= 100;
        }
    }
    
    void operator++() {
        seconds++;
        if (seconds > 59) {
            minutes += seconds/60;
            seconds %= 60;
        }
        if (minutes > 59) {
            hours += minutes/60;
            minutes %= 60;
        }
        if (hours > 99) {
            hours %= 100;
        }
    }

    friend ostream operator<<(ostream out, StopWatch watch) {
        string buff;
        buff += to_string(watch.hours/10) + to_string(watch.hours%10) + ":";
        buff += to_string(watch.hours/10) + to_string(watch.hours%10) + ":";
        buff += to_string(watch.hours/10) + to_string(watch.hours%10) + ":";
        cout << buff;
    }
    friend void operator>>(istream in, StopWatch watch) {
        int hours, minutes, seconds;
        in >> hours >> minutes >> seconds;
        if (seconds > 59) {
            minutes += seconds/60;
            seconds %= 60;
        }
        if (minutes > 59) {
            hours += minutes/60;
            minutes %= 60;
        }
        if (hours > 99) {
            hours %= 100;
        }
        watch.set_hours(hours);
        watch.set_minutes(minutes);
        watch.set_seconds(seconds);
    }
};
