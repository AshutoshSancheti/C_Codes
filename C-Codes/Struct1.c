#include<stdio.h>
#include<stdlib.h>
struct textbook
{
 char name[10];
 int bid;
 float price;
 int numaut;
 char autlist[5][10];
};

struct class
{
 int nobooks;
 struct textbook *booklist;               //since booklist is declared as a pointer so it can be used as an array of "textbook"
};
typedef struct class std;

void readclassinfobyref(std *s,int clno,int nb)
{
 int i,j;
 s->booklist=(struct textbook*)malloc(nb*sizeof(struct textbook));
 // s[cl_no -1].booklist = rest is same
 for(i=0;i<nb;i++)
 {
  printf("enter details:");
  scanf("%s",&(s->booklist[i].name));
  scanf("%d",&(s->booklist[i].bid));           //&s[cl_no -1].booklist[i].bid
  scanf("%f",&(s->booklist[i].price));
  scanf("%d",&(s->booklist[i].numaut));
  for(j=0;j<s->booklist[i].numaut;j++)
  scanf("%s",&(s->booklist[i].autlist[j]));
 }
}
void printclassinfo(std s,int clno)
{
 int i,j,k;
 printf("%d",(s.nobooks));
 for(i=0;i<s.nobooks;i++)
 {
  printf(" details:");
  printf("%s",(s.booklist[i].name));
  printf("%d",(s.booklist[i].bid));
  printf("%f",(s.booklist[i].price));
  printf("%d",(s.booklist[i].numaut));
  for(j=0;j<s.booklist[i].numaut;j++)
  printf("%s",(s.booklist[i].autlist[j]));
 }
}
void printallinfo(std *s,int nc)
{
 int i,j,k;
 for(k=0;k<nc;k++){
 printf("%d",(s[k].nobooks));
 for(i=0;i<s[k].nobooks;i++)
 {
  printf(" details:");
  printf("%s",(s[k].booklist[i].name));
  printf("%d",(s[k].booklist[i].bid));
  printf("%f",(s[k].booklist[i].price));
  printf("%d",(s[k].booklist[i].numaut));
  for(j=0;j<s[k].booklist[i].numaut;j++)
  printf("%s",(s[k].booklist[i].autlist[j]));
 }}
}
void main()
{
 int nc,ns,i,j;
 std *s;                              //s is declared as a pointer therefore array of "struct class" or "std" is indirectly declared
 printf("enter no of classes:");
 scanf("%d",&nc);
 s=(std*)malloc(nc*sizeof(std));
 for(i=1;i<=nc;i++)
 {
  printf("enter no of textbooks:");
  scanf("%d",&ns);
  readclassinfobyref(&s[i-1],i,ns);
 }
 for(i=0;i<nc;i++)
 {
  printclassinfo(s[i],i);
 }
 printallinfo(s,nc);
}
