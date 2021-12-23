#include <iostream>
#include <iomanip>

using namespace std;

double** createMatrix(int, int);
void initMatrix(double**, int, int);
void outputMatrix(double**, int, int);
void deleteMatrix(double**, int);
int searchMaxMin(double**, int, int&, int, int);
void changeMaxMin(double**, double**, double** , int, int, int, int);

int main()
{
    srand(time(NULL));
    double** matrixC, ** matrixB, ** matrixY, ** matrixZ;
    // ініціалізація матриць згідно з варіантом
    int rows, columns;
    cout << "Enter a number of rows: "; cin >> rows;
    cout << "Enter a number of columns: "; cin >> columns;
    // задання розмірності матриць

    matrixY = createMatrix(rows, columns);
    matrixZ = createMatrix(rows, columns);
    // створення динамічних матриць

    cout << "Matirx C is: \n";
    matrixC = createMatrix(rows, columns);
    initMatrix(matrixC, rows, columns);
    outputMatrix(matrixC, rows, columns);
    
    cout << "Matirx B is: \n";
    matrixB = createMatrix(rows, columns);
    initMatrix(matrixB, rows, columns);
    outputMatrix(matrixB, rows, columns);
    // створення й ініціалізація динамічних матриць

    struct maxMin {
        int max, min;
    };
    maxMin matrix1, matrix2;
   // структури, які будуть зберігати інформацію про рядки в яких розміщуються найбілшьі і найманші елементи матриць

    matrix1.max = searchMaxMin(matrixC, 1, matrix1.min, rows, columns);
    printf_s("The max element of first matrix located in %d row\n", matrix1.max);
    printf_s("The min element of first matrix located in %d row\n", matrix1.min);

    matrix2.max = searchMaxMin(matrixB, 1, matrix2.min, rows, columns);
    printf_s("The max element of second matrix located in %d row\n", matrix2.max);
    printf_s("The min element of second matrix located in %d row\n\n", matrix2.min);
    // пошук рядків з найбільшим і найменшим елементами матриці

    changeMaxMin(matrixC, matrixB, matrixY, matrix1.max, matrix2.max, rows, columns);
    // утворення матриці Y за допомогою зміни рядків з найбільшим значенням
    changeMaxMin(matrixY, matrixB, matrixY, matrix1.min, matrix2.min, rows, columns);
    // зміна рядків з найменшим значенням в матриці Y
    cout << "Matirx Y is: \n";
    outputMatrix(matrixY, rows, columns);
    
    changeMaxMin(matrixB, matrixC, matrixZ, matrix2.max, matrix1.max, rows, columns);
    // утворення матриці Z за допомогою зміни рядків з найбільшим значенням
    changeMaxMin(matrixZ, matrixC, matrixZ, matrix2.min, matrix1.min, rows, columns);
    // зміна рядків з найменшим значенням в матриці Z
    cout << "Matirx Z is: \n";
    outputMatrix(matrixZ, rows, columns);

    deleteMatrix(matrixC, rows);
    deleteMatrix(matrixB, rows);
    deleteMatrix(matrixY, rows);
    deleteMatrix(matrixZ, rows);
    // видалення динамічних матриць
    return 0;
}

void changeMaxMin(double** matrix1, double** matrix2, double** matrix3, int matrix1Row, int matrix2Row, int rows, int columns)
// функція яка створює матрицю matrix3 на основі matrix1 і замніяє в ній задані рядки з matrix2
{
    for (int i = 0; i < rows; i++) {
    // перебір рядків в матриці
        if (i != matrix1Row - 1) {
        // умова, яка перевіряє чи вибраний нами рядок не містить макс/мін занчення
            for (int j = 0; j < columns; j++)
                matrix3[i][j] = matrix1[i][j];
        // якщо умова правильна, то ми переписуємо рядок з matrix1
        }
        else {
        // якщо умова неправильна, то ми переписуємо макс/мін рядок з matrix2
            for (int j = 0; j < columns; j++)
                matrix3[i][j] = matrix2[matrix2Row - 1][j];
        }
    }
}

int searchMaxMin(double** matrix, int numberRowMax, int& numberRowMin, int rows, int columns)
// функція, яка знаходить рядки в яких розміщуються макс/мін елемент
{
    double max = matrix[0][0];
    double min = matrix[0][0];
    numberRowMin = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] > max)
            {
                numberRowMax = i + 1;
                max = matrix[i][j];
            }
            else if (matrix[i][j] < min)
            {
                numberRowMin = i + 1;
                min = matrix[i][j];
            }
        }
    return numberRowMax;
}

void deleteMatrix(double** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
}

void initMatrix(double** matrix, int rows, int columns)
// заповнення мартиці дійсними дісними числами
{
    int upLim = 9, dnLim = -9;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            matrix[i][j] = (double)(rand() % (upLim * 100 - dnLim * 100 + 1) + dnLim * 100) / 100;
}

double** createMatrix(int rows, int columns)
// створення динамічної матриці
{
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new double[columns];
    return matrix;
}

void outputMatrix(double** matrix, int rows, int columns)
// виведення матриці
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            cout << setw(6) << matrix[i][j];
        cout << endl;
    }
    cout << endl;
}