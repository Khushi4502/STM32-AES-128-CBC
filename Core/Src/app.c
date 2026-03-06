/*
 * app.c
 *
 *  Created on: Jan 24, 2026
 *      Author: DuttEngi
 */

#include "app.h"

extern UART_HandleTypeDef huart4;

void uart_print(const char *s)
{
    HAL_UART_Transmit(&huart4, (uint8_t *)s, strlen(s), 60);
}

//void uart_print(char *data)     //Debug UART
//{
//  uint16_t len = (uint16_t)strlen((const char *)data);
//
//      HAL_UART_Transmit(&huart4,(uint8_t *) data, len, 1000);
//}

/* ================= AES TEST VECTORS ================= */
/* AES-128 key (16 bytes = 128 bits)
 * This is a known test key
 */

/* AES-128 test key */
uint8_t aes_key[16] = {
  0x2B,0x7E,0x15,0x16,
  0x28,0xAE,0xD2,0xA6,
  0xAB,0xF7,0x15,0x88,
  0x09,0xCF,0x4F,0x3C
};


/* Initialization Vector (IV)
 * Used only in CBC mode
 * Must be 16 bytes
 */
/* AES IV */
uint8_t aes_iv[16] = {
  0x00,0x01,0x02,0x03,
  0x04,0x05,0x06,0x07,
  0x08,0x09,0x0A,0x0B,
  0x0C,0x0D,0x0E,0x0F
};

/* Plaintext (16 bytes exactly) */
uint8_t plaintext[16] = {
  'A','E','S','_','T','E','S','T','_','O','K','_','1','2','3','4'
};

uint8_t buffer[16];

/* =====================================================
 * AES SELF TEST FUNCTION
 * =====================================================
 * Steps:
 * 1. Copy plaintext to buffer
 * 2. Print plaintext
 * 3. Encrypt buffer
 * 4. Print encrypted data
 * 5. Decrypt buffer
 * 6. Print decrypted data
 */

void aes_self_test(void)
{
    struct AES_ctx ctx;
    char line[64];

    memcpy(buffer, plaintext, 16);

    uart_print("\r\nPLAINTEXT:\r\n");
    for (int i = 0; i < 16; i++) {
        sprintf(line, "%02X ", buffer[i]);
        uart_print(line);
    }

    /* Encrypt */
    AES_init_ctx_iv(&ctx, aes_key, aes_iv);
    AES_CBC_encrypt_buffer(&ctx, buffer, 16);

    uart_print("\r\n\r\nENCRYPTED:\r\n");
    for (int i = 0; i < 16; i++) {
        sprintf(line, "%02X ", buffer[i]);
        uart_print(line);
    }

    /* Decrypt */
    AES_init_ctx_iv(&ctx, aes_key, aes_iv);
    AES_CBC_decrypt_buffer(&ctx, buffer, 16);

    uart_print("\r\n\r\nDECRYPTED:\r\n");
    for (int i = 0; i < 16; i++) {
        sprintf(line, "%02X ", buffer[i]);
        uart_print(line);
    }

    uart_print("\r\n");
}
