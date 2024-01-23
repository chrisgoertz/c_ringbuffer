/*
 * ringbuffer.h
 * Circular buffer data structure for my mcu project.
 *  Created on: Jan 21, 2024
 *      Author: chris
 *
 */

#ifndef INC_RINGBUFFER_H_
#define INC_RINGBUFFER_H_
#include <stdint.h>
#define RINGBUFFER_DEFAULT_SIZE (128U)

/**
 * Ringbuffer type definition
 */
typedef struct ringb{
	uint32_t size;
	uint32_t pos;
	uint8_t *head;
	uint8_t *tail;
	uint8_t *buffer;
}ringbuffer_t;

void ringBuffer_init(ringbuffer_t *rb);
void ringBuffer_clear(ringbuffer_t *rb);
void ringBuffer_delete(ringbuffer_t *rb);
bool ringBuffer_isEmpty(ringbuffer_t *rb);
uint8_t ringBuffer_first(ringbuffer_t *rb);
uint8_t ringBuffer_last(ringbuffer_t *rb);
uint8_t ringBuffer_at(ringbuffer_t *rb, uint32_t at);
void ringBuffer_push(ringbuffer_t *rb, uint8_t chr);
uint8_t ringBuffer_get(ringbuffer_t *rb);
#endif /* INC_RINGBUFFER_H_ */
