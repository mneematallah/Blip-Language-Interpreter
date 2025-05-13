#include <iostream>
#include <map>
//#include "VectorParse_main.cpp"
//#include "Input.cpp"
#include "Project8.h"
#include "Parse.h"

using namespace std;

int main() {
    cout << "Test 1" << endl;
    set_input("test1.blip");
    run();
    cout << endl;
    cout << "Test 2" << endl;
    set_input("test2.blip");
    run();
    cout << endl;
    cout << "Test 3" << endl;
    set_input("test3.blip");
    run();
    cout << endl;
    cout << "Test 4" << endl;
    set_input("test4.blip");
    run();
    cout << endl;
}
