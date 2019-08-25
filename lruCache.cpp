//author shanu gandhi 25 aug 2019
#include <bits/stdc++.h>
#include<vector>
# include<map>
#include <typeinfo>
using namespace std;
template <class X, class Y> class LruCache{
    public:
        LruCache(int size1){
            capacity=size1;
            //cursize=0;
        }
        int findincache(X x){
            auto it = std::find(cachelist.begin(), cachelist.end(), x);
             if (it != cachelist.end()) 
            { 
                return it - cachelist.begin() + 1; 
            } 
            
            return -1;
        }
        // void movetoend(int x){
        //     auto it = std::find (cachelist.begin(), cachelist.end(), x);
        //     cachelist.erase(it);
        //     cachelist.push_back(x);
        // }
        void insertatend(X x){
            cachelist.push_back(x);
        }
        void set(X x, Y y){
            int foundIndex=findincache(x);
            if(foundIndex== -1){//not found
                if(capacity> cachelist.size()){//insert at back if vacant
                    cachelist.push_back(x);
                    //update in map
                    cache.insert(pair<X, Y>(x, y));
                }
                else {//not vacant so pop front and then insert
                    X frontel=cachelist.front();
                    //remove entry from map of frontel
                    
                    cachelist.erase(cachelist.begin());
                    cache.erase(frontel);

                    cachelist.push_back(x);
                    cache.insert(pair<X , Y>(x,y));
                }
            }
            else{//found
                    //movetoend(x);
                    //change value in map if different
                auto it = std::find (cachelist.begin(), cachelist.end(), x);
                cachelist.erase(it);
                cachelist.push_back(x);
                auto itr = cache.find(x);
                if(itr->second!=y){
                    itr->second=y;
                }
            }
        }
        Y get(X x){
            auto it = std::find (cachelist.begin(), cachelist.end(), x);
             if (it != cachelist.end()) 
            { 
                //return *it;
                //auto it = std::find (cachelist.begin(), cachelist.end(), x);
                cachelist.erase(it);
                cachelist.push_back(x);
                auto itr = cache.find(x);
                return itr->second;
            }
            return -1;
        }
        // void printall(){
        //     cout<<"printall"<<endl;
        //     for(auto it =cachelist.begin(); it!=cachelist.end();it++){
        //          cout << *it << " "; 
        //     }
        // }
    map<X, Y> cache; 
    int capacity;
    //int cursize;
    vector <X> cachelist;
};

int main()
{
    int frames,queries;
    int x;
    int y;
    char ch;
    cin>>frames>>queries;
    LruCache <int,int>l1(frames);

    for(int i =0; i<queries;i++){
        cin>>ch;
        if(ch=='S' || ch == 's'){
            cin>>x>>y;
            l1.set(x,y);

        }else if(ch=='G' || ch=='g'){
            cin>>x;
            cout<<l1.get(x);
            cout<<endl;
            // Y y2= l1.get(x);
            // string s = typeid(Y).name();
            // if(s=="string") { Y y1="-1"; return y1;}
            // if(s=="int") { Y y1=-1; return y1;}
        }
       // l1.printall();
        //cout<<endl;
    }
}
