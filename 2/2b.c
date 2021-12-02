
#include <stdio.h>
#include <string.h>

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int hpos = 0, depth = 0, aim = 0;
    int in = 0;

    do {
        char dirbuf[256];
        int amount;

        in = fscanf( input, "%s ", dirbuf );
        in += fscanf( input, "%i\n", &amount);

        if ( in < 1 )
            break;

        if ( strcmp( dirbuf, "forward" ) == 0 ) {
            hpos += amount;
            depth += aim * amount;
        } else if ( strcmp( dirbuf, "down" ) == 0 ) {
            aim += amount;
        } else if ( strcmp( dirbuf, "up" ) == 0 ) {
            aim -= amount;
        } else {
            printf("unknown direction %s\n", dirbuf );
            return 1;
        }

    } while ( in > 0 );

    printf("final: %i\n", hpos * depth);

    return 0;
}