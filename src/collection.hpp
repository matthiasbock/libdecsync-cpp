
#include <string>
#include <vector>


using namespace std;


namespace DecSync {
    class Collection
    {
        sync_type_e sync_type;
        char* collection_id;
        char* app_id;
        info_t* info;
        sequences_t* sequences;

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

    };
}
