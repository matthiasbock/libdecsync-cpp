
#include "sync_type.hpp"


using namespace std;


namespace DecSync {
    class Database{
    protected:
        string root_path;
        vector<SyncType> sync_types;

    public:
        /**
         * @brief Get a list of synced folders within the given root path.
         *
         * This function iterates through the directories in the specified root path
         * and checks if their names match any of the predefined sync type names.
         * It returns a vector of matching folder names.
         *
         * @param root_path The path to the root directory to search for synced folders.
         * @return A vector of strings containing the names of synced folders.
         */
        vector<string> load(string& root_path);
    };
}
