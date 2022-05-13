#include <iostream>
#include <math.h>
#include <iomanip>
#include <sstream>
using namespace std;

class money
{
private:
    long double value;
    string charset = "0123456789";
    bool isFrac = false;
    int fracCount = 0; 

public:
    money() {
        value = 0;
    }
    
    void mstold(string s){
        
        for (int i = 0; i < s.length(); i++)
        {
            if (charset.find(s[i]) != -1){

                value *= 10;
                value += (int)s[i]-48;
                if(isFrac)
                    fracCount++;
            }
            else if (s[i] == '.'){
                isFrac = true;
            }
        }
        
        value = value / pow(10, fracCount);
    }

    long double getValue() {
        return value;
    }

    void setValue(long double v){
        value = v;
    }

    string getStr(){
        const int size = 100; 
        string result;
        stringstream ss;
        
        ss << setprecision(10) << setiosflags(ios_base::fixed) << value;
        
        string t = ss.str();
        int dotpos = t.length();
        
        while ((t[dotpos] != '.') && (dotpos > 0))
            dotpos--;
        
        if (dotpos == 0){
            dotpos = t.length();
        }
        
        int counter = 0;

        for (int i = t.length() - 1; i >= 0; i--)
        {
            if(i < dotpos){
                if ((counter % 3 == 0) && (counter != 0))
                    result = ',' + result;
                counter++;
            }

            result = t[i] + result;
        }
        
        return '$' + result;
    }
};

int main() {

    money m = money();
    long double ld;
    cin >> ld;
    m.setValue(ld);

    cout << m.getStr() << endl;   

return 0;
}