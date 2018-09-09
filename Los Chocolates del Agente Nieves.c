#include <stdio.h>
#include <stdlib.h>
#define Nodo struct nodo
#define List struct list

Nodo{
	int dato;
	Nodo*siguiente;
	Nodo*anterior;
};

List{
	Nodo*inicio;
	Nodo*final;
};

int buscarMenor(List*lista);
void insertar(List*lista, int dato);
Nodo*nuevoElemento(int dato);
Nodo*inicio=0;
Nodo*final=0;
int main(){
	List Lista;
	Lista.inicio=Lista.final=NULL;
	int N,i,Ni,Total=0;
	do{
		scanf("%d",&N);
	}while(N<3 | N>1000);
	for(i=0;i<N;i++){
		do{
			scanf("%d",&Ni);
		}while(Ni<1 | Ni>1000);
		insertar(&Lista,Ni);
	}
	for(i=1;i<=N;i++){
		Total+=(buscarMenor(&Lista)*i);
	}
	printf("%i",Total);
}

void insertar(List *list,int dato){
	Nodo*nuevo=nuevoElemento(dato);
	if(list->inicio==NULL && list->final==NULL){
		list->inicio=nuevo;
		list->final=nuevo;
	}else{
		list->final->siguiente=nuevo;
		nuevo->anterior=list->final;
		list->final=nuevo;
	}
}

Nodo*nuevoElemento(int dato){
	Nodo*q=(Nodo*)malloc(sizeof(Nodo));
	q->dato=dato;
	q->siguiente=NULL;
	q->anterior=NULL;
	return q;
}

int buscarMenor(List*lista){
	int dato;
	if(lista->inicio!=NULL && lista->final!=NULL){
		if(lista->final->dato<=lista->inicio->dato){
			dato=lista->final->dato;
			Nodo*aux=lista->final;
			lista->final=lista->final->anterior;
			free(aux);
		}else{
			dato=lista->inicio->dato;
			Nodo*aux=lista->inicio;
			lista->inicio=lista->inicio->siguiente;
			free(aux);
		}
	}
	return dato;
}
