#include <stdio.h>
#include <string.h>

// Функція для обчислення факторіала числа
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Функція для обчислення кількості можливих анаграм для слова
int countAnagrams(const char* word) {
    int len = strlen(word);
    int count[26] = {0}; // Масив для збереження кількості кожної букви

    // Рахуємо кількість кожної букви в слові
    for (int i = 0; i < len; i++) {
        count[word[i] - 'A']++;
    }

    // Обчислюємо кількість можливих анаграм за допомогою формули n!
    int anagrams = factorial(len);

    // Ділимо загальну кількість анаграм на факторіал кількості кожної букви
    for (int i = 0; i < 26; i++) {
        if (count[i] > 1) {
            anagrams /= factorial(count[i]);
        }
    }

    return anagrams;
}

int main() {
    char word[15];
    printf("Введіть слово: ");
    scanf("%s", word);

    int result = countAnagrams(word);
    printf("Кількість можливих анаграм: %d\n", result);

    return 0;
}
