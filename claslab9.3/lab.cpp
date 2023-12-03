#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>

// ���������, �� ������ ���������� ��� �����
struct Zodiac {
    std::string lastName;
    std::string firstName;
    std::string zodiacSign;
    int birthDate[3];
};

// �������� ����� ��� ����� � �����
void inputZodiacData(Zodiac* zodiacArray, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << "������ ��� ��� ����� " << i + 1 << ":\n";
        std::cout << "�������: ";
        std::cin >> zodiacArray[i].lastName;
        std::cout << "��'�: ";
        std::cin >> zodiacArray[i].firstName;
        std::cout << "���� ������: ";
        std::cin >> zodiacArray[i].zodiacSign;
        std::cout << "���� ���������� (���� ����� ��): ";
        for (int j = 0; j < 3; ++j) {
            std::cin >> zodiacArray[i].birthDate[j];
        }
    }
}

// ���������� ������ ������ �� ��������
void sortZodiacArray(Zodiac* zodiacArray, int size) {
    std::sort(zodiacArray, zodiacArray + size, [](const Zodiac& a, const Zodiac& b) {
        return a.lastName < b.lastName;
        });
}

// ��������� ��� � ������ ������ ������
void printPeopleByZodiac(Zodiac* zodiacArray, int size, const std::string& targetZodiacSign) {
    bool found = false;
    std::cout << "��� ����� �� ������ ������ " << targetZodiacSign << ":\n";
    for (int i = 0; i < size; ++i) {
        if (zodiacArray[i].zodiacSign == targetZodiacSign) {
            found = true;
            std::cout << zodiacArray[i].lastName << " " << zodiacArray[i].firstName << "\n";
        }
    }

    if (!found) {
        std::cout << "��� � �������� ������ ������ �� ��������.\n";
    }
}

// ���������� ������ ������ � ����
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
        std::cout << "��� ��������� � ����: " << filename << "\n";
        outFile.close();
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ���������� �����.\n";
    }
}

// ������������ ������ ������ � �����
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
        std::cout << "��� ����������� � �����: " << filename << "\n";
        inFile.close();
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ������������ �����.\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size;
    std::cout << "������ ������� ���: ";
    std::cin >> size;

    Zodiac* zodiacArray = new Zodiac[size];

    inputZodiacData(zodiacArray, size);
    sortZodiacArray(zodiacArray, size);

    // ���������� ������ � ����
    std::string filename;
    std::cout << "������ ����� ����� ��� ���������� �����: ";
    std::cin >> filename;
    saveZodiacArrayToFile(zodiacArray, size, filename);

    // ������������ ������ � �����
    std::cout << "������ ����� ����� ��� ������������ �����: ";
    std::cin >> filename;
    loadZodiacArrayFromFile(zodiacArray, size, filename);

    // ��������� ������������� ������
    std::cout << "³����������� �����:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << zodiacArray[i].lastName << " "
            << zodiacArray[i].firstName << " "
            << zodiacArray[i].zodiacSign << " "
            << zodiacArray[i].birthDate[0] << " "
            << zodiacArray[i].birthDate[1] << " "
            << zodiacArray[i].birthDate[2] << "\n";
    }

    // ��������� ��� � ������ ������ ������
    std::string targetZodiacSign;
    std::cout << "������ ���� ������ ��� ������: ";
    std::cin >> targetZodiacSign;
    printPeopleByZodiac(zodiacArray, size, targetZodiacSign);

    return 0;
}
