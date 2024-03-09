#pragma once

#include "student.hpp"
#include "data.hpp"

#include <vector>
#include <memory>


class Db {
public:
    Db () = default;
    
    void printDb() const;

    void sortByPesel();
    void sortBySurname();

    std::unique_ptr<Student> findBySurname(const std::string& surname);
    std::unique_ptr<Student> findByPesel(const std::string& pesel);

    void addStudent();

    bool validatePesel(const std::string& pesel);
    

    

private:
    std::vector<std::unique_ptr<Student>> db_;
    std::string generateAddress();
    void generateNames(std::string& name, std::string& gender);
    std::string generatePesel(const std::string& gender);
    void numberGender(const std::string& gender);
    bool validateSurame(const std::string& name);
};

// Przechowywanie rekordów studentów o strukturze: Imię, nazwisko, adres, nr indeksu, PESEL, płeć
// Dodawanie nowych studentów
// Wyświetlanie całej bazy danych
// Wyszukiwanie po nazwisku
// Wyszukiwanie po numerze PESEL
// Sortowanie po numerze PESEL
// Sortowanie po nazwisku
// Usuwanie po numerze indeksu
// university-db
// Opcjonalne wymagania (12 XP):
// Walidacja czy numer PESEL jest poprawny Wiki - poprawność PESEL (trudne)
// Wczytywanie z pliku i zapisywanie całej bazy w pliku (trudne)