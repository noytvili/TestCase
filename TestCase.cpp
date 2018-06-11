
#include "TestCase.hpp"

TestCase::TestCase(string s1, ostream& cerr) : cerr(cerr.rdbuf()){//constructor
    s=s1;
    num_failure = counter = 0;

}

void TestCase::print(){
    int sum = counter-num_failure;
    cerr << s << ": " << num_failure << " failed, " << sum << " passed, " << counter << " total." << endl;
    cerr << "---" << endl;
}
