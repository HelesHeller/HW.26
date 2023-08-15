#include <iostream>
#include <vector>
#include <string>
#include<Windows.h>

// Структура для зберігання даних про поїзд
struct Train {
    int number;
    std::string destination;
    std::string departureTime;
};

int main() {
    
    std::vector<Train> trainDatabase;

    int choice;
    do {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        std::cout << "1. Додати поїзд" << std::endl;
        std::cout << "2. Вивести інформацію про всі поїзди" << std::endl;
        std::cout << "3. Вивести інформацію про запитуваний поїзд" << std::endl;
        std::cout << "0. Вийти" << std::endl;
        std::cout << "Ваш вибір: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Train newTrain;
            std::cout << "Введіть номер поїзда: ";
            std::cin >> newTrain.number;
            std::cout << "Введіть час відправлення: ";
            std::cin >> newTrain.departureTime;
            std::cout << "Введіть станцію призначення: ";
            std::cin.ignore(); // Очистка буфера перед введенням рядка
            std::getline(std::cin, newTrain.destination);

            trainDatabase.push_back(newTrain);
            std::cout << "Поїзд додано до системи." << std::endl;
            break;
        }
        case 2: {
            std::cout << "Інформація про всі поїзди:" << std::endl;
            for (const Train& train : trainDatabase) {
                std::cout << "Поїзд " << train.number << " до " << train.destination
                    << ", час відправлення: " << train.departureTime << std::endl;
            }
            break;
        }
        case 3: {
            int queryNumber;
            std::cout << "Введіть номер запитуваного поїзда: ";
            std::cin >> queryNumber;

            bool found = false;
            for (const Train& train : trainDatabase) {
                if (train.number == queryNumber) {
                    std::cout << "Інформація про запитуваний поїзд:" << std::endl;
                    std::cout << "Поїзд " << train.number << " до " << train.destination
                        << ", час відправлення: " << train.departureTime << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "Поїзд з номером " << queryNumber << " не знайдено." << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "Програма завершує роботу." << std::endl;
            break;
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
