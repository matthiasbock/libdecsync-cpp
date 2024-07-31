#ifndef DECSYNC_HPP
#define DECSYNC_HPP

#include <string>


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
}

#endif
