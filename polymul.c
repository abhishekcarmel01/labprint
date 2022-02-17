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






#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char data;
	struct node *left;
	struct node *right;
	struct node *next;
};

struct node *head = NULL;

struct node* createnode(char data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp -> data = data;
	temp -> left = NULL;
	temp -> right = NULL;
	temp -> next = NULL;

	return temp;
	
}

void push(struct node *ptr)
{
	if(head == NULL)
		head = ptr;
	else
	{
		ptr -> next = head;
		head = ptr;
	}
}

struct node* pop()
{
	struct node *ptr = head;
	if(head != NULL)
	head = head -> next;
	return ptr;
}


void inorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		inorder(ptr -> left);
		printf("%c", ptr->data);
		inorder(ptr -> right);
	}
}


void preorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		printf("%c", ptr -> data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void postorder(struct node *ptr)
{
	if(ptr == NULL)
		return;
	else
	{
		postorder(ptr -> left);
		postorder(ptr -> right);
		printf("%c", ptr -> data);
	}
}


int main()
{

	struct node *a, *b, *exp;
	char s[100];
	printf("\nEnter the postfix expression : ");
	scanf("%s", s);
	//printf("%s", s);
	int l = strlen(s);
	for(int i = 0; i < l; i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^')
		{
			exp = createnode(s[i]);
			a = pop();
			b = pop();
			exp -> left = b;
			exp -> right =a;
			push(exp);
		}
		else
		{
			exp = createnode(s[i]);
			push(exp);
		}
	}

	exp = pop();
	printf("\nInorder Traversal : ");
	inorder(exp);
	printf("\nPreorder Traversal : ");
	preorder(exp);
	printf("\nPostorder Traversal gives : ");
	postorder(exp);
	return 0;
}








// Create a graph using adjascency matrix and traverse using Breadth First Scan and Depth First Scan.


#include<stdio.h>

int Graph[20][20], visited[20], n;

void DFS(int i)
{
    int j;
    printf("\n%d", i);
    visited[i] = 1;
    for(j=1; j<=n; j++)
        if(!visited[j] && Graph[i][j]==1)
            DFS(j);
}

void DFS_main(){
    for(int i=1; i<=n; i++)
        visited[i] = 0;

    DFS(1);
}

int queue[20], front=0, rear=-1;

void BFS(int v){
    visited[v] = 1;
    printf("\n%d", v);
    for(int i=1; i<=n; i++){
        if(Graph[v][i] && !visited[i]){
            queue[++rear] = i;
            visited[i] = 1;
        }
    }
    if(front<=rear){
        BFS(queue[front++]);
    }
}

void BFS_main(){
    for(int i=1; i<=n; i++){
        visited[i] = 0;
    }
    BFS(1);
}

void main() {
    int choice=0;
    do {
        printf("\n\n\nMENU \n");
        printf("1. Enter Graph details\n");
        printf("2. DFS \n");
        printf("3. BFS \n");
        printf("4. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter the number of vertices: ");
                scanf("%d", &n);
                printf("Enter the adjacency matrix of the graph: \n");
                for(int i=1; i<=n; i++)
                    for(int j=1; j<=n; j++)
                        scanf("%d", &Graph[i][j]);
                break;
            case 2:
                DFS_main();
                break;
            case 3:
                BFS_main();
                break;
            case 4:
                printf("Exiting");
                break;
            default:
                printf("Invalid choice");
        }
    } while(choice!=4);
}





#include<stdio.h>

int array1[100], array2[100], array3[100],n;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[100],int lb,int ub){
    int pivot = array[lb], start=lb, end=ub;
    while(start<end){
        while(array[start]<=pivot)
            start++;
        while(array[end]>pivot)
            end--;
        if(start<end)
            swap(&array[start],&array[end]);
    }
    swap(&array[lb],&array[end]);
    return end;
}

int QuickSort(int array[100],int lb,int ub){
    if(lb<ub){
        int loc = partition(array,lb,ub);
        QuickSort(array,lb,loc-1);
        QuickSort(array,loc+1,ub);
    }
}

void merge(int array[100],int lb,int mid,int ub){
    int temp[100];
    int i,j,k;
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
        if(array[i]<array[j])
            temp[k++]=array[i++];
        else
            temp[k++]=array[j++];

    while(i<=mid)
        temp[k++]=array[i++];
    
    while(j<=ub)
        temp[k++]=array[j++];

    for(int i=lb;i<=ub;i++){
        array[i]=temp[i];
    }
}

