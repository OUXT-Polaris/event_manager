#ifndef EVENT_ID_LIST_H_INCLUDED
#define EVENT_ID_LIST_H_INCLUDED

#include <map>
#include <stdint.h>
#include <event_manager/event.h>

class event_id_list
{
public:
    event_id_list()
    {
        _max_index = 0;
    };
    ~event_id_list(){};
    void add_event(event event_)
    {
        if(_data.count(event_.key) == 0 && _max_index != (UINT64_MAX-1))
        {
            _data.insert(std::make_pair(event_.key,_max_index));
            _max_index++;
        }
    }
private:
    std::map<std::string, uint64_t> _data;
    uint64_t _max_index;
};
#endif  //EVENT_ID_LIST_H_INCLUDED