
#include <stdio.h>

char board[3][3];

void init_board() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void print_board() {
    printf("\n  1   2   3\n");
    for (int i = 0; i < 3; ++i) {
        printf("%d %c | %c | %c \n", i+1, board[i][0], board[i][1], board[i][2]);
        if (i < 2) printf("  --+---+--\n");
    }
    printf("\n");
}

int is_winner(char p) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return 1;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return 1;
    }
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return 1;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return 1;
    return 0;
}

int board_full() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ') return 0;
    return 1;
}

void player_move(char p) {
    int r, c;
    while (1) {
        printf("Player %c, enter row and column: ", p);
        if (scanf("%d %d", &r, &c) != 2) {
            while (getchar() != '\n');
            continue;
        }
        if (r < 1 || r > 3 || c < 1 || c > 3) continue;
        if (board[r-1][c-1] != ' ') continue;
        board[r-1][c-1] = p;
        break;
    }
}

int main() {
    init_board();
    char turn = 'X';
    while (1) {
        print_board();
        player_move(turn);
        if (is_winner(turn)) {
            print_board();
            printf("Player %c wins!\n", turn);
            break;
        }
        if (board_full()) {
            print_board();
            printf("Draw!\n");
            break;
        }
        turn = (turn == 'X') ? 'O' : 'X';
    }
    return 0;
}
