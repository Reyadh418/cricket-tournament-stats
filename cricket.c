#include <stdio.h>

void print_banner(void);
void print_line(void);
double calc_average(int runs, int times_out);
double calc_strike_rate(int runs, int balls_faced);
void display_player_stats(int player_id, char name, int innings, int runs, int times_out, int balls_faced, double batting_average, double strike_rate);

int main(void) 
{
    int player_id, innings, runs, times_out, balls_faced;
    double batting_average, strike_rate;
    char name;

    print_banner();

    printf("--- Enter Player Performance ---\n");
    printf("Enter Player ID\t\t: ");
    scanf("%d", &player_id);

    printf("Enter Player Initial\t: ");
    scanf(" %c", &name);

    printf("Enter Innings\t\t: ");
    scanf("%d", &innings);

    printf("Enter Total Runs\t: ");
    scanf("%d", &runs);

    printf("Enter Times Out\t\t: ");
    scanf("%d", &times_out);

    printf("Enter Balls Faced\t: ");
    scanf("%d", &balls_faced);

    batting_average = calc_average(runs, times_out);
    strike_rate = calc_strike_rate(runs, balls_faced);

    printf("\n--- Player Statistics Record ---\n");
    display_player_stats(player_id, name, innings, runs, times_out, balls_faced, batting_average, strike_rate);
    printf("\n");

    return 0;
}

void print_banner(void) 
{
    printf("=======================================================================================\n");
    printf("                         CRICKET TOURNAMENT STATISTICS TRACKER                         \n");
    printf("=======================================================================================\n");
}

void print_line(void) 
{
    printf("---------------------------------------------------------------------------------------\n");
}

double calc_average(int runs, int times_out) 
{
    return (double)runs / times_out;
}

double calc_strike_rate(int runs, int balls_faced) 
{
    return ((double)runs / balls_faced) * 100.0;
}

void display_player_stats(int player_id, char name, int innings, int runs, int times_out, int balls_faced, double batting_average, double strike_rate) 
{
    print_line();
    printf("| %-8s | %-6s | %-8s | %-6s | %-6s | %-6s | %-10s | %-12s |\n", "ID", "Name", "Innings", "Runs", "Outs", "Balls", "Average", "Strike Rate");
    print_line();
    printf("| %-8d | %-6c | %-8d | %-6d | %-6d | %-6d | %-10.2f | %-12.2f |\n", player_id, name, innings, runs, times_out, balls_faced, batting_average, strike_rate);
    print_line();
}