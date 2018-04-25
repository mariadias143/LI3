#include "heap.h"

#define PAI(i) (i-1)/2
#define ESQUERDO(i) 2*i + 1
#define DIREITO(i) 2*i + 2

static Heap swap(Heap heap,int n1,int n2);
static Heap bubbleDown(Heap heap,int n, char ord);
static Heap bubbleUp(Heap heap,int i, char ord);

struct heap {
    int tamanho;
    int pos;
    char* pal;
    Post* posts;
};

//Função devolve -1 se a primeira data for mais recente e 1 se a segunda data for a mais recente
int maisRecente(Date date1, Date date2){
  int y1 = get_year(date1);
  int m1 = get_month(date1);
  int d1 = get_day(date1);
  int y2 = get_year(date2);
  int m2 = get_month(date2);
  int d2 = get_day(date2);

  if(y1 > y2) return -1;
  if(y2 > y1) return 1;
  if(y1 == y2){
    if(m1 > m2) return -1;
    if(m2 > m1) return 1;
    if(m1 == m2){
      if(d1 > d2) return -1;
      if(d2 > d1) return 1;
    }
  }
  return 0;
}

Heap initHeap(){
    Heap heap = malloc(sizeof(struct heap));
    heap->tamanho = 5;
    heap->pos = 0;
    heap->posts = malloc(5 * sizeof(Post));
    heap->pal = NULL;
    return heap;
}

Heap initHeapPal(char* word){
    Heap heap = malloc(sizeof(struct heap));
    heap->tamanho = 5;
    heap->pos = 0;
    heap->posts = malloc(5 * sizeof(Post));
    heap->pal = malloc(5 * sizeof(word));
    heap->pal = word;
    return heap;
}

char* getHeapPal(Heap h){
  return h->pal;
}

Heap heap_push(Heap heap, Post post, char ord){
    if(heap->tamanho-1 == heap->pos) {
        heap->tamanho *= 2;
        heap->posts = realloc(heap->posts,heap->tamanho *sizeof(Post));
    }
    heap->posts[heap->pos] = post;
    heap = bubbleUp(heap,heap->pos,ord);
    heap->pos++;
    return heap;
}


Post heap_pop(Heap heap, char ord) {
    if(heap->pos==0) return 0;
    Post r = heap->posts[0];
    heap->pos--;
    heap->posts[0] = heap->posts[(heap->pos)];

    heap = bubbleDown(heap,heap->pos,ord);

    return r;
}

// n -> tamanho do array
// ord pode ser 'D' (data masi recente) ou 'S' (score mais alto)
static Heap bubbleDown(Heap heap, int n, char ord){
    int i, m, r;
    i=0;
    if(ord == 'D'){
      while(ESQUERDO(i) < n){
          if(DIREITO(i) < n){
            r = maisRecente(getPostDate(heap->posts[(ESQUERDO(i))]), getPostDate(heap->posts[(DIREITO(i))]));
            if (r <= 0) m = ESQUERDO(i);
            else m = DIREITO(i);
          }
          else m = ESQUERDO(i);

          //Se a data do post de indice i(pai) for menos recente do que a data do post de indice m(um dos filhos), fazer swap
          if(maisRecente(getPostDate(heap->posts[i]), getPostDate(heap->posts[m])) >= 0){
              heap = swap(heap,i,m);
              i = m;
          }
          else return heap;
        }
      return heap;
    }
    else if(ord == 'S'){
      while(ESQUERDO(i) < n){
          if(DIREITO(i) < n){
            r = (getPostScore(heap->posts[(ESQUERDO(i))])) - (getPostScore(heap->posts[(DIREITO(i))]));
            if (r > 0) m = ESQUERDO(i);
            else m = DIREITO(i);
          }
          else m = ESQUERDO(i);

          //Se a data do post de indice i(pai) for menos recente do que a data do post de indice m(um dos filhos), fazer swap
          if((getPostScore(heap->posts[i])) - (getPostScore(heap->posts[m])) < 0){
              heap = swap(heap,i,m);
              i = m;
          }
          else return heap;
      }
      return heap;
    }
    else{
      while(ESQUERDO(i) < n){
          if(DIREITO(i) < n){
            r = (getPostNRes(heap->posts[(ESQUERDO(i))])) - (getPostNRes(heap->posts[(DIREITO(i))]));
            if (r > 0) m = ESQUERDO(i);
            else m = DIREITO(i);
          }
          else m = ESQUERDO(i);

          //Se a data do post de indice i(pai) for menos recente do que a data do post de indice m(um dos filhos), fazer swap
          if((getPostNRes(heap->posts[i])) - (getPostNRes(heap->posts[m])) < 0){
              heap = swap(heap,i,m);
              i = m;
          }
          else return heap;
      }
      return heap;
    }
}


static Heap bubbleUp(Heap heap, int i, char ord){
    if(ord == 'D'){
      Date dpai, di; //filho é mais recente ou seja, score do filho é maior
      while(i > 0 && maisRecente((dpai = getPostDate(heap->posts[PAI(i)])), (di = getPostDate(heap->posts[i]))) == 1){
          heap=swap(heap,i,PAI(i));
          i = PAI(i);
          free_date(dpai);
          free_date(di);
      }
      return heap;
    } else if(ord == 'S'){
        while(i > 0 && (getPostScore(heap->posts[PAI(i)]) - (getPostScore(heap->posts[i]))) < 0){
            heap=swap(heap,i,PAI(i));
            i = PAI(i);
        }
        return heap;
    }
    else{
      while(i > 0 && (getPostNRes(heap->posts[PAI(i)]) - (getPostNRes(heap->posts[i]))) < 0){
          heap=swap(heap,i,PAI(i));
          i = PAI(i);
      }
      return heap;
    }
}


static Heap swap(Heap heap,int n1,int n2) {
    Post p = heap->posts[(n1)];
    heap->posts[(n1)] = heap->posts[(n2)];
    heap->posts[(n2)] = p;
    return heap;
}


int heap_count(Heap heap){
    return heap->pos;
}

void heap_free(Heap heap){
    free(heap->posts);
    free(heap);
}
