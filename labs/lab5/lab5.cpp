#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x1,y1,x2,y2;

    cout << "Enter 1st point coordinates: ";
    cin >> x1 >> y1; 
    cout << endl << "Enter 2nd point coordinates: ";
    cin >> x2 >> y2;

    cout << endl << "Length : " << sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) << endl;


    return 0;
}
