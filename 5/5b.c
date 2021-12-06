
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

short grid[1024][1024];

void line( x1, y1, x2, y2 ) {
    int deltax = 0, deltay = 0;
    int x = x1, y = y1;
    int count;
    
    if ( x1 != x2 ) {
        if ( x1 > x2 )
            deltax = -1;
        else
            deltax = 1;
        count = abs(x2 - x1);
    }
    if ( y1 != y2 ) {
        if ( y1 > y2 )
            deltay = -1;
        else
            deltay = 1;
        count = abs(y2 - y1);
    }

    int i = 0;
    do {
        grid[x][y]++;
        x += deltax;
        y += deltay;
        i++;
    } while ( i <= count );
}

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int in = 0;
    
    memset( grid, 0, sizeof(grid) );

    do {
        int x1, y1, x2, y2;

        in = fscanf( input, "%i,%i -> %i,%i\n ", &x1, &y1, &x2, &y2 );

        if ( in < 1 )
            break;

        line( x1, y1, x2, y2 ); 
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
    for ( int y = 0; y < 10; y++ ) {
        for ( int x = 0; x< 10; x++ ) {
            if ( grid[x][y] == 0 )
                printf(".");
            else
                printf("%i", grid[x][y]);
        }
        printf("\n");
    }

    return 0;
}