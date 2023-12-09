//
#include "die.h"
#include<stdlib.h>

void Die::roll()
{
    int dieIndex = (rand()%6);
    roll_value = sides[dieIndex];
}
