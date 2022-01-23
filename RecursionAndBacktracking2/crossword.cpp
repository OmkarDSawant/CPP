#include<iostream>
#include<vector>

using namespace std;

void display(vector<vector<char>> &arr){

    for(int i = 0; i < arr.size(); i++){
        for(int j = 0; j<arr[0].size(); j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

}

bool canPlaceH(vector<vector<char>> &arr, string word, int i, int j){
    //first two ifs checking absolute fit condition
    if(j-1>=0 && arr[i][j-1] != '+'){
        return false;
    }

    if( j+word.size()<arr[0].size() && arr[i][j+word.size()] != '+'){
        return false;
    }

    for(int jj=0; jj<word.size(); jj++){

        if(j+jj>=arr[0].size()){
            return false;
        }

        if(arr[i][j+jj] != '-' && arr[i][j+jj] != word[jj] ){
            return false;
        }
    }

    return true;
}

bool canPlaceV(vector<vector<char>> &arr, string word, int i, int j){
    if(i-1>=0 && arr[i-1][j] != '+'){
        return false;
    }

    if( i+word.size()<arr.size() && arr[i+word.size()][j] != '+'){
        return false;
    }

    for(int ii=0; ii<word.size(); ii++){

        if(i+ii>=arr.size()){
            return false;
        }

        if(arr[i+ii][j] != '-' && arr[i+ii][j] != word[ii] ){
            return false;
        }
    }

    return true;
}

vector<bool> placeH(vector<vector<char>> &arr, string word, int i, int j){

    vector<bool> wePlaced(word.size(), false);

    for(int jj=0; jj<word.size(); jj++){
        if(arr[i][j+jj] == '-'){
            arr[i][j+jj] = word[jj];
            wePlaced[jj] = true;
        }
    }

    return wePlaced;

}

vector<bool> placeV(vector<vector<char>> &arr, string word, int i, int j){

    vector<bool> wePlaced(word.size(), false);

    for(int ii=0; ii<word.size(); ii++){
        if(arr[i+ii][j] == '-'){
            arr[i+ii][j] = word[ii];
            wePlaced[ii] = true;
        }
    }

    return wePlaced;

}

void unplaceH(vector<vector<char>> &arr, vector<bool> &wePlaced, int i, int j){
    for(int jj=0; jj<wePlaced.size(); jj++){
        if(wePlaced[jj]){
            arr[i][j+jj] = '-';
        }
    }
}

void unplaceV(vector<vector<char>> &arr, vector<bool> &wePlaced, int i, int j){
    for(int ii=0; ii<wePlaced.size(); ii++){
        if(wePlaced[ii]){
            arr[i+ii][j] = '-';
        }
    }
}

//Levels - words
//possible options - 2 * o(n^2) i.e vertical and horizontal call for each cell
void solution(vector<vector<char>> &arr, vector<string> &words, int vidx){

    if(vidx == words.size()){
        display(arr);
        return;
    }

    string word = words[vidx];

    //Exploring options for each level
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[0].size(); j++){
            if( arr[i][j] == '-' ||  arr[i][j] == word[0]){
                if(canPlaceH(arr, word, i, j)){
                    vector<bool> wePlaced(word.size());
                    wePlaced = placeH(arr, word, i, j);
                    solution(arr, words, vidx + 1);
                    unplaceH(arr, wePlaced, i, j);

                }

                if(canPlaceV(arr, word, i, j)){
                    vector<bool> wePlaced(word.size());
                    wePlaced = placeV(arr, word, i, j);
                    solution(arr, words, vidx + 1);
                    unplaceV(arr, wePlaced, i, j);

                }
            }
        }
    }

}

int main(){

    //matrix size
    int n;
    cin>>n;

    //crossword
    vector<vector<char>> arr(n, vector<char>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }

    //Number of words
    int k;
    cin>>k;

    vector<string> words(k);
    for(int i=0; i<k; i++){
        cin>>words[i];
    }

    solution(arr, words, 0); //0 indicates first  word.

    return 0;
}

//Input : 
// 10
// +-++++++++
// +-++++++++
// +-++++++++
// +-----++++
// +-+++-++++
// +-+++-++++
// +++++-++++
// ++------++
// +++++-++++
// +++++-++++
// 4
// DELHI     
// ICELAND   
// ANKARA    
// LONDON 