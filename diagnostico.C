#include <stdio.h>
#include <stdlib.h>

void addAtTail (int data, int *n, int *arr);
void addAtFront (int data, int *n, int *arr); 
int size (int n,int *arr); 
void removeAll (int n, int *arr); 
int  getAt (int n,int *arr, int index);

int main () {

    return (0);

}

int  getAt(int n, int *arr, int index ) {

    if(index < n) {

        return *(arr + index);

    }else {

        return NULL;
    }
}

int size(int n, int *arr) {

    int i = 0, contador = 0;

    while(*(arr + i) != NULL && i < n) {

        contador++;
        i++;
    }

    return contador;
}

void removeAll(int n, int *arr) {

    int j;

    for(j = 0; j < n ; j++) {
        *(arr + j) = NULL;
    }

}

void addAtFront(int num, int *n, int *arr){

    int i = 1, j;

    if (*arr == NULL){
        *arr = num;
    }
    else {

        while(*(arr + i) != NULL && i < *n){
            i++;
        }

        if(i < *n ) {
            for(j = i; j > -1; j--) {
                *(arr + (j + 1)) = *(arr + j);
            }

            *arr = num;
        }

        else {

            *n = *n + 1;
            arr = realloc(arr, ((*n)*sizeof(int)));

            for(j = i; j> -1; j--) {
                *(arr + (j + 1)) = *(arr + j);
            }

            *arr = num;
        }
    }
}

void addAtTail (int num, int *n, int *arr){

    int i = 1;

    if (*arr == NULL) {
        *arr = num;
    }

    else {
        while (*(arr+i) != NULL && i < *n) {
            i++;
        }

        if(i < *n ) {
            *(arr + i) = num;
        } 
        else {

            *n = *n+1;
            arr = realloc(arr,((*n)*sizeof(int)));

            *(arr + i) = num;
        }
    }

}