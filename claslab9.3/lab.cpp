#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>

// Структура, що містить інформацію про Зодіак
struct Zodiac {
    std::string lastName;
    std::string firstName;
    std::string zodiacSign;
    int birthDate[3];
};

// Введення даних про Зодіак у масив
void inputZodiacData(Zodiac* zodiacArray, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "Введіть дані для особи " << i + 1 << ":\n";
        std::cout << "Прізвище: ";
        std::cin >> zodiacArray[i].lastName;
        std::cout << "Ім'я: ";
        std::cin >> zodiacArray[i].firstName;
        std::cout << "Знак Зодіаку: ";
        std::cin >> zodiacArray[i].zodiacSign;
        std::cout << "Дата народження (день місяць рік): ";
        for (int j = 0; j < 3; ++j) {
            std::cin >> zodiacArray[i].birthDate[j];
        }
    }
}

// Сортування масиву Зодіаку за прізвищем
void sortZodiacArray(Zodiac* zodiacArray, int size) {
    std::sort(zodiacArray, zodiacArray + size, [](const Zodiac& a, const Zodiac& b) {
        return a.lastName < b.lastName;
        });
}

// Виведення осіб з певним знаком Зодіаку
void printPeopleByZodiac(Zodiac* zodiacArray, int size, const std::string& targetZodiacSign) {
    bool found = false;
    std::cout << "Ось особи із знаком Зодіаку " << targetZodiacSign << ":\n";
    for (int i = 0; i < size; ++i) {
        if (zodiacArray[i].zodiacSign == targetZodiacSign) {
            found = true;
            std::cout << zodiacArray[i].lastName << " " << zodiacArray[i].firstName << "\n";
        }
    }

    if (!found) {
        std::cout << "Осіб з вказаним знаком Зодіаку не знайдено.\n";
    }
}

// Збереження масиву Зодіаку у файл
void saveZodiacArrayToFile(Zodiac* zodiacArray, int size, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int i = 0; i < size; ++i) {
            outFile << zodiacArray[i].lastName << " "
                << zodiacArray[i].firstName << " "
                << zodiacArray[i].zodiacSign << " "
                << zodiacArray[i].birthDate[0] << " "
                << zodiacArray[i].birthDate[1] << " "
                << zodiacArray[i].birthDate[2] << "\n";
        }
        std::cout << "Дані збережено у файл: " << filename << "\n";
        outFile.close();
    }
    else {
        std::cerr << "Не вдалося відкрити файл для збереження даних.\n";
    }
}

// Завантаження масиву Зодіаку з файлу
void loadZodiacArrayFromFile(Zodiac*& zodiacArray, int& size, const std::string& filename) {
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        inFile >> size;
        zodiacArray = new Zodiac[size];
        for (int i = 0; i < size; ++i) {
            inFile >> zodiacArray[i].lastName
                >> zodiacArray[i].firstName
                >> zodiacArray[i].zodiacSign
                >> zodiacArray[i].birthDate[0]
                >> zodiacArray[i].birthDate[1]
                >> zodiacArray[i].birthDate[2];
        }
        std::cout << "Дані завантажено з файлу: " << filename << "\n";
        inFile.close();
    }
    else {
        std::cerr << "Не вдалося відкрити файл для завантаження даних.\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    std::cout << "Введіть кількість осіб: ";
    std::cin >> size;

    Zodiac* zodiacArray = new Zodiac[size];

    inputZodiacData(zodiacArray, size);
    sortZodiacArray(zodiacArray, size);

    // Збереження масиву у файл
    std::string filename;
    std::cout << "Введіть назву файлу для збереження даних: ";
    std::cin >> filename;
    saveZodiacArrayToFile(zodiacArray, size, filename);

    // Завантаження масиву з файлу
    std::cout << "Введіть назву файлу для завантаження даних: ";
    std::cin >> filename;
    loadZodiacArrayFromFile(zodiacArray, size, filename);

    // Виведення відсортованого масиву
    std::cout << "Відсортований масив:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << zodiacArray[i].lastName << " "
            << zodiacArray[i].firstName << " "
            << zodiacArray[i].zodiacSign << " "
            << zodiacArray[i].birthDate[0] << " "
            << zodiacArray[i].birthDate[1] << " "
            << zodiacArray[i].birthDate[2] << "\n";
    }

    // Виведення осіб з певним знаком Зодіаку
    std::string targetZodiacSign;
    std::cout << "Введіть знак Зодіаку для пошуку: ";
    std::cin >> targetZodiacSign;
    printPeopleByZodiac(zodiacArray, size, targetZodiacSign);

    return 0;
}
