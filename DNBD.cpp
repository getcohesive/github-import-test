#include<iostream>
using namespace std;

class Time{
    private:
        int hr, min, sec;

    public:
        void show_time();
        void set_time(int, int, int);
        void normalize();
        Time operator+(Time);
};

void Time :: set_time(int h, int m, int s){
    /* Takes in input of hour, minutes and seconds
    from the user and assigns to the variables
    hr, min, sec respectively*/
    hr  = h;
    min = m;
    sec = s;
    normalize();
}

void Time :: show_time(){
    /* Outputs the normalized time on screen */
    normalize();
    cout<<hr<<":"<<min<<":"<<sec<<endl;
}

void Time :: normalize(){
    /* Normalizes the time */
    int temp = 0;
    min += sec/60;
    sec = sec % 60;
    hr += min/60;
    min = min % 60;
}

Time Time :: operator+(Time t2){
    /* Performs the addition of two different Time 
    data srtuctures */
    Time t;
    t.hr = hr + t2.hr;
    t.min = min + t2.min;
    t.sec = sec + t2.sec;
    t.normalize();

    return t;
}

int main(){
    Time t1;
    t1.set_time(4, 100, 100);
    t1.show_time();
    Time t2;
    t2.set_time(1, 20, 6);
    Time t3 = t1+t2;
    t3.show_time();
}