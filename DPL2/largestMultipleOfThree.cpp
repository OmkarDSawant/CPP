#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n, greater<int>());

    if(arr[0] == 0){
        cout<<"0";
        return 0;
    }

    //Calculate sum
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }

    if(sum%3==0){
        string ans;
        for(int i=0; i<n; i++){
            ans+= to_string(arr[i]);
        }
        cout<<ans;
        return 0;
    }else if(sum%3==1){
        int idx;
        bool found = 0;
        for(int i=n-1; i>=0; i--){
            if(arr[i]%3==1){
                idx = i;
                found = true;
                arr[i] = -1;
                break;
            }
        }

        if(found){
            string ans;
            for(int i=0; i<n; i++){
                if(arr[i]!=-1){
                    ans += to_string(arr[i]);
                }
            }
            cout<<ans;
            return 0;
        }else{
            int idx[2];
            idx[0]=-1;
            idx[1]=-1;

            for(int i=n-1; i>=0; i--){
                if(arr[i]%3==2){
                    if(idx[0]==-1){
                        idx[0] = i;
                        arr[i] = -1;
                    }else{
                        idx[1] = i;
                        arr[i] = -1;
                        break;
                    }
                }
            }

            if(idx[1]!= -1){
                string ans;
                for(int i=0; i<n; i++){
                    if(arr[i]!=-1){
                        ans += to_string(arr[i]);
                    }
                }
                cout<<ans;
                return 0;
            }else{
                cout<<"";
                return 0;
            }
        }
    }else{
        int idx;
        bool found = 0;
        for(int i=n-1; i>=0; i--){
            if(arr[i]%3==2){
                idx = i;
                found = true;
                arr[i] = -1;
                break;
            }
        }

        if(found){
            string ans;
            for(int i=0; i<n; i++){
                if(arr[i]!=-1){
                    ans += to_string(arr[i]);
                }
            }
            cout<<ans;
            return 0;
        }else{
            int idx[2];
            idx[0]=-1;
            idx[1]=-1;

            for(int i=n-1; i>=0; i--){
                if(arr[i]%3==1){
                    if(idx[0]==-1){
                        idx[0] = i;
                        arr[i] = -1;
                    }else{
                        idx[1] = i;
                        arr[i] = -1;
                        break;
                    }
                }
            }

            if(idx[1]!= -1){
                string ans;
                for(int i=0; i<n; i++){
                    if(arr[i]!=-1){
                        ans += to_string(arr[i]);
                    }
                }
                cout<<ans;
                return 0;
            }else{
                cout<<"";
                return 0;
            }
        }
    }

    return 0;
}