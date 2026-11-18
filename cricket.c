#include <stdio.h>

void print_banner(void);
void print_line(void);
int print_menu(void);
double calc_average(int runs, int times_out);
double calc_strike_rate(int runs, int balls_faced);
void display_player_stats(int player_id, char name, int innings, int runs, int times_out, int balls_faced, double batting_average, double strike_rate);

int main(void)
{
    int player_id = 0, innings = 0, runs = 0, times_out = 0, balls_faced = 0;
    double batting_average = 0.0, strike_rate = 0.0;
    char name = '-';
    int has_record = 0;
    int choice = 0;

    print_banner();

    do
    {
        choice = print_menu();

        switch (choice)
        {
            case 1:
                printf("\n--- Enter Player Performance ---\n");

                printf("Enter Player ID\t\t: ");
                scanf("%d", &player_id);
                while (player_id <= 0)
                {
                    printf("Player ID must be positive. Try again: ");
                    scanf("%d", &player_id);
                }

                printf("Enter Player Initial\t: ");
                scanf(" %c", &name);

                printf("Enter Innings\t\t: ");
                scanf("%d", &innings);
                while (innings < 0)
                {
                    printf("Innings cannot be negative. Try again: ");
                    scanf("%d", &innings);
                }

                printf("Enter Total Runs\t: ");
                scanf("%d", &runs);
                while (runs < 0)
                {
                    printf("Runs cannot be negative. Try again: ");
                    scanf("%d", &runs);
                }

                printf("Enter Times Out\t\t: ");
                scanf("%d", &times_out);
                while (times_out < 0 || times_out > innings)
                {
                    printf("Invalid! Times out must be between 0 and %d. Try again: ", innings);
                    scanf("%d", &times_out);
                }

                printf("Enter Balls Faced\t: ");
                scanf("%d", &balls_faced);
                while (balls_faced < 0)
                {
                    printf("Balls faced cannot be negative. Try again: ");
                    scanf("%d", &balls_faced);
                }

                batting_average = calc_average(runs, times_out);
                strike_rate = calc_strike_rate(runs, balls_faced);
                has_record = 1;

                printf("\n--- Player Statistics Record ---\n");
                display_player_stats(player_id, name, innings, runs, times_out, balls_faced, batting_average, strike_rate);
                if (times_out == 0)
                {
                    printf("Note: Batting average is undefined (never out).\n");
                }
                if (balls_faced == 0)
                {
                    printf("Note: Strike rate is undefined (0 balls faced).\n");
                }
                break;

            case 2:
                printf("\n--- Batting Average ---\n");
                if (!has_record)
                {
                    printf("No player performance recorded yet. Choose Option 1 first.\n");
                }
                else if (times_out == 0)
                {
                    printf("Player %d (%c): Average is undefined (never out).\n", player_id, name);
                }
                else
                {
                    printf("Player %d (%c): Batting Average = %.2f\n", player_id, name, batting_average);
                }
                break;

            case 3:
                printf("\n--- Strike Rate ---\n");
                if (!has_record)
                {
                    printf("No player performance recorded yet. Choose Option 1 first.\n");
                }
                else if (balls_faced == 0)
                {
                    printf("Player %d (%c): Strike rate is undefined (0 balls faced).\n", player_id, name);
                }
                else
                {
                    printf("Player %d (%c): Strike Rate = %.2f\n", player_id, name, strike_rate);
                }
                break;

            case 4:
                printf("\n--- Search by Player ---\n");
                printf("Multi-player search will be available in Version 5.\n");
                break;

            case 5:
                printf("\n--- Top Five by Average ---\n");
                printf("Top five ranking will be available in Version 5.\n");
                break;

            case 6:
                printf("\n--- Save & Load ---\n");
                printf("File save & load will be available in Version 5.\n");
                break;

            case 7:
                printf("\nExiting Cricket Tournament Statistics Tracker. Goodbye!\n");
                break;

            default:
                printf("\nInvalid choice! Please select an option between 1 and 7.\n");
                break;
        }
    } while (choice != 7);

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

int print_menu(void)
{
    int choice;

    printf("\n--- Main Menu ---\n");
    printf("1. Add a performance\n");
    printf("2. Batting averages\n");
    printf("3. Strike rates\n");
    printf("4. Search by player\n");
    printf("5. Top five by average\n");
    printf("6. Save & load\n");
    printf("7. Exit\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);

    return choice;
}

double calc_average(int runs, int times_out)
{
    if (times_out == 0)
    {
        return -1.0;
    }
    return (double)runs / times_out;
}

double calc_strike_rate(int runs, int balls_faced)
{
    if (balls_faced == 0)
    {
        return -1.0;
    }
    return ((double)runs / balls_faced) * 100.0;
}

void display_player_stats(int player_id, char name, int innings, int runs, int times_out, int balls_faced, double batting_average, double strike_rate)
{
    print_line();
    printf("| %-8s | %-6s | %-8s | %-6s | %-6s | %-6s | %-10s | %-12s |\n",
           "ID", "Name", "Innings", "Runs", "Outs", "Balls", "Average", "Strike Rate");
    print_line();
    printf("| %-8d | %-6c | %-8d | %-6d | %-6d | %-6d | ",
           player_id, name, innings, runs, times_out, balls_faced);

    if (times_out == 0)
    {
        printf("%-10s | ", "Undefined");
    }
    else
    {
        printf("%-10.2f | ", batting_average);
    }

    if (balls_faced == 0)
    {
        printf("%-12s |\n", "N/A");
    }
    else
    {
        printf("%-12.2f |\n", strike_rate);
    }
    print_line();
}
