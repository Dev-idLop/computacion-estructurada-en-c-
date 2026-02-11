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
    Fecha() : dia(1), mes(1), annio(1970) {}

    //Constructor con parametros
Fecha(short d, short m, short a) : Fecha()
{
    if (!set_fecha(d, m, a)) {
        dia = 1;
        mes = 1;
        annio = 1970;
    }
}
  


    //3.Constructor Copia: Recibe como único parámetro una referencia a otro objeto fecha previamente creado,
    // y lo usa como ejemplo para copiar todos sus valores internos (de manera similar al método Object.clone() de Java).
        Fecha(const Fecha& f){
            dia = f.dia;
            mes = f.mes;
            annio = f.annio;
        }
    
    




    private:
    /** Getters & setters (basic accesors & mutators) */
    /// Escribe las validaciones que necesitas para asegurar que nunca asignas un
    /// valor erroneo a cualquiera de los atributos.
    /// Para los setters, regresa verdadero si el cambio fue exitoso, falso si el parametro fue invalido
    short get_dia  () const
    {
        return dia;
    }
    bool  set_dia  (short d, short max = 31)
    {

        if (mes == 2 && annio % 4 == 0 && (annio % 100 != 0 || annio % 400 == 0))
            max = 29;
        else if (mes == 2)
            max = 28;
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
            max = 30;
        else
            max = 31;

        if (d < 1 || d > max)
            return false;
        dia = d;
        return true;


    }
    short get_mes  () const
    {
        return mes;
    }
    bool  set_mes  (short m)
    {
        if (m < 1 || m > 12)
            return false;
        mes = m;
        return true;
    }
    short get_annio() const
    {
        return annio;
    }
    bool  set_annio(short a)
    {
        if (a < 1)
            return false;
        annio = a;
        return true;
    }

    public:
    
    /** Accesors */
    /// Metodos que permiten leer el contenido de Fecha, no necesariamente igual que los getters
    std::string get_fecha (bool extra = false) const
    {
        /// Convierte los atributos dia, mes, annio, en un solo valor de tipo string que contiene
        /// la representaci�n de la fecha en formato "dd/mm/aaaa"
        /// PUNTOS EXTRA, si logras imprimir un formato adicional "dd-MES-aaaa" (3 primeras letras del mes)
        
        std::string dia_s = std:: to_string(dia);
        std::string annio_s = std:: to_string(annio);
        std::string meses[] = {
            "Ene", "Feb", "Mar", "Abr", "May", "Jun",
            "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"
        };

        std::string retVal;
            if (extra){
                retVal = dia_s + "-" + meses[mes - 1] + "-" + annio_s;
            }
            else {
                retVal = dia_s + "/" + std:: to_string(mes) + "/" + annio_s;
            }

        return retVal;
    }

    /** Mutators */
    /// Metodos que permiten cambiar el contenido de Fecha, faciles de usar desde fecha_main.cpp

    bool set_fecha (short d, short m = INVALID_MONTH, short a = INVALID_YEAR)
    {
        /// Invoca los setters para asegurar que los valores siempre estan dentro de rango.
        /// retorna si todos los setters se ejecutaron sin problema o no.
        /// PUNTOS EXTRA, si puedes usar el mes y a�o actual en vez de los defaults invalidos.
        // Primero invocamos el setter del a�o, ya que el valor del a�o es necesario para validar el dia
        if (a != INVALID_YEAR && !set_annio(a))
        //despues el setter del mes, ya que el valor del mes es necesario para validar el dia
            return false;
        if (m != INVALID_MONTH && !set_mes(m))
        //despues el setter del dia, ya que el valor del dia es necesario para validar el mes
            return false;
        if (d != INVALID_DAY && !set_dia(d))
            return false;

        return true;
    } 

};

#endif // FECHA_H_CUT_UDG_MX
