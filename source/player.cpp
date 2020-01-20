#include "player.h"
#include "VideoState.h"

player::player()
{
    init();
}

player::~player()
{
    
}

int player::init()
{
    string filename;
    static shared_ptr<VideoState> ptr = VideoState::stream_open(filename);
    return 0;
}

void player::event_loop()
{
    
}
