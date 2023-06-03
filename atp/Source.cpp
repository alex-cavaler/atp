#include <stdio.h>

void citesteMatriceAdiacenta(const char* numeFisier, int* n, int* m, int matrice[][100]) {
    FILE* f = fopen(numeFisier, "r");
    if (f == NULL) {
        printf("Nu s-a putut deschide fisierul!");
        return;
    }

    fscanf(f, "%d %d", n, m);

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            matrice[i][j] = 0;
        }
    }

    int x, y;
    for (int i = 0; i < *m; i++) {
        fscanf(f, "%d %d", &x, &y);
        matrice[x - 1][y - 1] = 1;
        matrice[y - 1][x - 1] = 1;
    }

    fclose(f);
}

void afiseazaMatriceAdiacenta(int n, int matrice[][100]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
}

void noduriGradNminus1(int n, int matrice[][100], int noduri[], int* k) {
    *k = 0;

    for (int i = 0; i < n; i++) {
        int grad = 0;
        for (int j = 0; j < n; j++) {
            if (matrice[i][j] == 1) {
                grad++;
            }
        }
        if (grad == n - 1) {
            noduri[(*k)++] = i + 1;
        }
    }
}

int main() {
    const char* numeFisier = "lista.txt";
    int n, m;
    int matrice[100][100];

    citesteMatriceAdiacenta(numeFisier, &n, &m, matrice);

    printf("Matricea de adiacenta:\n");
    afiseazaMatriceAdiacenta(n, matrice);

    int noduri[100];
    int k;
    noduriGradNminus1(n, matrice, noduri, &k);
    printf("Nodurile de grad n-1 sunt: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", noduri[i]);
    }
    printf("\n");

    return 0;
}
