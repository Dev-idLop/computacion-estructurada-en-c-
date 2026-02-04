#ifndef FECHA_H_CUT_UDG_MX
#  define FECHA_H_CUT_UDG_MX
#  include <string>

class Fecha
{
  public:
    enum {
        INVALID_DAY = -1,
        INVALID_MONTH = -2,
        INVALID_YEAR = -3
    };

  private:
    ///  Atributos encapsulados, solo accesibles desde dentro de la clase
    short dia;
    short  mes;
    short annio;

    public:

    /** Constructores (semana 3) */

    private:
    /** Getters & setters (basic accesors & mutators) */
    /// Escribe las validaciones que necesitas para asegurar que nunca asignas un
    /// valor erroneo a cualquiera de los atributos.
    /// Para los setters, regresa verdadero si el cambio fue exitoso, falso si el parametro fue invalido
    short get_dia  () const
    {}
    bool  set_dia  (short d, short max = 31)
    {}
    short get_mes  () const
    {}
    bool  set_mes  (short m)
    {}
    short get_annio() const
    {}
    bool  set_annio(short a)
    {}

    public:
    /** Accesors */
    /// Metodos que permiten leer el contenido de Fecha, no necesariamente igual que los getters
    std::string get_fecha (bool extra = false) const
    {
        /// Convierte los atributos dia, mes, annio, en un solo valor de tipo string que contiene
        /// la representación de la fecha en formato "dd/mm/aaaa"
        /// PUNTOS EXTRA, si logras imprimir un formato adicional "dd-MES-aaaa" (3 primeras letras del mes)
        std::string retVal;
        return retVal;
    }

    /** Mutators */
    /// Metodos que permiten cambiar el contenido de Fecha, faciles de usar desde fecha_main.cpp

    bool set_fecha (short d, short m = INVALID_MONTH, short a = INVALID_YEAR)
    {
        /// Invoca los setters para asegurar que los valores siempre estan dentro de rango.
        /// retorna si todos los setters se ejecutaron sin problema o no.
        /// PUNTOS EXTRA, si puedes usar el mes y año actual en vez de los defaults invalidos.
        return false;
    }

};

#endif // FECHA_H_CUT_UDG_MX
