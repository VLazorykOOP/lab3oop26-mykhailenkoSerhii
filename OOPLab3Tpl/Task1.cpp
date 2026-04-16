#include "Task1.h"
#include <iostream>

class Time
{
    public:
    int hour;
    int minute;
    int second;

    Time(int hour, int minute, int second)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }

    Time(int hour, int minute)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = 0;
    }

    int getHour()
    {
        return hour;
    }

    int getMinute()
    {
        return minute;
    }

    int getSecond()
    {
        return second;
    }

    void setHour(int hr)
    {
        if (hr >= 24)
            hr = 0;

        this->hour = hr;
    }

    void setMinute(int min)
    {
        if (min >= 60)
        {
            this->hour += 1;
            setMinute(min-60);
            return;
        }
        this->minute = min;
    }

    void setSecond(int sec)
    {
        if (sec >= 60)
        {
            this->minute += 1;
            setSecond(sec-60);
            return;
        }
        this->second = sec;
    }

    void printTime24H()
    {
        std::cout << hour << " hours " << minute << " minutes " << second << " seconds" << std::endl;
    }

    void printTime12H()
    {
        std::string time = " a.m ";
        if (hour >= 12)
            time = " p.m. ";

        std::cout << hour % 12 << time << minute << " minutes " << second << " seconds" <<std::endl;
    }
};

void test()
{
    Time time(10, 0, 0);
    Time otherTime(8, 0);

    std::cout << time.getHour() << ":" << time.getMinute() << ":" << time.getSecond() << std::endl;
    otherTime.setSecond(150);

    time.setHour(11);
    time.setMinute(60);
    time.setSecond(180);

    otherTime.printTime24H();
    time.printTime12H();
}