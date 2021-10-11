#include <stdarg.h>
#include <stdbool.h>

#include "sapi.h"

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

#include "keys.h"


#include "stdout_leds.h"
#include "ledtennis.h"
#include "random.h"



#define LEDTENNIS_HIT_WINDOW        300

#define LEDTENNIS_THROW_MAX_TIME    800
#define LEDTENNIS_THROW_MIN_TIME    300

#define LEDTENNIS_STEP_MAX          200
#define LEDTENNIS_STEP_MIN          100

#define LEDTENNIS_HIT_WINDOW        300

#define LEDTENNIS_ROUNDS            10
#define LEDTENNIS_GAMEPLAY_TIMEOUT	20000  

 
 

} ledtennis_event_t;

/* global objects  */
QueueHandle_t queue_evnt;


/* prototypes */


void ledtennis_service_logic( void* pvParameters );
void user_service_logic( void* pvParameters );


 

/**
   @brief init game

 */
void ledtennis_init()
{
    BaseType_t res;

    /* creacion de tareas */


    configASSERT( ... );

    /* creacion de objetos */


    configASSERT( ... );
}



/**
   @brief Devuelve el puntaje cuando un golpe es certero.

   @param tiempo_reaccion_usuario valor de tiempo POSITIVO
   @return uint32_t
 */
int32_t ledtennis_points_hit( TickType_t tiempo_reaccion_usuario )
{
    if( tiempo_reaccion_usuario==0 )
    {
        return LEDTENNIS_HIT_WINDOW;
    }

    return LEDTENNIS_HIT_WINDOW / tiempo_reaccion_usuario ;
}

/**
   @brief devuelve el puntaje por haber perdido el golpe

   @return uint32_t
 */
int32_t ledtennis_points_miss()
{
    return -10;
}

/**
   @brief devuelve el puntaje por haber pulsado en un momento incorrecto.

   @return uint32_t
 */
int32_t ledtennis_points_invalid()
{
    return -20;
}

/**
   @brief servicio principal del juego

   @param pvParameters
 */
void ledtennis_service_logic( void* pvParameters )
{
    BaseType_t res;
    bool game_alive;

    ledtennis_event_t evnt;

    int32_t puntos;
 


    TickType_t init_time;

    TickType_t tiempo_lanzamiento;
    TickType_t tiempo_paso;

    while( 1 )
    {
        /* inicio de juego ??? */

        puntos=0;
        /* randomizo (se usa el tick count del sistema)*/
        random_seed_freertos();

        while( true == game_alive )
        {
            /* preparo el turno */
            tiempo_lanzamiento  = random( LEDTENNIS_THROW_MIN_TIME, LEDTENNIS_THROW_MAX_TIME );
            tiempo_paso         = random( LEDTENNIS_STEP_MIN, LEDTENNIS_STEP_MAX );

        }
    }
}

/**
   @brief servicio de espera de teclas y envio de eventos a tarea 1

   @param pvParameters
 */
void user_service_logic( void* pvParameters )
{
    while( 1 )
    {


    }
}

