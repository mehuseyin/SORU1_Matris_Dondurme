#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20
#define MAX_ATTEMPTS 5

#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RESET   "\033[0m"

//kelime dosyasının tanımlanması ve rastgele kelimenin seçilmesi
char* select_random_word(const char* filename) {
    static char words[MAX_WORDS][MAX_WORD_LENGTH];
    int word_count = 0;

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Dosya acilamadi");
        exit(1);
    }

    while (fgets(words[word_count], MAX_WORD_LENGTH, file)) {
        words[word_count][strcspn(words[word_count], "\n")] = '\0'; 
        word_count++;
        if (word_count >= MAX_WORDS) break;
    }

    fclose(file);

    srand(time(NULL));
    int random_index = rand() % word_count;

    return words[random_index];
}

// 
void evaluate_guess(const char* guess, const char* secret) {
    int secret_len = strlen(secret);
    int guess_len = strlen(guess);
    int matched[secret_len]; // 

    memset(matched, 0, sizeof(matched));

    // yeri doğru harflerin belirtilmesi
    for (int i = 0; i < secret_len; i++) {
        if (i < guess_len && guess[i] == secret[i]) {
            printf(GREEN "%c" RESET, guess[i]);
            matched[i] = 1; 
        } else {
            printf("_");
        }
    }
    printf("\n");

    // kelime içinde olan harflerin belirtilmesi
    for (int i = 0; i < guess_len; i++) {
        if (guess[i] != secret[i]) {
            for (int j = 0; j < secret_len; j++) {
                if (guess[i] == secret[j] && !matched[j]) {
                    printf(YELLOW "%c" RESET, guess[i]);
                    matched[j] = 1;
                    break;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    const char* filename = "wordlistTR1.txt";
    char* secret_word = select_random_word(filename);
    int secret_len = strlen(secret_word);
    char guess[MAX_WORD_LENGTH];

    printf("Gizli kelime secildi! Tahmin etmek icin %d harfli bir kelime girin.\n", secret_len);
    printf("Toplam %d deneme hakkiniz var.\n", MAX_ATTEMPTS);

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++) {
        printf("(%d/%d) Tahmininizi girin: ", attempt, MAX_ATTEMPTS);
        fgets(guess, sizeof(guess), stdin);
        guess[strcspn(guess, "\n")] = '\0'; 

        if (strlen(guess) != secret_len) {
            printf("Lutfen %d harfli bir kelime girin!\n", secret_len);
            attempt--;
            continue;
        }

        evaluate_guess(guess, secret_word);

        if (strcmp(guess, secret_word) == 0) {
            printf(GREEN "Tebrikler! Dogru bildiniz: %s\n" RESET, secret_word);
            return 0;
        }
    }

    printf("Maalesef bilemediniz. Dogru kelime: %s\n", secret_word);
    return 0;
}
