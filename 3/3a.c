
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int in;
    int bitcount_zero[16];
    int bitcount_one[16];
    size_t len = 0;

    memset( bitcount_zero, 0, 16 * 4 );
    memset( bitcount_one, 0, 16 * 4 );

    do {
        char bytes[16];
        memset( bytes, 0, 16 );

        in = fscanf( input, "%s\n", bytes );
    
        if ( in < 1 ) {
            break;
        }

        if ( !len ) {
            len = strlen(bytes);
        }

        for ( int i = 0; i < len; i++ ) {
            if ( bytes[i] == '1' ) {
                bitcount_one[i]++;
            } else if ( bytes[i] == '0' ) {
                bitcount_zero[i]++;
            } else {
                printf("bad value %s\n", bytes);
            }
        }

    } while ( in > 0 );

    int gamma = 0;
    for( int i = 0; i < len; i++ ) {
        if ( bitcount_one[i] == bitcount_zero[i] ) {
            printf("problem\n");
        } else if ( bitcount_one[i] > bitcount_zero[i] ) {
            gamma |= ( 0x8000 >> i );
        }
    }
    gamma = gamma >> (16 - len);
    printf("gamma: %i\n", gamma);

    int epsilon = 0;
    for( int i = 0; i < len; i++ ) {
        if ( bitcount_one[i] < bitcount_zero[i] ) {
            epsilon |= ( 0x8000 >> i );
        }
    }
    epsilon = epsilon >> (16 - len);
    printf("epsilon: %i\n", epsilon);

    printf("total: %i\n", gamma * epsilon);

    return 0;
}