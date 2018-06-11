#pragma once
#include<string>
#include <sstream>
#include <iostream>
using namespace std;

class TestCase{
    private:
    string s; 
    int num_failure;  //number of fail tests
    int counter; //number of all test
    ostream cerr;
    
    public:
    TestCase(string s, ostream& cerr);
    void print(); //  מדפיסה את תוצאות הבדיקה - כמה בדיקות עברו ונכשלו.

    template <typename T> TestCase& check_equal(T a, T b){
        counter++;
        if(a != b){
            cerr << s << ": Failure in test #" <<  counter << ": " << a << " should equal " << b << "!" << endl;
            num_failure++;
        }
        return *this;
    }
    
    template <typename T> TestCase& check_different(T a, T b){
        counter++;
        if(a == b){
            cerr << s << ": Failure in test #" <<  counter << ": " << a << " should not equal " << b << "!" << endl;
            num_failure++;
        }
        return *this;
    }

    template <typename T> TestCase& check_output(T a, string s1){
        counter++;
        ostringstream new_os;
        new_os << a;
        if(new_os.str() != s1){
          cerr << s << ": Failure in test #" << counter << ": string value should be " << a << " but is " << new_os.str() << endl;
          num_failure++;
        }
        return *this;    
    }
    
    template <typename T,typename function> TestCase& check_function(function f ,T a, int b){
        counter++;
        int ans = f(a);
        if(ans != b){
           cerr << s << ": Failure in test #" << counter << ": Function should return " << b << " but returned " << ans << "!" << endl;
            num_failure++;
        return *this;
    }
};
