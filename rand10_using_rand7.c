// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

/* the idea here is to generate numbers from 1 to 10 with 
 * equal probability. 
 * 
 * Idea of a random num generator is to use a % 
 * 
 * going by that fact, 
 *
 * we can generate 1 by taking % of 11 (11%10 == 1)
 * 2 by % (12), 3 by % (13) and so on... 
 *
 * we need to generate from 1 to 10
 *
 * so for 9, we need % (19%10 == 9)
 
 */
 


#define MAX_RANDOM 10

int rand10() {

    int val  = 0;

    do {
        val = 7 * rand7() + 4;
    } while (val > 20 || val < 11);

    return val%10?val%10:10;
}
