//                  //Linear Search
// #include<stdio.h>
// int linearSearch(int arr[] , int key , int size){
//     int ans = -1;
//     for(int i=0; i<size; i++){
//         if(arr[i] == key){
//             ans = i;
//             break;
//         }
//     }
//     return ans;
// }

// int main(){
//     int arr[] = {10,25,8,22,4,0,19,2,16};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int ans = linearSearch(arr , 22 , size);
//     printf("%d ",ans);
//     return 0;
// }





//                  //Binary Search
// #include<stdio.h>
// int binarySearch(int arr[] , int key , int size){
//     int ans = -1;
//     int l = 0;
//     int r = size-1;
//     while(r>=l){
//         int middle = (l+r)/2;
//         if(arr[middle] == key){
//             return middle;
//         }
//         if(arr[middle]>key){
//             r = middle-1;
//         }
//         if(arr[middle]<key){
//             l = middle+1;
//         }
//     }
//     return ans;
// }

// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int ans = binarySearch(arr , 9 , size);
//     if(ans==-1){
//         printf("Element is Not Present\n");
//     }
//     else{
//         printf("Element is present at position: %d",ans);
//     }
//     return 0;
// }





//                  //Binary Search -> Recursive
// #include<stdio.h>
// int binarySearch(int arr[], int key, int l , int r){
//     int middle = (l+r)/2;
//     if(arr[middle]==key){
//         return middle;
//     }
//     if(l>r){
//         return -1;
//     }
//     else if(arr[middle] > key){
//         return binarySearch(arr , key , l , middle-1);
//     }
//     else if(arr[middle] < key){
//         return binarySearch(arr , key , middle+1 , r);
//     }
// }

// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     int ans = binarySearch(arr,0,0,size-1);
//     if(ans==-1){
//         printf("Element is Not Present\n");
//     }
//     else{
//         printf("Element is present at position: %d",ans);
//     }
//     return 0;
// }





//                  //Bubble Sort -> Stable Sorting Algorithm
// #include<stdio.h>

// void swap(int *a , int *b){
//     int temp = *a;
//     *a=*b;
//     *b=temp;
// }

// void bubbleSort(int arr[] , int size){
//     for(int i=0; i<size-1; i++){  //Outer Loop
//         for(int j=0; j<size-1; j++){
//             if(arr[j] > arr[j+1]){
//                 swap(&arr[j],&arr[j+1]);
//             }
//         }
//     }
// }

// int main(){
//     int arr[] = {10,25,8,22,4,0,19,2,16};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     bubbleSort(arr,size);
//     for(int i=0; i<size; i++){
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }




//                  //Selection Sort -> Unstable Sorting Algorithm
// #include<stdio.h>
// void swap(int *a , int *b){
//     int temp = *a;
//     *a=*b;
//     *b=temp;
// }

// void selectionSort(int arr[], int size){
//     for(int i=0; i<size-1; i++){
//         int min_idx = i;        //Give the Smallest Element present in the array
//         for(int j=i+1; j<size; j++){
//             if(arr[j]<arr[min_idx]){
//                 min_idx = j;
//             }
//         }
//         swap(&arr[i] , &arr[min_idx]);
//     }
// }

// int main(){
//     int arr[] = {10,25,8,22,4,0,19,2,16};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     selectionSort(arr,size);
//     for(int i=0; i<size; i++){
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }




//                  //Insertion Sort -> Stable Sorting Algorithm
// #include<stdio.h>
// void insertionSort(int arr[], int size){
//     for(int i=1; i<size; i++){
//         int currentEle = arr[i];
//         int j = i-1;
//         while(j>=0 && currentEle < arr[j]){
//             arr[j+1] = arr[j];
//             j--;
//         }
//         arr[j+1] = currentEle;
//     }
// }

// int main(){
//     int arr[] = {10,25,8,22,4,0,19,2,16};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     insertionSort(arr,size);
//     for(int i=0; i<size; i++){
//         printf("%d ",arr[i]);
//     }
//     return 0;
// }


