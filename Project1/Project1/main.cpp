#include <iostream>
#include <cstdlib> // Для использования std::atoi
#include "Aeroflot.h"
#include "RecordsManager.h"
#include "FileManager.h"

int main() {
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

    return 0;
}
