#include<bits/stdc++.h>

using namespace std;

int main(){
    string str1;
    cin>>str1;

    string str2;
    cin>>str2;

    int n = str1.length();

    vector<vector<int>> dpt(n, vector<int>(n,0));
    vector<vector<int>> dpf(n, vector<int>(n,0));

    for(int g=0; g<n; g++){
        for(int i=0, j=g; j<n; i++, j++){
            if(g==0){
                if(str1[i] == 'T'){
                    dpt[i][j] = 1;
                    dpf[i][j] = 0;
                }else{
                    dpt[i][j] = 0;
                    dpf[i][j] = 1;
                }
            }else{
                for(int k=i; k<j; k++){
                    char op  = str2[k];

                    int ltc = dpt[i][k];
                    int rtc = dpt[k+1][j];
                    int lfc = dpf[i][k];
                    int rfc = dpf[k+1][j];

                    if(op=='&'){

                        dpt[i][j] += ltc * rtc;
                        dpf[i][j] += ltc * rfc + lfc * rtc + lfc * rfc; 

                    }else if(op=='|'){
                        
                        dpt[i][j] += ltc * rtc + ltc * rfc + lfc * rtc;
                        dpf[i][j] += lfc * rfc;

                    }else{

                        dpt[i][j] += ltc * rfc + lfc * rtc;
                        dpf[i][j] += ltc * rtc + lfc * rfc;

                    }
                }
            }
        }
    }

    cout<<dpt[0][n-1];

    return 0;
}