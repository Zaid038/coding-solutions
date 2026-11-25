/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int m = matSize;           // original rows
    int n = matColSize[0];     // original columns

    // If total elements don't match, return the original matrix
    if (m * n != r * c) {
        *returnSize = m;
        *returnColumnSizes = matColSize;
        return mat;
    }

    // Allocate the new reshaped matrix
    int** result = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    *returnSize = r;

    for (int i = 0; i < r; i++) {
        result[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    // Fill the new matrix by mapping 1D indices
    for (int i = 0; i < m * n; i++) {
        // i / n and i % n give the position in the original matrix
        // i / c and i % c give the position in the new matrix
        result[i / c][i % c] = mat[i / n][i % n];
    }

    return result;
}