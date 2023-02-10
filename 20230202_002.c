#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMES 20
#define MAX_NOME_TAM 120

void printlista(char nomes[MAX_NOMES][MAX_NOME_TAM], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, nomes[i]);
    }
}

void deletarNome(char nomes[MAX_NOMES][MAX_NOME_TAM], int *count, int index) {
    for (int i = index; i < (*count) - 1; i++) {
        strcpy(nomes[i], nomes[i + 1]);
    }
    (*count)--;
}

int comparenomes(const void *a, const void *b) {
    const char *nameA = *(const char **)a;
    const char *nameB = *(const char **)b;
    return strcmp(nameA, nameB);
}

void classificarLista(char nomes[MAX_NOMES][MAX_NOME_TAM], int count) {
    qsort(nomes, count, sizeof(char[MAX_NOME_TAM]), comparenomes);
}

void copiarLista(char nomes[MAX_NOMES][MAX_NOME_TAM], char sortednomes[MAX_NOMES][MAX_NOME_TAM], int count) {
    for (int i = 0; i < count; i++) {
        strcpy(sortednomes[i], nomes[i]);
    }
}

int main() {
    char nomes[MAX_NOMES][MAX_NOME_TAM];
    int count = 0;

    
    while (count < MAX_NOMES) {
        printf("Digite o nome %d (ou pressione enter para parar): ", count + 1);
        fgets(nomes[count], MAX_NOME_TAM, stdin);

        
        nomes[count][strlen(nomes[count]) - 1] = '\0';

        if (strlen(nomes[count]) == 0) {
            break;
        }

        count++;
    }
    printf("\nA lista de nomes:\n");
    printlista(nomes, count);

    int index;
    printf("\nInsira o indice do nome a ser excluido: ");
    scanf("%d", &index);
    deletarNome(nomes, &count, index - 1);

    printf("\nA lista atualizada de nomes:\n");
    printlista(nomes, count);

    classificarLista(nomes, count);

    printf("\nA lista ordenada de nomes:\n");
    printlista(nomes, count);

    char sortednomes[MAX_NOMES][MAX_NOME_TAM];
    copiarLista(nomes, sortednomes, count);

    printf("\nA lista copiada de nomes:\n");
    printlista(sortednomes,count);
     return 0;
}
