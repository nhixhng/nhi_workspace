#include <stdio.h>
#include <stdlib.h>

#define MATRIX_M 3
#define MATRIX_N 3

typedef struct Node{
    int data; 
    struct Node* next;
} node_t;

// creates a new indipendent node
// points to NULL address to be sure no random address is accessed
// writes data in node
// returns address of new node
node_t* create_new_node(int data){
    node_t* new_node = malloc(sizeof(node_t) * data);
    new_node->data = data;
    new_node->next = NULL;
    return new_node; 
}

// creates new node with helper function
// saves current head address in the next pointer(which was previously NULL)
// so now new Node's next pointer points to address of previous head
// returns the new node, which is now the new head of the linked list
node_t* insert_node_as_head(node_t* head, int data){
    node_t* new_node;
    new_node = create_new_node(data);
    new_node->next = head;
    return new_node;
}

// creates node with helperfunction
// recursively searching the last element, which is pointing to NULL
// inserts new node at NULL 
// returns new node and saves it's address as the next pointer of the previous element
// --> this will go on and end in the original head until all recursive funciton calls have finished
node_t* insert_node_as_tail(node_t* head, int data){
    node_t* new_node;
    if (head == NULL){
        head = create_new_node(data);
    }else{
        head->next = insert_node_as_tail(head->next, data);
    }
    return head;
}

// initialize linked list with data
// as example this function initializes 3x3 matrices
node_t* initialize_linked_list(node_t* new_list, 
        int a, int b, int c, int d, int e, int f, int g, int h, int i){
    new_list = insert_node_as_head(new_list, a);
    new_list = insert_node_as_head(new_list, b);
    new_list = insert_node_as_head(new_list, c);
    new_list = insert_node_as_head(new_list, d);
    new_list = insert_node_as_head(new_list, e);
    new_list = insert_node_as_head(new_list, f);
    new_list = insert_node_as_head(new_list, g);
    new_list = insert_node_as_head(new_list, h);
    new_list = insert_node_as_head(new_list, i);
    return new_list;
}

// inititalizes linked list with data recursively 
// as example this function initializes 3x3 matrices
node_t* initialize_linked_list_recursive(node_t* new_list,
        int a, int b, int c, int d, int e, int f, int g, int h, int i){
    new_list = insert_node_as_tail(new_list, a);
    new_list = insert_node_as_tail(new_list, b);
    new_list = insert_node_as_tail(new_list, c);
    new_list = insert_node_as_tail(new_list, d);
    new_list = insert_node_as_tail(new_list, e);
    new_list = insert_node_as_tail(new_list, f);
    new_list = insert_node_as_tail(new_list, g);
    new_list = insert_node_as_tail(new_list, h);
    new_list = insert_node_as_tail(new_list, i);
    return new_list;
}

// return how many elements with equal data contains the linked list
// easy version: count elements while iterating threw linked list
// here: find number of specific integers
int number_of_elements_iter_easy(node_t* head, int number){
    int counter = 0;
    while(head != NULL){
        if(head->data == number){
            counter++;
        }
        head = head->next;
    }
    return counter;
}

// return how many elements with equal data contains the linked list
// harder version: creating a new linked list which saves found values
// count elements by counting all elements of new created linked list
// here: find number of specific integers 
int number_of_elements_iter_harder(node_t* head, int number){
    int counter = 0;
    node_t* counter_linked_list = NULL;
    while(head != NULL){
        if(head->data == number){
            node_t * new_node;
            new_node = create_new_node(number);
            new_node->next = counter_linked_list;
            counter_linked_list = new_node; 
        }
        head = head->next;
    }
    while(counter_linked_list != NULL){
        counter++;
        counter_linked_list = counter_linked_list->next;
    }
    return counter;
}

// return how many elements with equal data contains the linked list
// easy version: count elements while iterating threw linked list recursively 
// here: find number of specific integers
int number_of_elements_rec_easy(node_t* head, int number, int counter){
    if (head != NULL){
        if(head->data == number){
            counter++;
            counter = number_of_elements_rec_easy(head->next, number, counter);
        }else{
            counter = number_of_elements_rec_easy(head->next, number, counter);
        }
    }
    return counter;
}

