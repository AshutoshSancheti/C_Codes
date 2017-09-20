/****************************************************************************************************************
Implement the following three functions:
1) PTR Add_Node_List(PTR list, player ps)
2) int Best_Team(player tp[], int np, player team[])
3) player Read_Player_Info(player q)
Please read the comments inside the functions for details regarding their functionality.
The following utility function is given to you that can be used for testing:
void Print_List(PTR list)
Note:
1) You have to upload only the three functions implementations in the appropriate boxes on uploading site.
2) You are not suppose to modify any of the structure and typedefinitions given in the question.
3) You can assume all user inputs (where ever applicable) are valid and correct.
**************************************************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

typedef enum {GL=1,DD,KKR,SRH,RPS,MI,KXIP,RCB,WORLDTEAM} team_name;
typedef enum {ROHIT=1,PRAVEEN,DHONI,SMITH,RAINA,GAUTI} player_name;
typedef int match_played;
typedef int highest_score;

typedef struct {
player_name pname;
team_name tname;
match_played mp;
highest_score hs;
} player;

struct node;
typedef struct node NODE;
typedef  NODE* PTR;

struct node
{
    player p;
    PTR link;
};

PTR Add_Node_List(PTR list, player ps)
{
/*This function inserts a new node (with player ps in it) in the list if the highest_score of the player ps is greater than atleast one of the existing players highest_score in the list.
The new node should be inserted in the list such that all the nodes in the list are in increasing order with respect to the match_played by the players.     MAX MARKS[30]
This function will have partial marking*/
    PTR temp = list;
    int flag =0;
    NODE* p1 = (NODE*)malloc(sizeof(NODE));
    p1->p = ps;
    p1->link = NULL;
    while(temp->link!=NULL)
    {
        if((ps.hs)>(temp->p).hs)
        {
            printf("\n%d\n",(temp->p).hs);
            flag =1; ///Flag = 1 indicates that this node is to be inserted into the list
            printf("flag 1\n");
            break;
        }
        temp = (temp->link);
    }

    ///Reseting temp to point to the first node
    PTR damn = list;
    PTR a=NULL;
    if(flag == 1)
    {
printf("\nflag 2\n");
        while((damn->p).mp<(ps.mp) && (damn) != NULL)
        {
            printf("\nflag 3\n");
            a=damn;
            damn = (damn->link);

        }
        ///We get the position at which the new node has to be inserted
        ///temp points to the node having matches played greater than ps
        if(a)
        p1->link = a->link;
        a->link = p1;
        //return list;
        return temp;
    }

    else
        return temp;           ///Both can be used interchangeably
        //return list;
}


int Best_Team(player tp[], int np, player team[]) {
/* A player is a star player if he has played more than 100 matches and his highest score is greater than and equal to 100.
This function finds and copies all the star players from tp[] to team[]. The tp[] contains np number of players.
Change the team name for every star player in team[] to WORLDTEAM (as defined at the top in team_name).
The function returns the number of players that had been copied from tp[] to team[].    MAX MARKS[12.5]
This function has binary grading (either 0 or 12.5M) */
    int i,count =0;
    for(i=0;i<np;i++)
    {
        if((tp[i].mp) >100 && (tp[i].hs)>=100)
        {
            team[count].pname = tp[i].pname;
            team[count].tname = WORLDTEAM;
            team[count].mp = tp[i].mp;
            team[count].hs = tp[i].hs;
            count++;
        }
    }
return count;

}

player Read_Player_Info(player q)
{
/* This function takes the details of player q as user input and returns the player q.
Read the details in the following order: player name, team name, match played, and highest score. MAX MARKS[10]
This function has binary grading (either 0 or 10M) */
    printf("Please enter the player name(ROHIT=1,PRAVEEN,DHONI,SMITH,RAINA,GAUTI):");
    scanf("%d",&q.pname);
    printf("Please enter the team name(GL=1,DD,KKR,SRH,RPS,MI,KXIP,RCB,WORLDTEAM):");
    scanf("%d",&q.tname);
    printf("Please enter the no. of matches played:");
    scanf("%d",&q.mp);
    printf("Please enter the highest score:");
    scanf("%d",&q.hs);
    return q;

}


void Print_List(PTR list) {
PTR t;
t=list;
while(t!= NULL) {
printf("(%d %d %d %d)-->",t->p.pname,t->p.tname, t->p.mp, t->p.hs);
t=t->link;
}
printf("NULL");
}

int main()
{
    player p,p1;
   // p1 = Read_Player_Info(p);
/* Here you can declare appropriate variables, do initializations and function calls to test your function implementations */
   // printf("\n%d",p1.pname);
   // printf("\n%d",p1.tname);
   // printf("\n%d",p1.mp);
   // printf("\n%d",p1.hs);
   // int i =WORLDTEAM;
   // printf("\n%d\n",i);

    NODE* first = (NODE*)malloc(sizeof(NODE));
    NODE* second = (NODE*)malloc(sizeof(NODE));
    NODE* third = (NODE*)malloc(sizeof(NODE));

    (first->p).pname = 1;
    (first->p).tname = 1;
    (first->p).mp = 99;
    (first->p).hs = 99;
    first->link = second;

    (second->p).pname = 2;
    (second->p).tname = 2;
    (second->p).mp = 100;
    (second->p).hs = 100;
    second->link = third;

    (third->p).pname = 4;
    (third->p).tname = 4;
    (third->p).mp = 103;
    (third->p).hs = 103;
    third->link = NULL;

    player ashu;
    ashu.pname = 3;
    ashu.tname = 3;
    ashu.mp =102;
    ashu.hs =102;

    Add_Node_List(first, ashu);

    Print_List(first);
    return 0;
}
