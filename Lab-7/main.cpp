
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Matrix {
public:
    int matrix_size;
    double** matrix_data;

    Matrix(int size = 0) : matrix_size(size) {
        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
        }
    }

    Matrix& operator=(const Matrix& other) {
        if (this == &other) {
            return *this;
        }

        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;

        matrix_size = other.matrix_size;

        matrix_data = new double*[matrix_size];
        for (int i = 0; i < matrix_size; ++i) {
            matrix_data[i] = new double[matrix_size];
            for (int j = 0; j < matrix_size; ++j) {
                matrix_data[i][j] = other.matrix_data[i][j];
            }
        }

        return *this;
    }

    ~Matrix() {
        for (int i = 0; i < matrix_size; ++i) {
            delete[] matrix_data[i];
        }
        delete[] matrix_data;
    }
};

void read_matrix_from_file(const string& file_name, Matrix& matrix_1, Matrix& matrix_2) {
    // TODO: Read matrix data from the file
    //    Make sure to handle potential errors and invalid input

	ifstream inputFile(file_name);

	int matrixSize;
	try {
        inputFile >> matrixSize;
	} catch (exception e) {
		cout << endl << "Invalid input, quitting";
		exit(1);
	}
	matrix_1 = Matrix(matrixSize); // make matricies
	matrix_2 = Matrix(matrixSize);

	// TODO: Read matrix data from cin into matrix_1 and matrix_2
	//       Make sure to handle potential errors and invalid input
	
	//read file
	for (int row = 0; row < matrixSize * 2; ++row) {
		for (int col = 0; col < matrixSize; ++col) {
			double cellData;
			try {
				inputFile >> cellData;
			} catch (exception e) {
				cout << endl << "Invalid input, quitting";
				exit(1);
			}
			if (row < matrixSize) { //matrix 1
				matrix_1.matrix_data[row][col] = cellData;
			} else { //matrix 2
				matrix_2.matrix_data[row % matrixSize][col] = cellData;
			}
		}
	}
}

void print_matrix(const Matrix& matrix) {
    // TODO: Print the matrix to the console
	for (int row = 0; row < matrix.matrix_size; row++) {
		for (int col = 0; col < matrix.matrix_size; col++) {
			cout << matrix.matrix_data[row][col] << "\t";
		}
    cout << endl;
  }
  cout << endl;
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) {
    print_matrix(matrix_1);
	print_matrix(matrix_2);
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    int size = matrix_1.matrix_size;
    Matrix newMatrix = Matrix(size);
    for (int row = 0; row < size; ++row) {
        for (int col = 0; col < size; ++col) {
            newMatrix.matrix_data[row][col] = matrix_1.matrix_data[row][col] + matrix_2.matrix_data[row][col];
        }
    }
    return newMatrix;
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) {
    int size = matrix_1.matrix_size;
    Matrix newMatrix = Matrix(size);
    for (int row = 0; row < size; row++) { //for each row
        for (int col = 0; col < size; col++) { //for each column
            double resultForTile = 0;
            for (int item = 0; item < size; item++) { // add products into tile in out
                resultForTile += matrix_1.matrix_data[row][item] * matrix_2.matrix_data[item][col]; // add this product to the tile result
            }
            newMatrix.matrix_data[row][col] = resultForTile; // set the out tile to the tile result
        }
    }
    return newMatrix;
}

// Overloaded + operator for matrix addition
Matrix operator+(const Matrix& matrix_1, const Matrix& matrix_2) {
    return add_matrices(matrix_1, matrix_2);
}

// Overloaded * operator for matrix multiplication
Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2) {
    return multiply_matrices(matrix_1, matrix_2);
}

/*
void get_diagonal_sum(const Matrix& matrix) {
    // TODO: Calculate and print the sum of the diagonal elements
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    // TODO: Swap the rows 'row1' and 'row2' in the matrix
    //    Handle invalid row indices
}
*/

int main(int argc, char* argv[]) {
    Matrix matrix_1, matrix_2;
    read_matrix_from_file("matrix.txt", matrix_1, matrix_2);

    cout << "print_matrix" << endl;
    print_matrix(matrix_1, matrix_2);


    cout << "add_matrices result:" << endl;
    Matrix add_result_1 = add_matrices(matrix_1, matrix_2);
    print_matrix(add_result_1);
    Matrix add_result_2 = matrix_1 + matrix_2;
    print_matrix(add_result_2);

    cout << "multiply_matrices result:" << endl;
    Matrix multiply_result_1 = multiply_matrices(matrix_1, matrix_2);
    print_matrix(multiply_result_1);
    Matrix multiply_result_2 = matrix_1 * matrix_2;
    print_matrix(multiply_result_2);

    /*
    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1);

    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, 0, 1);
	*/

    return 0;
}