

//Stack implementation

int arr[5];
top=-1;

push(x){
    arr[++top]=x;
}

pop(){
    top--;
}

top(){
    return arr[top];
}

size(){
    return top+1;
}

isEmpty(){
    return (top==-1);
}