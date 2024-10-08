//
// Created by Eu on 10/07/2024.
//

#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>

class Pixel {
private:
    int cores[3];
public:
    Pixel();
    explicit Pixel(const int *_cores);

    Pixel(int r, int g, int b);

    // funções auxiliares para entrada e saída padrão
    friend std::ostream& operator<<(std::ostream &out, const Pixel &pixel);
    friend std::istream& operator>>(std::istream &in, Pixel &pixel);

    void imprimir();
    void ler();

    bool ehPreto() const;
};



#endif //PIXEL_H
