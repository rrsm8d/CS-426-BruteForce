#include "FileReading.h"

void readHashes(std::ifstream &in, std::map<std::string, std::string> &passwordHashes)
{
    std::string readString, lineNo; // lineNo is trash
    while(std::getline(in, readString)) {
        std::stringstream ss(readString);

        ss >> lineNo >> readString;

        // Once the password is later found, set it to whatever it is
        passwordHashes[readString] = "unknown";
    }
    return;
}

void readDictionary(std::ifstream &in, std::vector<std::string> &dictionary)
{
    std::string readString = "";
    // Stupid issue with the file being UTF-8 is giving the first line some BOM. This bool tracks if it's the first line or not
    bool isFirstLine = true;
    while(std::getline(in, readString)) {
        if (!readString.empty()) {
            std::string tempTrimmedString;
            if(isFirstLine)
            {
                isFirstLine = false;
                tempTrimmedString = readString.substr(3, readString.length() - 4);
                dictionary.push_back(tempTrimmedString);

            } else {
                // Trim the \r at the end of a line
                tempTrimmedString = readString.substr(0, readString.length() - 1);
                dictionary.push_back(tempTrimmedString);
            }
        }
    }
    return;
}

bool fillData(std::map<std::string, std::string> &passwordHashes, std::vector<std::string> &dictionary)
{
    // Attempt to open the password file
    try {
        std::ifstream in;
        in.open("passwords.txt");

        // Failure to open file
        if(!in.good()) {
            throw std::runtime_error("Failure opening file: passwords.txt.");
        }
        readHashes(in, passwordHashes);
        in.close();
    }
    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    try {
        std::ifstream in;
        in.open("dictionary.txt");

        // Failure to open file
        if(!in.good()) {
            throw std::runtime_error("Failure opening file: dictionary.txt");
        }
        readDictionary(in, dictionary);
        in.close();
    }
    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return false;
    }
    return true;
}
