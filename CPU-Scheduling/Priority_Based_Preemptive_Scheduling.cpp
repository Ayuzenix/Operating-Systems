#include<bits/stdc++.h>
using namespace std ;

// Priority Based ( Preemptive ) Scheduling 

int main() {
    
    int n ;
    cout<<"Enter the Number of Process:" ;
    cin>>n ;
    vector<int>at( n ) ;
    vector<int>bt( n ) ;
    vector<int>priority( n ) ;
    for ( int i = 0 ; i < n ; i ++ ) {
         cout<<"Enter the Arrival Time of Process"<<( i + 1 )<<endl ;
         cin>>at[i] ;
         cout<<"Enter the Burst Time of Process"<<( i + 1 )<<endl ;
         cin>>bt[i] ;
         cout<<"Enter the Priority of Process"<<( i + 1 )<<endl ;
         cin>>priority[i] ;
    }
    int completed = 0 , time = 0 ; // Higher Priority - Highest 
    priority_queue<pair<int,int>>pq ;
    unordered_map<int,int>mp ;
    vector<int>ct( n ) ;
    vector<int>dbt = bt ;
    while ( completed != n ) {
         int idx = -1 ;
         for ( int i = 0 ; i < n ; i ++ ) {
              if ( at[i] <= time && bt[i] != -1 && mp.find( i ) == mp.end() ) {
                  pq.push( { priority[i] , i } ) ;
                  mp[i] ++ ;
              }
         }
         if ( !pq.empty() ) {
             idx = pq.top().second ;
         } else {
             for ( int i = 0 ; i < n ; i ++ ) {
                  if ( bt[i] != -1 ) {
                      idx = i ;
                      pq.push( { priority[idx] , i } ) ;
                      mp[idx] ++ ;
                      break ;
                  }
             }
         }
         if ( at[idx] > time ) {
             time = at[idx] ;
         }
         time = time + 1 ;
         bt[idx] = bt[idx] - 1 ;
         if ( bt[idx] == 0 ) {
             completed ++ ;
             ct[idx] = time ;
             bt[idx] = -1 ;
             pq.pop() ;
         }
    }
    cout<<"P_id"<<" "<<"Completion Time"<<" "<<"Turn Around Time"<<" "<<"Waiting Time"<<endl ;
    for ( int i = 0 ; i < n ; i ++ ) {
         int p_id = ( i + 1 ) , completionTime = ct[i] , Tat = completionTime - at[i] , Wt = Tat - dbt[i] ;
         cout<<p_id<<"|"<<completionTime<<"|"<<Tat<<"|"<<Wt<<endl ;
    }
    return 0 ;
}
