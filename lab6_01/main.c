#include <stdio.h>
#include <stdlib.h>
#define CORRECT_ARR_MATRIX 1
#define MIN_ARR_MATRIX 0

typedef enum {
    CORRECT_INPUT,
    INCORRECT_INPUT,
} InputStatus;

InputStatus inputArrMatrix(int* n);
InputStatus inputMatrix(int** mat, int n);
int** memoryAllocation(int n);
void transposeMatrix(int** mat, int n);
void clearMemory(int **mat, int n);
void outputMatrix(int** mat, int n);

void swap(int* pa, int* pb);

int main() {
    int n;
    InputStatus inputStatus = inputArrMatrix(&n);
    if (inputStatus == INCORRECT_INPUT)
        printf("Incorrect input");
    else {
        int** mat = memoryAllocation(n);
        if (mat == NULL)
            inputStatus = INCORRECT_INPUT;
        else {
            inputStatus = inputMatrix(mat, n);
            if (inputStatus == CORRECT_INPUT) {
                transposeMatrix(mat, n);
                outputMatrix(mat, n);
            }
        }
        clearMemory(mat, n);
    }
    return inputStatus;
}

InputStatus inputArrMatrix(int* n) {
    InputStatus inputStatus;
    if (scanf("%d", n) != CORRECT_ARR_MATRIX || (*n < MIN_ARR_MATRIX))
        inputStatus = INCORRECT_INPUT;
    else
        inputStatus = CORRECT_INPUT;
    return inputStatus;
}

InputStatus inputMatrix(int** mat, int n) {
    InputStatus inputStatus = CORRECT_INPUT;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(!(scanf("%d", *(mat + i) + j))) {
                inputStatus = INCORRECT_INPUT;
                break;
            }
        }
    }
    return inputStatus;
}

int** memoryAllocation(int n) {
    int **mat = (int **) calloc(n ,sizeof(int*));
    for(int i = 0; i < n; i++)
    {
        if(mat != NULL)
            mat[i] = (int *) calloc(n, sizeof(int));
        else
            free(mat);
    }
    return mat;
}

void clearMemory(int **mat, int n) {
    for(int i = 0; i < n; ++ i)
    {
        free(mat[i]);
    }
    free(mat);
}

void swap(int* pa, int* pb) {
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void transposeMatrix(int** mat, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++) {
            int* pa = mat[i] + j;
            int* pb = mat[n - 1 - j] + n - 1 - i;
            swap(pa, pb);
        }
}

void outputMatrix(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        for ( int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
