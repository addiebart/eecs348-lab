
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
	try { // check that value is an int
        inputFile >> matrixSize;
	} catch (exception e) {
		cout << endl << "Invalid input, quitting";
		exit(1);
	}
	matrix_1 = Matrix(matrixSize); // make matricies
	matrix_2 = Matrix(matrixSize);
	
	//read file
	for (int row = 0; row < matrixSize * 2; ++row) {
		for (int col = 0; col < matrixSize; ++col) {
			double cellData;
			try { // ensure value is a double
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

void print_matrix(const Matrix& matrix) { // print one matrix
	for (int row = 0; row < matrix.matrix_size; row++) {
		for (int col = 0; col < matrix.matrix_size; col++) {
			cout << matrix.matrix_data[row][col] << "\t"; // print every entry followed by a tab
		}
    cout << endl; // print a newline after each row
  }
  cout << endl; // print a newline after the matrix
}

void print_matrix(const Matrix& matrix_1, const Matrix& matrix_2) { //print two matricies
    print_matrix(matrix_1);
	print_matrix(matrix_2);
}

Matrix add_matrices(const Matrix& matrix_1, const Matrix& matrix_2) { //add two matricies
    int size = matrix_1.matrix_size;
    Matrix newMatrix = Matrix(size);
    for (int row = 0; row < size; ++row) { //new[i,j] = old1[i,j] + old2[i,j]
        for (int col = 0; col < size; ++col) {
            newMatrix.matrix_data[row][col] = matrix_1.matrix_data[row][col] + matrix_2.matrix_data[row][col];
        }
    }
    return newMatrix;
}

Matrix multiply_matrices(const Matrix& matrix_1, const Matrix& matrix_2) { // multiply two matricies
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

void get_diagonal_sum(const Matrix& matrix) { // add on diagionals and print sums
    int size = matrix.matrix_size; // define variables
    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < size; i++) {
        sum1 += matrix.matrix_data[i][i];
        sum2 += matrix.matrix_data[(size - 1) - i][i]; // rows for sum2 mirror row1 while cols are the same
    }
    cout << "top-left -> bottom-right sum: " << sum1 << endl; //print
    cout << "bottom-left -> top-right sum: " << sum2 << endl;
}

void swap_matrix_row(Matrix& matrix, int row1, int row2) {
    int size = matrix.matrix_size;
    if (row1 >= size || row2 >= size) { //check for valid row indicies
        cout << endl << "One of the provided indicies is out of range, quitting";
        exit(1);
    }
    double *data1 = matrix.matrix_data[row1]; // arrays are pointers, shuffle them around.
    matrix.matrix_data[row1] = matrix.matrix_data[row2];
    matrix.matrix_data[row2] = data1;
    print_matrix(matrix); //print
}

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

    cout << "get matrix diagonal sum" << endl;
    get_diagonal_sum(matrix_1);
    cout << endl;

    cout << "swap matrix rows" << endl;
    swap_matrix_row(matrix_1, 0, 1);

    return 0;
}