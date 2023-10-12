#include <stdio.h>

#define USD 1
#define EUR 2
#define VND 3

typedef union
{
    double usd;
    double eur;
    double vnd;
} RoomPrice;

typedef enum
{
    SINGLE,
    DOUBLE
} RoomType;

typedef enum
{
    EMPTY,
    BOOKED
} RoomStatus;

typedef struct
{
    int roomNumber;
    RoomType type;
    RoomStatus status;
    RoomPrice price;
    int currencyType;
} Room;

double getPriceInUSD(Room room)
{
    switch (room.currencyType)
    {
    case USD:
        return room.price.usd;
    case EUR:
        return room.price.eur;
    case VND:
        return room.price.vnd;
    default:
        return 0.0;
    }
}

void displayRoomList(Room rooms[], int count)
{
    printf("Room List:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Room %d: ", rooms[i].roomNumber);
        if (rooms[i].status == EMPTY)
        {
            printf("Status: Empty\n");
        }
        else
        {
            printf("Status: Booked\n");
        }
    }
}

int main()
{
    Room rooms[10];
    for (int i = 0; i < 10; i++)
    {
        rooms[i].roomNumber = i + 1;
        rooms[i].status = EMPTY;
    }

    int choice;
    int roomChoice;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Check Rooms\n");
        printf("2. Book Room\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayRoomList(rooms, 10);
            break;
        case 2:
            printf("Enter room number: ");
            scanf("%d", &roomChoice);
            if (roomChoice < 1 || roomChoice > 10)
            {
                printf("Invalid room number. Please choose a room between 1 and 10.\n");
            }
            else if (rooms[roomChoice - 1].status == BOOKED)
            {
                printf("Room is already booked. Please choose another room.\n");
            }
            else
            {
                rooms[roomChoice - 1].status = BOOKED;
                printf("Room %d has been booked.\n", roomChoice);
                printf("Choose room type: (1) Single or (2) Double: ");
                int roomType;
                scanf("%d", &roomType);
                if (roomType == 1)
                {
                    rooms[roomChoice - 1].type = SINGLE;
                    rooms[roomChoice - 1].price.usd = 10;
                    rooms[roomChoice - 1].price.vnd = 10000;
                    printf("USD: 10 \nVND: 10000\n");
                }
                else if (roomType == 2)
                {
                    rooms[roomChoice - 1].type = DOUBLE;
                    rooms[roomChoice - 1].price.usd = 20;
                    rooms[roomChoice - 1].price.vnd = 15000;
                    printf("USD: 20 \nVND: 15000\n");
                }
                else
                {
                    printf("Invalid choice. Defaulting to Single Room.\n");
                    rooms[roomChoice - 1].type = SINGLE;
                    rooms[roomChoice - 1].price.usd = 10;
                    rooms[roomChoice - 1].price.vnd = 10000;
                }
            }
            break;
        case 3:
            return 0;
        default:
            printf("Invalid choice. Please choose 1, 2, or 3.\n");
            break;
        }
    }

    return 0;
}
