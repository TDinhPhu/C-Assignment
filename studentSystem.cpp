#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Score
{
    float Mark;
    char Grade;
};

struct Student
{
    char Name[50];
    int ID;
    union Score StudentScore;
};

int compareByName(const void *a, const void *b)
{
    return strcmp(((struct Student *)a)->Name, ((struct Student *)b)->Name);
}

int compareByID(const void *a, const void *b)
{
    return ((struct Student *)a)->ID - ((struct Student *)b)->ID;
}

int compareByMark(const void *a, const void *b)
{
    return (int)(((struct Student *)a)->StudentScore.Mark - ((struct Student *)b)->StudentScore.Mark);
}

void customSort(struct Student students[], int n, int (*compareFunc)(const void *, const void *))
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (compareFunc(&students[i], &students[j]) > 0)
            {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main()
{
    struct Student students[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter student %d's name: ", i + 1);
        scanf("%s", students[i].Name);

        printf("Enter student %d's ID: ", i + 1);
        scanf("%d", &students[i].ID);

        printf("Enter student %d's mark: ", i + 1);
        scanf("%f", &students[i].StudentScore.Mark);
        getchar();
    }

    // Sort students by name 
    customSort(students, 3, compareByName);
    printf("Students sorted by Name:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s, ID: %d, Mark: %.1f\n", students[i].Name, students[i].ID, students[i].StudentScore.Mark);
    }

    // Sort students by ID 
    customSort(students, 3, compareByID);
    printf("\nStudents sorted by ID:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s, ID: %d, Mark: %.1f\n", students[i].Name, students[i].ID, students[i].StudentScore.Mark);
    }

    // Sort students by mark 
    customSort(students, 3, compareByMark);
    printf("\nStudents sorted by Mark:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s, ID: %d, Mark: %.1f\n", students[i].Name, students[i].ID, students[i].StudentScore.Mark);
    }

    return 0;
}
