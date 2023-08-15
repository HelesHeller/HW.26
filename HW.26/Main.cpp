#include <iostream>
#include <vector>
#include <string>
#include<Windows.h>

// ��������� ��� ��������� ����� ��� ����
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
        std::cout << "1. ������ ����" << std::endl;
        std::cout << "2. ������� ���������� ��� �� �����" << std::endl;
        std::cout << "3. ������� ���������� ��� ����������� ����" << std::endl;
        std::cout << "0. �����" << std::endl;
        std::cout << "��� ����: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Train newTrain;
            std::cout << "������ ����� �����: ";
            std::cin >> newTrain.number;
            std::cout << "������ ��� �����������: ";
            std::cin >> newTrain.departureTime;
            std::cout << "������ ������� �����������: ";
            std::cin.ignore(); // ������� ������ ����� ��������� �����
            std::getline(std::cin, newTrain.destination);

            trainDatabase.push_back(newTrain);
            std::cout << "���� ������ �� �������." << std::endl;
            break;
        }
        case 2: {
            std::cout << "���������� ��� �� �����:" << std::endl;
            for (const Train& train : trainDatabase) {
                std::cout << "���� " << train.number << " �� " << train.destination
                    << ", ��� �����������: " << train.departureTime << std::endl;
            }
            break;
        }
        case 3: {
            int queryNumber;
            std::cout << "������ ����� ������������ �����: ";
            std::cin >> queryNumber;

            bool found = false;
            for (const Train& train : trainDatabase) {
                if (train.number == queryNumber) {
                    std::cout << "���������� ��� ����������� ����:" << std::endl;
                    std::cout << "���� " << train.number << " �� " << train.destination
                        << ", ��� �����������: " << train.departureTime << std::endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cout << "���� � ������� " << queryNumber << " �� ��������." << std::endl;
            }
            break;
        }
        case 0:
            std::cout << "�������� ������� ������." << std::endl;
            break;
        default:
            std::cout << "������� ����. ��������� �� ���." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
