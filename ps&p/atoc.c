#include <stdio.h>

#define MAX_OPTIONS 10
#define MAX_NAME_LENGTH 50

int main() {
    int numOptions, votes[MAX_OPTIONS] = {0}, choice, totalVotes = 0;
    char options[MAX_OPTIONS][MAX_NAME_LENGTH];

    printf("Enter the number of options (1-%d): ", MAX_OPTIONS);
    scanf("%d", &numOptions);

    if (numOptions < 1 || numOptions > MAX_OPTIONS) {
        printf("Invalid number of options.\n");
        return 1;
    }

    printf("Enter the names of the options:\n");
    for (int i = 0; i < numOptions; i++) {
        printf("Option %d: ", i + 1);
        scanf(" %[^\n]", options[i]);
    }

    printf("\nVoting begins! Enter 0 to finish.\n");
    while (1) {
        printf("Vote (1-%d, or 0 to end): ", numOptions);
        scanf("%d", &choice);

        if (choice == 0) break;
        if (choice >= 1 && choice <= numOptions) {
            votes[choice - 1]++;
            totalVotes++;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    printf("\nPoll Results:\n");
    if (totalVotes == 0) {
        printf("No votes were cast.\n");
    } else {
        for (int i = 0; i < numOptions; i++) {
            printf("%d. %s: %d votes (%.2f%%)\n", i + 1, options[i], votes[i], (votes[i] * 100.0) / totalVotes);
        }
    }

    printf("Thank you for participating!\n");
    return 0;
}