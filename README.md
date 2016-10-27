### Overview
The code in this repository implements an interface similar to a C++ STL vector in C. In terms of memory footprint, it requires one more word than std::vector, because the size of the stored elements cannot be determined at compile time.

### Usage
``` c
int main() {
    vec myvec;
    
    /* Initialize vector with the size of the elements to be stored */
    vec_init(&myvec, sizeof(int));
    
    for (int i = 0; i < 4; i += 1) {
        /* Push elements onto the vector */
        vec_push(&myvec, &i);
    }
    
    /* Call the vec_get to access an element */
    printf("%d\n", *(int *)vec_get(&myvec, 2));
    
    for (int i = 0; i < 4; i += 1) {
        /* Pop some elements off the vector */
        printf("%d\n", *(int *)vec_pop(&myvec));
    }
    
    /* Release resources from free store */
    vec_free(&myvec);
}
```
