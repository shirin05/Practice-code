#include <stdio.h>
#include <stdlib.h>

char GetPlayerMove() {
    char player_move;
    int valid_input;

    while(1) {
        printf("Enter your move (r for rock, p for paper, s for scissors): ");
        valid_input = scanf(" %c", &player_move);

        if (valid_input == 1 && (player_move == 'r' || player_move == 'p' || player_move == 's')) {
            return player_move;
        } else {
            printf("Invalid move. ");
        }
    }
}

char GetComputerMove() {
    char choices[] = {'r', 'p', 's'};
    int random_num = rand() % 3;
    return choices[random_num];
}

void PlayRockPaperScissorsGame() {
    char player_move = GetPlayerMove();
    char computer_move = GetComputerMove();
    printf("Computer's move: %c\n", computer_move);

    if (player_move == 'r' && computer_move == 's') {
        printf("You win!\n");
    } else if (player_move == 'r' && computer_move == 'p') {
        printf("Computer wins!\n");
    } else if (player_move == 'p' && computer_move == 's') {
        printf("Computer wins!\n");
    } else if (player_move == 'p' && computer_move == 'r') {
        printf("You win!\n");
    } else if (player_move == 's' && computer_move == 'r') {
        printf("Computer wins!\n");
    } else if (player_move == 's' && computer_move == 'p') {
        printf("You win!\n");
    } else if (player_move == computer_move) {
        printf("Draw!\n");
    }
}

int main() {
    char game_start;
    printf("Welcome to Rock, Paper, Scissors! Press 'q' to quit or any other key to continue: \n");
    scanf(" %c", &game_start);

    while(game_start != 'q') {
        PlayRockPaperScissorsGame();
        printf("Press 'q' to quit or any other key to continue: \n");
        scanf(" %c", &game_start);
    }

    printf("Bye Bye!\n");

    return 0;
}



