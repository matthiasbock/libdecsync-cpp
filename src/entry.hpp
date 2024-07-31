#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <sstream>
#include <string>

#include "path.hpp"
#include "timestamp.hpp"


using namespace std;


namespace DecSync {
    class Collection;

    class Entry{
        Collection* collection = NULL;
        string filename = NULL;

        Path* path = NULL;
        Timestamp* timestamp = NULL;
        string key = NULL;
        string value = NULL;

        void load(istringstream);
    };
}

#endif // ENTRY_HPP
