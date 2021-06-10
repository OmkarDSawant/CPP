#include<bits/stdc++.h>

using namespace std;

int rain_water(vector<int>a){
    int n = a.size();
    int ans = 0;
    stack<int> st;

    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()] < a[i]){
            int cur = st.top();
            st.pop();

            if(st.empty()){ // when left wall is not present. The biggest always becomes the left wall.
                break;
            }
            
            int len = i - st.top() - 1;
            ans+= (min(a[st.top()],a[i]) - a[cur])*len; 
        }
        st.push(i); //Note: pushing index and not value.
    }
    return ans;
}

int main(){

    vector<int> a = {3,1,2,3,4,5};
    cout<<rain_water(a);

    return 0;
}