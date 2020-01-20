#ifndef LL_PACKET_QUEUE_H
#define LL_PACKET_QUEUE_H

#include <list>
#include <mutex>
#include <condition_variable>

using namespace std;

template<typename T>
class PacketQueue
{
public:
    
    size_t size() const
    {
        return m_pkts.size();
    }
    
private:
    
    list<T> m_pkts;
    
    mutex m_mutex;
    condition_variable m_cond;
};

#endif
