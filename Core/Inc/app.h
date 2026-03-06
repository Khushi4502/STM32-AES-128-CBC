/*
 * app.h
 *
 *  Created on: Jan 24, 2026
 *      Author: DuttEngi
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"     /* Cube Generated Init Code */

/* String Functions */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>


#include "aes.h"

void uart_print(const char *s);
//void uart_print(char *data);
void aes_self_test(void);

#endif /* INC_APP_H_ */
