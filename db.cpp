#include "db.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>

using const int FIRSTLETTER = 0;

void Db::printDb() const {
    for (const auto& el : db_) {
        std::cout << el << '\n';
    }
}

bool Db::validateName(const std::string name) {
    return isupper(name[FIRSTLETTER]) && std::all_of(name.cbegin() + 1, name.cend(), [](char c) { return islower(c);});
}

bool Db::validatePesel(const std::string& pesel) {
    if (pesel.length() != 11)
        return false;

    int weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        sum += (pesel[i] - '0') * weights[i];
    }

    int checksum = (10 - (sum % 10)) % 10;

    return (checksum == pesel[10] - '0');
}

std::string generateAddress() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int houseNumber = dis(gen);

    auto city = cities[std::rand() % cities.size()];
    auto street = streets[std::rand() % streets.size()];

    return city + " " + street " " + houseNumber;
}

void Db::addStudent() {
    std::string name{};
    std::string surname{};
    std::string pesel{};
    std::string address{};
    Gender gender{};

    // napisz funkcje sprawdzajace 

    do
    {
        std::cout << "Podaj imie \n";
        std::getline(std::cin, name);
    } while (validateName(name));
    
    do
    {
        std::cout << "Podaj nazwisko \n";
        std::getline(std::cin, name);
    } while (validateName(name));

    do
    {
        std::cout << "Podaj pesel \n";
        std::getline(std::cin, name);
    } while (validatePesel(pesel));
    
}