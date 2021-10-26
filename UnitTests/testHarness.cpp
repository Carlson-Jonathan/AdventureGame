#ifndef TESTHARNESS_CPP
#define TESTHARNESS_CPP

#include <iostream>
#include <map>
#include "spriteSchematic_test.h"
using namespace std;

void printResults(const map<string, bool> & allResults) {
    cout << "################## Unit Test Results: ##################" << endl;
    for(auto i : allResults) {
        if(i.second)
            cout << "Passed: ";
        else
            cout << "FAILED: ";
        cout << i.first << endl;
    }
}

int main() {

    map<string, bool> allResults;
    SpriteSchematic_Test spriteSchematic_test;

    allResults.insert(std::pair<string, bool> (
        "SpriteSchematic_Test::detectKeyword_test()", 
        spriteSchematic_test.detectKeyword_Test()
    ));

    printResults(allResults);

    return 0;
}

#endif // TESTHARNESS_CPP