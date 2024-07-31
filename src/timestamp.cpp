
#include "timestamp.hpp"


void DecSync::Timestamp::parse(const std::string& timestamp)
{
    std::istringstream ss(timestamp);
    ss >> year;
    ss.ignore(1);
    ss >> month;
    ss.ignore(1);
    ss >> day;
    ss.ignore(1);
    ss >> hour;
    ss.ignore(1);
    ss >> minute;
    ss.ignore(1);
    ss >> second;
}


const string DecSync::Timestamp::serialize()
{
    std::ostringstream ss;
    ss  << std::setfill('0')
        << std::setw(4) << year << '-'
        << std::setw(2) << month << '-'
        << std::setw(2) << day << 'T'
        << std::setw(2) << hour << ':'
        << std::setw(2) << minute << ':'
        << std::setw(2) << second;
    return ss.str();
}
