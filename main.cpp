#include "db.hpp"

#include <iostream>
#include <random>



int main() {
    Db db;
    db.addStudent();
    db.addStudent();
    db.addStudent();
    db.addStudent();
    db.printDb();
    db.sortByPesel();
    db.printDb();
    db.sortBySurname();
    db.printDb();
    return 0;
}