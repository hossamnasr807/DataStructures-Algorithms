#include <iostream>
#include <cassert>
using namespace std;
    class Vector{

    private:
    int *arr=nullptr; // intialize array as nullptr at the start
    int size=0;    // size inputed by the user
    int capacity; //actual size of the internal array

    public:          // public usually have all public functions,methods and set and get.It also has constructor and destructor
    Vector(int size): size(size){ // parameterized constructor to initialize the pointer(array) with the inputed size . It takes a size as argument.
    capacity=size*2; //initializing the capacity in the constructor
    if (size<0)                             // this line of code size(size) assigns the member variable "size" of the class "vector" to the argument given and inputed by the user ---->> (size)
    size=1;
    arr=new int[capacity]{}; //This line dynamically allocates memory on the heap for an integer array of the actual size not the given size from user unlike the past sessions.
                        //The new keyword is used to allocate memory. The int[capacity] part specifies that an array of integers of the actual size should be created.
                       //The { } part initializes all elements of the array to 0.

    };

    ~Vector(){    //destructor
                 // in dynamic arrays and dynamic memory allocation Make sure you don't forget to explicitly free memory using delete keyword after finishing to prevent memory leaks
    delete []arr;
    arr=nullptr;}

    void set_arr(int idx,int value){
    assert(0<=idx&&idx<size);
    arr[idx]=value;
    }

    int get_arr(int idx){
    assert(0<=idx&&idx<size);
    return arr[idx];
    }

    int find_arr(int value){
    for(int i=0;i<size;i++){
        if(arr[i]==value)
            return i;}
    return -1; //NOT FOUND // enta 8by f45 ew3a t7ot el return -1 gwa el loop 34an kda awl m m4 hyla2y el rqm from 1st iteration  hy return -1 w 5lsna 3la kdea

    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i];
        }
    cout<<endl;
    }

    void push_back(int value){
    if(size==capacity)
        expand_capacity();
    arr[size]=value;
    size++;
    }

    void expand_capacity(){
    capacity*=2; //double the capacity to double the actual array size
    int*arr2=new int[capacity]{}; // initializing all the elements of the new ptr(array) at first to its default values which is 0
    for(int i=0;i<size;i++){ // move old data into new array
        arr2[i]=arr[i];
        }
    swap(arr,arr2);
    delete[]arr2;
            }

    void insert_arr(int idx,int value){
    assert(0<=idx&&idx<size); // any function has index w should check first if the given index if proper;
    if(size==capacity)
        expand_capacity(); // check for special case if the array is filled so we expand its capacity to be able to shift the elements;
    for(int p=size-1;p>=idx;p--){
        arr[p+1]=arr[p];
        }
    arr[idx]=value;
    size++;
        }

    void right_rotate(){
    int last_element=arr[size-1];
    for(int p=size-2;p>=0;p--){

        arr[p+1]=arr[p];
    }
    arr[0]=last_element;
    }
    void left_rotate(){
    int first_element=arr[0];
    for(int p=1;p<=size-1;p++){

        arr[p-1]=arr[p];
    }
    arr[size-1]=first_element;
    }
    int pop(int idx){           //using left shift method
    int removed_val=arr[idx];
    assert(0<=idx&&idx<size);
    for(int p=idx+1;p<=size-1;p++){
        arr[p-1]=arr[p];

    }
    size--; // 7rka creative gdn w mohma mgt4 fe baly 34an el array elly el user faker en dah el size bta3ha for example (5) msln
                //f beltaly lma a4eel wa7ed mn el size a5r elemnt hyt4al bel nsba ll user w lw geet 3mlt print ll array by loop from 0 to size elly asb7 (4)
                // htla2y el element el a5eer mt4al;

    cout<<"removed value is : ";            //Very important in special case if we want to delete last element the loop in function won't work since p would be equal to size
            // and not enter the loop but the size-- would however remove the last element which is required to be removed;
    return removed_val;
    }
    void right_rotates(int times){
    int rotations = times%size; // since the order of the array resets to default after size times // for ex if size equal 5 and times = 26
    for(int i=0;i<rotations;i++){
        right_rotate();

    }                          // 26%5=1 therefore it is equivalent as if we rotated only one time
                             // (similar as rotation angle 360 degree+ one another rotation)

    }
    int find_transposition(int value){ // function act as the original find function but once you find the required value you shift one step left
                                      //  shift here means swap indicies not overwrite unlike problems 1,2
    for (int i=0;i<size;i++){
        if(arr[i]==value){
            if(i==0)return 0; // special case if index =0 AKA---->>> cant be shifted left again //  VI REVISION;
            swap(arr[i],arr[i-1]);
            return i-1;
            }
            }

    }
    };



    int main(){

Vector v(5); // the size inputed by the user ;
	for (int i = 0; i < 5; ++i)
		v.set_arr(i, i);
    cout<<"before any modifications \n";
	v.print();
	cout<<v.find_arr(6)<<" "<<v.find_arr(55); // lw el function feha cout already mn gwa e3mlha call bs enma lw feha return bs mn gwa e3mlha cout 34an ttbe the value of the return statement
    v.right_rotate();cout<<endl;
    cout<<"after right rotation\n";
    v.print();
    v.left_rotate();
    cout<<"after left rotation\n";
    v.print();
    v.right_rotates(20000000000006); // ms2la 7lwa gdn; feha fkra rw4a
    cout<<"after n right rotations\n";
    v.print();
    cout<<"new position of element after transposition:\n";
    cout<<v.find_transposition(4)<<endl;
    cout<<"after transposition of an element in vector\n";
    v.print();
    cout<<v.pop(4);
    cout<<"\nafter removing an element of index n\n";
    v.print();
    return 0;
    }
