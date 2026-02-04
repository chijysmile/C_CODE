#define _CRT_SECURE_NO_WARNINGS
int minPathSum(int** grid, int gridSize, int* gridColSize) {
    for (int i = gridSize - 1; i >= 0; --i)
    {
        for (int j = gridColSize[i] - 1; j >= 0; --j)
        {
            if (i + 1 < gridSize && j + 1 < gridColSize[i])
            {
                grid[i][j] = grid[i][j] + fmin(grid[i + 1][j], grid[i][j + 1]);
            }
            else if (i + 1 < gridSize && j + 1 >= gridColSize[i])
            {
                grid[i][j] = grid[i][j] + grid[i + 1][j];
            }
            else if (i + 1 >= gridSize && j + 1 < gridColSize[i])
            {
                grid[i][j] = grid[i][j] + grid[i][j + 1];
            }
        }
    }

    return grid[0][0];
}

