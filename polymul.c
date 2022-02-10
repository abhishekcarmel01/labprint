#include<stdio.h>
#include<stdlib.h>


struct Node {
	int pow, coeff;
	struct Node* next;
};

struct Node *add_node(struct Node* start, int coeff, int pow){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->coeff = coeff;
    newnode->pow = pow;
    newnode->next = NULL;
    if (start == NULL){
        return(newnode);
    } else {
        struct Node* ptr = start;
        while (ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = newnode;
        return(start);
    }
}

void display(struct Node *ptr){
    while (ptr->next != NULL){
    	if(ptr->coeff!=0)
            printf("%dx^%d+", ptr->coeff, ptr->pow); 
            ptr = ptr->next;
        }
        printf("%d", ptr->coeff); 
}

void rmDup(struct Node *start){
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
    while(ptr1 != NULL && ptr1->next != NULL){
        ptr2 = ptr1;
        while(ptr2->next != NULL){
            if (ptr1->pow == ptr2->next->pow){
                ptr1->coeff += ptr2->next->coeff;
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
                 
            } else {
                ptr2 = ptr2->next;
            }
        }
        ptr1 = ptr1->next;
    }
}

struct Node *multiply(struct Node *poly1, struct Node *poly2, struct Node *poly){
    struct Node *ptr1, *ptr2;
    int pow, coe;
    ptr1 = poly1;
    ptr2 = poly2;
    while(ptr1 != NULL){
        while(ptr2 != NULL){
            coe = ptr1->coeff * ptr2->coeff;
            pow = ptr1->pow + ptr2->pow;
            poly = add_node(poly, coe, pow);
            ptr2 = ptr2->next;
        }
        ptr2 = poly2;
        ptr1 = ptr1->next;
    }
    rmDup(poly);
    return(poly);
}

void main(){
	struct Node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
    int n, pow, coe, i;
    printf("Enter the number of elements in Polynomial 1: ");
    scanf("%d", &n);
    printf("Enter data in space seperated format. Each element in each line. Coeff <space> power\n");
    for (i=1; i<=n; i++){
        scanf("%d %d", &coe, &pow);
        poly1 = add_node(poly1, coe, pow);
    }
    printf("Enter the number of elements in Polynomial 2: ");
    scanf("%d", &n);
    printf("Enter data in space seperated format. Each element in each line. Coeff <space> power\n");
    for (i=1; i<=n; i++){
        scanf("%d %d", &coe, &pow);
        poly2 = add_node(poly2, coe, pow);
    }
	printf("Polynomial 1: ");
	display(poly1);
	printf("\nPolynomial 2:");
	display(poly2);
	poly = multiply(poly1, poly2, poly);
	printf("\nPolynomial product:");
	display(poly);
	printf("\n");
    
}
