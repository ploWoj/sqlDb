#pragma once

#include <vector>
#include <string>
#include <utility>

const std::vector<std::string> cities { "Warszawa", "Kraków", "Łódź", "Wrocław", "Poznań", 
                                        "Gdańsk", "Szczecin", "Bydgoszcz", "Lublin", "Białystok", 
                                        "Katowice", "Gdynia", "Częstochowa", "Radom", "Sosnowiec", 
                                        "Toruń", "Kielce", "Rzeszów", "Gliwice", "Zabrze", 
                                        "Olsztyn", "Rybnik", "Opole", "Elbląg", 
                                        "Wałbrzych", "Tarnów", "Chorzów","Płock", "Piła"};

    
const std::vector<std::string> streets = {"Mickiewicza", "Sienkiewicza", "Kościuszki", "Paderewskiego", "Łokietka", "Kopernika",
                                         "Piłsudskiego", "Słowackiego", "Reymonta", "Bukowska", "Wyspiańskiego", "Grunwaldzka",
                                         "Polska", "Bugarska", "Swoboda", "Wigry", "Sosnkowskiego", "Tuwima",
                                         "Grudziacka", "Opolska" };


const std::vector<std::pair<std::string, std::string>> nameAndGender{
    // Męskie imiona
    {"Jan", "Man"}, {"Piotr", "Man"}, {"Adam", "Man"}, {"Krzysztof", "Man"}, {"Andrzej", "Man"}, {"Józef", "Man"},
    {"Marek", "Man"}, {"Tomasz", "Man"}, {"Paweł", "Man"}, {"Michał", "Man"}, {"Łukasz", "Man"}, {"Kazimierz", "Man"},
    {"Ryszard", "Man"}, {"Stanisław", "Man"}, {"Wojciech", "Man"}, {"Jerzy", "Man"}, {"Dariusz", "Man"}, {"Henryk", "Man"},
    {"Robert", "Man"}, {"Mariusz", "Man"}, {"Mateusz", "Man"}, {"Zbigniew", "Man"}, {"Edward", "Man"}, {"Tadeusz", "Man"},
    {"Kamil", "Man"}, {"Roman", "Man"}, {"Artur", "Man"}, {"Władysław", "Man"}, {"Arkadiusz", "Man"}, {"Bartłomiej", "Man"},
    // Żeńskie imiona
    {"Anna", "Woman"}, {"Maria", "Woman"}, {"Katarzyna", "Woman"}, {"Małgorzata", "Woman"}, {"Agnieszka", "Woman"}, {"Barbara", "Woman"},
    {"Ewa", "Woman"}, {"Krystyna", "Woman"}, {"Zofia", "Woman"}, {"Elżbieta", "Woman"}, {"Joanna", "Woman"}, {"Magdalena", "Woman"},
    {"Halina", "Woman"}, {"Teresa", "Woman"}, {"Danuta", "Woman"}, {"Irena", "Woman"}, {"Jolanta", "Woman"}, {"Beata", "Woman"},
    {"Marianna", "Woman"}, {"Janina", "Woman"}, {"Helena", "Woman"}, {"Aleksandra", "Woman"}, {"Monika", "Woman"}, {"Dominika", "Woman"},
    {"Alicja", "Woman"}, {"Wanda", "Woman"}, {"Iwona", "Woman"}, {"Kinga", "Woman"}, {"Patrycja", "Woman"}, {"Karolina", "Woman"}
};