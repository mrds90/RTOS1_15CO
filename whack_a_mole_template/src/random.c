/**
BSD 3-Clause License

Copyright (c) 2021, Franco Bucafusco, Martin Menendez
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <stdlib.h>


#ifdef USE_FREERTOS
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#endif

/**
   @brief establece la semilla del pseudorandom generator

   @param semilla
 */
void random_set_seed( uint32_t semilla )
{
    if ( semilla != 0 )
    {
        srand( semilla ) ;
    }
}

/**
   @brief   Genera un numero aleatorio entre min y max, incluidos
            Pueden utilizarse numeros negativos

   @param min
   @param max
   @return uint32_t
 */
uint32_t random( int32_t min, int32_t max )
{
    if ( min>=max )
    {
        return min ;
    }

    //printf( "%d %d %d\n", min, max, ( max-min ) + min );

    return rand() % ( max-min ) + min;
}

#ifdef USE_FREERTOS
/**
   @brief genera una semilla nueva usando el tick del sistema al momento en que se llama.

 */
void random_seed_freertos()
{
    random_set_seed( xTaskGetTickCount() );
}
#endif