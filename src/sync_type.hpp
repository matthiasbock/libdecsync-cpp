#ifndef SYNC_TYPE_HPP
#define SYNC_TYPE_HPP

#include <string>

#include "app.hpp"


using namespace std;


namespace DecSync
{
    typedef enum {
        SYNCTYPE_CALENDAR,
        SYNCTYPE_CONTACT,
        SYNCTYPE_TASK,
        SYNCTYPE_RSS
    } sync_type_e;

    const string sync_type_name[] = {
        "calendars",
        "contacts",
        "tasks",
        "rss"
    };

    class Database;

    class SyncType
    {
        Database* database = NULL;
        string name = NULL;
        App apps[];

        void load_apps();
    };
}

#endif
