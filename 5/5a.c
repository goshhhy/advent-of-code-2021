
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short grid[1024][1024];

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int in = 0;
    
    memset( grid, 0, sizeof(grid) );

    do {
        int x1, y1, x2, y2;

        in = fscanf( input, "%i,%i -> %i,%i\n ", &x1, &y1, &x2, &y2 );

        if ( in < 1 )
            break;

        if ( x1 == x2 ) {
             if ( y1 < y2 ) {
                for ( int y = y1; y <= y2; y++ ) {
                    grid[x1][y] += 1;
                }
            } else {
                for ( int y = y2; y <= y1; y++ ) {
                    grid[x1][y] += 1;
                }                
            }           
        } else if ( y1 == y2 ) {
            if ( x1 < x2 ) {
                for ( int x = x1; x <= x2; x++ ) {
                    grid[x][y1] += 1;
                }
            } else {
                for ( int x = x2; x <= x1; x++ ) {
                    grid[x][y1] += 1;
                }                
            }
        }

    } while ( in > 0 );

    int count = 0;
    for ( int x = 0; x < 1024; x++ ) {
        for ( int y = 0; y < 1024; y++ ) {
            if ( grid[x][y] >= 2 ) {
                count++;
            }
        }
    }

    printf("%i overlaps\n", count);

    return 0;
}