// initializes the matrix array with values stored in the linked lists
int** initialize_array(int** array, node_t* head, int rows, int cols){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (head != NULL){
                array[i][j] = head->data;
                head = head->next;
            }
            else{
                printf("Failed to initialize array!");
                exit(0);
            }
        }
    }
    return array;
}

// allocating memory for cols of an array 
void malloc_cols(int rows, int cols, int** array){
    for(int i = 0; i < rows; i++){
        array[i] = malloc(sizeof(int) * cols);
    }
}

// free memory of array
void free_array(int** array, int rows){
    for(int i = 0; i < rows; i++){
        free(array[i]);
    }
}

// free memory of linked list
void free_linked_list(node_t* head){
    node_t* next;
    while (head != NULL){
        next = head->next;
        free(head);
        head = next;
    }    
}

// prints a matrix to stdout
void printmat(int** mat, int rows, int cols, char name[3]){
    printf("Matrix %s:\n", name);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// matrices addition
void matadd(int** a, int** b, int** sum, int rows, int cols){
    printf("Matrices addition\n");
    printmat(a, rows, cols, "A  ");
    printmat(b, rows, cols, "B  "); 
    int i, j;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            sum[i][j] = a[i][j] + b[i][j];
        };
    };
    printmat(sum, rows, cols, "A+B");
}

// matrices multiplication
void matmult(int** a, int** b, int** sum, int rows, int cols){
    printf("Matrices multiplication\n");
    printmat(a, rows, cols, "A  ");
    printmat(b, rows, cols, "B  "); 
    int temp_sum;
    int i, j, k; 
    for(i=0; i < rows; i++){
        for (k=0; k < MATRIX_M; k++){
            temp_sum = 0;
            for (j=0; j < MATRIX_N; j++){
                temp_sum += (a[i][j] * b[j][k]);
            }
            sum[i][k] = temp_sum;
        }
    }
    printmat(sum, rows, cols, "A*B");
}

int main(){
    // constant variables for rows and cols of arrays
    const int rows = 3;
    const int cols = 3;

    // defining linked lists for initializing matrix values
    node_t* matrix_list_a = NULL;
    node_t* matrix_list_b = NULL;

    // initializing with choosen values of type int
    // example initialization
    //matrix_list_a = initialize_linked_list(matrix_list_a, 9, 3, 2, 1, 4, 6, 5, 6, 2);
    //matrix_list_b = initialize_linked_list(matrix_list_b, 2, 1, 3, 4, 5, 1, 3 ,2, 1);

    // example recursive initialization
    matrix_list_a = initialize_linked_list_recursive(matrix_list_a, 9, 3, 2, 1, 4, 6, 5, 6, 2);
    matrix_list_b = initialize_linked_list_recursive(matrix_list_b, 2, 1, 3, 4, 5, 1, 3 ,2, 1);

    // initializing a pointer to a pointer of an array
    // allocating size for each pointer to an array 
    int** A = malloc(sizeof(int*) * rows);
    int** B = malloc(sizeof(int*) * rows);
    int** sum = malloc(sizeof(int*) * rows);

    // allocating memmory for each array(representing cols) of a pointer(representing rows)
    // each pointer points to another array --> this is how to implement two dimensional arrays
    // as last step there has to be initialized a pointer to a pointer that points to that array 
    // this indicates a two dimensional array 
    malloc_cols(rows, cols, A);
    malloc_cols(rows, cols, B);
    malloc_cols(rows, cols, sum);

    // initializing arrays with values
    A = initialize_array(A, matrix_list_a, rows, cols);
    B = initialize_array(B, matrix_list_b, rows, cols);

    // call functions
    matmult(A, B, sum, rows, cols);
    //matadd(A, B, sum, rows, cols);
    //printf("Number of elements '%d' in linked list: %d\n", 2, number_of_elements_iter_easy(matrix_list_a, 2));
    //printf("Number of elements '%d' in linked list: %d\n", 2, number_of_elements_rec_easy(matrix_list_a, 2, 0));
    //printf("Number of elements '%d' in linked list: %d\n", 2, number_of_elements_iter_harder(matrix_list_a, 2));

    // free memory
    free_array(A, rows);
    free(A);
    free_array(B, rows);
    free(B);
    free_array(sum, rows);
    free(sum);
    free_linked_list(matrix_list_a);
    free_linked_list(matrix_list_b);
}