//                     //Trees
// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>
// struct Node{
//     int data;
//     struct Node *left;
//     struct Node *right;
// };

// struct Node *createNode(int value){
//     struct Node *temp =  (struct Node*)malloc(sizeof(struct Node));
//     temp->data = value;
//     temp->left = NULL;
//     temp->right = NULL;
//     return temp;
// }



//                     // Insert
// struct Node *insertBST(struct Node* root , int value){
//     if(root==NULL){
//         return createNode(value);
//     }
//     if(root->data > value){
//         root->left = insertBST(root->left , value);
//     }
//     else if(root->data < value){
//         root->right = insertBST(root->right , value);
//     }
//     return root;
// }


//                     // Delete
// struct Node *maxValueNode(struct Node* root){
//     struct Node *temp =  root;
//     while(temp->right!=NULL){
//         temp = temp->right;
//     }
//     return temp;
// }

// struct Node* deleteNode(struct Node*root, int value){
//     if(root==NULL){
//         return root;
//     }
//     if(root->data >  value){
//         root->left = deleteNode(root->left , value);
//     }
//     else if(root->data <  value){
//         root->right = deleteNode(root->right , value);
//     }
//     else{ 
//         if(root->left == NULL && root->right == NULL){  
//             free(root);
//             return NULL;
//         }
//         else if(root->left == NULL){ 
//             struct Node* temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if(root->right == NULL){  
//             struct Node* temp = root->left;
//             free(root);
//             return temp;
//         }
//         else{                              
//             struct Node *justSmallestNode = maxValueNode(root->left);
//             root->data = justSmallestNode->data;
//             root->left = deleteNode(root->left , justSmallestNode->data);
//         }
//     }
//     return root;
// }



//                     //Search
// bool searchNode(struct Node *root , int value){
//     if(root==NULL){
//         return false;
//     }
//     if(root->data == value){
//         return true;
//     }
//     if(root->data > value){
//         return searchNode(root->left , value);
//     }
//     else if(root->data < value){
//         return searchNode(root->right , value);
//     }
//     return false;  //if element is not present
// }



//                 //Number of Nodes
// int noOfNodes(struct Node *root){
//     if(root==NULL){
//         return 0;
//     }
//     int left = noOfNodes(root->left);
//     int right = noOfNodes(root->right);
//     return (left+right)+1;
// }

                //Height of BST
// int maxHeight(struct Node *root){
//     if(root==NULL){
//         return 0;
//     }
//     int leftHeight = maxHeight(root->left);
//     int rightHeight = maxHeight(root->right);
//     if(leftHeight>rightHeight){
//         return leftHeight+1;
//     }
//     return rightHeight+1;
// }

                        //No. of Internal Nodes
// void printInternalNodes(struct Node* root) {
//     if (root == NULL) {
//         return;
//     }

//     printInternalNodes(root->left);
//     if (root->left != NULL && root->right != NULL) {
//         printf("%d ", root->data);
//     }
//     printInternalNodes(root->right);
// }

//                     //Traversal Method
// void inOrder(struct Node* root){
//     if(root==NULL){
//         return;
//     }
//     inOrder(root->left);
//     printf("%d ",root->data);
//     inOrder(root->right);
// }

// void preOrder(struct Node *root){
//     if(root==NULL){
//         return;
//     }
//     printf("%d ",root->data);
//     preOrder(root->left);
//     preOrder(root->right);
// }

// void postOrder(struct Node *root){
//     if(root==NULL){
//         return;
//     }
//     postOrder(root->left);
//     postOrder(root->right);
//     printf("%d ",root->data);
// }


//                          Mirror A BST                        
// void mirror(struct Node* root){
//     if(root==NULL){
//         return;
//     }
//     mirror(root->left);
//     mirror(root->right);
//     struct Node *temp = root->right;
//     root->right = root->left;
//     root->left = temp;
// }

