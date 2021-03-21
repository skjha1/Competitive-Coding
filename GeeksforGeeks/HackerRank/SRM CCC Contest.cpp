I M17 - Reverse Vowels

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    char str[100001],rev[100001];
    int i,j=0;
    scanf("%[^\n]s",str);
    i=0;
    while(str[i])
    {
       if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U') 
       {
           rev[j]=str[i];
           j++;
       }
        i++;
    }
    j--;
    i=0;
    while(str[i])
    {
       if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U') 
       {
           printf("%c",rev[j]);
           j--;
       }
        else 
         printf("%c",str[i]);
        
        i++;
    }
    
    
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------------------------------------


O 02 - Printing the Linked List in Reverse

void ReversePrint(LinkedListNode* head) 
{
    LinkedListNode* temp=head;
    if(temp==NULL)
     return;
    else 
    {
        ReversePrint(temp->next);
        printf("%d ",temp->val);
    }
}


------------------------------------------------------------------------------------------------------------------------------------------

O M01 - Looped List

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

struct Node{
	int value;
	struct Node* next;
};
typedef struct Node Node;
Node links[105];

void add_link(int from, int to){
	links[from].next = &links[to];
}
void set_value(int index, int val){
	links[index].value = val;
}


//BODY BEGINS HERE
int find_loop(Node* head)
{
    Node* f=head;
    Node* s=head;
    while(f!=NULL && f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
        if(s==f)
         return 1;
    }
    return 0;
}
//BODY ENDS HERE

//TAIL BEGINS HERE
int main(){
	int i,n,m,tmp,tmp1,tmp2;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++){
		scanf("%d", &tmp);
		set_value(i, tmp);
	}
	for(i = 0; i < m; i++){
		scanf("%d %d", &tmp1, &tmp2);
		add_link(tmp1,tmp2);
	}
	if(find_loop(&links[0]) == 1) printf("Loop Found");
	else printf("No Loop Found");
	return 0;
}

-------------------------------------------------------------------------------------------------


O M02 - Comparing Two Linked Lists

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode {
    int val;
    LinkedListNode *next;
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, LinkedListNode *tail, int val) {
    if(head == NULL) {
        head = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        head->val = val;
        head->next = NULL;
        tail = head;
    }
    else {
        LinkedListNode *node = (LinkedListNode *) (malloc(sizeof(LinkedListNode)));
        node->val = val;
        node->next = NULL;
        tail->next = node;
        tail = tail->next;
    }
    return tail;
}

//BODY STARTS HERE


/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    int val;
    LinkedListNode *next;
};
*/
int compare(LinkedListNode* headA, LinkedListNode* headB) 
{
    LinkedListNode* x=headA;
    LinkedListNode* y=headB;
    while( x && y )    // while (x!=NULL && y!=NULL)
    {
        if(x->val != y->val)
         return 0;
        x=x->next;
        y=y->next;
    }
    if(x==NULL && y==NULL)
     return 1;
    else 
     return 0;
}


//BODY ENDS HERE

int main()
{
    FILE *f = stdout;
    char *output_path = getenv("OUTPUT_PATH");
    if (output_path) {
        f = fopen(output_path, "w");
    }

    int res;
    int headA_size = 0;

    LinkedListNode* headA = NULL;
    LinkedListNode* headA_tail = NULL;

    scanf("%d\n", &headA_size);
    for(int i = 0; i < headA_size; i++) {
        int headA_item;
        scanf("%d", &headA_item);
        headA_tail = _insert_node_into_singlylinkedlist(headA, headA_tail, headA_item);

        if(i == 0) {
            headA = headA_tail;
        }
    }


    int headB_size = 0;

    LinkedListNode* headB = NULL;
    LinkedListNode* headB_tail = NULL;

    scanf("%d\n", &headB_size);
    for(int i = 0; i < headB_size; i++) {
        int headB_item;
        scanf("%d", &headB_item);
        headB_tail = _insert_node_into_singlylinkedlist(headB, headB_tail, headB_item);

        if(i == 0) {
            headB = headB_tail;
        }
    }


    res = compare(headA, headB);
    fprintf(f, "%d\n", res);

    fclose(f);
    return 0;
}

