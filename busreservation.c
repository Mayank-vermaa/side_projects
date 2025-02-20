#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SEATS 40

// Structure to store passenger details
struct Passenger {
    int seatNumber;
    char name[50];
};

// Function prototypes
void initializeSeats(struct Passenger seats[]);
void displaySeats(struct Passenger seats[]);
void bookSeat(struct Passenger seats[]);
void displayBookings(struct Passenger seats[]);

// Main function
int main() {
    struct Passenger seats[MAX_SEATS];
    int choice;

    initializeSeats(seats);

    while (1) {
        printf("\n=== BUS RESERVATION SYSTEM ===\n");
        printf("1. View Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Display All Bookings\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySeats(seats);
                break;
            case 2:
                bookSeat(seats);
                break;
            case 3:
                displayBookings(seats);
                break;
            case 4:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to initialize seats
void initializeSeats(struct Passenger seats[]) {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i].seatNumber = i + 1;
        strcpy(seats[i].name, "Available");
    }
}

// Function to display available seats
void displaySeats(struct Passenger seats[]) {
    printf("\nAvailable Seats:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (strcmp(seats[i].name, "Available") == 0) {
            printf("Seat %d  ", seats[i].seatNumber);
        }
    }
    printf("\n");
}

// Function to book a seat
void bookSeat(struct Passenger seats[]) {
    int seatNum;
    char passengerName[50];

    printf("\nEnter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seatNum);
    getchar(); // To consume newline character left by scanf

    if (seatNum < 1 || seatNum > MAX_SEATS) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    if (strcmp(seats[seatNum - 1].name, "Available") != 0) {
        printf("Seat already booked! Choose another seat.\n");
        return;
    }

    printf("Enter passenger name: ");
    fgets(passengerName, sizeof(passengerName), stdin);
    passengerName[strcspn(passengerName, "\n")] = 0; // Remove newline character

    strcpy(seats[seatNum - 1].name, passengerName);
    printf("Seat %d successfully booked for %s!\n", seatNum, passengerName);
}

// Function to display all bookings
void displayBookings(struct Passenger seats[]) {
    printf("\nCurrent Bookings:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        if (strcmp(seats[i].name, "Available") != 0) {
            printf("Seat %d - %s\n", seats[i].seatNumber, seats[i].name);
        }
    }
}
