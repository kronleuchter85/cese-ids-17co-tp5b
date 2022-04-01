/*=====[Module Name]===========================================================
 * Copyright 2019 Esteban Daniel VOLENTINI <evolentini@gmail.com>
 * All rights reserved.
 * License: BSD-3-Clause <https://opensource.org/licenses/BSD-3-Clause>)
 *
 * Version: 0.1.0
 * Creation Date: 2019/03/01
 */

/*=====[Avoid multiple inclusion - begin]====================================*/

#ifndef _ALUMNOS_H_
#define _ALUMNOS_H_

/*=====[Inclusions of public function dependencies]==========================*/

#include <stdbool.h>
#include <stddef.h>

/*=====[C++ - begin]=========================================================*/

#ifdef __cplusplus
extern "C" {
#endif

/*=====[Definition macros of public constants]===============================*/

/*=====[Public function-like macros]=========================================*/

/*=====[Definitions of public data types]====================================*/

///
/// Declaracion del tipo de dato alumno_t como tipo de estructura constante.
/// Contiene los campos:
/// - apellidos: los apellidos del alumno, 
/// - nombres: el primer y segundo nombre del alumno
/// - documento: el DNI del alumno
///
typedef struct alumno_s {
    char apellidos[30];
    char nombres[30];
    char documento[11];
} const * alumno_t;

/*=====[Definitions of public global variables]==============================*/

/*=====[Prototypes (declarations) of public functions]=======================*/



/**
 * Serializa un objeto alumno pasado como parametro y devuelve si hubo un error en el proceso
 *
 * @param[char*] arreglo de caracteres donde se guarda el alumno serializado
 * @param[size_t] el tamaño del arreglo de caracteres
 * @param[const alumno_t] el objeto alumno a serializar
 *
 * @return[bool] si hubo o no error
 */
bool SerializarAlumno(char * cadena, size_t espacio, const alumno_t alumno);


/**
 * Serializa el arreglo completo de ALUMNOS en una cadena pasada como parametro. Devuelve si hubo error
 * en el proceso.
 *
 * @param[char*] cadena en la que se serializan todos los alumnos
 * @param[size_t] tamaño de la cadena en la que se serializan todos los alumnos
 *
 * @return[bool] si hubo algun error en el proceso
 */
bool SerializarAlumnos(char * cadena, size_t espacio);

/*=====[Prototypes (declarations) of public interrupt functions]=============*/

/*=====[C++ - end]===========================================================*/

#ifdef __cplusplus
}
#endif

/*=====[Avoid multiple inclusion - end]======================================*/

#endif /* _ALUMNOS_H_ */
