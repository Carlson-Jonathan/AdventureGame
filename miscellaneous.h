#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include <iostream>
#include <dirent.h>     // directory
#include <vector>
#include <stdlib.h>     // srand, rand 
#include <time.h>       
using namespace std;

// A library for miscellaneous, non-cohesive functions that do not need initialization.

class Miscellaneous {
public:
    static vector<string> filterByFileType(vector<string> files, const string fileType);
    static unsigned short generateRandomNumber(const short unsigned max);
    static vector<string> getFileTypesFromDirectory(const char *path, const string fileType);
    static vector<string> getAllFileNamesFromDirectory(const char *path);
    static bool           isFileType(const string fileName, const string fileType);
    static float          convertStringToFloat(string number);
};

#endif // MISCELLANEOUS_H