----------------------------------------------------------------------------------------------------------------------------------

02x00 Maximum Element in the Stack

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int stack[10000001],maxstack[10000001],top=-1,mtop=-1;
int main() 
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int x;
            scanf("%d",&x);
            
            if(mtop==-1 || x>=maxstack[mtop])
                maxstack[++mtop]=x;
            
            stack[++top]=x;
        }
        else if(ch==2)
        {
            if(stack[top]==maxstack[mtop])
                mtop--;
            
            top--;
        }
        else 
            printf("%d\n",maxstack[mtop]);
    }
    
    return 0;
}
---------------------------------------------------------------------------------------------------------------------------------------------

02x04 Captain Tsubasa and his Fest

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long int stack[1000000],top=-1,t,n,id,i;
char ch[10];
void push(long int id)
{
    stack[++top]=id;
}
long int pop()
{
    long int a=stack[top];
    top--;
    return a;
}
void swap()
{
    long int x=pop();
    long int y=pop();
    push(x);
    push(y);
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld",&n,&id);
        push(id);
        for(i=1;i<=n;i++)
        {
           scanf("%s",ch);
           if(ch[0]=='P')
           {
               scanf("%ld",&id);
               push(id);
           }
           else 
           {
               swap();
           }
        }
        printf("Player %ld\n",stack[top]);
    }
    return 0;
}
---------------------------------------------------------------------------------------------------------------------------

02x03 - The MaxMin Card Game

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int stack[100000],minstack[100000],maxstack[100000],top=-1,mintop=-1,maxtop=-1;
int n,x;
char ch[10];
void push(int x)
{
    if(mintop==-1 || x<=minstack[mintop])
        minstack[++mintop]=x;
    if(maxtop==-1 || x>=maxstack[maxtop])
        maxstack[++maxtop]=x;
    stack[++top]=x;
}
void pop()
{
    if(top==-1)
     printf("Invalid\n");
    else 
    {
        if(stack[top]==minstack[mintop])
            mintop--;
        if(stack[top]==maxstack[maxtop])
            maxtop--;
        top--;
    }
}
void min()
{
    if(top==-1)
        printf("Invalid\n");
    else 
        printf("%d\n",minstack[mintop]);
}
void max()
{
    if(top==-1)
        printf("Invalid\n");
    else 
        printf("%d\n",maxstack[maxtop]);
}
 int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",ch);
        if(ch[0]=='A')
        {
            scanf("%d",&x);
            push(x);
        }
        else if(ch[0]=='R')
         pop();
        else if(ch[6]=='n')
            min();
        else 
            max();
    }
    return 0;
}
--------------------------------------------------------------

P 301 - Shortest Man on the Team


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n,minIndex,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    minIndex=0;
    for(i=1;i<n;i++)
    {
        if(a[minIndex]>a[i])
            minIndex=i;
    }
    int t=a[0];
    a[0]=a[minIndex];
    a[minIndex]=t;
    for(i=0;i<n;i++)
     printf("%d ",a[i]);
    return 0;
}

------------------------------------------------------------------------------------------------------------------------------------------

P 302 - A Smaller Team

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int n,minIndex,i,k,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&k);
    for(j=0;j<k;j++)
    {
        minIndex=j;
        for(i=j+1;i<n;i++)
        {
            if(a[minIndex]>a[i])
                minIndex=i;
        }
        int t=a[j];
        a[j]=a[minIndex];
        a[minIndex]=t;
    }
    for(i=0;i<n;i++)
     printf("%d ",a[i]);
    return 0;
}

-------------------------------------------------------------------------------



