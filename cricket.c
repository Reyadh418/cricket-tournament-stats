#include <stdio.h>

int main() {
    int player_id, innings, runs, times_out, balls_faced;
    char name[50];

    printf("Enter Player ID: ");
    scanf("%d", &player_id);

    printf("Enter Player Name: ");
    scanf(" %49[^\n]", name);

    printf("Enter Innings: ");
    scanf("%d", &innings);

    printf("Enter Total Runs: ");
    scanf("%d", &runs);

    printf("Enter Times Out: ");
    scanf("%d", &times_out);

    printf("Enter Balls Faced: ");
    scanf("%d", &balls_faced);

}
