#include "FileReading.h"
#include "BruteForcing.h"
#include "Hashing.h"

void printMap(const std::map<std::string, std::string>& myMap) {
    for (const auto& pair : myMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

int main()
{
    // Hashed passwords are the key, if already found set to true
    std::map<std::string, std::string> passwordHashes;
    // Hold the dictionary in a vector
    std::vector<std::string> dictionary;

    if(!fillData(passwordHashes, dictionary))
    {
        std::cerr << "Exiting program early due to file reading errors" << std::endl;
        return 0;
    }

    //std::cout << "Hash of 123456:" << SHA1Hash("123456") << std::endl;

    bruteForce(dictionary, passwordHashes);

    printMap(passwordHashes);

    return 0;
}
