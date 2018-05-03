#include <date.h>
#include <stdio.h>
#include <time.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>
#include <glib.h>
#include "user.h"
#include "parser.h"
#include "interface.h"
#include "mypost.h"
#include "myuser.h"
#include "key.h"
#include "heap.h"

//VER SE NO GETHEAPPAL NAO E PARA FAZER A COPIA!
// ver query 4,5,8,10

int main(int argc, char **argv){
  printf("ola");
  TAD_community tad = init();

//  int i;
 // clock_t t1, t2, t3, t6, t7, t9;//t4, t5,t8, t10;
  char* path = "/home/pedro90/Desktop/LI3/Grupo51/src";
  
  load(tad,path);
/*
 // t1 = clock();
  STR_pair q1 = info_from_post(tad, 1);
  char* c1 = get_fst_str(q1);
  char* c2 = get_fst_str(q1);
  printf("%s %s\n", c1, c2);
  t1 = clock() - t1;
  double a1 = ((double) t1) /CLOCKS_PER_SEC *1000;
  printf("Q1: %f ms \n",a1 );
  free_str_pair(q1);
  free(c1);
  free(c2);

  t2 = clock();
  LONG_list l2 = top_most_active(tad, 10);
  for(i=0; i<10; i++)
  printf("%ld\n", get_list(l2,i));
  t2 = clock() - t2;
  a1 = ((double) t2) /CLOCKS_PER_SEC *1000;
  printf("Q2: %f ms \n",a1);
  free_list(l2);

  t3 = clock();
  Date d1 = createDate(15,7,2000);
  Date d2 = createDate(3,10,2020);  
  LONG_pair par = total_posts(tad, d1, d2);
  long s1 = get_fst_long(par);
  long s2 = get_fst_long(par);
  printf("%ld %ld\n", s1, s2);
  t3 = clock() - t3;
  a1 = ((double) t3) /CLOCKS_PER_SEC *1000;
  printf("Q3: %f ms \n",a1 );
  free_long_pair(par);
*//*
  t4 = clock();
  Date data1 = createDate(4,5,2014);
  Date data2 = createDate(4,6,2014);
  LONG_list l3 = questions_with_tag(tad, "rooting", data1, data2);
  t4 = clock() - t4;
  a1 = ((double) t4) /CLOCKS_PER_SEC *1000;
  printf("Q4: %f ms \n",a1 );
  free_list(l3);



  t5 = clock();
  USER u = get_user_info(tad, 10);
  char* bio = get_bio(u);
  printf("%s\n", bio);
  long* posts = get_10_latest_posts(u);
  for(i=0; i<10; i++)
    printf("%ld\n", posts[i]);
  t5 = clock() - t5;
  a1 = ((double) t5) /CLOCKS_PER_SEC *1000;
  printf("Q5: %f ms \n",a1 );
  free_user(u);
  for(i=0;i<10;i++)
    free(posts[i]);
  free(posts);
  free(bio) ; 
*//*
  t6 = clock();
  Date begin = createDate(13,10,2010);
  Date end = createDate(13,10,2010);
  LONG_list l6 = most_voted_answers(tad, 5, begin, end);
  for(i=0; i<5; i++)
    printf("%ld\n", get_list(l6,i));
  t6 = clock() - t6;
  a1 = ((double) t6) /CLOCKS_PER_SEC *1000;
  printf("Q6: %f ms \n",a1 );
  free_list (l6);


  t7 = clock();
  Date begin2 = createDate(1,8,2014);
  Date end2 = createDate(11,8,2014);
  LONG_list l7 = most_answered_questions(tad, 10, begin2, end2);
  for(i=0; i<10; i++)
    printf("%ld\n", get_list(l7,i));
  t7 = clock() - t7;
  a1 = ((double) t7) /CLOCKS_PER_SEC *1000;
  printf("Q7: %f ms \n",a1 );
  free_list(l7);
/*

  t8 = clock();
  LONG_list l8 = contains_word(tad, "Nexus", 10);
  for(i=0; i<10; i++)
    printf("%ld\n", get_list(l8,i));
  t8 = clock() - t8;
  a1 = ((double) t8) /CLOCKS_PER_SEC *1000;
  printf("Q8: %f ms \n",a1);
  free_list(l8);
*/
/*
  t9 = clock();
  LONG_list l9 =  both_participated(tad, 1465, 16575, 13);
  for(i=0; i<13; i++)
    printf("%ld\n", get_list(l9,i));
  t9 = clock() - t9;
  a1 = ((double) t9) /CLOCKS_PER_SEC *1000;
  printf("Q9: %f ms \n",a1);
  free_list(l9); 
*/

/*
  t10 = clock();
  long l10= better_answer(tad, 154309);
  printf("%ld\n", l10);
  t10 = clock() - t10;
  a1 = ((double) t10) /CLOCKS_PER_SEC *1000;
  printf("Q10: %f ms \n",a1);

*/
  tad = clean(tad);
  free(tad);

  return 0;
}