// int main(){
//     struct Node* root = NULL;
//     root = insertBST(root,50);
//     insertBST(root,30);
//     insertBST(root,70);
//     insertBST(root,20);
//     insertBST(root,40);
//     insertBST(root,60);
//     insertBST(root,80);
//     insertBST(root,25);

//     return 0;
// }



//              QuickSort -> Taking last element as a pivot point
// #include<iostream>
// using namespace std;

// int partitionPoint(int arr[], int first, int last){
//     int j = first;
//     int i = first-1;
//     int pivotEle = arr[last];
//     for(; j<last-1; j++){
//         if(pivotEle > arr[j]){
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[last]);
//     return i+1;
// }

// void quickSort(int arr[], int first , int last){
//    if(first>=last){
//     return;
//    }
//    int pivot = partitionPoint(arr,first,last);
//    quickSort(arr,first,pivot-1);
//    quickSort(arr,pivot+1,last);
// }

// int main(){
//     int arr[] = {1,4,9,6,0,11,3};
//     quickSort(arr,0,6);
//     for(int i=0; i<7; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }



//                     MergeSort
// #include<iostream>
// using namespace std;

// void merge(int arr[], int first, int mid, int last){
//     int a = mid+1;   //mid - first + 1;
//     int b = last - mid;
//     int arr1[a], arr2[b] = {0};

//     for(int i = 0; i < a; i++){
//         arr1[i] = arr[first + i];
//     }

//     for(int i = 0; i < b; i++){
//         arr2[i] = arr[mid + 1 + i];
//     }

//     int i = 0, j = 0, k = first;

//     while(i < a && j < b){
//         if(arr1[i] > arr2[j]){
//             arr[k++] = arr2[j++];
//         } else {
//             arr[k++] = arr1[i++];
//         }
//     }

//     while(i < a){
//         arr[k++] = arr1[i++];
//     }

//     while(j < b){
//         arr[k++] = arr2[j++];
//     }
// }


// void mergeSort(int arr[], int first, int last){
//     if(first>=last){
//         return;
//     }
//     int mid = (first+last)/2;
//     mergeSort(arr,first,mid);
//     mergeSort(arr,mid+1,last);
//     merge(arr,first,mid,last);
// }

// int main(){
//     int arr[] = {1,4,9,6};
//     mergeSort(arr,0,4);
//     for(int i=0; i<4; i++){
//         cout<<arr[i]<<" ";
//     }
//     return 0;
// }



//                                 DFS
// #include <stdio.h>
// int visited[7] = {0, 0, 0, 0, 0, 0, 0};
// int matrix[7][7] = {{0, 1, 1, 3, 0, 0, 0},
//                     {1, 0, 1, 1, 0, 0, 0},
//                     {1, 1, 0, 1, 1, 0, 0},
//                     {1, 1, 1, 0, 1, 0, 0},
//                     {0, 0, 1, 1, 0, 1, 1},
//                     {0, 0, 0, 0, 1, 0, 0},
//                     {0, 0, 0, 0, 1, 0, 0}};

// void DFS(int i){
//     printf("%d ",i);
//     visited[i] = 1;
//     for(int j=0; j<7; j++){
//         if(matrix[j][i]==1 && visited[j]!=1){
//             DFS(j);
//         }
//     }
// }

// int main()
// {
//     DFS(0);
//     return 0;
// }




//                                 BFS
// #include<stdio.h>
// #include<stdbool.h>
// #include<stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* node, *temp;

// struct Queue {
//     int size;
//     struct Node* head;
//     struct Node* tail;
// };

// struct Queue* queue;

// struct Queue* createQueue() {
//     queue = (struct Queue*)malloc(sizeof(struct Queue));
//     queue->size = 0;
//     queue->head = NULL;
//     queue->tail = NULL;
//     return queue;
// }

