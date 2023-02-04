#include "AidMan.h"
#include "Utils.h"
#include "Date.h"

namespace sdds
{
    AidMan::AidMan() : m_mainMenu(7, "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n") {}

    AidMan::~AidMan() {
        delete[] m_fileName;

    }
    unsigned AidMan::menu() const {
        Date D;
        std::cout << "Aid Management System Version 0.1\n";
        std::cout << "Date: " << D << "\n";
        std::cout << "Data file: " << (m_fileName != nullptr ? m_fileName : "No file");
        std::cout << "\n---------------------------------\n";

        int result = m_mainMenu.run();

        return result;

    }
    void AidMan::run() {
        bool done = false;
        do {
            int menuVal = menu();
            switch (menuVal) {
            case 0:
                done = true;
                break;
            case 1:
                std::cout << "\n****List Items****\n\n";
                break;
            case 2:
                std::cout << "\n****Add Item****\n\n";
                break;
            case 3:
                std::cout << "\n****Remove Item****\n\n";
                break;
            case 4:
                std::cout << "\n****Update Quantity****\n\n";
                break;
            case 5:
                std::cout << "\n****Sort****\n\n";
                break;
            case 6:
                std::cout << "\n****Ship Items****\n\n";
                break;
            case 7:
                std::cout << "\n****New/Open Aid Database****\n\n";
                break;

            }

        } while (!done);
        std::cout << "Exiting Program!\n";

    }
}
