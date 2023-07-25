#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <algorithm>
#endif

#ifndef STRING_H
#define STRING_H
#include <string>
#endif

#ifndef MATRIZ_2D_H
#define MATRIZ_2D_H

using namespace std;

template <class T>
class Matriz2D
{
private:
    bool DEBUGGIN_MODE = true;
    size_t ROWS;        // Numero de Filas en la matriz
    size_t COLS;        // NUmero de Columnas en la matriz
    T **matrix;
public:
    Matriz2D( size_t ROWS, size_t COLS);
    ~Matriz2D();

    bool setXY(T value, size_t COL, size_t ROW);
    T* getXY(size_t ROW, size_t COL);

    size_t getNumRows() const{ return this->ROWS; }
    size_t getNumCols() const{ return this->COLS; }

    bool esSimetricaConCorteVertical();
    bool esSimetricaConCorteHorizontal();
    bool esSimetricaConCorteDiagonalIzq();
    bool esSimetricaConCorteDiagonalDer();

    // Metodos Para Matrices algebraicas
    bool esSimetrica();
    bool esMatrizTriangularSuperior();
    bool esMatrizTriangularInferior();
    bool esMatrizDiagonal();
    bool esMatrizDeIdentidad();
    bool esMatrizConBanda();
    bool esMatrizCuadrada();

    void print();
    Matriz2D<T> operator+(const Matriz2D<T> &b) const;
    void reflect_x();
};

/**
 * ===============================================================================================
 * @brief Matriz2D::Matriz2D
 * En este contructor se le pasa como parametro el numero de filas y  el numero  de columnas de la
 * matriz,  al  momento  de entrar en  el  constructor  separa  espacio de memoria para crear  una
 * matriz de N filas por M columnas. Debido a que la memoria se crea de manera dinamica, cuando se
 * inicializa con este constructor los datos en la matriz contendran basura.
 *
 * @param ROWS
 * El numero de filas que tendra la matrix bidimensional.
 *
 * @param COLS
 * El numero de columnas que tendra la matrix bidimensional.
 */
template <class T>
Matriz2D<T>::Matriz2D(size_t ROWS, size_t COLS)
{
    this->ROWS  = ROWS;
    this->COLS  = COLS;

    this->matrix = new T*[ROWS];

    for(size_t i=0; i < ROWS; i++)
    {
        this->matrix[i] = new T[COLS];
    }
}

/**
 * ===============================================================================================
 * @brief Matriz2D::~Matriz2D
 * En este metodo se libera toda  la  memoria  que es apartada de manera dinamica por la clase, no
 * es necesario llamarlo ya que se hace de manera implicita.
 */
template <class T>
Matriz2D<T>::~Matriz2D()
{
    for(size_t i = 0; i < this->ROWS; i++)
    {
        delete[] this->matrix[i];                   // Borramos las columnas de la matriz
    }
    delete[] this->matrix;                          // Borramos las filas de la matriz
}

/**
 * ===============================================================================================
 * @brief Matriz2D::setXY
 * Recordar que una matriz es una tabla, un arreglo bidimensional. Por lo tanto se decidio agregar
 * este metodo para acceder a los datos de la matriz de forma sencilla como si fuera un mapa en un
 * plano cartesiano.
 *
 * @param value
 * el tipo de dato que almacena (un objeto de class T).
 *
 * @param COL
 *
 *
 * @param ROW
 *
 *
 * @return T
 */
template <class T>
bool Matriz2D<T>::setXY( T value, size_t COL, size_t ROW)
{
    // Validamos los limites del array en x (columnas)
    if( COL < 0 || COL >= this->COLS)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[FAIL] Intentaste acceder a una posicion mas alla de (X) en la matriz actual."
                 << "Recuerda que Empieza en 0 y termina en " << (this->COLS-1) << endl;
        return false;
    }

    // Validamos los limites del array en y (filas)
    if( ROWS < 0 && ROWS >= this->ROWS)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[FAIL] Intentaste acceder a una posicion mas alla de (Y) en la matriz actual."
                 << "Recuerda que Empieza en 0 y termina en " << (this->ROWS-1) << endl;
        return false;
    }

    this->matrix[COL][ROW] = value;
    return true;
}

/**
 * ===============================================================================================
 * @brief Matriz2D::getXY
 * @param ROW
 * @param COL
 * @return
 */
template <class T>
T* Matriz2D<T>::getXY( size_t COL, size_t ROW)
{
    // Validamos los limites del array en x (columnas)
    if( COL < 0 && COL >= this->COLS)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[FAIL] Intentaste acceder a una posicion mas alla de (X) en la matriz actual."
                 << "Recuerda que Empieza en 0 y termina en " << (this->COLS-1) << endl;
        return nullptr;
    }

    // Validamos los limites del array en y (filas)
    if( ROWS < 0 && ROWS >= this->ROWS)
    {
        if(this->DEBUGGIN_MODE)
            cout << "[FAIL] Intentaste acceder a una posicion mas alla de (Y) en la matriz actual."
                 << "Recuerda que Empieza en 0 y termina en " << (this->ROWS-1) << endl;
        return false;
    }

    return this->matrix[COL][ROW];
}

/**
 * ===============================================================================================
 * @brief Matriz2D::print
 */