// struct Node* createNode(int data) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->next = NULL;
//     node->data = data;
//     return node;
// }

// void enqueue(int data) {
//     queue->size++;
//     node = createNode(data);
//     if (queue->head == NULL) {
//         queue->head = queue->tail = node;
//     }
//     queue->tail->next = node;
//     queue->tail = node;
// }

// int dequeue() {
//     if (queue->head == NULL) {
//         printf("Queue is empty");
//         return 0;
//     }
//     queue->size--;
//     temp = queue->head;
//     queue->head = temp->next;
//     int data = temp->data;
//     free(temp);
//     return data;
// }

// void display() {
//     if (queue->head == NULL) {
//         printf("Queue is empty\n");
//         return;
//     }
//     temp = queue->head;
//     while (temp != NULL) {
//         printf("%d->", temp->data);
//         temp = temp->next;
//     }
//     printf("NULL\n");
// }

// bool isEmpty() {
//     return queue->head == NULL;
// }

// int main() {
//     queue = createQueue();
//     int i = 0;
//     int visited[7] = {0, 0, 0, 0, 0, 0, 0};
//     int matrix[7][7] = {{0, 1, 1, 3, 0, 0, 0},
//                         {1, 0, 1, 1, 0, 0, 0},
//                         {1, 1, 0, 1, 1, 0, 0},
//                         {1, 1, 1, 0, 1, 0, 0},
//                         {0, 0, 1, 1, 0, 1, 1},
//                         {0, 0, 0, 0, 1, 0, 0},
//                         {0, 0, 0, 0, 1, 0, 0}};

//     visited[i] = 1;
//     enqueue(i);
//     while (!isEmpty()) {
//         int node = dequeue();
//         printf("%d ", node);
//         for (int j = 0; j < 7; j++) {
//             if (matrix[node][j] == 1 && visited[j] == 0) {
//                 visited[j] = 1;
//                 enqueue(j);
//             }
//         }
//     }
//     return 0;
// }




//                                 Fibonacii Search
// #include <stdio.h>

// int min(int x, int y) {
//     return (x <= y) ? x : y;
// }

// int fibonacciSearch(int arr[], int n, int x) {
//     int fib2 = 0; 
//     int fib1 = 1; 
//     int fib = fib1 + fib2;

//     // Find the smallest Fibonacci Number greater than or equal to n
//     while (fib < n) {
//         fib2 = fib1;
//         fib1 = fib;
//         fib = fib1 + fib2;
//     }

//     int offset = -1;

//     while (fib > 1) {
//         int i = min(offset + fib2, n - 1);

//         // If x is greater than the value at index fib2 , Move Backward by 1 step
//         if (arr[i] < x) {
//             fib = fib1;
//             fib1 = fib2;
//             fib2 = fib - fib1;
//             offset = i;
//         }
//         // If x is less than the value at index fib2, Move Backward by 2 step
//         else if (arr[i] > x) {
//             fib = fib2;
//             fib1 = fib1 - fib2;
//             fib2 = fib - fib1;
//         }
//         // If x is found
//         else
//             return i;
//     }

//     if (fib1 && arr[offset + 1] == x){
//         return offset + 1;
//     }

//     return -1;
// }

// int main() {
//     int arr[] = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int x = 85;
//     int result = fibonacciSearch(arr, n, x);
//     if (result != -1)
//         printf("Element found at index %d\n", result);
//     else
//         printf("Element not found in the array\n");
//     return 0;
// }




//                                 Priority Q
// #include<stdio.h>
// #include<stdlib.h>
// struct Node{
//     int data;
//     int priority;
//     struct Node *next;
// };
// struct Node *temp,*node;

// struct Queue{
//     struct Node *front;
// };
// struct Queue *q;

// struct Queue *createQueue(){
//     struct Queue* node = (struct Queue*)malloc(sizeof(struct Queue));
//     node->front = NULL;
// }

