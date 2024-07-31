
#include <string>

#include "path.hpp"


using namespace std;


namespace DecSync {

    class Collection;

    class Entry{
        Collection* collection;
        string filename;

        Path* path;
        string timestamp;
        string key;
        string value;

        Entry(): collection(NULL), filename(""), key(""), value("") {};
    };

}
