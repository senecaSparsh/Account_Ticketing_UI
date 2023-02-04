#pragma once
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
namespace sdds
{
    class AidMan
    {

        char* m_fileName{};
        Menu m_mainMenu{};
        unsigned menu() const;

    public:
        AidMan();
        AidMan(const AidMan& src) = delete;
        AidMan& operator=(const AidMan& src) = delete;
        ~AidMan();
        void run();
    };

}
#endif