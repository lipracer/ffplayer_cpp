#ifndef LL_VIDEOSTATE_H
#define LL_VIDEOSTATE_H

#include <string>
#include <thread>
#include <memory>
#include "PacketQueue.h"

using namespace std;

class VideoState : public enable_shared_from_this<VideoState>
{
public:
    
    static shared_ptr<VideoState> stream_open(const string & filename)
    {
        auto state =  make_shared<VideoState>();
        
        state->start_read_th();
        
        return state;
    }
    
    VideoState();
    VideoState(const string & filename);
    virtual ~VideoState();
    
    void start_read_th();
    
    
private:
    
    shared_ptr<thread> m_th;
    
//    PacketQueue<<#typename T#>> m_videoq;
    int read_thread();
    
};

#endif
