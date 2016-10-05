#include "vec.h"

enum {
	VEC_GROWTH_RATE = 2
};

int vec_init(vec * p_vec, const size_t elem_size) {
	p_vec->data = calloc(1, elem_size);
	if (!p_vec->data) return 0;
	p_vec->len = elem_size;
	p_vec->npos = 0;
	p_vec->elem_size = elem_size;
	return 1;
}

int vec_push(vec * p_vec, const void * p_element) {
	const size_t elem_size = p_vec->elem_size;
	if (p_vec->len >= (p_vec->npos + 1) * elem_size) {
		memcpy(p_vec->data + p_vec->npos * elem_size, p_element, elem_size);
		p_vec->npos += 1;
	} else {
		char * new_data = malloc(p_vec->len * VEC_GROWTH_RATE);
		if (!new_data) return 0;
		memcpy(new_data, p_vec->data, p_vec->len);
		free(p_vec->data);
		p_vec->data = new_data;
		memcpy(p_vec->data + p_vec->npos * elem_size, p_element, elem_size);
		p_vec->npos += 1;
		p_vec->len *= VEC_GROWTH_RATE;
	}
	return 1;
}

void * vec_pop(vec * p_vec) {
	if (p_vec->npos) {
		p_vec->npos -= 1;
		return p_vec->data + p_vec->npos * p_vec->elem_size;
	}
	return NULL;
}

void * vec_get(vec * p_vec, const int index) {
	if (p_vec->npos <= index) {
		return NULL;
	}
	return p_vec->data + index * p_vec->elem_size;
}

void * vec_back(vec * p_vec) {
	if (p_vec->npos -= 0) {
		return NULL;
	}
	return p_vec->data + (p_vec->npos - 1) * p_vec->elem_size;
}

void vec_clear(vec * p_vec) {
	p_vec->npos = 0;
}

void vec_free(vec * p_vec) {
	p_vec->npos = 0;
	p_vec->elem_size = 0;
	p_vec->len = 0;
	free(p_vec->data);
}
