
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;

int T[50];

void remplir() {
    srand(time(NULL));
    FILE *file = fopen("fileex02", "w"); 
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    for (int i = 0; i < 50; i++) {
        T[i] = rand() % 200;
        fprintf(file, "%d\n", T[i]); 
    }

    fclose(file); 
}

bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void* test() {
    pthread_mutex_lock(&my_mutex);
    for (int i = 0; i < 50; i++) {
        if (is_prime(T[i])) {
            printf("%d est premier\n", T[i]);
        } else {
            printf("%d n'est pas premier\n", T[i]);
        }
    }
    pthread_mutex_unlock(&my_mutex);
    return NULL;
}

int main() {
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, (void*)remplir, NULL);
    pthread_create(&thread2, NULL, test, NULL);
    pthread_join(thread2, NULL);
    pthread_create(&thread3, NULL, test, NULL);
    pthread_join(thread3, NULL);
    return 0;
}
