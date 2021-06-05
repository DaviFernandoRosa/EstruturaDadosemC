#include<stdio.h>
#include<stdlib.h>
struct ARVORE{
       int dado;
       struct ARVORE *esquerda, *direita, *pai;
};
typedef struct ARVORE ARV;
ARV *criaArvore();
ARV *criaNo(ARV *arvore, int v);
int vazia();
void exibirEmOrdem(ARV *a);
void imprimir(ARV *a);
int main(){
    ARV *a = criaArvore();
    int opc, valor;
    do{
        printf("1-inserir no\n"
               "0-sair\n");
        scanf("%d",&opc);
        switch(opc){
          case 1:
               printf("informe um valor: ");
               scanf("%d",&valor);
               a = criaNo(a, valor);
               system("cls");
               printf("\nValores em Ordem :");
               exibirEmOrdem(a);
               printf("\n");
               imprimir(a);
               printf("\n");
               system("pause");
               system("cls");
          break;
          case 0: break;
          default: printf("opcao invalida\n");
        }
        
    }while(opc != 0);
    printf("\nValores em Ordem :");
    exibirEmOrdem(a);
    printf("\n");
    imprimir(a);
    printf("\n");
}
ARV *criaArvore(){
    return NULL;
}
ARV *criaNo(ARV *arvore, int v){
    ARV *atemp;
    
    if(arvore == NULL){
       atemp = (ARV*)malloc(sizeof(ARV));
       atemp->dado = v;
       atemp->esquerda = criaArvore();
       atemp->direita = criaArvore();
       return atemp;
       }
    else{
         int dir;
         atemp = arvore;
         ARV *pai = NULL, *raiz = arvore;
         while(atemp != NULL){
           pai = atemp;
           if(v <= atemp->dado){
              dir = 0;
              atemp = atemp->esquerda;
              }
           else{
              dir = 1;
              atemp = atemp->direita;
              }
           }
    atemp = (ARV*)malloc(sizeof(ARV));
    atemp->dado = v;
    atemp->esquerda = criaArvore();
    atemp->direita = criaArvore();
    
    if(dir)
      pai->direita = atemp;
    else
      pai->esquerda = atemp;
      return raiz;
    }
}
int vazia(ARV *a){
    return a == NULL;
}

void imprimir(ARV *a){
     printf("\n\n\t( Pai %d )\n",a->dado);
     if(a->esquerda != NULL)
       printf("Esq: %d\t",a->esquerda->dado);
     else
       printf("Esq: NULL\t");
     if(a->direita != NULL)
       printf("\tDir: %d\t",a->direita->dado);
     else
       printf("Dir: NULL\t");
     if(a->esquerda != NULL)
      imprimir(a->esquerda);
     if(a->direita != NULL)
       imprimir(a->direita);
}
void exibirEmOrdem(ARV *a){
    if(a != NULL){
        exibirEmOrdem(a->esquerda);
        printf("%d ", a->dado);
        exibirEmOrdem(a->direita);
    }
}
