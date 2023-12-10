//
#include "die.h"
#include<stdlib.h>

void Die::roll()
{
    roll_value = 1 + (rand()%6);
}
