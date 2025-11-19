    #include <stdio.h>
#include <stdlib.h>

// Прототипы функций
int** funk1(int n);
int funk2(int** arr, int n);
int funk3(int** arr, int n);
void text_op();

int main()
{
    int n;
    int choice;
    int** arr;
    printf("Enter massive size:");
    scanf_s("%d", &n);
    arr = funk1(n);

    do {
        printf("\n MENU \n");
        printf("1. Find rows with all zeros\n");
        printf("2. Find rows with all even numbers\n");
        printf("3. Work with text massive\n");
        printf("4. Exit\n");
        printf("Your choice: ");
        scanf_s("%d", &choice);

        switch (choice)
        {
        case 1:
            funk2(arr, n);
            break;
        case 2:
            funk3(arr, n);
            break;
        case 3:
            text_op();
            break;
        case 4:
            printf("goodbye\n");
            break;
        default:
            printf("Invalid choice");
        }
    } while (choice != 4);

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}

// Функция создания матрицы
int** funk1(int n)
{
    int i, j;
    int** arr = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(n * sizeof(int));
    }

    printf("Enter matrix elements:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf_s("%d", &arr[i][j]);
        }
    }
    return arr;
}

// Функция поиска нулевых строк
int funk2(int** arr, int n)
{
    int i, j;
    int found_zeros = 0;
    printf("strings that have all zeros: ");
    for (i = 0; i < n; i++)
    {
        int all_zeros = 1;
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                all_zeros = 0;
                break;
            }
        }
        if (all_zeros == 1)
        {
            printf("%d ", i + 1);
            found_zeros = 1;
        }
    }
    if (found_zeros == 0)
    {
        printf("no");
    }
    printf("\n");
    return 0;
}

// Функция поиска строк с четными числами
int funk3(int** arr, int n)
{
    int i, j;
    int found_even = 0;
    printf("which strings have all even numbers: ");
    for (i = 0; i < n; i++)
    {
        int all_even = 1;
        for (j = 0; j < n; j++)
        {
            if (arr[i][j] % 2 != 0 || arr[i][j] == 0)
            {
                all_even = 0;
                break;
            }
        }
        if (all_even == 1)
        {
            printf("%d ", i + 1);
            found_even = 1;
        }
    }
    if (found_even == 0)
    {
        printf("no");
    }
    printf("\n");
    return 0;
}
int str_lenght(char* str)
{
    int lenght = 0;
    while (str[lenght] != '\0')
    {
        lenght++;
    }
    return lenght;
}

// Функция для работы с текстом
void text_op()
{
    char** texts;
    int count;
    int i;

    printf("How many strings?\n");
    scanf_s("%d", &count);
    

    if (count <= 0) {
        printf("Invalid count\n");
        return;
    }

    texts = (char**)malloc(count * sizeof(char*));

    printf("Enter %d strings:\n", count);
    for (i = 0; i < count; i++) {
        texts[i] = (char*)malloc(100 * sizeof(char));
        printf("String %d: ", i + 1);
        scanf_s("%s", texts[i], 100);
    }

    // Поиск самой длинной строки
    int max_length = 0;
    int longest_index = 0;

    for (i = 0; i < count; i++) {
        int current_length = str_lenght(texts[i]);
        if (current_length > max_length) {
            max_length = current_length;
            longest_index = i;
        }
    }

    printf("\nLongest string: \"%s\" at position %d\n", texts[longest_index], longest_index+1 );

    // Инвертирование строки
    char* longest = texts[longest_index];
    int len = str_lenght(longest);

    for (i = 0; i < len / 2; i++) {
        char temp = longest[i];
        longest[i] = longest[len - 1 - i];
        longest[len - 1 - i] = temp;
    }

    printf("After reverse: \"%s\"\n", longest);

    // Освобождение памяти текстового массива
    for (i = 0; i < count; i++) {
        free(texts[i]);
    }
    free(texts);
}
