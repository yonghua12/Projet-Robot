/*------------------------------------------------------------------------------*/
/* Description:     Driver_UART.h contains prototype of UART */
/*------------------------------------------------------------------------------*/

#ifndef DRIVER_UART_H_
#define DRIVER_UART_H_

#include <msp430.h>
#include <string.h>

/* ----------------------------------------------------------------------------
 * Fonction d'initialisation de l'UART
 * Entree : -
 * Sorties: -
 */
void init_UART(void);

/* ----------------------------------------------------------------------------
 * Fonction d'emission d'une chaine de caracteres
 * Entree : pointeur sur chaine de caracteres
 * Sorties:  -
 */
void envoi_msg_UART(char *msg);

/* ----------------------------------------------------------------------------
 * Fonction d'interpretation des commandes utilisateur
 * Entrees: -
 * Sorties:  -
 */
void interpreteur(void);



#endif /* DRIVER_UART_H_ */
