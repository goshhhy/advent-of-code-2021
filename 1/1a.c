
#include <stdio.h>

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int previous, current, in;
    int bigger = 0;

    in = fscanf( input, "%i\n", &previous );

    while ( in > 0 ) {
        in = fscanf( input, "%i\n", &current );
        if ( current > previous ) {
            bigger++;
        }
        previous = current;
    }

    printf("%i\n", bigger);

    return 0;
}