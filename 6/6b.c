
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long unsigned int fishes[12];
long long unsigned int fishes_count = 0;

const int days = 256;

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int in = 0, timer;
    char c;
    
    memset( fishes, 0, sizeof(fishes) );

    // read in fish timers
    do {
        in = fscanf( input, "%i%c", &timer, &c);
        if ( in < 0 ) {
            break;
        }
        fishes[timer]++;
    } while ( ( in > 0 ) || (c == '\n' ));

    /*
    for( int i = 0; i < 10; i++ ) {
        printf("%llu,", fishes[i]);
    }
    printf("\n");
    */

    for( int d = 0; d < days; d++ ) {
        fishes[9] = fishes[0];
        fishes[7] += fishes[0];
        for ( int i = 1; i < 10; i++ ) {
            fishes[i-1] = fishes[i];
        }
        fishes[9] = 0;

        /*
        for( int i = 0; i < 10; i++ ) {
            printf("%llu,", fishes[i]);
        }
        printf("\n");
        */
    }

    for ( int i = 0; i < 10; i++ ) {
        fishes_count += fishes[i];
    };

    printf("%llu fishes\n", fishes_count);

    return 0;
}