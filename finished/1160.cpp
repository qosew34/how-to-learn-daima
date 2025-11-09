#include <bits/stdc++.h>

    //没写过，先小巧思
int main(){
    int n ;
    std :: cin >> n ;
    std :: vector < int > parent( n+1 , 0) ;//0代表头
    std :: vector < int > son ( n+1 , 0 );//0代表尾巴
    parent[0] = -1 ;son[0] = -1 ;
    for( int i = 2 ; i < n + 1 ; i ++){
        int k , p ;
        std :: cin >> k >> p ;
            if( p == 0 ){//i是k爹
                parent[ i ] = parent[ k ];
                if(parent[ k ]!= 0 ) son[parent[k]] = i;
                parent[ k ] = i ;
                son[ i ] = k ; 
                
            }else if ( p == 1 ){
                parent[ i ] = k;
                son [ i ] = son[ k ];
                if( son[ k ]!= 0 ) parent[son[k]] = i;
                son [ k ] = i ;
                
            }
    }
    int m ;
    std :: vector<int> die(n+1,0); 
    std :: cin >> m;
    for ( int i = 0 ; i < m ; i++){
        int x ; 
        std :: cin >> x ;
        if( die [x] == -1 ) continue ;
        die[x] = -1;
        if(parent[x]!=0) son[ parent [ x ]] = son[ x ];
        if(son[x]!=0) parent[son[x]] = parent[ x ];
    }
    int cur = -1;
    for(int i=1;i<n;i++){
        if(parent[i]==0) {cur=i;break;}
    }
    do{
        std :: cout << cur <<" ";
        cur = son[cur];
    }while(son[cur]!=0);
    std :: cout<<cur;
}







/*vector是错的，要模拟一个链表
int main(){
    int n ;
    std :: cin >> n ;
    std :: vector < int > student ;
    student.push_back( 1 );
    for( int i = 0 ; i < n - 1 ; i ++){
        int k , p ;
        std :: cin >> k >> p ;
        auto it = std :: find ( student.begin(), student.end(), k);
            if( p == 0 ){
                student.insert( it , i + 2 );
            }else if ( p == 1 ){
                student.insert( it + 1 , i + 2 );
            }
    }
    int m ; 
    std :: cin >> m;
    for ( int i = 0 ; i < m ; i++){
        int x ; 
        std :: cin >> x ;
        auto it = std :: find( student.begin(), student.end(), x);
        if( it != student.end()) student.erase( it );
    }
    for( int i = 0 ; i < student.size() ; i++){
        std :: cout << student[i] <<" ";
    }
}*/