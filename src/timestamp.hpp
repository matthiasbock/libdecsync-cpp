#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

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

        void parse(const string& timestamp);

        const string serialize();
    };
}

#endif // TIMESTAMP_HPP
