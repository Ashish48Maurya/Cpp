#include<iostream>
#include<vector>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};


void insertAtHead(Node* &head , int data){
Node *n2 = new Node(data);
n2->next = head;
head = n2;
}

void insertAtTail(Node* &head, int data){
//Initialise a pointer pointing to head of linked list which helps in iterating it;
Node* temp = head;
while(temp->next != NULL){
    temp = temp->next;
}
//temp is now pointing to last node
Node* new_node = new Node(data);
temp->next = new_node;
}


void insertAtPosition(Node* head,int pos,int data){
Node* temp = head;
if(pos==0){
    insertAtHead(head,data);
}

int position = 0;
while(position != pos-1){
    temp = temp->next;
    position++;
}

//now temp is pointing to pos-1;
Node* new_node = new Node(data);
new_node->next = temp->next;
temp->next = new_node;
}


void deleteAtHead(Node* &head){
    Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtTail(Node* &head){
 Node* temp = head;
 while(temp->next->next != NULL){
    temp = temp->next;
 }
//now temp is pointing to second last node;
Node* second_last = temp;
temp = temp->next;
second_last->next = NULL;
free(temp);
}

void updateAtPosition(Node* &head,int pos, int val){
Node* temp = head;
int position = 0;
while(position != pos){
temp = temp->next;
position++;
}
temp->data = val;
}

void deleteAltNodes(Node* &head){
    Node* curr_node = head;
    while(curr_node != NULL  and curr_node->next != NULL){
        Node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp);
        curr_node = curr_node->next;
    }
}


void deleteAtPosition(Node* head, int pos){
    if(pos==0){
        deleteAtHead(head);
        return;
    }
int num = 0;
Node* curr = head;
while(num<pos-1){
    num++;
    curr = curr->next;
}
Node* temp  =  curr->next;
curr->next =curr->next->next;
free(temp);
}


Node* remeovedup(Node* &head){
    if(head==NULL){
        return NULL;
    }
Node* curr_node = head;
while(curr_node != NULL){
    while(curr_node->next != NULL and curr_node->data == curr_node->next->data){
       Node* temp = curr_node->next;
        curr_node->next = curr_node->next->next;
        free(temp); 
    }
    curr_node = curr_node->next;
}
return head;
}


Node* reverseLL(Node* &head){
    if(head==NULL){
        return NULL;
    }
Node* prev = NULL;
Node* curr = head;
while(curr != NULL){
    Node* nextt = curr->next;
    curr->next = prev;
    //Move all three pointers one step ahead
    prev = curr;
    curr = nextt;
}
//When this loops ends prev pointer is then pointing to last node which is now new head
return prev;
}


bool same_or_not(Node* &head1 , Node* &head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1 != NULL and ptr2 != NULL){
        if(ptr1->data != ptr2->data){
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    //We will be out of the loop , only when ptr1 is Null or ptr2 will be Null or both will be Null
    //if we will be out of the loop just because one of  pointer has become null than return false
    //Because if one of the pointer has become null it means length of LL is not equal -> they are not same
    return (ptr1==NULL and ptr2==NULL);
}


int length(Node* &head){
Node* temp = head;
int length = 0;
while(temp!=NULL){
    ++length;
    temp=temp->next;
}
return length;
}


Node* moveHeadByk(Node* &head, int k){
    Node* ptr = head;
    while(k>0){
        ptr=ptr->next;
        k--;
    }
    return ptr;
}


void intersect(Node* &head1 , Node* &head2 , int pos){
Node* temp1 = head1;
Node* temp2 = head2;

while(pos>0){
temp1=temp1->next;
pos--;
}

while(temp2->next!=NULL){
temp2=temp2->next;
}
temp2->next = temp1;
}


int getIntersection(Node* &head1,Node* &head2){

    //Calculate length
    int l1 = length(head1);
    int l2 = length(head2);

    Node* ptr1;
    Node* ptr2;
    if(l1>l2){
        int k = l1-l2;
        ptr1 = moveHeadByk(head1,k);
        ptr2 = head2;
    }
    else{
        int k = l2-l1;
        ptr1 = head1;  
        ptr2 = moveHeadByk(head2,k);
    }

    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}


//Given 2 sorted linked list merge them and return that mergerd sorted LL
Node* merge_2_sorted_ll(Node* &head1, Node* &head2){
    //if linkdlist 1 is empty then return linked list 2;
    if(head1==NULL){
        return head2;
    }

    if(head2==NULL){
        return head1;
    }
    Node* dummy_node = new Node(-1);
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* temp3 = dummy_node;


    while(temp1!=NULL && temp2!=NULL){
        if(temp1->data > temp2->data){
            temp3->next = temp2;
            temp2 = temp2->next;
        }
        else{
            temp3->next = temp1;
            temp1 = temp1->next;
        }
        temp3 = temp3->next;
    }

    if(temp1==NULL){
        temp3->next = temp2;
    }
    if(temp2==NULL){
        temp3->next = temp1;
    }
    return dummy_node->next;
}


Node* mergeKLinkedList(vector<Node*> &lists){
    int n = lists.size();
if(n==0){
    return NULL;
}

while(n>1){
Node* ans1 = merge_2_sorted_ll(lists[0],lists[1]);
lists.push_back(ans1);
lists.erase(lists.begin());
lists.erase(lists.begin());
n--;
}
return lists[0];
}


//If their is racing competition b/w 2 person  and if 1st person is running with speed x and other person is moving with speed 2x , than when 2nd person is reached to destination then first person is present at middle of track;

//Same logic is applied here we are moving two pointer with speed x and 2x and when fast moving pointer reached at last node at that time slow moving pointer is present at middle node of LL and than we are returning that slow pointer;
int findMiddleNode(Node* &head){
    
Node* slow = head;
Node* fast = head;
//for even Number of Nodes = fast->next!=NULL
//for odd Number of Nodes = fast!=NULL
while(fast->next!=NULL && fast!=NULL){
slow = slow->next;
fast = fast->next->next;
}
return slow->data;
}


void makeCycle(Node* &head, int pos){
    Node* temp = head;
    Node* startNode;
    int count = 1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next = startNode;
}


bool detectCycle(Node* &head){

    if(head==NULL){
        return false;
    }

    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL and fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            cout<<"slow and fast pointer are meet at a Node whose data is "<<slow->data<<endl;
            return true;
        }
    }
    return false;
}


