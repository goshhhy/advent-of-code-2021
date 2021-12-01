
#include <stdio.h>

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int a, b, c, previous, current, in;
    int bigger = 0;

    fscanf( input, "%i\n", &a );
    fscanf( input, "%i\n", &b );
    in = fscanf( input, "%i\n", &c );

    previous = a + b + c;

    printf("%i (N/A - no previous sum)\n", previous);

    while ( in > 0 ) {
        a = b;
        b = c;
        in = fscanf( input, "%i\n", &c );
        if ( in < 1 ) 
            break;

        current = a + b + c;
        if ( current > previous ) {
            bigger++;
            printf("%i (increased)\n", current);
        } else if ( current == previous ) {
            printf("%i (no change)\n", current);
        } else {
            printf("%i (decreased)\n", current);
        }
        previous = current;
    }

    printf("%i\n", bigger);

    return 0;
}