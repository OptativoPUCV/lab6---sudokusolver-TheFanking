#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <stdbool.h>


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int EstaRepetidoF(Node* aux ,int fila)
{
    for (int i = 0 ; i < 8 ; i++)
       {
          for (int j = 1 ; j <= 9 ; j++)
             {
                if (aux->sudo[fila][i] == aux->sudo[fila][j])
                {
                   return 1;
                }
             }
       }
   return 0;
}

int EstaRepetidoC(Node* aux,int col)
{
   for (int i = 0 ; i < 9 ; i++)
      {
         for (int j = i + 1 ; j < 9 ; j++)
            {
               if (aux->sudo[i][col] == aux->sudo[j][col])
               {
                  return 1;
               }
            }
      }
   return 0;
}

int EstaRepetidoS(Node * aux , int filaI, int colI)
{
   for  (int i = filaI ; i < (filaI+3); i++)
      {
         for  (int j = colI ; j < (colI+3) ; j++)
            {
               for (int k = filaI ; k < (filaI+3) ; k++)
                  {
                     for (int l = colI; l < (colI+3) ; l++)
                        {
                           if (k != i || l != j)
                           {
                              if (aux->sudo[i][j] != 
                                 aux->sudo[k][l])
                              {
                                 return 1;
                              }
                           }
                        }
                  }
            }
      }
   return 0;
}

int is_valid(Node* n)
{
   for (int i = 0 ; i < 9 ; i++)
   {
      int num[10] = {0};
      for (int j = 0 ; j < 9 ; j++)
         {
            if (n->sudo[i][j] != 0 && num[n->sudo[i][j]] == 1)
            {
               return 0;
            }
            else
            {
               num[n->sudo[i][j]] = 1;
            }
         }
   }
   return 1;
}   
  


List* get_adj_nodes(Node* n){
   List* list=createList();
   int i = 0;
   int j = 0;
   int k = 1;
   for (; i < 9 ; i++)
      {
         for (; j < 9 ; j++)
            {
               if (n->sudo[i][j] == 0)
               {
                  for (; k <= 9 ; k++)
                     {
                        Node *valor = copy(n);
                        valor->sudo[i][j] = k;
                        pushBack(list,valor);
                     }
               }
            }
      }
   return list;
}


int is_final(Node* n){
   for (int i = 0 ; i < 9 ; i++)
      {
         for (int j = 0 ; j < 9 ; j++)
            {
               if (n->sudo[i][j] == 0)
               {
                  return 0;
               }
            }
      }
    return 1;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/