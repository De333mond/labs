#include <iostream>

using namespace std;

struct time {

    int seconds, minutes, hours;
    long getTotalSecs(){
        return hours*3600 + minutes*60 + seconds; 
    }

    void setfs(int s){
        seconds = s % 60;
        minutes = (s / 60) % 60;
        hours = s / 3600; 
    }
};

int main() {

    time t;

    t.setfs(73964);

    cout << ' ' << endl;

return 0;
}