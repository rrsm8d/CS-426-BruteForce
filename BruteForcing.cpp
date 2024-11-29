#include "BruteForcing.h"

void bruteForce(std::vector<std::string> &dictionary, std::map<std::string, std::string> &passwordHashes)
{
    // Passwords could have up to 10 digits, with some 0's prepended to numbers lower than 10 digits
    std::string passwordAttempt = "";
    for(long long int i = 0; i < 9999999999; i++)
    {
        passwordAttempt = std::to_string(i);
        // Some digits may have the form of 01, 002, etc...
        // this will try combos of it
        if(i < 10000000000)
        {
            // First, check with the simple digit
            verifyHash(passwordHashes, passwordAttempt);
            // Only want to try numerical brute forcing for 3 digits or less
            // Otherwise run time will take too long without rewriting to parallelize across multiple cores
            if(passwordAttempt.length() <= 3) {
                addDictWords(passwordHashes, passwordAttempt, dictionary);
            }
            // Try using this digit with prepended 0's now
            for(int j = passwordAttempt.length(); j < 10; j++)
            {
                passwordAttempt.insert(passwordAttempt.begin(), '0');
                verifyHash(passwordHashes, passwordAttempt);
                if(passwordAttempt.length() <= 3) {
                    addDictWords(passwordHashes, passwordAttempt, dictionary);
                }
            }
        }
    }
    std::cout << "Brute forcing should be finished!" << std::endl;
}


void addDictWords(std::map<std::string, std::string> &passwordHashes, std::string numbers, std::vector<std::string> &dictionary)
{
    std::string newPassword = "";
    std::string wordCombo = "";
    // Keep track if it's the first brute force attempt, so we don't need to repeat word-only checks
    bool isFirstBruteForce;
    isFirstBruteForce = (numbers == "0");

    // One word in the dictionary
    for (size_t i = 0; i < dictionary.size(); ++i) {
        wordCombo = dictionary[i];
        if(isFirstBruteForce)
            verifyHash(passwordHashes, wordCombo);

        // Now try a word + digit
        newPassword = wordCombo + numbers;
        verifyHash(passwordHashes, newPassword);

        // And then a word + word + digit
        for (size_t j = 0; j < dictionary.size(); ++j) {
            if (j == i) continue;
            wordCombo = dictionary[i] + dictionary[j];
            if(isFirstBruteForce)
                verifyHash(passwordHashes, wordCombo);

            newPassword = wordCombo + numbers;
            verifyHash(passwordHashes, newPassword);

            // And finally, a word + word + word + digit
            // ONLY IF digit length is small, otherwise this will take too long
            if(numbers.size() = 1)
            {
                for (size_t k = 0; k < dictionary.size(); ++k) {
                    if (k == i || k == j) continue;
                    wordCombo = dictionary[i] + dictionary[j] + dictionary[k];
                    if(isFirstBruteForce)
                        verifyHash(passwordHashes, wordCombo);

                    newPassword = wordCombo + numbers;
                    verifyHash(passwordHashes, newPassword);
                }
            }
        }
        wordCombo = "";
    }
}


void wordOnly(std::map<std::string, std::string> &passwordHashes, std::vector<std::string> &dictionary)
{
    // Was for testing purposes to guage speed. Not needed anymore
    std::string wordCombo = "";
    for (size_t i = 0; i < dictionary.size(); ++i) {
        wordCombo = dictionary[i];
        verifyHash(passwordHashes, wordCombo);
        for (size_t j = 0; j < dictionary.size(); ++j) {
            if (j == i) continue;
            wordCombo = dictionary[i] + dictionary[j];
            verifyHash(passwordHashes, wordCombo);
            for (size_t k = 0; k < dictionary.size(); ++k) {
                if (k == i || k == j) continue;
                wordCombo = dictionary[i] + dictionary[j] + dictionary[k];
                verifyHash(passwordHashes, wordCombo);
            }
        }
    }
}

bool verifyHash(std::map<std::string, std::string> &passwordHashes, std::string &password)
{
    // First get the SHA1 hash of the password
    std::string hashedPassword = SHA1Hash(password);
    // Then check if it's in the hashmap
    if(passwordHashes.find(hashedPassword) == passwordHashes.end()) // If not found
    {
        return false;
    } else // If found
    {
        std::cout << "Found a valid password! It is: " << password << std::endl;
        passwordHashes[hashedPassword] = password;
        return true;
    }
}
