/// (C) 2019 - 2025
///@author Carlos Ramon Patiño
/// Include con <pointy-brakets> jala clases de la libreria estandar
#include <iostream>
#include <cstdlib>

/// Include con "comillas" jala clases del directorio actual
#include "Fecha.h"

int main(){
    using namespace std;

    Fecha hoy;
    short d, m, a;
    int cuenta = 0;

    do {
        cout << "Escribe una fecha de en formato dd mm aaaa:";
        cin >> d >> m >> a;
        hoy.set_fecha(d, m, a);
        cout << "La fecha capturada fue: "
            << hoy.get_fecha() << endl;
    }
    while (cuenta++ < 12);


    return 0;
}
