#include "student.hpp"

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.name_ << ", " << student.surname_ << ", "
       << student.pesel_ << ", " << student.gender_ << ", " << student.address_;
    return os;
}