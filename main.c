/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Paarth
 *
 * Created on March 19, 2017, 4:56 PM
 */

#include <stdio.h> /* Allows for input and output */
#include <stdlib.h> 
#include <pthread.h> /* allows for threads */



//predefining a function that 
void* say_hello(void* data){
    
    char *str; //creates a pointer to a string called str
    str = (char*)data; // converts data to a string pointer and points/stores address in str
    
    while(1){ //always gonna run
        
        printf("%s \n", str);// prints the address of character data
        sleep(1); // makes the program sleep for 1 second
            
    }
    
}



/*
 * 
 */
int main(int argc, char** argv) {
    
    
    pthread_t t1, t2; //creates the first 2 threads
    
    
    //initializes the return threads 
    
    //format of the pthread_create(address of the p_thread, pointer to the p_threads attributes, start routine of the p_thread, arguments of the p_thread )
    //pthreads attribute functions aren't really neccissary, which is why they're NULL in this example and specified at creation time
    //pthreads attribute can hold info about the scheduling policy and stack size if initialized
    
    
    //start routine is the function the thread executes
    // void pointer passes to any start routine -> passes to any start toutine as well
    
    pthread_create(&t1, NULL, say_hello, "hello from 1");
    pthread_create(&t2, NULL, say_hello, "hello from 2");
    
   //waits for the thread specified in the first argument to exit, then initializes the second thread (locks the thread) 
    
   //prototype works like this: pthread_join(thread waiting to exit, address of the status variable)    
   //status variable is the value returned by the function that thread starts executing
    
    
   //in this case, because in the function it's specified as while(1), this will always be true and result in an infinite loop
    
    pthread_join(t1, NULL);
    
    
    
    
    return (EXIT_SUCCESS);
}

