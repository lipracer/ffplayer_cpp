//
//  main.cpp
//  player
//
//  Created by 陈龙 on 2020/1/20.
//  Copyright © 2020 陈龙. All rights reserved.
//

#include <iostream>
#include <initializer_list>

#include "player.h"

void print_list(std::initializer_list<int> params)
{
    for(auto it : params)
    {
        std::cout << it << std::endl;
    }
}

int main(int argc, const char * argv[])
{
    print_list({1, 2, 3, 4});
    player player;
    return 0;
}
