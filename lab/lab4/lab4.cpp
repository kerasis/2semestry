//Реализуйте шаблонный класс для описания матриц(в частном случае, векторов).Предусмотрите 3 шаблонных параметра : тип элемента, размеры матрицы N и M(N, M <= 3)
//В составе класса должны быть :
//1.+	Конструктор копирования
//2.+	Оператор присваивания копированием
//3.+	Оператор ввода и вывода
//4.+	Операторы + , +=, *, *=
//5.+	Оператор++, который увеличивает все элементы матрицы на 1
//6.+	Метод вычисления определителя
//7.+	Метод или оператор для получения и изменения элемента матрицы по индексу


#include <iostream>
#include <algorithm>
#include <vector>

template<typename T, int N, int M>
class Matrix
{
public:
    T m_matrix[N][M];
    int m_n = N;
    int m_m = M;

    //public:
    Matrix() = default;

    ~Matrix() = default;

    Matrix(const Matrix& other) = default;

    Matrix& operator=(Matrix temp)
    {
        std::cout << " = " << '\n';
        std::swap(m_matrix, temp.m_matrix);
        std::swap(m_n, temp.m_n);
        std::swap(m_m, temp.m_m);
        return *this;
    }

    Matrix& operator+=(const Matrix& other)
    {
        std::cout << "+=" << '\n';
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                this->m_matrix[i][j] += other.m_matrix[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& other)
    {
        std::cout << "+" << '\n';
        Matrix<T, N, M> temp = *this;
        temp += other;
        return temp;
    }


    template<int M, int V>
    Matrix<T, N, M> operator*(const Matrix<T, M, V>& other)
    {
        Matrix<T, N, V> temp;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < V; j++)
            {
                temp.m_matrix[i][j] = 0;
                for (int k = 0; k < M; k++)
                {
                    temp.m_matrix[i][j] += (this->m_matrix[i][k] * other.m_matrix[k][j]);
                }
            }
        }
        return temp;
    }

  
    Matrix<T, N, M>& operator*=(const Matrix<T, N, M>& other)
    {
        if ((N == M))
        {
            Matrix<T, N, M> temp;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    temp.m_matrix[i][j] = 0;
                    for (int k = 0; k < N; k++)
                    {
                        temp.m_matrix[i][j] += (this->m_matrix[i][k] * other.m_matrix[k][j]);
                    }
                }
            }
            *this = temp;
        }
        else
        {
            std::cout << "incorrect matrix" << '\n';
            
        }
        return *this;
    }

    T determinant()
    {
        if (M == N)
        {
            if (M == 1) { return m_matrix[0][0]; }
            T d = 0;
            int perm[N];
            std::vector<std::vector<T>> comb;
            comb.push_back({});
            for (int i = 0; i < N; i++)
            {
                perm[i] = i;
                comb[0].push_back(i);
            }
            int ind = 1;
            while (std::next_permutation(perm, perm + N))
            {
                comb.push_back({});
                for (int i = 0; i < N; i++)
                {
                    comb[ind].push_back(perm[i]);

                }
                ind++;
            }
            //считаем чет/нечет подстановка
            for (int i = 0; i < size(comb); i++)
            {
                int inversions = 0;
                for (int j = 1; j < size(comb[i]); j++)
                {
                    for (int k = 0; k < j; k++)
                    {
                        if (comb[i][k] > comb[i][j]) { inversions += 1; }
                    }
                }

                //счиаем промежуточное значение, одно из слагаемых определителя, и взависимости от четности прибавляем/вычитаем из итогового значения определтеля
                T prom = 1;
                for (int x = 0; x < N; x++)
                {
                    prom *= m_matrix[x][comb[i][x]];
                }
                //std::cout << "prom " << prom << '\n';
                if (inversions % 2 == 0) { d += prom; }
                else { d -= prom; }
            }

            return d;

        }
        else
        {
            std::cout << "det doesn't exist" << '\n';
            return 0;
        }
    }

    Matrix<T, N, M>& operator++()
    {

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                m_matrix[i][j] += 1;
            }
        }
        return *this;
    }


    T& operator()(int ind1, int ind2)
    {
        return m_matrix[ind1][ind2];
    }

    template<typename T, int N, int M>
    friend std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& arr);
    template<typename T, int N, int M>
    friend std::istream& operator>>(std::istream& in, Matrix<T, N, M>& arr);
};


template<typename T, int N, int M>
std::istream& operator>>(std::istream& in, Matrix<T, N, M>& arr)
{
    std::cout << "in" << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            in >> arr.m_matrix[i][j];
        }
    }
    return in;
}


template<typename T, int N, int M>
std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& arr)
{
    std::cout << "out" << '\n';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            out << arr.m_matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
    return out;
}

int main()
{
    /*Matrix<int, 2, 2> m;
    Matrix<int, 2, 2> k;
    std::cin >> m;
    Matrix<int, 2, 2> b;
    b = m;
    std::cout << '\n';
    std::cout << b;
    std::cin >> k;
    k += m;
    std::cout << "k+=m:" << '\n';
    std::cout << k;
    std::cout << "k+m:" << '\n';
    std::cout << (k + m);
    std::cout << "m[1][2]" << " " << m(1, 2)<<'\n';
    m(1, 2) = 555;
    std::cout << "m[1][2]" << " " << m(1, 2)<<'\n';*/

    /* Matrix<int, 2, 3> m;
    std::cin >> m;
    std::cout << m<< ' ';
    ++m;
    std::cout << m;*/


    Matrix<int, 3, 3> m;
    Matrix<int, 3, 3> k;
    std::cin >> m;
    std::cin >> k;
    std::cout << "k*m:" << '\n';
    
    std::cout << k*m;



   /* std::cout << (k * m);
    std::cout << "k*m det" << '\n';
    std::cout << (k * m).determinant();*/


    //Matrix<int, 3, 3> p;
    //std::cin >> p;
    //std::cout << "p det" << '\n';
    //std::cout << (p).determinant();

}

