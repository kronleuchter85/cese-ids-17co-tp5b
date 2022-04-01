/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */
 
/*=====[Inclusion of own header]=============================================*/

#include "alumnos.h"
#include <stdio.h>
#include <string.h>

/*=====[Inclusions of private function dependencies]=========================*/

/*=====[Definition macros of private constants]==============================*/

/*=====[Private function-like macros]========================================*/

/*=====[Definitions of private data types]===================================*/

/*=====[Definitions of external public global variables]=====================*/

/*=====[Definitions of public global variables]==============================*/

///
/// Constante del tipo alumno_s para el docente ESTEBAN_VOLENTINI
///
static const struct alumno_s ESTEBAN_VOLENTINI = {
    .apellidos = "VOLENTINI",
    .nombres = "Esteban Daniel",
    .documento = "23.517.968",
};

///
/// Constante del tipo alumno_s para el alumno GONZALO_CARRENO
///
static const struct alumno_s GONZALO_CARRENO = {
    .apellidos = "CARRENO",
    .nombres = "Gonzalo Carreno",
    .documento = "31.789.456",
};

///
/// Constante arreglo del tipo alumno_t
///
const alumno_t ALUMNOS[] = {
    &ESTEBAN_VOLENTINI,
    &GONZALO_CARRENO,
};

const int CANTIDAD_ALUMNOS = (sizeof(ALUMNOS) / sizeof(alumno_t));

/*=====[Definitions of private global variables]=============================*/

/*=====[Prototypes (declarations) of private functions]======================*/

/*=====[Implementations of public functions]=================================*/

/*=====[Implementations of interrupt functions]==============================*/

/**
 * Serializa un objeto alumno pasado como parametro y devuelve si hubo un error en el proceso
 *
 * @param[char*] arreglo de caracteres donde se guarda el alumno serializado
 * @param[size_t] el tamaño del arreglo de caracteres
 * @param[const alumno_t] el objeto alumno a serializar
 *
 * @return[bool] si hubo o no error
 */
bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno) {
    int resultado;
    const char FORMATO[] = "{"
        "\"documento\":\"%s\","
        "\"apellidos\":\"%s\","
        "\"nombres\":\"%s\""
    "}";

    resultado = snprintf(cadena, espacio, FORMATO, 
             alumno->documento, alumno->apellidos, alumno->nombres);

    return (resultado >= 0);
}

/**
 * Serializa el arreglo completo de ALUMNOS en una cadena pasada como parametro. Devuelve si hubo error
 * en el proceso.
 *
 * @param[char*] cadena en la que se serializan todos los alumnos
 * @param[size_t] tamaño de la cadena en la que se serializan todos los alumnos
 *
 * @return[bool] si hubo algun error en el proceso
 */
bool SerializarAlumnos(char * cadena, size_t espacio) {
    static const int  cantidad = sizeof(ALUMNOS) / sizeof(alumno_t);
    int posicion = snprintf(cadena, espacio, "[\r\n  ");
    bool resultado = (posicion > 0);

    if (resultado){
        for(int indice = 0; indice < cantidad; indice++ ) {
            resultado = SerializarAlumno(&cadena[posicion], espacio - posicion, ALUMNOS[indice]);
            if (resultado) {
                posicion += strlen(&cadena[posicion]);
                posicion += snprintf(&cadena[posicion], espacio - posicion, ",\r\n  ");
            } else {
                break;
            }
        }
    }

    snprintf(&cadena[posicion] - 5, espacio - posicion + 5, "\r\n]");
    return resultado;
}

/*=====[Implementations of private functions]================================*/
