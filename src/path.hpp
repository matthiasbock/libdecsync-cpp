
#include <sstream>
#include <string>
#include <strstream>
#include <regex>


using namespace std;


namespace DecSync {
    class Path
    {
    public:
        bool info = false;
        bool resources = false;
        string uid = NULL;

        /**
         * @brief Parses a string or istringstream
         *
         * First find the square opening bracket,
         * then read until the square closing bracket.
         * Split what was read using comma as delimiter.
         * Strip surrounding apostrophes or quotes from the split items.
         * return the list of parsed items.
         */
        void parse(istringstream& input);

        ostringstream serialize();
    };
}
