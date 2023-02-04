#pragma once

#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <iostream>
#include "Status.h"
namespace sdds
{

    const int MAX_YEAR_VALUE = 2030;
    class Date
    {
        int m_year{};
        int m_month{};
        int m_day{};
        Status m_state{};
        bool m_formatted{ true };
        bool validateDate();
        int uniqueDate() const;

    public:
        Date();
        Date(int year, int month, int day);
        bool operator==(const Date& d2) const;
        bool operator!=(const Date& d2) const;
        bool operator<(const Date& d2) const;
        bool operator>(const Date& d2) const;
        bool operator<=(const Date& d2) const;
        bool operator>=(const Date& d2) const;
        const Status& state() const;
        Date& formatted(bool value);
        operator bool() const;
        std::ostream& write(std::ostream& os) const;
        std::istream& read(std::istream& is);
    };
    std::ostream& operator<<(std::ostream& os, const Date& toPrint);
    std::istream& operator>>(std::istream& is, Date& toGet);

}

#endif