#ifndef HASHING_H
#define HASHING_H

#include <iostream>
#include <openssl/sha.h>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <iomanip>
#include <cstdio>
#include <QCryptographicHash>
#include <QString>
#include <QByteArray>

using namespace std;

std::string SHA1Hash(const std::string &password);

#endif // HASHING_H
