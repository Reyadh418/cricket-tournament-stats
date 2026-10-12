#include <stdio.h>

int main() {
    int player_id, innings, runs, times_out, balls_faced;
    double batting_average, strike_rate;
    char name[50];

    printf("Enter Player ID\t\t: ");
    scanf("%d", &player_id);

    printf("Enter Player Name\t: ");
    scanf(" %s", name);

    printf("Enter Innings\t\t: ");
    scanf("%d", &innings);

    printf("Enter Total Runs\t: ");
    scanf("%d", &runs);

    printf("Enter Times Out\t\t: ");
    scanf("%d", &times_out);

    printf("Enter Balls Faced\t: ");
    scanf("%d", &balls_faced);
    printf("\n\n");

    batting_average = (double) runs / times_out;
    strike_rate = ((double) runs / balls_faced) * 100;

    printf("-------------------------------------------------------------------------------------------------\n");
    printf("|ID\t\t|Name\t\t|Runs\t\t|Innings\t|Average\t|Strike_Rate\t|\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    printf("|%-15d|%-15s|%-15d|%-15d|%-15.2f|%-15.2f|\n", player_id, name, runs, innings, batting_average, strike_rate);
    printf("-------------------------------------------------------------------------------------------------\n");
    
    return 0;
}
