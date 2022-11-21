#include <stdlib.h> 
#include <stdio.h>
 
typedef struct list_tag { 
    int data; 
    struct list_tag *next; 
} list; 
 
 
list * first(list*L) { return L; } 
list * next(list*L) { return L->next; } 
 
list * last(list*L) 
{ 
    while( L->next ) L = L->next; 
    return L; 
} 

 
void insert_after(list*L,list*p,list*n) 
{ 
    n->next = p->next; 
    p->next = n; 
} 
 
void insert_before(list*L, list*head, list*n) 
{ 
    insert_after(L,head,n); 
    int tmp = head->data; 
    head->data = n->data; 
    n->data = tmp; 
}
 
/*list* delete_item(list* root, list *n)
{
    list *temp;
    temp = root;
    while (temp->next != n) 
    { 
        temp = temp->next;
        if(temp->next == 0) return 0;
    }
    temp->next = n->next; // переставляем указатель
    free(n); // освобождаем память удаляемого узла
    return(temp);
}
*/

 
list* search(list*L, int key) 
{ 
    /*for(L->next; L; L=L->next){
        if(L->data == key) return L;
    }
    return 0; 
    */
    L = L->next;
    while (L->next){
        if (L->data == key) return L;
        L = L->next;
    }
    return 0;
}

void delete(list* L, int num) 
{ 
    list* n = search(L, num);
    if(n != 0){
        //printf("*%d*", n);
        list* after_n = n->next; 
        // меняем данные со следующим 
        int data = after_n->data;
        after_n->data = n->data; 
        n->data = data; 
        // удаляем после n 
        n->next = n->next->next;
        after_n->next = NULL; 
        free(after_n);
    }
} 
 
list* create(int data) 
{ 
    list *n = malloc(sizeof(list)); 
    n->next = 0; 
    n->data = data; 
    return n; 
} 
void insert_at_the_end(list* L, int n){
    list* elem = create(n);
    list* p = last(L);
    elem->next = p->next; 
    p->next = elem;    
}

void fill(list* L, int N){
    list* n;
    for (int i=0;i<=N;i++){ 
        n=create(rand()); 
        printf("%d\n", n->data); 
        insert_after(L, last(L),n); 
    } 
    printf("\n-----------------------------------\n");
}

void print_list(list* L){
    list* n;
    for(n=L->next;n;n=n->next){ 
        printf("%d\n", n->data); 
    } 
    printf("\n---------------------------------\n");
}
 
int main(void) 
{  

    list* K = create(0);
    fill(K, 5);
    //printf("*%d*", search(K, 0)->data);
    insert_after(K, K, create(0));
    delete(K,0);
    //print_list(K);
    //delete(K, 41);
    //insert_after(K, search(K, 6334), create(10));
    print_list(K);
    printf("*%d*", sizeof(list));
}