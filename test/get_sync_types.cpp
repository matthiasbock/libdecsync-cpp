#include "../src/decsync.hpp"

#include <boost/test/unit_test.hpp>
#include <algorithm>


using namespace DecSync;
using namespace std;
namespace fs = std::filesystem;


// Create a test fixture to reuse the same temporary directory
struct GetSyncedFoldersTest {
    fs::path temp_dir;

    GetSyncedFoldersTest() {
        temp_dir = fs::temp_directory_path() / "decsync_test";
        fs::create_directories(temp_dir);
    }

    ~GetSyncedFoldersTest() {
        fs::remove_all(temp_dir);
    }
};


BOOST_FIXTURE_TEST_CASE(TestGetSyncedFolders, GetSyncedFoldersTest) {
    // Create some test folders
    fs::create_directories(temp_dir / "calendars");
    fs::create_directories(temp_dir / "contacts");
    fs::create_directories(temp_dir / "tasks");
    fs::create_directories(temp_dir / "some_other_folder");

    // Call the function
    vector<string> synced_folders = get_synced_folders(temp_dir.string());

    // Check the results
    BOOST_CHECK_EQUAL(synced_folders.size(), 3);
    BOOST_CHECK(find(synced_folders.begin(), synced_folders.end(), "calendars") != synced_folders.end());
    BOOST_CHECK(find(synced_folders.begin(), synced_folders.end(), "contacts") != synced_folders.end());
    BOOST_CHECK(find(synced_folders.begin(), synced_folders.end(), "tasks") != synced_folders.end());
}
