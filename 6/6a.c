
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fishes[4194304];
int fishes_count = 0;

const int days = 80;

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
        fishes[fishes_count++] = timer;
    } while ( ( in > 0 ) || (c == '\n' ));

    for ( int i = 0; i < days; i++ ) {
        for( int f = 0; f < fishes_count; f++ ) {
            fishes[f]--;
            if ( fishes[f] < 0 ) {
                fishes[f] = 6;
                fishes[fishes_count++] = 9;
            }
        }
    }

    printf("%i fishes\n", fishes_count);

    return 0;
}