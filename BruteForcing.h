#ifndef BRUTEFORCING_H
#define BRUTEFORCING_H

#include "Hashing.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

void bruteForce(std::vector<std::string> &dictionary, std::map<std::string, std::string> &passwordHashes);

bool verifyHash(std::map<std::string, std::string> &passwordHashes, std::string &password);

void addDictWords(std::map<std::string, std::string> &passwordHashes, const std::string numbers, std::vector<std::string> &dictionary);

void wordOnly(std::map<std::string, std::string> &passwordHashes, std::vector<std::string> &dictionary);

#endif // BRUTEFORCING_H
