#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H

#include <iostream>
#include <dirent.h>
#include <vector>
using namespace std;

// A library for miscellaneous, non-cohesive functions that do not need initialization.

class Miscellaneous {
public:

    static vector<string> filterByFileType(vector<string> files, const string fileType);
    static vector<string> getFileTypesFromDirectory(const char *path, const string fileType);
    static vector<string> getAllFileNamesFromDirectory(const char *path);
    static bool           isFileType(const string fileName, const string fileType);
};

#endif // MISCELLANEOUS_H