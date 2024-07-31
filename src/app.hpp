
#include <string>
#include <vector>

#include "sequence.hpp"


using namespace std;


namespace DecSync {
    class SyncType;

    class App
    {
        SyncType* sync_type = NULL;
        string name = NULL;
        vector<Sequence> sequences[] = NULL;

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
        vector<string> get_sync_folders(const string& root_path);

        void load(string folder_path);
    };
}
