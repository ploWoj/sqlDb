#pragma once

#include "student.hpp"

#include <vector>
#include <memory>

constexpr std::vector<std::string> cities {"Warszawa", "Kraków", "Łódź", "Wrocław", "Poznań", "Gdańsk", "Szczecin", "Bydgoszcz",
                                              "Lublin", "Białystok", "Katowice", "Gdynia", "Częstochowa", "Radom", "Sosnowiec",
                                              "Toruń", "Kielce", "Rzeszów", "Gliwice", "Zabrze", "Olsztyn", "Bielsko-Biała",
                                              "Bytom", "Zielona Góra", "Rybnik", "Tychy", "Gorzów Wielkopolski", "Dąbrowa Górnicza",
                                              "Elbląg", "Płock"};

    
constexpr std::vector<std::string> streets = {"Mickiewicza", "Sienkiewicza", "Kościuszki", "Paderewskiego", "Łokietka", "Kopernika",
                                         "Piłsudskiego", "Słowackiego", "Reymonta", "Jana Pawła II", "Wyspiańskiego", "3 Maja"};


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
    bool validateName(const std::string& name);

    std::string generateAddress();

private:
    std::vector<std::unique_ptr<Student>> db_;
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