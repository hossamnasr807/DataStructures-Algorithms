// these are solutions for some problems on Linked List data structure. The problems are available in the pdf file inside the same folder.
#include <iostream>
using namespace std;
struct Node {
    int data { };
    Node* next { };
    Node(int data) : data(data) {}
    ~Node() {
    cout << "Destroy value: " << data <<" at address "<< this<< "\n";
        }
    };
class LinkedList {
private:
	Node *head { };
	Node *tail { };
	int length = 0;	// let's maintain how many nodes
public:
    //q1 O(1)memory , O(n)time

    ~LinkedList(){
Node*currentptr;
while(head){
    currentptr=head;
    head=head->next;
    delete currentptr;
}

}

    //q2
void insert_front(int value){
Node*new_head=new Node(value); // do not forget memory allocation syntax;
    if(!head)
        head=tail=new_head;
    else {
        new_head->next=head;
        head=new_head;

        }
}

    //q3
void delete_front(){
 Node*current=head;
 head=head->next;
 delete current;

}


    //q4
    Node*get_nthfromtheback(int n){       // (out of bounds ) // it means he wants for example the 6th element in a 5 elements list;
                                            // always do not forget special cases ;
    Node*currentptr=head;                   // why < length-n+1 not <= for ex if want the 2nd elemnt from the front ,
                                            //since the increment statement is inside the body of the loop if the ptrr was at one and we inc then ptr now is at 2
                                            // so if it entered the loop one more time it will inc and  be = 3 so when we print the data it will be 3rd element not 2nd which is required
    if (length<n)return nullptr;            // another solution , (i=0;i<length-n;i++)
    for(int i=1;i<length-n+1;i++){

        currentptr=currentptr->next;

    }
    return currentptr;
    }
    //q5 
    bool is_same(const LinkedList&new_list){
    if(length!=new_list.length)
        return false;
    Node* new_ptr=new_list.head;
    for(Node*current=head;current;current=current->next){
        if(current->data!=new_ptr->data)
        return false ;
        new_ptr=new_ptr->next;
    }
    return true;
    }
    // q5 with no length variable
    bool is_same_nolength(const LinkedList&new_list){
    Node* new_ptr=new_list.head;
    Node* current=head;
    while(head&&new_ptr){
     if(current->data!=new_ptr->data)
        return false ;
    new_ptr=new_ptr->next;
    current=current->next;
    }
    return !new_ptr&&!current; // to check for the length as if one of them wasnt null it means one of them is greater than the other;


    }
    //q6
    void print_new(){
    for(Node*currentptr=head;currentptr;currentptr=currentptr->next) // already implemented
        cout<<currentptr->data;
    }

    Node*get_tail(){
    Node*prev=nullptr; // a  better solution was to stop the for loop if currentptr->next == null , this way you wouldn't need a previous variable;
    for(Node*currentptr=head;currentptr;prev=currentptr,currentptr=currentptr->next){}
    return prev;
    }

    void add_element(int value){
    Node*tail=get_tail();
    Node*new_node=new Node(value);
    tail->next=new_node;
    tail=new_node;
    }
    // q6 another solution using the head approach if you do not want to get the tail first;
    void add_element2(int value){   // but be careful you have to maintain entering the data in a reversed order;
    Node*new_head=new Node(value);  // ex: if you enter 15 10 8 6 it will be 6->8->10->15->null
    new_head->next=head;
    head=new_head;
    }};
int main()
{
    return 0;
}