// struct Node* createNode(int data, int priority) {
//     struct Node* node = (struct Node*)malloc(sizeof(struct Node));
//     node->next = NULL;
//     node->priority = priority;
//     node->data = data;
//     return node;
// }

// void enqueue(int data , int priority){
//     node = createNode(data,priority);
//     if(q->front==NULL || q->front->priority < priority){
//         node->next = q->front;
//         q->front = node;
//     }
//     else{
//         temp = q->front;
//         while(temp->next!=NULL && temp->next->priority > priority){
//             temp = temp->next;
//         }
//         node->next = temp->next;
//         temp->next = node;
//     }
// }

// void dequeue(){
//     if(q->front==NULL){
//         return;
//     }
//     temp = q->front;
//     q->front = temp->next;
//     free(temp);
// }

// void display(){
//     temp = q->front;
//     while(temp!=NULL){
//         printf("element %d have priority %d\n",temp->data , temp->priority);
//         temp=temp->next;
//     }
// }

// int main(){
//     q = createQueue();
//     enqueue(1,1);
//     enqueue(3,2);
//     enqueue(2,3);
//     display();
//     dequeue();
//     display();
//     return 0;
// }                                



//                                 //Balanced Bracket
// #include<iostream>
// #include<stack>
// using namespace std;

//     bool isValid(string S){
//         int n=S.size();
//         stack<char> st;
//         bool ans= true;    //Assume kar liya ki valid hi hoga
//         for(int i=0; i<n; i++){
//             if(S[i]=='(' or S[i]=='{' or S[i]=='['){
//                 st.push(S[i]);
//             }
//             else if(S[i]==')'){
//                 if(st.top()=='('){
//                     st.pop();
//                 }
//                 else{
//                      ans = false;
//                      break;
//                 }
//             }
//             else if(S[i]=='}'){
//                 if(st.top()=='{'){
//                     st.pop();
//                 }
//                 else{
//                      ans = false;
//                      break;
//                 }
//             }
//             else if(S[i]==']'){
//                 if(st.top()=='['){
//                     st.pop();
//                 }
//                 else{
//                      ans = false;
//                      break;
//                 }
//             }
//         }    
//       if(st.empty()){
//         return true;
//       }
//       else{return ans;}
//     }
// int main(){
//     // string S = "[{()}]";
//     string S = "[{(}])";
//     if(isValid(S)){
//         cout<<"Valid String"<<endl;
//     }
//     else{
//         cout<<"Invalid String"<<endl;
//     }
// return 0;
// }




//                                 //Infix to Postfix
// #include<iostream>
// #include<stack>
// #include<math.h>
// using namespace std;
// int prec(char ch){
//     if(ch=='^'){return 3;}
//     else if(ch=='*' or ch=='/'){return 2;}
//     else if(ch=='+' or ch=='-'){return 1;}
//     else{return -1;}
// }
// string infixToPostfix(string s){
//     stack<char> st;
//     string res;
//     for(int i=0; i<s.length(); i++){
//         if(s[i]>='a' and s[i]<='z'){
//            res += s[i];
//         }
//         // if(s[i]>='A' and s[i]<='Z'){
//         //      res += s[i];
//         // }
//         else if(s[i]=='('){
//             st.push(s[i]);
//         }
//         else if(s[i]==')'){
//             while(!st.empty() and st.top()!='('){
//               res += st.top();
//               st.pop();
//             }
//             st.pop();
//         }
//         else{
//             while(!st.empty() and prec(s[i])<prec(st.top())){
//                 res+=st.top();
//                 st.pop();
//             }
//             st.push(s[i]);
//         }
//     }

//     while(!st.empty()){
//         res += st.top();
//         st.pop();
//     }

//     return res;
// }

// int main(){
//     string s = "(a-b/c)*(a/k-l)";
//     cout<<infixToPostfix(s)<<endl;
//     return 0;
// }                                                             