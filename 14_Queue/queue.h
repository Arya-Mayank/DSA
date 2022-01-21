
class Queue{

    int *arr; //pointer to array
    int cs; //current size
    int ms; //maximum size
    int front;
    int rear;

    public: 
    //constructor
    Queue(int default_size =5){
        ms = default_size;
        arr = new int[ms];
        cs =0;
        front =0;
        rear = ms-1;
    }

    bool full(){
        return cs==ms;
    }

    void push(int data){
        if(!full()){
            //take rear to next index
            rear = (rear+1)%ms;
            // push at rear
            arr[rear]=data;
            //increase current size by one
            cs++;
        }
    }

    bool empty(){
        return cs ==0;
    }

    void pop(){
        if(!empty()){
            front = (front+1)%ms;
            cs--;
        }
    }

    int getFront(){
        return arr[front];
    }

};