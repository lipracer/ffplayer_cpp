#ifndef LL_PLAYER_H
#define LL_PLAYER_H

class player
{
public:
    player();
    virtual ~player();
    
    int init();
    
    void event_loop();
};

#endif
