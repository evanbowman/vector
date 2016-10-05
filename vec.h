#pragma once

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct vec {
	char * data;
	size_t len;
	size_t npos;
	size_t elem_size;
} vec;

int vec_init(vec * p_vec, const size_t elem_size);

int vec_push(vec * p_vec, const void * p_element);

void * vec_get(vec * p_vec, const int index);

void * vec_pop(vec * p_vec);

void vec_clear(vec * p_vec);

void vec_free(vec * p_vec);
