#include<bits/stdc++.h>
using namespace std ;

int mutex = 1 , empty = 5 , full = 0 ;
vector<int>store( 5 ) ;
int in = 0 , out = 0 ;

void acquire( int &s ) {
     while ( s == 0 ) {

     }
     s -- ;
}

void release( int &s ) {
     s ++ ;
}

void producer ( int item ) {
    // check is there any space left 
    acquire( empty ) ;
    acquire( mutex ) ;
    cout<<"Produced item is : "<<item<<endl ;
    store[( in ) ] = item ;
    in = ( in + 1 ) % 5 ;
    release( mutex ) ; 
    release( full ) ;
}

void consumer () {
    acquire( full ) ;
    acquire( mutex ) ;
    int item = store[out] ;
    cout<<"Consumed item is : "<<item<<endl ;
    out = ( out + 1 ) % 5 ; 
    release( mutex) ;
    release( empty ) ;
}

int main() {
    
    producer( 50 ) ;
    producer( 43 ) ;
    producer( 12 ) ;
    producer( 10 ) ;
    consumer() ;
    consumer( ) ;

    return 0 ;
}
