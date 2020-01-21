#include "VideoState.h"
#include <iostream>

VideoState::VideoState()
{
    
}

VideoState::VideoState(const string & filename)
{
    
}

VideoState::~VideoState()
{
    
}

void VideoState::start_read_th()
{
    read_tid = make_shared<thread>(&VideoState::read_thread, this);
    read_tid->detach();
}

int VideoState::read_thread()
{
    auto self(shared_from_this());
    while (true)
    {
        cout << "read_thread\n";
    }
    return 0;
}
