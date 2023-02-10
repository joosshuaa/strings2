#include <stdio.h>
#include <string.h>

#define NUM_EQUIPES 5
#define NUM_ALUNOS 4
#define TAM_NOME 20

struct aluno {
    char primeiroNome[TAM_NOME];
    char ultimoNome[TAM_NOME];
};

struct equipe {
    struct aluno membros[NUM_ALUNOS];
};

int encontrarAluno(struct equipe equipes[], int numEquipes, char primeiroNome[], char ultimoNome[]) {
    int indiceEquipe = -1;
    int indiceAluno;
    for (int i = 0; i < numEquipes; i++) {
        for (int j = 0; j < NUM_ALUNOS; j++) {
            if (strcmp(equipes[i].membros[j].primeiroNome, primeiroNome) == 0 && 
                strcmp(equipes[i].membros[j].ultimoNome, ultimoNome) == 0) {
                indiceEquipe = i;
                indiceAluno = j;
                break;
            }
        }
    }

    return indiceEquipe;
}
int main() {
    struct equipe equipes[NUM_EQUIPES];
    char primeiroNome[TAM_NOME];
    char ultimoNome[TAM_NOME];

    // entrada de equipes e integrantes
    for (int i = 0; i < NUM_EQUIPES; i++) {
        for (int j = 0; j < NUM_ALUNOS; j++) {
            printf("Digite o primeiro nome do aluno %d na equipe %d: ", j + 1, i + 1);
            scanf("%s", equipes[i].membros[j].primeiroNome);
            printf("Digite o ultimo nome do aluno %d na equipe %d: ", j + 1, i + 1);
            scanf("%s", equipes[i].membros[j].ultimoNome);
        }
    }

// entrada do nome do aluno
    printf("Digite o primeiro nome do aluno: ");
    scanf("%s", primeiroNome);
    printf("Digite o ultimo nome do aluno: ");
    scanf("%s", ultimoNome);

    int indiceEquipe = encontrarAluno(equipes, NUM_EQUIPES, primeiroNome, ultimoNome);
    if (indiceEquipe == -1) {
    printf("Aluno nao encontrado\n");
    } else {
    printf("O aluno esta na equipe %d\n", indiceEquipe + 1);
    }

    return 0;
}
