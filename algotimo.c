#include <stdio.h>

// Função para encontrar o maior elemento no array
int maiorElemento(int array[], int n) {
    int max = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}

// Função para realizar o Radix Sort
void radixSort(int array[], int n) {
    int maior = maiorElemento(array, n); // Encontra o maior elemento

    // Realiza a ordenação para cada dígito
    for (int exp = 1; maior / exp > 0; exp *= 10) {
        int output[n]; // Array de saída
        int count[10] = {0}; // Contagem dos dígitos

        // Conta a ocorrência de cada dígito
        for (int i = 0; i < n; i++)
            count[(array[i] / exp) % 10]++;
    
        // Ajusta a contagem para obter as posições corretas
        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Array de saída
        for (int i = n - 1; i >= 0; i--) {
            output[count[(array[i] / exp) % 10] - 1] = array[i];
            count[(array[i] / exp) % 10]--;
        }

        // Copia o array de saída para o array original
        for (int i = 0; i < n; i++)
            array[i] = output[i];

        // Imprime o array após cada etapa de ordenação
        printf("Array após a ordenação dos dígitos: ");
        for (int i = 0; i < n; i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}

// Função para imprimir o array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Exemplo de casos de teste
int main() {
    int array1[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    printf("Array original: ");
    printArray(array1, n1);
    radixSort(array1, n1);
    printf("Array ordenado: ");
    printArray(array1, n1);

    int array2[] = {321, 123, 543, 111, 222, 999, 888};
    int n2 = sizeof(array2) / sizeof(array2[0]);
    printf("Array original: ");
    printArray(array2, n2);
    radixSort(array2, n2);
    printf("Array ordenado: ");
    printArray(array2, n2);

    int array3[] = {10, 5, 15, 25, 20};
    int n3 = sizeof(array3) / sizeof(array3[0]);
    printf("Array original: ");
    printArray(array3, n3);
    radixSort(array3, n3);
    printf("Array ordenado: ");
    printArray(array3, n3);
    
    return 0;
}