#include <iostream>
#include <cstdlib> // Для использования std::atoi
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>  // Для использования std::isalpha

#include "Aeroflot.h"
#include "RecordsManager.h"
#include "FileManager.h"

int main() {
    int choice;
    do {
        std::cout << "\nMenu:\n1. Task 1 - Aeroflot Records Manager\n2. Task 2 - Words starting with vowels\n3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Welcome to Aeroflot Records Manager!" << std::endl;

            RecordsManager recordsManager;

            // Тестирование конструкторов и деструктора
            AEROFLOT testRecord("TestDestination", 123, "TestAircraft");
            RecordsManager testManager;
            testManager.addRecord(testRecord);
            int choice;
            do {
                std::cout << "\nMenu:\n1. Add Record\n2. Sort Records\n3. Display Records by Destination\n"
                    "4. Write to File\n5. Read from File\n6. Exit\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice;

                switch (choice) {
                case 1: {
                    std::string destination;
                    int flightNumber;
                    std::string aircraftType;

                    std::cout << "Enter destination: ";
                    std::cin >> destination;

                    std::cout << "Enter flight number: ";
                    std::cin >> flightNumber;

                    std::cout << "Enter aircraft type: ";
                    std::cin >> aircraftType;

                    AEROFLOT newRecord(destination, flightNumber, aircraftType);
                    recordsManager.addRecord(newRecord);
                    break;
                }
                case 2:
                    recordsManager.sortRecords();
                    std::cout << "Records sorted by flight number." << std::endl;
                    break;
                case 3: {
                    std::string searchDestination;
                    std::cout << "Enter destination to search: ";
                    std::cin >> searchDestination;
                    recordsManager.displayRecordsByDestination(searchDestination);
                    break;
                }
                case 4:
                    FileManager::writeToFile(recordsManager, "records.txt");
                    std::cout << "Records written to file 'records.txt'." << std::endl;
                    break;
                case 5:
                    recordsManager = RecordsManager(); // Очищаем текущие записи
                    FileManager::readFromFile(recordsManager, "records.txt");
                    std::cout << "Records read from file 'records.txt'." << std::endl;
                    break;
                case 6:
                    std::cout << "Exiting the program. Goodbye!" << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please enter a valid option." << std::endl;
                    break;
                }
            } while (choice != 6);

            break;
        }
        case 2: {
            // Чтение английского текста из файла
            std::ifstream inputFile("english_text.txt");
            if (!inputFile.is_open()) {
                std::cerr << "Error opening file for reading." << std::endl;
                return 1;
            }

            std::string englishText;
            std::string line;
            while (std::getline(inputFile, line)) {
                englishText += line + "\n";
            }

            inputFile.close();

            // Использование строкового потока для чтения слов, начинающихся с гласных букв
            std::stringstream ss(englishText);
            std::string word;
            std::vector<std::string> vowelWords;

            while (ss >> word) {
                if (std::isalpha(word[0]) && (word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u')) {
                    vowelWords.push_back(word);
                }
            }

            // Вывод слов, начинающихся с гласных букв
            std::cout << "Words starting with vowels:\n";
            for (const auto& w : vowelWords) {
                std::cout << w << std::endl;
            }

            break;
        }
        case 3:
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            break;
        }
    } while (choice != 3);

    return 0;
}
