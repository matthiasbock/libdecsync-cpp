
#include <string>

using namespace std;


namespace DecSync {
    class Path
    {
    public:
        bool info;
        bool resources;
        string uid;

        Path(): info(false), resources(false), uid("") {};

        string serialize() {
            if (this->info) {
                return "[\"info\"]";
            }
            if (this->resources) {
                const string _resources1 = "[\"resources\", \"";
                const string _resources2 = "\"]";
                if (this->uid.empty()) {
                    return _resources1 + _resources2;
                } else {
                    return _resources1 + this->uid + _resources2;
                }
            }
            return "";
        }
    };
}