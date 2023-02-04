
#include <iostream>
#include "Date.h"
#include "Utils.h"
#include <string.h>

namespace sdds
{

    bool Date::validateDate()
    {

        bool valStop = false;
        int currYear{ 0 };
        ut.testMode(false);
        ut.getSystemDate(&currYear);

        if ((m_year > MAX_YEAR_VALUE || m_year < currYear) && m_month != 0)
        {
            valStop = true;
            m_state = "Invalid year in date";
            m_state = 1;
        }
        if (!valStop && (m_month < 1 || m_month > 12))
        {
            valStop = true;
            m_state = "Invalid month in date";
            m_state = 2;
        }
        if (!valStop && (m_day < 1 || m_day > ut.daysOfMon(m_month, m_year)))
        {
            valStop = true;
            m_state = "Invalid day in date";
            m_state = 3;
        }
        if (!valStop)
            m_state.clear();

        return valStop;
    }
    int Date::uniqueDate() const
    {
        return m_year * 372 + m_month * 31 + m_day;
    }
    Date::Date()
    {
        ut.getSystemDate(&m_year, &m_month, &m_day);
    }
    Date::Date(int year, int month, int day)
    {
        m_year = year;
        m_month = month;
        m_day = day;
        validateDate();
    }
    bool Date::operator==(const Date& d2) const
    {
        return uniqueDate() == d2.uniqueDate();
    }
    bool Date::operator!=(const Date& d2) const
    {
        return uniqueDate() != d2.uniqueDate();
    }
    bool Date::operator<(const Date& d2) const
    {
        return uniqueDate() < d2.uniqueDate();
    }
    bool Date::operator>(const Date& d2) const
    {
        return uniqueDate() > d2.uniqueDate();
    }
    bool Date::operator<=(const Date& d2) const
    {
        return uniqueDate() <= d2.uniqueDate();
    }
    bool Date::operator>=(const Date& d2) const
    {
        return uniqueDate() >= d2.uniqueDate();
    }
    const Status& Date::state() const
    {
        return m_state;
    }
    Date& Date::formatted(bool value)
    {
        m_formatted = value;
        return *this;
    }
    Date::operator bool() const
    {
        return m_state.operator bool();
    }
    std::ostream& Date::write(std::ostream& os) const
    {

        if (*this)
        {
            if (m_formatted)
            {
                os << m_year << "/";
                os.width(2);
                os.fill('0');
                os << m_month << "/";
                os.width(2);
                os.fill('0');
                os << m_day;
            }
            else
            {
                os << m_year - 2000;
                os.width(2);
                os.fill('0');
                os << m_month;
                os.width(2);
                os.fill('0');
                os << m_day;
            }
        }

        return os;
    }
    std::istream& Date::read(std::istream& is)
    {

        std::string result;
        bool failed{ false };
        is >> result;
        m_state = 0;
        m_state = "Invalid date value";
        if (atoi(result.c_str()) == 0 || strlen(result.c_str()) > 6)
            failed = true;
        if (!failed)
        {
            m_state.clear();
            if (strlen(result.c_str()) == 4)
            {
                m_month = atoi((result.substr(0, 2)).c_str());
                m_day = atoi((result.substr(2, 2)).c_str());
                ut.testMode(false);
                ut.getSystemDate(&m_year);
            }

            else
            {
                if (strlen(result.c_str()) < 6)
                    result += "000000";
                m_year = atoi((result.substr(0, 2)).c_str()) + 2000;
                m_month = atoi((result.substr(2, 2)).c_str());
                m_day = atoi((result.substr(4, 2)).c_str());
            }
            if (validateDate())
            {
                failed = true;
            }
        }
        if (failed)
        {
            is.setstate(std::ios::badbit);
        }
        return is;
    }
    std::ostream& operator<<(std::ostream& os, const Date& toPrint)
    {
        return toPrint.write(os);
    }
    std::istream& operator>>(std::istream& is, Date& toGet)
    {
        return toGet.read(is);
    }
}