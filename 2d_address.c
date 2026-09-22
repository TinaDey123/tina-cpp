#include <stdio.h>

int main()
{
    int choice;
    int base_address, element_size;
    int total_rows, total_cols;
    int lower_bound_row, lower_bound_col;
    int i, j, address;

    printf("2D Array Address Calculator\n");

    printf("1. Row Major Order\n");
    printf("2. Column Major Order\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("\nEnter base address: ");
    scanf("%d", &base_address);

    printf("Enter element size in bytes: ");
    scanf("%d", &element_size);

    printf("Enter total number of columns: ");
    scanf("%d", &total_cols);

    printf("Enter total number of rows: ");
    scanf("%d", &total_rows);

    printf("Enter lower bound of column: ");
    scanf("%d", &lower_bound_col);

    printf("Enter lower bound of row: ");
    scanf("%d", &lower_bound_row);

    printf("Enter target element row index: ");
    scanf("%d", &i);

    printf("Enter target element column index: ");
    scanf("%d", &j);

    switch (choice)
    {
        case 1:

            // Row Major Formula
            address = base_address +
                      element_size *
                      ((i - lower_bound_row) * total_cols
                      + (j - lower_bound_col));

             printf("\n[RESULT] Address of element at [%d][%d] "
                   "using Row Major Order is: %d\n",
                   i, j, address);

                    break;
        case 2:
            address = base_address +
                      element_size *
                      ((j - lower_bound_col) * total_rows
                      + (i - lower_bound_row));

              printf("\n[RESULT] Address of element at [%d][%d] "
                   "using Column Major Order is: %d\n",
                   i, j, address);

                    break;

        default:

            printf("\n[ERROR] Invalid choice selected!\n");

            return 0;
    }

    return 0;
}
          
