
#include "path.hpp"
#include <sstream>


void DecSync::Path::parse(istringstream &input) {
    // Extract the content surrounded by squared brackets
    string line;
    getline(input, line, ']');
    line = line.substr(line.find_first_of('[') + 1);

    // Split at commata and iterate over split items
    vector<string> literals;
    string literal;
    istringstream ss(line);
    while (getline(ss, literal, ',')) {
        // Strip spaces, quotes and apostrophes
        const basic_regex<char> re_literal = regex("^\\s*(['\"]\\s*([^\\s]*)\\s*['\"]\\s*$");
        literal = regex_replace(literal, re_literal, "$2");
        literals.push_back(literal);
    }
}


ostringstream DecSync::Path::serialize() {
    ostringstream ss;

    const string _info = "[\"info\"]";
    const string _resources1 = "[\"resources\", \"";
    const string _resources2 = "\"]";

    if (info) {
        ss << _info;
    }
    if (resources) {
        if (uid.empty()) {
            ss << _resources1 << _resources2;
        } else {
            ss << _resources1 << uid << _resources2;
        }
    }

    return ss;
}
