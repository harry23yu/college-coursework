#include "multdiv.h"

int main() {
    //do something here wih array
    int numRows, numColumns, matrix;
    cout << "Enter number of rows for multiplication and division tables: ";
    cin >> numRows;
    cout << "Enter number of columns for multiplication and division tables: ";
    cin >> numColumns;
    cout << endl;
    Multdiv_entry** array = create_array(numRows, numColumns);
    print_array(array, numRows, numColumns);
    delete_array(array, numRows);
    cout << "Would you like to see a different size matrix? Type '1' if you want to. ";
    cin >> matrix;
    if (matrix == 1) {
        main();
    }
    cout << endl;
    return 0;
}