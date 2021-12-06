
#include <stdio.h>
#include <string.h>

typedef struct board {
    int numbers[5][5];
    int marked[5][5];
    int winning;
} board;

int main( int argc, char **argv ) {
    FILE* input = fopen( argv[1], "r" );
    board boards[512];
    int numbers[512];
    int total_numbers = 0, total_boards = 0, total_winning_boards = 0, in;
    int last_board_found = 0;
    char c;

    memset(numbers, 0, sizeof(numbers));
    memset(boards, 0, sizeof(boards));
    // read in numbers to draw
    do {
        in = fscanf( input, "%2i%c,", &numbers[total_numbers++], &c);
        if ( c != ',' )
            break;
    } while ( in > 0 );

    /*
    for ( int i = 0; i < total_numbers - 1; i++ ) {
        printf( "%i,", numbers[i] );
    }
    printf( "%i\n", numbers[total_numbers - 1] );
    */
    
    // read in a newline
    in = fscanf( input, "%c,", &c);
    // read in boards
    while ( in > 0 ) {
        //printf("\n");
        for ( int y = 0; y < 5; y++ ) {
            for ( int x = 0; x < 5; x++ ) {
                // up to 2 digit number, then a space or newline
                fscanf( input, "%2i%c", &boards[total_boards].numbers[y][x], &c);
            }
        }

        /*
        for ( int y = 0; y < 5; y++ ) {
            for ( int x = 0; x < 5; x++ ) {
                // up to 2 digit number, then a space or newline
                printf( "%2i ", boards[total_boards].numbers[y][x]);
            }
            printf("\n");
        }
        */

        // attempt to read in a newline
        in = fscanf( input, "%c,", &c);
        total_boards++;
    }

    // go through each number
    for ( int i = 0; i < total_numbers; i++ ) {
        //printf( "round %i: drawn %i\n", i, numbers[i] );
        // for each number, go through every board
        for ( int b = 0; b < total_boards; b++ ) {
            // check all the numbers, mark if they were the one drawn
            for ( int y = 0; y < 5; y++ ) {
                for ( int x = 0; x < 5; x++ ) {
                    if ( boards[b].numbers[y][x] == numbers[i] ) {
                        boards[b].marked[y][x] = 1;
                    }
                }
            }
        }

        for ( int b = 0; b < total_boards; b++ ) {
            if ( boards[b].winning )
                continue;
            // look for horizontal wins
            for ( int y = 0; y < 5; y++ ) {
                int total = 0;
                for ( int x = 0; x < 5; x++ ) {
                    if ( boards[b].marked[y][x] == 1) {
                        total++;
                    }
                }
                if ( total > 4 ) {
                    printf("horizontal win on board %i\n", b);

                    int sum = 0;
                    for ( int y2 = 0; y2 < 5; y2++ ) {
                        for ( int x2 = 0; x2 < 5; x2++ ) {
                            if ( boards[b].marked[y2][x2] == 0) {
                                sum += boards[b].numbers[y2][x2];
                            }
                        }
                    }
                    printf("sum %i, score %i\n", sum, sum * numbers[i]);
                    boards[b].winning = 1;
                    total_winning_boards++;
                }
            }
        }

    for ( int b = 0; b < total_boards; b++ ) {
            if ( boards[b].winning )
                continue;

            // look for vertical wins
            for ( int x = 0; x < 5; x++ ) {
                int total = 0;
                for ( int y = 0; y < 5; y++ ) {
                    if ( boards[b].marked[y][x] == 1) {
                        total++;
                    }
                }
                if ( total > 4 ) {
                    printf("vertical win on board %i\n", b);

                    int sum = 0;
                    for ( int y2 = 0; y2 < 5; y2++ ) {
                        for ( int x2 = 0; x2 < 5; x2++ ) {
                            if ( boards[b].marked[y2][x2] == 0) {
                                sum += boards[b].numbers[y2][x2];
                            }
                        }
                    }
                    printf("sum %i, score %i\n", sum, sum * numbers[i]);
                    boards[b].winning = 1;
                    total_winning_boards++;
                }
            }

            if ( !last_board_found ) {
                printf("%i of %i winning boards\n", total_winning_boards, total_boards );
                if ( total_winning_boards == total_boards - 1 ){
                    printf( "\nONE BOARD REMAINS:\n" );
                    last_board_found = 1;
                } 
            }
        }
    }

    return 0;
}