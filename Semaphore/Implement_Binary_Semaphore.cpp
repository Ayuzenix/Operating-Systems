#include<bits/stdc++.h>
using namespace std ;

int sem = 3 ; 

queue<int>waiting ;
void acquire( int x ) {
    if ( sem == 0 ) {
        waiting.push( x ) ;
        cout<<"Element "<<x <<" is Waiting !! "<<endl ;
    } else {
        sem -- ;
        cout<<"Element "<<x <<" has Entered into Critical Section !! "<<endl ;
    }
}

void release( int x ) {
     cout<<"Element "<<x <<"has released from Critical Section !! "<<endl ;
     if ( !waiting.empty() ) {
         int num = waiting.front() ;
         waiting.pop() ;
         cout<<"Element "<<num <<"has Entered into Critical Section !! "<<endl ;
     } else {
        sem ++ ;
     }
}

int main() {
   
   acquire( 12 ) ;
   acquire( 2 ) ;
   acquire( 8 ) ;
   acquire( 10 ) ; // now 10 have entered into waiting queue 
   release( 8 ) ;  // now 10 has entered into critical section 
   acquire( 22 ) ;
   acquire( 222 );
   release( 12 ) ;
    return 0 ;
}
