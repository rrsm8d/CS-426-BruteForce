#ifndef FILEREADING_H
#define FILEREADING_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

void readHashes(std::ifstream &in, std::map<std::string, std::string> &passwordHashes);

void readDictionary(std::ifstream &in, std::vector<std::string> &dictionary);

bool fillData(std::map<std::string, std::string> &passwordHashes, std::vector<std::string> &dictionary);

#endif // FILEREADING_H
