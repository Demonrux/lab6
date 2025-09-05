#include <stdio.h>
#include <stdlib.h>
#define CORRECT_ARR_MATRIX 2
#define MIN_ARR_MATRIX 0

typedef enum {
    CORRECT_INPUT,
    INCORRECT_INPUT,
} InputStatus;

InputStatus inputArrMatrix(int* n, int* m);
InputStatus inputMatrix(int** mat, int n, int m);
int** memoryAllocation(int n, int m);
void findSumElem(int** mat, int n, int m);
void transform(int** mat, int* vec, int n, int m);
void memoryClear(int** mat);
void outputMatrix(int** mat, int n, int m);

int main()
{
    int n, m;
    InputStatus inputStatus = inputArrMatrix(&n, &m);
    if (inputStatus == INCORRECT_INPUT)
        printf("Incorrect input");
    else {
        int** mat = memoryAllocation(n, m);
        if (mat == NULL)
            inputStatus = INCORRECT_INPUT;
        else {
            inputStatus = inputMatrix(mat, n, m);
            if (inputStatus == CORRECT_INPUT) {
                findSumElem(mat, n, m);
                outputMatrix(mat, n, m);
            }
        }
        memoryClear(mat);
    }
    return inputStatus;
}

InputStatus inputArrMatrix(int* n, int* m) {
    InputStatus inputStatus;
    if (scanf("%d%d", n , m) != CORRECT_ARR_MATRIX || ((*n < MIN_ARR_MATRIX) || (*m < MIN_ARR_MATRIX)))
        inputStatus = INCORRECT_INPUT;
    else
        inputStatus = CORRECT_INPUT;
    return inputStatus;
}

InputStatus inputMatrix(int** mat, int n, int m) {
    InputStatus inputStatus = CORRECT_INPUT;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j++) {
            if( !(scanf("%d", *(mat + i) + j ))) {
                inputStatus = INCORRECT_INPUT;
                break;
            }
        }
    }
    return inputStatus;
}

void transform(int** mat, int* vec, int n, int m) {
    for(int i = 0; i < n; i++) {
        mat[i] = vec + m * i;
    }
}

int** memoryAllocation(int n, int m) {
    int** mat = (int**)calloc(n, sizeof(int*));
    int* vec = (int*)calloc(m * n, sizeof(int));
    transform(mat, vec, n, m);
    return mat;
}

void findSumElem(int** mat, int n, int m) {
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++) {
            if (i + j >=  m)
                sum += mat[i][j];
        }
    }
    if(n > 1 && m > 1)
        **mat = sum;
}

void memoryClear(int** mat) {
    free(*mat);
    free(mat);
}

void outputMatrix(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}
