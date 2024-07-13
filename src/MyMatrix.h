//
// Created by Eu on 10/07/2024.
//

#ifndef MYMATRIX_H
#define MYMATRIX_H

#include <cmath>

#include "Calculadora.h"
// #include "CalculaMenorDistanciaPixelPreto.h"

using namespace std;

template<typename T>
class MyMatrix {
public:
    const T ** getData() const;

    // construtores e destrutores
    MyMatrix(int _qtdColunas, int _qtdLinhas);
    ~MyMatrix();

    // métodos de acesso
    T& get(long long linha, long long coluna){return data[linha][coluna];}
    const T& get(long long linha, long long coluna) const {return data[linha][coluna];} //read-only

    void lerEntrada() const;
    void gerarDistanciasTrivial();
    void gerarDistanciasTrivialMelhorado();

    void imprimir() const;
    void imprimirDistancias() const;
    void imprimirResumo() const;

    int getQtdColunas() const;
    int getQtdLinhas() const;

private:
    // guarda os dados da matriz principal
    T **data;
    // guarda as distancias entre cada célula da matriz principal "data"
    double **distancias;

    int qtdColunas;
    int qtdLinhas;

};


template<typename T>
MyMatrix<T>::MyMatrix(int _qtdColunas, int _qtdLinhas)
    :
          qtdColunas(_qtdColunas),
          qtdLinhas(_qtdLinhas)
{
    // cria a matriz 2d principal
    this->data = new T*[qtdLinhas];
    for (int i = 0; i < qtdLinhas; i++) {
        this->data[i] = new T[qtdColunas];
    }

    // cria outra matriz 2d com o mesmo tamanho de linhas e colunas
    this->distancias = new double*[qtdLinhas];
    for (int i = 0; i < qtdLinhas; i++)
        this->distancias[i] = new double[qtdColunas];

    // le os valores da matriz principal
    this->lerEntrada();
}

template<typename T>
void MyMatrix<T>::gerarDistanciasTrivial() {
    // encontra o pixel preto mais próximo para cada pixel
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            this->distancias[i][j] = Calculadora::getMenorDistanciaTrivial(
                                                            qtdLinhas,
                                                            qtdColunas,
                                                            i,
                                                            j,
                                                            this->data);
        }
    }
}

template<typename T>
void MyMatrix<T>::gerarDistanciasTrivialMelhorado() {
    //TODO
}


template<typename T>
void MyMatrix<T>::lerEntrada() const {
    for (int i = 0; i < qtdLinhas; i++) {
        for (int j = 0; j < qtdColunas; j++) {
            // Le o valor de cada pixel (cada pixel possui 3 cores, indo de 0 até 255)
            std::cin >> this->data[i][j];
        }
    }
}

template<typename T>
void MyMatrix<T>::imprimir() const {
    for (int i = 0; i < this->getQtdLinhas(); i++) {
        for (int j = 0; j < this->getQtdColunas(); j++) {
            cout << this->data[i][j] << " ";
        }
        cout << "\n";
    }
}

template<typename T>
void MyMatrix<T>::imprimirDistancias() const {
    for (int i = 0; i < this->getQtdLinhas(); i++) {
        for (int j = 0; j < this->getQtdColunas(); j++) {
            cout << std::round(this->distancias[i][j]) << " ";
        }
        cout << "\n";
    }
}

template<typename T>
void MyMatrix<T>::imprimirResumo() const {
    cout << Calculadora::getSomaDistancias(qtdLinhas, qtdColunas, distancias) << endl;
}


template<typename T>
const T ** MyMatrix<T>::getData() const {
    return this->data;
}


template<typename T>
int MyMatrix<T>::getQtdColunas() const {
    return this->qtdColunas;
}

template<typename T>
int MyMatrix<T>::getQtdLinhas() const {
    return this->qtdLinhas;
}

template<typename T>
MyMatrix<T>::~MyMatrix() {
    for (int i = 0; i < qtdLinhas; i++) {
        delete[] data[i];
        delete[] distancias[i];
    }
    delete[] data;
    delete[] distancias;

}

#endif //MYMATRIX_H
