// a linear space 2 row Levenshtein distance (or edit distance) calculator

void edit_distance(int n, int m, const char *a, const char *b, int &d)
{
    if(m == 0) {
        d = n;
        return;
    }

    int* higher = new int[n+1];
    int* lower = new int[n+1];
    int i = 0;
    while(i <= n) {
        higher[i] = i;
        i++;
    }
    int first_row_first_col = 1;
    int row = 1;
    while(row <= m){
        lower[0] = first_row_first_col;
        int column = 1;
        while(column <= n){
            if(a[column-1] == b[row-1]) {
                lower[column] = higher[column-1];
            }
            else {
                lower[column] = 1 + std::min(lower[column-1], std::min(higher[column-1], higher[column]));
            }
            column++;
        }
        row++;
        first_row_first_col++;
        for(int i=0; i <= n; i++){
            higher[i] = lower[i];
        }
    }

    d = lower[n];
    delete[] higher;
    delete[] lower;

}