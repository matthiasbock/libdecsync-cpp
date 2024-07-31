
#include "decsync.hpp"

#include <gtest/gtest.h>
#include <algorithm>


using namespace DecSync;
using namespace std;
namespace fs = std::filesystem;


// Create a test fixture to reuse the same temporary directory
class GetSyncedFoldersTest : public ::testing::Test {
protected:
    fs::path temp_dir;

    void SetUp() override {
        temp_dir = fs::temp_directory_path() / "decsync_test";
        fs::create_directories(temp_dir);
    }

    void TearDown() override {
        fs::remove_all(temp_dir);
    }
};


TEST_F(GetSyncedFoldersTest, TestGetSyncedFolders) {
    // Create some test folders
    fs::create_directories(temp_dir / "calendars");
    fs::create_directories(temp_dir / "contacts");
    fs::create_directories(temp_dir / "tasks");
    fs::create_directories(temp_dir / "some_other_folder");

    // Call the function
    vector<string> synced_folders = get_synced_folders(temp_dir.string());

    // Check the results
    ASSERT_EQ(synced_folders.size(), 3);
    ASSERT_NE(find(synced_folders.begin(), synced_folders.end(), "calendars"), synced_folders.end());
    ASSERT_NE(find(synced_folders.begin(), synced_folders.end(), "contacts"), synced_folders.end());
    ASSERT_NE(find(synced_folders.begin(), synced_folders.end(), "tasks"), synced_folders.end());
}