void mergeSort(int array[100],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(array,lb,mid);
        mergeSort(array,mid+1,ub);
        merge(array,lb,mid,ub);
    }
}

void heapify(int a[], int n, int i)  
{  
    int largest = i; // Initialize largest as root  
    int left = 2 * i; // left child  
    int right = 2 * i + 1; // right child  
    // If left child is larger than root  
    if (left < n && a[left] > a[largest])  
        largest = left;  
    // If right child is larger than root  
    if (right < n && a[right] > a[largest])  
        largest = right;  
    // If root is not largest  
    if (largest != i) {  
        // swap a[i] with a[largest]  
        swap(&a[i], &a[largest]);
          
        heapify(a, n, largest);  
    }  
}    
void heapSort(int a[], int n)  
{  
    for (int i = n / 2 + 1; i >= 0; i--)  
        heapify(a, n, i);  
    // One by one extract an element from heap  
    for (int i = n - 1; i >= 0; i--) {  
        swap(&a[0], &a[i]); 
          
        heapify(a, i, 0);  
    }  
}  


void printArr()  
{  
    printf("Array 1:\n\t");
    for (int i = 0; i < n; ++i) {  
        printf("%d", array1[i]);  
        printf(" ");  
    }  

    printf("\n\nArray 2:\n\t");
    for(int i = 0; i < n; ++i) {  
        printf("%d", array2[i]);  
        printf(" ");  
    }

    printf("\n\nArray 3:\n\t");
    for(int i = 0; i < n; ++i) {  
        printf("%d", array3[i]);  
        printf(" ");  
    }
          
}

void main()
{
    int i;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    printf("Enter the numbers: \n");
    for(i=0;i<n;i++) {
        scanf("%d",&array1[i]);
        array3[i] = array2[i] = array1[i];
        // printf(array3[i]);
    }
    printf("\n\nElements of the arrays: \n");
    printArr();
    int choice = 0;
    do {
        printf("\n\n\t\tMENU\n1.Quick Sort\n2.Merge Sort\n3.Heap Sort\n4.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
        case 1:
            QuickSort(array1,0,n-1);
            printArr();
            break;
        case 2:
            mergeSort(array2,0,n-1);
            printArr();
            break;
        case 3:
            heapSort(array3,n);
            printArr();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid Choice\n");
        }
    } while(choice !=4 );
}




#include<stdio.h>
#include<stdlib.h>

struct poly_node {
    int coeff;
    int exp;
    struct poly_node *next;
} *head1, *head2, *headprod;


void insert_poly(struct poly_node **head, int co, int ex) {
    struct poly_node *x = (struct poly_node *)malloc(sizeof(struct poly_node));
    x->coeff = co;
    x->exp = ex;
    x->next = NULL;
    if (*head == NULL) {
        *head = x;
    }
    else if((*head)->exp < ex) {
        x->next = *head;
        *head = x;
    }
    else {
        struct poly_node *temp = *head;
        while (temp->next != NULL && temp->next->exp >= ex) {
            temp = temp->next;
        }
        if(temp->exp == ex)
            temp->coeff+=co;
        else 
        {
            x->next = temp->next;
            temp->next = x;
        }
    }
}

void create_poly(struct poly_node **head) {
    int n, co, ex;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient and exponent of term %d: ", i+1);
        scanf("%d %d", &co, &ex);
        insert_poly(head, co, ex);
    }
}

void print_poly(struct poly_node **head){
    struct poly_node *temp = *head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if(temp->exp != 0)
            printf("x^%d ", temp->exp);
        temp = temp->next;
        if(temp != NULL)
            printf("+ ");
    }
    printf("\n");
}

void prod_poly() {
    headprod = NULL;
    int ncoeff, nexp;
    struct poly_node *temp1 = head1;
    struct poly_node *temp2 = head2;
    while(temp1 != NULL) {
        temp2 = head2;
        while(temp2 != NULL) {
            ncoeff = temp1->coeff * temp2->coeff;
            nexp = temp1->exp + temp2 ->exp;
            insert_poly(&headprod, ncoeff, nexp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
}

void main(){
    printf("\n\nPolynomial 1: \n");
    create_poly(&head1);
    printf("\n\nPolynomial 2: \n");
    create_poly(&head2);
    printf("\n\nPolynomial 1 is: \n");
    print_poly(&head1);
    printf("\n\nPolynomial 2 is: \n");
    print_poly(&head2);
    printf("\nProduct of the polynomials is: \n");
    prod_poly();
    print_poly(&headprod);
}
