#include <stdio.h>
#include <stdbool.h>

#define TOTAL_SEATS 10

// Function prototypes
void displayMenu();
void displaySeats(bool seats[]);
void bookSeat(bool seats[]);
void cancelReservation(bool seats[]);

int main() {
    bool seats[TOTAL_SEATS] = {false}; // false means seat is available
    int choice;

    while (1) {
        displayMenu();
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
                cancelReservation(seats);
                break;
            case 4:
                printf("Exiting the system. Thank you!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Display the menu options
void displayMenu() {
    printf("\nAirline Reservation System\n");
    printf("1. Display Available Seats\n");
    printf("2. Book a Seat\n");
    printf("3. Cancel Reservation\n");
    printf("4. Exit\n");
}

// Display the status of all seats
void displaySeats(bool seats[]) {
    printf("\nSeat Status:\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %d: %s\n", i + 1, seats[i] ? "Booked" : "Available");
    }
}

// Book a seat
void bookSeat(bool seats[]) {
    int seatNumber;

    displaySeats(seats);
    printf("Enter the seat number you want to book: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (seats[seatNumber - 1]) {
        printf("Seat %d is already booked.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = true;
        printf("Seat %d has been successfully booked.\n", seatNumber);
    }
}

// Cancel a reservation
void cancelReservation(bool seats[]) {
    int seatNumber;

    displaySeats(seats);
    printf("Enter the seat number you want to cancel: ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number. Please try again.\n");
        return;
    }

    if (!seats[seatNumber - 1]) {
        printf("Seat %d is not booked.\n", seatNumber);
    } else {
        seats[seatNumber - 1] = false;
        printf("Reservation for seat %d has been canceled.\n", seatNumber);
    }
}
