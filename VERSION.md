# Cricket Tournament Statistics: Version by version plan

---

## Version 1 (V1) - Due: Lab 3
**Goal: Static Layout Mastery (No variables, no input)**

This version is all about setting up the visual interface using only `printf`. Think of it as a mockup of your final program.

*   **The Banner:** Use `printf` to draw a nice ASCII box or visually distinct header for your tournament.
*   **The Menu:** Print exactly these options:
    1. Add a performance
    2. Batting averages
    3. Strike rates
    4. Search by player
    5. Top five by average
    6. Save & load
    7. Exit
*   **The Specimen Record:** Design how a player's stats will look on screen. Use escape sequences like `\t` (tab) and `\n` (newline) to align columns neatly. 
    *   *Example Output:* `ID: 101 | Name: Virat Kohli | Innings: 5 | Runs: 248 | Outs: 9 | Balls: 200`

---

## Version 2 (V2) - Due: Lab 4
**Goal: Memory, Input, and Arithmetic Traps**

Now, replace the hardcoded specimen record with variables and user input.

*   **Variable Setup:** Declare your variables at the top of `main()`:
    *   `int player_id, innings, runs, times_out, balls_faced;`
    *   `char name[50];`
*   **User Input:** Use `printf` to prompt the user, and `scanf` to read the values into your variables.
*   **The Calculation & The Trap:** 
    *   *Strike Rate:* `(runs / (float)balls_faced) * 100.0`
    *   *Batting Average:* You must prevent integer division truncation. If you do `runs / times_out` (e.g., 248 / 9), C will drop the decimals and give you `27`. 
    *   *The Fix:* Cast one of the integers to a float during the calculation: `float average = (float)runs / times_out;` (which gives `27.555...`).
*   **Display:** Print the calculated float using `%.2f` to round it to two decimal places (e.g., `27.56`).

---

## Version 3 (V3) - Due: Lab 6
**Goal: Modularization (Building Functions)**

You need to break your V2 code into at least five separate functions. Your `main()` should start looking like an outline, calling these functions instead of doing the heavy lifting.

*   **Suggested Architecture:**
    1.  `void print_banner(void);` (Just `printf`s)
    2.  `int print_menu(void);` (Prints menu, `scanf`s the choice, returns the choice)
    3.  `void get_player_input(int *id, char name[], int *in, int *runs, int *outs, int *balls);` *(Note: Because you need to modify multiple variables, passing pointers is best here, or just handle input in main for now if pointers aren't covered yet).*
    4.  `float calc_average(int runs, int times_out);`
    5.  `void display_record(int id, char name[], int in, int runs, int outs, int balls, float avg);`
*   **Paper Requirement:** Don't forget to draw a hierarchy chart (Structure Chart) on paper showing how `main()` calls these sub-functions.

---

## Version 4 (V4) - Due: Lab 12
**Goal: Interactivity, Validation, and Domain Rules**

This turns your linear program into an interactive application that runs continuously.

*   **The Menu Loop:** Wrap your program in a `while` or `do-while` loop.
    ```c
    int choice = 0;
    do {
        choice = print_menu();
        // switch statement here
    } while (choice != 7); 
    ```
*   **Switch Dispatch:** Use a `switch(choice)` block to trigger different print statements or functions based on what the user picks.
*   **Input Validation:** Use `while` loops immediately after a `scanf` to force the user to re-enter bad data.
    *   *Example:* `while (runs < 0) { printf("Runs cannot be negative. Try again: "); scanf("%d", &runs); }`
    *   *Rule:* `times_out` cannot be > `innings`.
*   **The Decision Rule (Division by Zero):** Implement the specific Cricket logic for undefined averages. 
    ```c
    if (times_out == 0) {
        printf("Average is undefined (never out).\n");
    } else {
        printf("Average: %.2f\n", (float)runs / times_out);
    }
    ```

---

## Version 5 (V5) - Due: Lab 20
**Goal: Arrays, Output Parameters, and File I/O**

You will now store *many* players using parallel arrays and make the menu fully functional.

*   **Parallel Arrays Setup:**
    *   `int ids[MAX_PLAYERS]; char names[MAX_PLAYERS][50]; int runs[MAX_PLAYERS];` etc.
    *   Keep an `int player_count = 0;` to track how many records are currently stored.
*   **Implementing the Menu:**
    *   *Search:* Loop through `ids[]` or `names[]` to find a match.
    *   *Top 5:* You'll need to implement a sorting algorithm (like Bubble Sort) that swaps elements in *all* parallel arrays simultaneously to keep a player's stats aligned.
*   **Output Parameter:** Write a function that returns a value via a pointer. For example, a search function: `void find_player(int search_id, int ids[], int count, int *found_index);`.
*   **Save & Load (File I/O):**
    *   *Save:* Use `fopen("stats.txt", "w")` and a loop with `fprintf` to write all array data to a text file before exiting.
    *   *Load:* On startup, use `fopen("stats.txt", "r")` and `fscanf` in a loop to populate your arrays automatically.

---

## Version 6 (V6) - Due: After Lab 21
**Goal: Structs and Recursion**

This is a structural refactoring phase. The program does exactly the same thing as V5, but the code is much cleaner.

*   **The Struct Refactor:** Replace your 6 messy parallel arrays with one clean blueprint.
    ```c
    typedef struct {
        int id;
        char name[50];
        int innings;
        int runs;
        int times_out;
        int balls_faced;
    } Player;
    
    // In main:
    Player team[MAX_PLAYERS];
    ```
    *Update all your functions to accept `Player` arrays or individual `Player` objects.*
*   **The Recursion Requirement:** Write a function to find the highest score recursively.
    *   *Hint:* The function takes the `team` array and an `index`. 
    *   *Base case:* If `index` reaches `player_count - 1`, return that player's runs.
    *   *Recursive step:* Compare `team[index].runs` with the result of a recursive call to `index + 1`. Return the maximum of the two.