// part 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRAINS 5
#define MAX_PASSENGERS 100

// part 2
typedef struct {
    int trainNo;
    char trainName[50];
    char source[30];
    char destination[30];
    int availableSeats;
} Train;

typedef struct {
    char name[50];
    char gender[10];
    int age;
} Passenger;

// part 3
void initializeTrains(Train trains[]) {
    trains[0] = (Train){1001, "Rajdhani Express", "Delhi", "Mumbai", 50};
    trains[1] = (Train){1002, "Shatabdi Express", "Delhi", "Chandigarh", 40};
    trains[2] = (Train){1003, "Garib Rath", "Kolkata", "Delhi", 60};
    trains[3] = (Train){1004, "Duronto Express", "Mumbai", "Chennai", 45};
    trains[4] = (Train){1005, "Goa Express", "Goa", "Delhi", 30};
}

// part 4
void showTrains(Train trains[]) {
    printf("\n==== AVAILABLE TRAINS ====\n");
    printf("Train No\tTrain Name\t\tSource\t\tDestination\tSeats Available\n");
    for (int i = 0; i < MAX_TRAINS; i++) {
        printf("%d\t\t%-20s%-15s%-15s\t%d\n",
               trains[i].trainNo,
               trains[i].trainName,
               trains[i].source,
               trains[i].destination,
               trains[i].availableSeats);
    }
}

// part 5
int findTrainIndex(Train trains[], int trainNo) {
    for (int i = 0; i < MAX_TRAINS; i++) {
        if (trains[i].trainNo == trainNo) {
            return i;
        }
    }
    return -1;
}

// part 6
void bookTickets(Train trains[], int trainIndex, Passenger passengers[], int count) {
    printf("\n=== BOOKING CONFIRMED ===\n");
    printf("Train: %s (%d)\n",
           trains[trainIndex].trainName,
           trains[trainIndex].trainNo);
    printf("From: %s To: %s\n",
           trains[trainIndex].source,
           trains[trainIndex].destination);
    printf("Total Seats Booked: %d\n", count);

    for (int i = 0; i < count; i++) {
        printf("\nPassenger %d:\n", i + 1);
        printf("Name: %s\n", passengers[i].name);
        printf("Gender: %s\n", passengers[i].gender);
        printf("Age: %d\n", passengers[i].age);
    }

    printf("\nYOUR TICKET HAS BEEN SUCCESSFULLY BOOKED\n");
}

// part 7
int main() {
    Train trains[MAX_TRAINS];
    Passenger passengers[MAX_PASSENGERS];
    int trainNo, seatCount, trainIndex;

    initializeTrains(trains);

    printf("\n==============================");
    printf("\nWELCOME TO TRAIN BOOKING SYSTEM");
    printf("\n==============================\n");

    // Step 1: Show available trains
    showTrains(trains);

    // Step 2: Ask for train number
    printf("\nEnter Train Number: ");
    scanf("%d", &trainNo);

    trainIndex = findTrainIndex(trains, trainNo);
    if (trainIndex == -1) {
        printf("Invalid Train Number.\n");
        return 0;
    }

    // Step 3: Ask for number of seats
    printf("Enter Number of Seats: ");
    scanf("%d", &seatCount);
    getchar(); // consume newline

    if (seatCount <= 0 || seatCount > trains[trainIndex].availableSeats) {
        printf("Invalid or unavailable seat count. Only %d seats left.\n",
               trains[trainIndex].availableSeats);
        return 0;
    }

    // Step 4: Input passenger details
    for (int i = 0; i < seatCount; i++) {
        if (seatCount == 1) {
            printf("\nEnter details of passenger:\n");
        } else {
            printf("\nEnter details for Passenger %d:\n", i + 1);
        }

        printf("Name: ");
        fgets(passengers[i].name, sizeof(passengers[i].name), stdin);
        passengers[i].name[strcspn(passengers[i].name, "\n")] = '\0';

        printf("Gender: ");
        fgets(passengers[i].gender, sizeof(passengers[i].gender), stdin);
        passengers[i].gender[strcspn(passengers[i].gender, "\n")] = '\0';

        printf("Age: ");
        scanf("%d", &passengers[i].age);
        getchar(); // consume newline
    }

    // Step 5: Book the ticket
    trains[trainIndex].availableSeats -= seatCount;
    bookTickets(trains, trainIndex, passengers, seatCount);

    return 0;
}
