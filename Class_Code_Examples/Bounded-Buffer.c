//SHARED DATA 

#define BUFFER_SIZE 10;

Typedef struct{
    ...
}item;

item buffer[BUFFER_SIZE];
int in = 0;
int out =0;


//Insert Method
while(true){
    /* Produce an item*/
    while (((in +1)% BUFFER_SIZE)== out);
    /*do nothing -- no free buffers*/
    buffer[in] = item;
    in = (in +1)% BUFFER_SIZE
}

//Remove method

while(true){
    while(in == out);
// do nothing -- nothing to consume

    //remove an item from the bufffer
    item = buffer[out];
    out = (out + 1) % BUFFER_SIZE;
    use(item);
}