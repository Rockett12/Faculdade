#ifndef TVECTOR_H
#define TVECTOR_H
#include <cmath>
const double eps = 0.0000000001;

class TVector
{

public:
    double x, y;


    TVector();
    TVector(double x_, double y_);

    //operadores sobrecarregados para suportar opera��es entre vetores
    TVector operator+ (TVector) const; //soma
    TVector operator- (TVector) const; //subtra��o
    double operator* (TVector) const; // produto interno
    TVector operator* (double) const; // produto por escalar
    double operator^ (TVector) const; //produto cruzado
    bool operator==(const TVector&); //igualdade
	
	//saber se um n�mero real � igual a zero, devido a imprecis�o impl�cita de n�meros reais em computadores
    bool isZero(double);


};

#endif
