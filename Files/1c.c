#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void update_clue(char guessed_letter, char* secret_word, char* clue) {
    int index = 0;
    while (index < strlen(secret_word)) {
        if (guessed_letter == secret_word[index]) {
            clue[index] = guessed_letter;
        }
        index = index + 1;
    }
}

int main() {
    srand(time(0));
    int lives = 3;
    char* words[] = {"Python", "yield", "Code", "Feichuan", "Mingzhi", "Creamy ice"};
    int num_words = sizeof(words) / sizeof(words[0]);
    char* secret_word = words[rand() % num_words];
    int secret_word_length = strlen(secret_word);
    char* clue = malloc((secret_word_length + 1) * sizeof(char));
    memset(clue, '?', secret_word_length);
    clue[secret_word_length] = '\0';
    int guessed_word_correctly = 0;

    printf("按任意键开始:");
    getchar();

    while (lives > 0) {
        printf("%s\n", clue);
        char guess[100];
        printf("请输入一个字母或整个单词:");
        scanf("%s", guess);
        if (strcmp(guess, secret_word) == 0) {
            guessed_word_correctly = 1;
            break;
        }
        int guess_length = strlen(guess);
        if (guess_length == 1) {
            char guessed_letter = guess[0];
            if (strchr(secret_word, guessed_letter) != NULL) {
                update_clue(guessed_letter, secret_word, clue);
            } else {
                printf("你猜错了，再试一次吧！\n");
                printf("您还有%d条命\n", lives - 1);
                lives = lives - 1;
            }
        } else {
            printf("你猜错了，再试一次吧！\n");
            printf("您还有%d条命\n", lives - 1);
            lives = lives - 1;
        }
    }

    if (guessed_word_correctly) {
        printf("You win\n");
    } else {
        printf("You Choice\n");
    }

    free(clue);

    return 0;
}
