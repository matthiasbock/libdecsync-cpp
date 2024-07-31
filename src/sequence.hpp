#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <string>
#include <vector>

#include "entry.hpp"


using namespace std;


namespace DecSync {
    class App;

    class Sequence
    {
    public:
        App* app = NULL;
        string name;
        vector<Entry> entries;

        Sequence() = default;
        // explicit Sequence(string& filepath) { load(filepath); };

        void load(string& filepath);
    };
}

#endif // SEQUENCE_HPP
