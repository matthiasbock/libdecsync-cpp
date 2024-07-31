
#include <string>
#include <strstream>

using namespace std;


namespace DecSync {
    class Timestamp
    {
    protected:
        uint16_t year = 0;
        uint8_t month = 0;
        uint8_t day = 0;
        uint8_t hour = 0;
        uint8_t minute = 0;
        uint8_t second = 0;

    public:
        Timestamp() = default;
        explicit Timestamp(const std::string& timestamp) { parse(timestamp); }

        void parse(const std::string& timestamp)
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

        std::string serialize() const
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
    };
}