template <class T>
void Matriz2D<T>::print()
{
    for(size_t ROW = 0; ROW < this->ROWS; ROW++)
    {
        for(size_t COL = 0; COL < this->COLS; COL++)
        {
            cout << this->matrix[ROW][COL] << " ";
        }
        cout << "\n";
    }
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esSimetricaConCorteVertical
 * @return
 */
template <class T>
bool Matriz2D<T>::esSimetricaConCorteVertical()
{
 //PENDIENTE
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esSimetricaConCorteHorizontal
 * @return
 */
template <class T>
bool Matriz2D<T>::esSimetricaConCorteHorizontal()
{
     //PENDIENTE
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esSimetricaConCorteDiagonalIzq
 * @return
 */
template <class T>
bool Matriz2D<T>::esSimetricaConCorteDiagonalIzq()
{
 //PENDIENTE
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esSimetricaConCorteDiagonalDer
 * @return
 */
template <class T>
bool Matriz2D<T>::esSimetricaConCorteDiagonalDer()
{
 //PENDIENTE
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esSimetrica
 * En algebra, una matriz simetrica es toda aquella donde sus indices xy = yx. Ademas la matriz
 * debe de ser cuadrada.
 *
 * @return
 */
template <class T>
bool Matriz2D<T>::esSimetrica()
{
    if( this->esMatrizCuadrada() )
    {
        for(size_t ROW = 0; ROW < this->ROWS; ROW++ )
        {
            for(size_t COL = 0; COL < this->COLS; COL++ )
            {
                if( this->matrix[COL][ROW] != this->matrix[ROW][COL] )
                    return false;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esMatrizTriangularSuperior
 * En algebra, una matriz triangular superior es aquella donde todos los elementos por debajo de
 * la diagonal principal son cero.
 *
 * @return
 */
template <class T>
bool Matriz2D<T>::esMatrizTriangularSuperior()
{
    if( this->esMatrizCuadrada() )
    {
        // Recorremos la diagonal principal
        for(size_t COL = 0; COL < this->COLS; COL++ )
        {
            for(size_t ROW = (COL+1); ROW < this->ROWS; ROW++ )
            {
                if( this->matrix[ROW][COL] != 0 )
                    return false;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esMatrizTriangularInferior
 * Una matriz triangular inferior es aquella donde todos los elementos por arriba de la diagonal
 * principal son cero.
 *
 * @return
 */
template <class T>
bool Matriz2D<T>::esMatrizTriangularInferior()
{
    if( this->esMatrizCuadrada() )
    {
        // Recorremos la diagonal principal
        for(size_t COL = 0; COL < this->COLS; COL++ )
        {
            for(size_t ROW = (COL+1); ROW < this->ROWS; ROW++ )
            {
                if( this->matrix[COL][ROW] != 0 )
                    return false;
            }
        }
    }
    else
    {
        return false;
    }

    return true;
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esMatrizDiagonal
 * Una matriz diagonal es una matriz cuadrada donde todos los elementos fuera de la diagonal
 * principal son iguales a cero.
 * @return
 */
template <class T>
bool Matriz2D<T>::esMatrizDiagonal()
{
    if(
            this->esMatrizCuadrada() &&
            this->esMatrizTriangularInferior() &&
            this->esMatrizTriangularSuperior()
      )
        return true;
    else
        return false;
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esMatrizDeIdentidad
 * Una matriz identidad es una matriz diagonal donde todos los elementos sobre la diagonal
 * principal son iguales a 1.
 * @return
 */
template <class T>
bool Matriz2D<T>::esMatrizDeIdentidad()
{
    if( this->esMatrizCuadrada())
    {
        for(size_t i = 0; i < this->COLS; i++)
        {
            if( this->matrix[i][i] != 1 )
                return false;
        }
    }
    else
    {
        return false;
    }

    return true;
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esMatrizConBanda
 * Una matriz a bandas tiene todos los elementos iguales a cero, con la excepción de una banda
 * centrada sobre la diagonal principal:
 * @return
 */
template <class T>
bool Matriz2D<T>::esMatrizConBanda()
{
    //PENDIENTE
}

/**
 * ===============================================================================================
 * @brief Matriz2D::esMatrizCuadrada
 * En algebra, la matriz cuadrada es aquella que tiene el mismo numero de filas y columnas.
 *
 * @return
 * true si la matriz es cuadrada y false en caso de que no sea cuadrada.
 */
template <class T>
bool Matriz2D<T>::esMatrizCuadrada()
{
    if( this->ROWS == this->COLS)
        return true;
    else
        return false;
}


//PENDIENTE VERIFICAR
template <class T>
Matriz2D<T> Matriz2D<T>::operator+(const Matriz2D<T> &b) const
{
    // CREAMOS UNA NUEVA MATRIX QUE VA A GUARDAR EL RESULTADO
    Matriz2D<T> r( this->ROWS, this->COLS);

    for(int ROW = 1; ROW <= this->ROWS; ROW++)
    {
        for(int COL = 1; COL <= this->COLS; COL++)
        {
            T a_xy;
            T b_xy;

            // INTENTAMOS LEER EL VALOR XY DE LA MATRIZ 1
            try {
                a_xy = this->getYX(ROW, COL);
            } catch (...)
            {

            }

            // INTENTAMOS LEER EL VALOR XY DE LA MATRIZ 2
            try {
                b_xy = b.getYX(ROW, COL);
            } catch (...) {

            }
            //cout << a_xy << " + " << b_xy << endl;

            r.setYX(a_xy + b_xy, ROW, COL);
        }
    }
    return r;
}

template <class T>
void Matriz2D<T>::reflect_x()
{
    T tmp_value;

    for(size_t ROW = 0; ROW < this->ROWS; ROW++)
    {
        for(size_t COL = 0; COL < this->COLS / 2; COL++)
        {
            tmp_value = this->matrix[ROW][COL];
            this->matrix[ROW][COL] = this->matrix[ROW][this->COLS - 1 - COL];
            this->matrix[ROW][this->COLS - 1 - COL] = tmp_value;
        }
    }
}
#endif // MATRIZ_2D_H
