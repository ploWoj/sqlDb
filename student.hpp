#pragma once

#include <iostream>
#include <string>



class Student {
public:
    Student() = default;
    Student(const std::string& name, const std::string& surname, const std::string& address, const std::string& pesel, const std::string& gender) :
        name_(name), surname_(surname), address_(address), pesel_(pesel), gender_(gender) {};
    ~Student() = default;

    // --------
    std::string getName() const { return name_; };
    std::string getSurname() const { return surname_; };
    std::string getPesel() const { return pesel_; };
    std::string getAddress() const { return address_; };
    std::string getGender() const { return gender_; };

    friend std::ostream& operator<<(std::ostream& os, const Student& student);

    // void print() { std::cout << name_ << " " << surname_ << " " << address_ << " " << pesel_ << " " << gender_ << '\n';}

private:
    std::string name_;
    std::string surname_;
    std::string address_;
    std::string pesel_;
    std::string gender_;
};




