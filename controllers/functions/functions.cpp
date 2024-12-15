#include <string>
#include <algorithm>
#include <cctype>
#include <random>
#include "functions.h"

std::string toLowerCase(const std::string &input) {
    std::string result = input;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return result;
}

std::string generateRandomId() {
    size_t length = 15;
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distribution(0, characters.size() - 1);

    std::string randomId;
    for (size_t i = 0; i < length; ++i) {
        randomId += characters[distribution(generator)];
    }

    return randomId;
}
