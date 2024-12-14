#include <stdio.h>
#include <stdlib.h>
struct nodo{
	int dato ;
	struct nodo *izq;
	struct nodo *der;


};
typedef struct nodo Nodo ;
struct arbol{
	Nodo *raiz;
	
};
typedef struct arbol Arbol ;
Nodo *CrearNodo(int dato){
	  Nodo *Nuevo;
	  Nuevo = (Nodo*)malloc(sizeof(Nodo));
	  if(Nuevo == NULL){
		printf("Error al crear nodo\n");
	  
	  }
	  Nuevo->dato = dato;
	  Nuevo->izq = NULL;
	  Nuevo->der = NULL;
	  return Nuevo ;

}
Arbol *CrearArbol(){
	  Arbol *Nuevo;
	  Nuevo = (Arbol*)malloc(sizeof(Arbol));
	  if(Nuevo == NULL){
		printf("Error al crear Arbol\n");
	  }
	  Nuevo->raiz = NULL;
	  return Nuevo ;
	
}
Nodo *AgregarNodo(Nodo *raiz,Nodo *nodo){
		Nodo *aux;
		aux = raiz;
		if(raiz == NULL){
			return nodo;
			
	   }else{
		   if(nodo->dato < raiz->dato){
				raiz->izq = AgregarNodo(raiz->izq,nodo);
		   
		   
		   }else{
				raiz->der = AgregarNodo(raiz->der,nodo);
		   
		   }
	   }
	   return raiz ;

}
void preorden(Nodo *raiz){
		Nodo *aux;
		aux = raiz;
		if(aux == NULL){
			return;
		
		}
		if(aux->izq == NULL && aux->der == NULL){
			printf("%d,",aux->dato);
		}else{
			printf("%d,",aux->dato);
			preorden(aux->izq);
			preorden(aux->der);
			
			
			
		}
}
void inorden(Nodo *raiz){
	Nodo *aux;
	aux = raiz;
	if(aux == NULL){
		return ;
	}
	if(aux->izq == NULL && aux->der == NULL){
		printf("%d,",aux->dato);
	}else{
	inorden(aux->izq);
	printf("%d,",aux->dato);
	inorden(aux->der);
	}
}
void postorden(Nodo *raiz){
	Nodo*aux;
	aux = raiz;
	if( raiz == NULL){
		
		return;
	}
	if(aux->izq == NULL && aux->der == NULL){
		printf("%d,",aux->dato);
	}else{
		postorden(aux->izq);
		postorden(aux->der);
		printf("%d,",aux->dato);
		
	}
	return ;

}
void Hojas(Nodo *raiz){
	Nodo*aux;
	aux = raiz;
	if( raiz == NULL){
		
		return;
	}
	if(aux->izq == NULL && aux->der == NULL){
		printf("%d,",aux->dato);
	}else{
		Hojas(aux->izq);
		Hojas(aux->der);
		
	}
	return ;

}
	
void EsABO(Nodo *raiz){
		Nodo *aux;
		aux = raiz;
		if(aux == NULL){
			return;
		
		}
		if(aux->izq == NULL && aux->der == NULL){
			printf("%d,",aux->dato);
		}else{
			if(aux->izq->dato > aux->dato || aux->der->dato<= aux->dato){
				printf("No es ABO\n");
			}else{
				printf("%d,",aux->dato);
				preorden(aux->izq);
				preorden(aux->der);
			}
			
			
		}
			
}
int CantidadHojas(Nodo *raiz,int sum){
	Nodo*aux;
	aux = raiz;
	if( raiz == NULL){
		
		return 0;
	}
	if(aux->izq == NULL && aux->der == NULL){
			return 1 ;
	}else{
		sum= CantidadHojas(aux->izq,sum);
		sum = CantidadHojas(aux->der,sum) + sum;
		
	}
	return sum ;

}
void Internos(Arbol *ABO,Nodo *raiz){
			Nodo *aux;
			aux = raiz;
			if(aux == NULL){
				return;
			}
			if(ABO->raiz != aux){
				if(aux->der != NULL || aux->izq !=NULL){
						//if(aux->dato != raiz->dato){//aqui hay un error
				printf("%d,",aux->dato);
					
				}
			}
			Internos(ABO,aux->izq);
			Internos(ABO,aux->der);
				
	


}
int altura(Nodo *raiz){
	int count ;
	int count1;
	Nodo *aux;
	aux = raiz;
	if(aux == NULL){
		return -1 ;
	}else{
		if(aux->izq == NULL && aux->der == NULL){
			return 0 ;
		
		}else{
			count = altura(aux->izq) + 1 ;
			count1 = altura(aux->der) +1;
		}
		if(count>count1){
			return count;
		
		
		}else{
			return count1;
		}
	}
	


}




int main(){
	int Al;
	int sum = 0;
	int sum1;
	int A[8] = {23,40,30,15,20,10,41,31};
	Arbol *ABO;
	ABO = CrearArbol();
	Nodo *Nuevo;
	for(int i=0;i<8;i++){
		Nuevo = CrearNodo(A[i]);
		ABO->raiz = AgregarNodo(ABO->raiz,Nuevo);
	}
	printf("%d\n",ABO->raiz->izq->dato);
	printf("\npreorden\n");
	preorden(ABO->raiz);
	//EsABO(ABO->raiz);
	printf("\ninorden\n");
	inorden(ABO->raiz);
	printf("\nPostorden\n");
	postorden(ABO->raiz);
	printf("\nHojas del Arbol\n");
	Hojas(ABO->raiz);
	sum1 = CantidadHojas(ABO->raiz,sum);
	printf("\n%d\n",sum1);
	printf("altura\n");
	Al = altura(ABO->raiz);
	printf("%d\n",Al);
	printf("\nInternos\n");
	Internos(ABO,ABO->raiz);
	  
}