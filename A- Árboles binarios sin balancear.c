#include <stdio.h>
#include <stdlib.h>

typedef struct arbol arbol;

struct arbol{
	int dato;
	arbol *izq;
	arbol *der;
};
int comp(arbol **r,int dato, int ac);
int main(int argc, char *argv[]) {
	int ac=0;
	int res,n,dato;
	arbol *raiz=NULL;
	scanf("%d", &n);
	int arreglo[n];
	for(int i=0;i<n;i++){
		scanf("%d", &dato);
		arreglo[i]=dato;
	}
	for(int j=0;j<n;j++){
		res = comp(&raiz,arreglo[j], 0);
		printf("%d\n", res);
	}
	return 0;
}
arbol *crearnodo(int dato){
	arbol *nuevo=NULL;
	nuevo=(arbol *)malloc(sizeof(arbol));
	nuevo->dato=dato;
	nuevo->der=NULL;
	nuevo->izq=NULL;
	return nuevo;
}

void insert(arbol **r,int dato){
	if (*r==NULL){
		arbol* nuevo=crearnodo(dato);
		*r=nuevo;
	}
	else{
		arbol *aux= *r;
		if(dato>aux->dato){
			insert(&aux->der,dato);
		}
		else{
			insert(&aux->izq,dato);
		}
	}
}

int comp(arbol **r,int dato, int ac){
	if (*r==NULL){
		arbol* nuevo=crearnodo(dato);
		*r=nuevo;
		return ac;
	}
	else{
		arbol *aux= *r;
		ac+=1;
		if(dato>aux->dato){
			comp(&aux->der,dato,ac);
		}
		else{
			comp(&aux->izq,dato,ac);
		}
	}   
}
