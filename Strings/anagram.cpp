#include<iostream>
using namespace std;

// 01. check anagram
bool anagram(string s1 , string s2){
    //O(n + alphabet_size)
    //O(alphabet_size) = O(1)
    if(s1.length() != s2.length()){
        return false;
    }

    int count[256] ={0};
    for( int i =0; i<s1.length();i++){
        count[s1[i]]++;
    }

    for( int i = 0; i<s2.length();i++){
        count[s2[i]]--;
    }


    for( int i = 0; i<256; i++){
        if(count[i] != 0){
            return false;
        }
    }
        return true;

}

// 02. Given a string. Find the leftmost character that repeats.
// input : s1 = "geeksforgeeks" output:0 // index of "g"
int firstRepeating(string str){
    int res = INT_MAX;
    int f1[256] = {-1};
    for( int i =str.length()-1 ; i>= 0; i--){
        if(f1[str[i]] == -1){
            f1[str[i]] = i;
        }
        else {
            res = f1[str[i]];
        }
    }

    return (res == INT_MAX) ? -1:res;
}

// 03. Given  a string. Find  the leftmost character that doesnot repeat (IMP)
// input: str:"geeksforgeeks" output: 5 //index of f
 int firstNonRepeat(string str){
    int res = INT_MAX;
    int f1[256]={-1};
    for( int i =0; i< str.length();i++){
        if(f1[str[i]] == -1){
            f1[str[i]] = i;
        }
        else {
            f1[str[i]] = -2;
        }

        for( int j =0 ; j<256; j++){
            if(f1[j] >= 0){
                res = min(res,f1[j]);
            }
        }
    }
    return res;
 }

 // 04. Given a string. Find the lexographic rank of it
 // input : str: "ABC" output:3
//         String       |          Lex Rank
       // ------------------------------------
       /*   ABC         |           1
       /*   ACB         |           2
       /*   BAC         |           3
       /*   BCA         |           4
       /*   CAB         |           5
       /*   CBA         |           6
       */

int fact( int n ){
    int ans = 1;
    for( int i =1; i<=n;i++){
        ans *= i;
    }

    return ans;
}
int lexRank(string str){
    int rank = 1;
    int n = str.length();
    int mul = fact(n);
    int count[256] = {0};
    for( int i= 0 ; i<n ; i++){
        count[str[i]]++;
    }

    for(int i = 1; i<256;i++){
        count[i] = count[i] + count[i-1];
    }

    for( int i =0 ;i<n;i++){
        mul = mul/(n-i);
        rank = rank + (count[str[i]-1]*mul);

        for( int j = str[i]; j<256;j++){
            count[j]--;
        }
    }
    return rank;

}

    


int main(){
    string s1 = "abc";
    string s2 = "bca";
    cout<<anagram(s1,s2)<<endl;

    return 0;
}