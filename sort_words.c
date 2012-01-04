/* Sorts a series of user-provided words lexicographically using the qsort 
 * function of the standard library */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define WORD_LEN 20

/* prototypes */
int readline(char str[], int n);
int compare_words(const void *p, const void *q);

int main(void)
{

    char *words[MAX_WORDS];
    char word[WORD_LEN+1];
    int i, num_words = 0;

    for (;;) {
        printf("Enter word: ");
        
        readline(word, WORD_LEN);

        if (strlen(word) == 0)
            break;

        words[num_words] = malloc(strlen(word) + 1);
        if (words[num_words] == NULL) {
            printf("\nError: malloc failed.\n");
            exit(EXIT_FAILURE);
        }

        strcpy(words[num_words], word);
        num_words++;
    }

    qsort(words, num_words, sizeof(char *), compare_words);

    printf("\nIn sorted order: ");
    for (i = 0; i < num_words; i++)
        printf("%s ", words[i]);
    printf("\n");

    return 0;
}

int readline(char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}

int compare_words(const void *p, const void *q)
{
    return (strcmp(*((const char **) p), *((const char **) q)));
}
