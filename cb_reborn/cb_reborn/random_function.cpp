//
//  random_function.cpp
//  cb_reborn
//
//  Created by Mikal Stapnes on 21/02/2017.
//  Copyright © 2017 Mikal Stapnes. All rights reserved.
//

#include "random_function.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomWithLimits(int lower, int upper) {
    srand(time(nullptr));
    return lower + rand()%(upper - lower);
}
