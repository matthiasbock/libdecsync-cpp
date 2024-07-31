
#include <filesystem>
#include <algorithm>
#include <vector>
#include <string>

#include "decsync.hpp"


using namespace DecSync;
using namespace std;
namespace fs = std::filesystem;


vector<string> DecSync::get_sync_folders(const string& root_path) {
  vector<string> sync_folders;

  // Iterate over all entries in the root path
  for (const auto & entry : fs::directory_iterator(root_path)) {
    if (entry.is_directory()) {
      // Check if the folder name matches any of the sync_type_names
      string folder_name = entry.path().filename().string();
      if (find(begin(sync_type_name), end(sync_type_name), folder_name) != end(sync_type_name)) {
        sync_folders.push_back(folder_name);
      }
    }
  }

  return sync_folders;
}

