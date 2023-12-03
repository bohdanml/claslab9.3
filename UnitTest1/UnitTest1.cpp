#include "pch.h"
#include "CppUnitTest.h"
#include "..\\claslab9.3\lab.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestPrintPeopleByZodiac)
        {
            // Масив об'єктів
            Zodiac zodiacArray[3];
            zodiacArray[0] = { "Petro", "Halchun", "Leo", {1,1,1990} };
            zodiacArray[1] = { "Kum", "Vasul","Leo", {2,2,1991} };
            zodiacArray[2] = { "Sudorenko", "Sidr", "Cancer", {3,3,1992} };

            std::ostringstream outputStream;
            auto originalOutput = std::cout.rdbuf();
            std::cout.rdbuf(outputStream.rdbuf());  // Перенаправлення виводу для збереження результату

            printPeopleByZodiac(zodiacArray, 2, "Leo");

            std::cout.rdbuf(originalOutput);

            std::string expectedOutput = "Ось особи із знаком Зодіаку Leo:\nPetro Halchun\nKum Vasul\n";
            Assert::AreEqual(expectedOutput, outputStream.str());
        }
    };
}