#include <iostream>
#include <cmath>
using namespace std;

class Time {
public:
    // Constructors and destructor
    Time(int = 0, int = 0);
    Time(const Time&);
    ~Time();

    // Set functions
    void setTime(int, int);
    void setHour(int);
    void setMinute(int);

    // Get functions
    int getHour() const;
    int getMinute() const;


    void print12() const;
    void print24() const;

    // Operators
    friend ostream& operator<<(ostream& out, const Time& ob);
    friend istream& operator>>(istream& in, Time& ob);
    bool operator==(const Time&) const;
    bool operator!=(const Time&) const;
    bool operator>(const Time&) const;
    bool operator<(const Time&) const;
    Time& operator++(int);
    Time& operator++();


    int minuteNumber() const;
    int secondNumber() const;

private:
    int hour;
    int minute;
};

Time::Time(int h, int m) : hour(h >= 0 && h < 24 ? h : 0), minute(m >= 0 && m < 60 ? m : 0) {}
Time::Time(const Time& ob) : hour(ob.hour), minute(ob.minute) {}

void Time::setHour(int h) { hour = (h >= 0 && h < 24) ? h : 0; }
void Time::setMinute(int m) { minute = (m >= 0 && m < 60) ? m : 0; }
int Time::getHour() const { return hour; }
int Time::getMinute() const { return minute; }

void Time::print12() const {
    int h = hour;
    string suffix = "AM";
    if (h >= 12) {
        suffix = "PM";
        if (h > 12)
            h -= 12;
    }
    cout << "Time: " << h << ":" << (minute < 10 ? "0" : "") << minute << " " << suffix;
}

void Time::print24() const {
    cout << "Time: " << hour << ":" << (minute < 10 ? "0" : "") << minute;
}

ostream& operator<<(ostream& out, const Time& ob) {
    out << "Time: " << ob.hour << ":" << (ob.minute < 10 ? "0" : "") << ob.minute;
    return out;
}

istream& operator>>(istream& in, Time& ob) {
    in >> ob.hour >> ob.minute;
    return in;
}

bool Time::operator==(const Time& ob) const {
    return hour == ob.hour && minute == ob.minute;
}

bool Time::operator!=(const Time& ob) const {
    return !(*this == ob);
}

bool Time::operator>(const Time& ob) const {
    if (hour > ob.hour)
        return true;
    else if (hour == ob.hour && minute > ob.minute)
        return true;
    return false;
}

bool Time::operator<(const Time& ob) const {
    return !(*this > ob || *this == ob);
}

Time& Time::operator++() {
    minute++;
    if (minute >= 60) {
        minute = 0;
        hour++;
        if (hour >= 24)
            hour = 0;
    }
    return *this;
}

Time& Time::operator++(int) {
    Time temp = *this;
    ++(*this);
    return temp;
}

int Time::minuteNumber() const {
    return hour * 60 + minute;
}

int Time::secondNumber() const {
    return hour * 3600 + minute * 60;
}

class TimeS : public Time {
private:
    int second;

public:
    TimeS(int h = 0, int m = 0, int s = 0);
    void setSecond(int);
    int getSecond() const {
        return second;
    }


    void print12() const;
    void print24() const;
};

TimeS::TimeS(int h, int m, int s) : Time(h, m), second(s >= 0 && s < 60 ? s : 0) {}

void TimeS::setSecond(int s) { second = (s >= 0 && s < 60) ? s : 0; }

void TimeS::print12() const {
    Time::print12();
    cout << ":" << (second < 10 ? "0" : "") << second;
}

void TimeS::print24() const {
    Time::print24();
    cout << ":" << (second < 10 ? "0" : "") << second;
}

int main() {
    Time timeArr[100];
    TimeS timeSArr[100];
    // Test Time class
    Time ob1(12, 30);
    cout << "Time in 12-hour format: ";
    ob1.print12();
    cout << endl;
    cout << "Time in 24-hour format: ";
    ob1.print24();
    cout << endl;
    cout << "Minutes since midnight: " << ob1.minuteNumber() << endl;
    cout << "Seconds since midnight: " << ob1.secondNumber() << endl;
    cout << endl;
    // Test TimeS class
    TimeS ob2(14, 45, 30);
    cout << "TimeS in 12-hour format: ";
    ob2.print12();
    cout << endl;
    cout << "TimeS in 24-hour format: ";
    ob2.print24();
    cout << endl;
    cout << "Minutes since midnight: " << ob2.minuteNumber() << endl;
    cout << "Seconds since midnight: " << ob2.secondNumber() << endl;
    cout << endl;

    // Test comparison operators
    Time t1(10, 30);
    Time t2(12, 45);
    cout << "t1 == t2: " << (t1 == t2 ? "true" : "false") << endl;
    cout << "t1 != t2: " << (t1 != t2 ? "true" : "false") << endl;
    cout << "t1 > t2: " << (t1 > t2 ? "true" : "false") << endl;
    cout << "t1 < t2: " << (t1 < t2 ? "true" : "false") << endl;
    cout << endl;

    // Test increment operators
    Time t3(23, 59);
    cout << "Before increment: " << t3 << endl;
    t3++;
    cout << "After postfix increment: " << t3 << endl;
    ++t3;
    cout << "After prefix increment: " << t3 << endl;
    //latest moment
    TimeS latestTimeS;
    for (int i = 0; i < 100; ++i) {
        if (timeSArr[i] > latestTimeS) {
            latestTimeS = timeSArr[i];
        }
    }

    cout << "Latest moment in TimeS objects: " << latestTimeS << endl;

    return 0;
}