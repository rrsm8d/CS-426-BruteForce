#include "Hashing.h"

std::string SHA1Hash(const std::string &password)
{
    // Every other SHA1 hashing algorithm I tried was shit. This is the simplest one I can use.
    QString tempPassword = QString::fromStdString(password); // Make a Qstring, which is just a string for QT (I don't understand why either)
    QByteArray byteArray = tempPassword.toUtf8();  // Convert QString to QByteArray
    QByteArray hash = QCryptographicHash::hash(byteArray, QCryptographicHash::Sha1);  // Calculate SHA1 hash

    return hash.toHex().toStdString();  // Turn hash into a hexadecimal QString, then convert to a std string (JANK)
}
