
#include <stdlib.h>
#include <stdio.h>
// Frendy Lio

struct Node {
	int val;
	struct Node * next;
};

void displayList(struct Node *head);
void destroyList(struct Node *head);
struct Node * initList(int n); 
struct Node * weave(struct Node * head);
struct Node * rotate_right(struct Node * head, int k);
struct Node * createNode(int val);

void main(void) 
{
struct Node * head;
printf("Weave an even length list\n");
head = initList(10);
displayList(head);
head = weave(head);
displayList(head);
destroyList(head);

printf("Weave an odd length list\n");
head = initList(9);
displayList(head);
head = weave(head);
displayList(head);
destroyList(head);

printf("Rotate to the right by 7 nodes\n");
head = initList(10);
displayList(head);
head = rotate_right(head,7);
displayList(head);
destroyList(head);
}

struct Node * weave(struct Node * head)
{
    // First we need to count how many elements in the array
    int count = 0;
    struct Node * current = head;
    while (current != NULL){
        count = count + 1;
        current = current->next;
    }

    // Then we need to know where to cut the node
    int cut;
    cut = count/2 + 1; // we cut on that one
        // If odd add + 1
        if ((count%2) == 1){
            cut = cut + 1;
        }

    // Make 2 nodes one with the left, another with the righ
    struct Node* Left;
    struct Node* Right;
    struct Node* DummyLeft;
    struct Node* DummyRight;
    // Restart Current node and count
    current = head;
    count = 0;

    // Initilialize the heads of the Left and RIght Node
    Left = createNode(current->val);

    while (count < cut - 1){
        current = current->next;
        count = count + 1;
    }

    Right = createNode(current->val);

    // Populate Left
        //Reset Count and heead
        current = head;
        count = 0;
    DummyLeft = Left;

    while(count < cut - 2){
        current = current->next;
        DummyLeft->next = createNode(current->val);
        DummyLeft = DummyLeft->next;
        count = count + 1;
    }
    DummyLeft->next = NULL;

    // Populate Right
    DummyRight = Right;
        // since we declared at the start we using next.
    while(current->next->next != NULL){
        current = current->next;
        DummyRight->next = createNode(current->next->val);
        DummyRight = DummyRight->next;
    }
    DummyRight->next = NULL;
        // No need Null because Null will be get at the end of the loop

    // Now do the weave.
    struct Node* weave;
    struct Node* Dummyweave;
    DummyRight = Right;
    DummyLeft = Left;

        //head of weave
        weave = createNode(DummyLeft->val);

        Dummyweave = weave;
        DummyLeft = DummyLeft->next;
        while(DummyLeft != NULL || DummyRight != NULL){
            if (DummyRight != NULL){
                Dummyweave->next = createNode(DummyRight->val);
                Dummyweave = Dummyweave->next;
                DummyRight = DummyRight->next;
            }
            if (DummyLeft != NULL){
                Dummyweave->next = createNode(DummyLeft->val);
                Dummyweave = Dummyweave->next;
                DummyLeft = DummyLeft->next;
            }
        }
        Dummyweave->next = NULL;

return weave;
}

struct Node * rotate_right(struct Node * head, int k)
{
    int rotate_times = 0;
    int size = 1;
    struct Node* rotate;
    struct Node* DummyRotate;
    struct Node* getHead;

    rotate = createNode(head->val);
    DummyRotate = rotate;

    // Make Current
    struct Node * current = head;
    struct Node* loop = head;

    // Make Dummy
    while (head->next != NULL){
        head = head->next;
        DummyRotate->next = createNode(head->val);
        DummyRotate = DummyRotate->next;
        size = size + 1;

    }

    //Make Head
    while (head->next != NULL){
        head = head->next;
        getHead->next = createNode(head->val);
        getHead = getHead->next;
    }
    DummyRotate->next = NULL;

    //Reset DummyRotate
    DummyRotate = rotate;
    int i = 1;
    int count = 0;
    int countsize = 0;
    int endvalue = 0;

    // How many times do i need to rotate
    while (rotate_times < k){


        while(i < size){
        
            // This is to move to the address so we can fchange the value
            while(count < i){
                DummyRotate = DummyRotate->next;
                count = count + 1;
            }

            // Change value.
            DummyRotate->val = loop->val;

            // Move value
            loop = loop->next;
            
            // Reset
            if (loop == NULL){
                loop = current;
            }

            //reset count and Dummyrotate so we can go to correct address
            count = 0;
            DummyRotate = rotate;

            // Increase i so we can go to the next address
            i = i  + 1;
        }
        rotate_times = rotate_times + 1;
        countsize = 0;
        i = 1;
    }

    i =0;
    // set tail
        //if it goes over the size to rotate
        
    while (size - k < 0){
        size = size + size;
    }
    while ( i < size - k){
        current = current->next;
        i = i + 1;

        // if goes to null reset
        if (current == NULL){
            current = head;
        }
    }

    rotate->val = current->val;

return rotate;
}

struct Node * createNode(int val)
{
struct Node * p = (struct Node *) malloc(sizeof(struct Node));
p->val = val;
p->next = NULL;
return p;
}

void destroyNode(struct Node *p)
{
free(p);
}


struct Node * initList(int n) 
{
if (n<=0) return NULL;
struct Node * head = createNode(0);
struct Node * p = head;
for (int i=1; i<n; i++) {
    p->next = createNode(i);
    p = p->next;
}
return head;
}

void destroyList(struct Node *head)
{
for (struct Node *p = head; p!=NULL;) {
    struct Node * temp = p;
    p = p->next;
    free(temp);
}
}

void displayList(struct Node *head)
{
for (struct Node *p = head; p!=NULL; p=p->next) {
	printf("->%d",p->val); 
}
printf("\n");
}
