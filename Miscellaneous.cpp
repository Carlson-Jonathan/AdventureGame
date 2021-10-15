vector<string> Miscellaneous::filterByFileType(vector<string> files, const string fileType) {
    for(short i = files.size() - 1; i > -1; i--) {
        if(!isFileType(files[i], fileType))
            files.erase(files.begin() + i);
    }
    return files;
}

vector<string> Miscellaneous::getAllFileNamesFromDirectory(const char *path) {
    struct dirent *entry;
    vector<string> files;
    DIR *directory = opendir(path);

    if (directory != NULL) {
        while ((entry = readdir(directory)) != NULL) {
            string file = entry->d_name;
                files.push_back(file);
        }
    }

    closedir(directory);
    return files;
}

vector<string> Miscellaneous::getFileTypesFromDirectory(const char *path, const string fileType) {
    vector<string> files = getAllFileNamesFromDirectory(path);
    return filterByFileType(files, fileType);
}


bool Miscellaneous::isFileType(const string fileName, const string fileType) {
    std::size_t found = fileName.find(fileType);
    return found!=std::string::npos;
}