void removeCycle(Node* &head){
    Node* slow = head;
    Node* fast = head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    
    fast = head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next = NULL;
}

//lec-2 CollegeWallah , time-stamp -> 2:02:00
bool isPalindrome(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* curr = slow->next;
    Node* prev = slow;
    slow->next = NULL;

    while(curr){
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    }

    Node* head1 = head;
    Node* head2 = prev;
    while(head2){
        if(head1->data != head2->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}


// 1->2->3->4->5->6  
//for k=1;  =>   6->1->2->3->4->5;  
//for k=2;  =>   5->6->1->2->3->4;
Node* rotateByK(Node* &head , int k){
    int n=0;
    Node* end = head;
    while(end->next != NULL){
        n++;
        end = end->next;
    }
    n++;  //for including last node
    end->next = head;
    k = k%n;
    if(k==0){
        return head;
    }
    Node* temp = head;
    for(int i=1; i<n-k; i++){
        temp = temp->next;
    }
    Node* new_head = temp->next;
    temp->next = NULL;
    return new_head;
}

//swap 2-adjacent node of linked list  1->2->3->4->5->6   =>  2->1->4->3->6->5;Self work swap first 2 adj node and then attach 2nd node with the rest of the swapped LL recursive work =>  return the head of the rest swapped LL (i.e -> 3rd node)
Node* swapAdj(Node* &head){
if(head==NULL or head->next ==NULL){
    return head;    //Base Case;
}
Node* second_node = head->next;
head->next = swapAdj(second_node->next); // head->next will point to the head   returned by recursive case;    1->4->3->6->5;
second_node->next = head; // reversing the linked between head and second_node;      2->1
return second_node;
}


//return the head of LL which contains first all odd_node followed by all even_node   
//(e.g) 1->2->3->4->5->6  =>    1->3->5->2->4->6;
Node* oddEven(Node* &head){
    if(head==NULL or head->next == NULL){
        return head;
    }

    Node* evenHead = head->next;
    Node* oddptr = head;
    Node* evenptr = head->next;
    while(evenptr and evenptr->next){
        oddptr = oddptr->next->next;
        evenptr = evenptr->next->next;
        oddptr = oddptr->next;
        evenptr = evenptr->next;
    }
    oddptr->next = evenHead;
    return head;
}                                                              

void display(Node* &head){
Node* temp = head;
while(temp != NULL){
cout<<temp->data<<"->";
temp = temp->next;
}
cout<<"NULL"<<endl;
}

int main(){

// Node *n1 = new Node(2);
// cout<<n1->data<<" "<<n1->next<<endl;

///Node* head = NULL;
// insertAtHead(head,4);
// display(head);
// insertAtHead(head,2);
// display(head);
// insertAtTail(head,5);
// display(head);
// insertAtPosition(head,2,7);
// display(head);
// deleteAtHead(head);
// display(head);
// deleteAtTail(head);
// display(head);
// insertAtTail(head,9);
// display(head);
// updateAtPosition(head,1,8);
// display(head);

// insertAtTail(head,1);
// insertAtTail(head,2);
// insertAtTail(head,3);
// deleteAltNodes(head);
// display(head);

// insertAtHead(head,4);
// insertAtHead(head,4);
// insertAtHead(head,2);
// insertAtHead(head,2);
// insertAtTail(head,5);
// insertAtTail(head,9);
// display(head);
// Node* new_head = remeovedup(head);
// display(new_head);

// insertAtHead(head,4);
// insertAtHead(head,2);
// insertAtHead(head,3);
// insertAtTail(head,5);
// insertAtTail(head,9);
// display(head);
// Node* new_head = reverseLL(head);
// display(new_head);

// Node* head1 = NULL;
// insertAtHead(head1,4);
// insertAtHead(head1,2);
// insertAtHead(head1,3);
// insertAtTail(head1,5);
// insertAtTail(head1,9);
// display(head1);
/*                     */
// Node* head2 = NULL;
// insertAtHead(head2,4);
// insertAtHead(head2,2);
// insertAtHead(head2,3);
// insertAtTail(head2,5);
// insertAtTail(head2,9);
// insertAtTail(head2,10);
// display(head2);
// cout<<same_or_not(head1,head2)<<endl;

// Node* head1 = NULL;
// insertAtHead(head1,4);
// insertAtHead(head1,2);
// insertAtHead(head1,3);
// insertAtTail(head1,5);
// insertAtTail(head1,9);
// display(head1);
// Node* head2 = NULL;
// insertAtHead(head2,6);
// insertAtHead(head2,11);
// insertAtHead(head2,39);
// display(head2);
// intersect(head1,head2,2);
// display(head2);
// cout<<getIntersection(head1,head2);

// Node* head1 = NULL;
// insertAtHead(head1,7);
// insertAtHead(head1,5);
// insertAtHead(head1,3);
// insertAtHead(head1,0);
// insertAtTail(head1,8);
// display(head1);
// Node* head2 = NULL;
// insertAtHead(head2,39);
// insertAtHead(head2,7);
// insertAtHead(head2,1);
// display(head2);
// Node* ans = merge_2_sorted_ll(head1, head2);
// display(ans);

// Node* head1 = NULL;
// insertAtHead(head1,7);
// insertAtHead(head1,5);
// insertAtHead(head1,3);
// insertAtHead(head1,0);
// insertAtTail(head1,8);
// display(head1);
// Node* head2 = NULL;
// insertAtHead(head2,39);
// insertAtHead(head2,7);
// insertAtHead(head2,1);
// display(head2);
// Node* head3 = NULL;
// insertAtHead(head3,22);
// insertAtHead(head3,15);
// insertAtHead(head3,10);
// display(head3);
// vector<Node*> vec;
// vec.push_back(head1);
// vec.push_back(head2);
// vec.push_back(head3);
// Node* ans = mergeKLinkedList(vec);
// display(ans);

// Node* head = NULL;
// insertAtHead(head,1);
// insertAtHead(head,4);
// insertAtHead(head,9);
// insertAtTail(head,11);
// insertAtTail(head,12);
// display(head);
// cout<<"Data of Middle Node is: "<<findMiddleNode(head);

// Node* head = NULL;
// insertAtHead(head,1);
// insertAtHead(head,2);
// insertAtHead(head,3);
// insertAtHead(head,4);
// insertAtHead(head,5);
// insertAtHead(head,6);
// insertAtHead(head,7);
// insertAtHead(head,8);
// cout<<"LL before making Cycle"<<endl;
// display(head);
// makeCycle(head,3);
// cout<<detectCycle(head)<<endl;
// removeCycle(head);
// cout<<detectCycle(head)<<endl;

// Node* head = NULL;
// insertAtHead(head,3);
// insertAtHead(head,2);
// insertAtHead(head,1);
// insertAtTail(head,4);
// insertAtTail(head,3);
// insertAtTail(head,2);
// insertAtTail(head,1);
// display(head);
// cout<<isPalindrome(head)<<endl;

// Node* head = NULL;
// insertAtHead(head,3);
// insertAtHead(head,2);
// insertAtHead(head,1);
// insertAtTail(head,4);
// insertAtTail(head,3);
// insertAtTail(head,2);
// insertAtTail(head,1);
// display(head);
// Node* ans = rotateByK(head,3);
// display(ans);

// Node* head = NULL;
// insertAtHead(head,6);
// insertAtHead(head,5);
// insertAtHead(head,4);
// insertAtHead(head,3);
// insertAtHead(head,2);
// insertAtHead(head,1);
// display(head);
// Node* ans = swapAdj(head);
// display(ans);

Node* head = NULL;
insertAtHead(head,6);
insertAtHead(head,5);
insertAtHead(head,4);
insertAtHead(head,3);
insertAtHead(head,2);
insertAtHead(head,1);
display(head);
Node* ans = oddEven(head);
display(ans);

return 0;
}