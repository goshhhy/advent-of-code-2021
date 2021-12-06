
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bitcount_zero[16];
int bitcount_one[16];
size_t len = 0;

char list[1024][16];
char list2[1024][16];
char origlist[1024][16];

void count_all( FILE* input, int listlen ) {
    int num = 0;

    memset( bitcount_zero, 0, 16 * 4 );
    memset( bitcount_one, 0, 16 * 4 );

    do {
        char bytes[16];
        memset( bytes, 0, 16 );
        
        for ( int i = 0; i < len; i++ ) {
            if ( list[num][i] == '1' ) {
                bitcount_one[i]++;
            } else if ( list[num][i] == '0' ) {
                bitcount_zero[i]++;
            } else {
                ;//printf("bad value %s\n", list[num]);
            }
        }
        //printf("listlen %i\t\t%s\n", num, list[num]);
    } while ( ++num < listlen );
}

int whittle( int bit, int listlen, int flip ) {
    int i, j = 0;
    char most_common_value = ( bitcount_one[bit] > bitcount_zero[bit] ) ? '1' : '0';

    if ( bitcount_one[bit] == bitcount_zero[bit] ) {
        most_common_value = '1';
    }

    memset(list2, 0, sizeof(list2));

    //printf("most common value %c\n", most_common_value );

    for ( i = 0; i < listlen; i++ ) {
        //printf("list[i][bit] = %c\n", list[i][bit] );
        if ( list[i][bit] == most_common_value ) {
            strncpy(list2[j++], list[i], 16 );
        }
    }

    return j;
}

int whittle_co2( int bit, int listlen, int flip ) {
    int i, j = 0;
    int count = 0;
    char least_common_value = ( bitcount_one[bit] < bitcount_zero[bit] ) ? '1' : '0';

    if ( bitcount_one[bit] == bitcount_zero[bit] ) {
        least_common_value = '0';
    }

    memset(list2, 0, sizeof(list2));

    /*printf("======= x\t\t");
    for ( i = 0; i < bit; i++ ) {
        printf(" ");
    }
    printf("^\n");
    printf("least common value %c\n", least_common_value );
    */
    for ( i = 0; i < listlen; i++ ) {
        //printf("list[i][bit] = %c ", list[i][bit] );
        if ( list[i][bit] == least_common_value ) {
            //printf("(keep)\n");
            strncpy(list2[j++], list[i], 16 );
            count++;
        } else {
            ;;//printf("(prune)\n");
        }
    }

    if (count == 0 ) {
        memcpy(list2, list, sizeof(list));
        j = listlen;
    }

    return j;
}


int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    int in;

    memset(list, 0, sizeof(list));

    int i = 0;
    do {
        in = fscanf( input, "%s\n", list[i] );
        if ( !len )
            len = strlen(list[i]);
        i++;
    } while ( in > 0 );
    int listlen = i;
    int origlistlen = listlen;

    memcpy(origlist, list, sizeof(list));

    for ( i = 0; i < listlen; i++ ) {
        ;;//printf( "%s\n", origlist[i] );
    }
    
    // calculate oxy
    count_all( input, listlen );
    for ( i = 0; i < len; i++ ) {
        listlen = whittle(i, listlen, 1);
        //printf("whittle %i reduces to %i\n\n", i + 1, listlen );
        memcpy( list, list2, sizeof(list) );
        if ( listlen <= 1 )
            break;
        count_all( input, listlen );
    }
    //printf("%s\n", list[0] );
    int oxy = 0;
    for( int i = 0; i < len; i++ ) {
        if ( list[0][i] == '1' ) {
            oxy |= ( 0x8000 >> i );
        }
    }
    oxy = oxy >> (16 - len);

    // reset list
    listlen = origlistlen;
    memcpy(list, origlist, sizeof(list));

    // calculate co2
    count_all( input, listlen );
    for ( i = 0; i < len; i++ ) {
        listlen = whittle_co2(i, listlen, 1);
        //printf("whittle %i reduces to %i\n\n", i + 1, listlen );
        memcpy( list, list2, sizeof(list) );
        if ( listlen <= 1 )
            break;
        count_all( input, listlen );
    }
    //printf("%s\n", list[0] );
    int co2 = 0;
    for( int i = 0; i < len; i++ ) {
        if ( list[0][i] == '1' ) {
            co2 |= ( 0x8000 >> i );
        }
    }
    co2 = co2 >> (16 - len);

    printf("oxy: %i\n", oxy);
    printf("co2: %i\n", co2);
    printf("life support rating: %i\n", oxy * co2);

    return 0;
}