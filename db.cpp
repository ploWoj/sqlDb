#include "db.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <random>

// using const int FIRSTLETTER = 0;

void Db::printDb() const {
std::cout << "--------------- BAZA STUDENTOW----------------\n";    
for (const auto& el : db_) {
        std::cout << *el << '\n';
    }
}

bool Db::validateSurame(const std::string& surname) {
    if (surname.empty() || !isupper(surname[0])) {
        return false;
    }
    
    return std::all_of(surname.cbegin() + 1, surname.cend(), [](char c) { return islower(c);});
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

std::string Db::generateAddress() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    int houseNumber = dis(gen);

    std::uniform_int_distribution<> cityDis(0, cities.size() - 1);
    std::uniform_int_distribution<> streetsDis(0, streets.size() - 1);

    auto city = cityDis(gen);
    auto street = streetsDis(gen);

    return cities[city] + " " + streets[street] + " " + std::to_string(houseNumber);
}

void Db::generateNames(std::string& name, std::string& gender) {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, nameAndGender.size() - 1);
    auto randomName = dis(gen);

    name = nameAndGender[randomName].first;
    gender = nameAndGender[randomName].second;
}


std::string Db::generatePesel(const std::string& gender) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> year_dist(1900, 2005); 
    std::uniform_int_distribution<int> month_dist(1, 12);
    std::uniform_int_distribution<int> day_dist(1, 31); 
    std::uniform_int_distribution<int> id_dist(100000, 999999); 
    std::uniform_int_distribution<int> control_dist(0, 9); 

    int year = year_dist(gen);
    int month = month_dist(gen);
    int day = day_dist(gen);
    while (month == 2 && day > 29) {
        day = day_dist(gen);
    }
    int id = id_dist(gen);
    int control;    
    if (gender == "man") {
        control = 1 + (id % 5) * 2;
    } else {
        control = 0 + (id % 5) * 2;
    }
   
    std::string pesel = std::to_string(year % 100); 
    
    if (month < 10) {
        pesel += "0"; 
    }
    pesel += std::to_string(month); 
    if (day < 10) {
        pesel += "0";
    }
    pesel += std::to_string(day); 
    pesel += std::to_string(id); 
    pesel += std::to_string(control); 

    return pesel;
}


void Db::addStudent() {
    std::string name{};
    std::string surname{};
    std::string pesel{};
    std::string address{};
    std::string gender{};
    
    generateNames(name, gender);
    address = generateAddress();
    int i =0;
    do
    {
        if (i > 1) {
            std::cout << "Podales zle nazwisko!\n";
        }
        std::cout << "Podaj nazwisko \n";
        std::getline(std::cin, surname);
        ++i;
    } while (!validateSurame(surname));
    
    pesel = generatePesel(gender);

    while(validatePesel(pesel)) {
        std::cout << "Pesel is wrong put it agian!\n";
        std::getline(std::cin, pesel);
    }

    auto student = std::make_unique<Student>(name, surname, address, pesel, gender);

    db_.push_back(std::move(student));    
}

void Db::sortByPesel() {
    std::sort(db_.begin(), db_.end(),[] (const auto& lhs, const auto& rhs) {
            return lhs->getPesel() < rhs->getPesel();
    });
}

void Db::sortBySurname() {
    std::sort(db_.begin(), db_.end(), [](const auto& lhs, const auto& rhs) {
        return lhs->getSurname() < rhs->getSurname();
    });
}