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

// 05.Given a text string  and a pattern string , find if a permutation of its pattern exists in the text.
// input: txt(n):"geeksforgeeks" pat(m): "egek" outptut: yes
// input: txt: "geeksforgeeks" pat: ""
//O((n-m) * m)

    bool areSame(int s1[], int s2[]){
        for( int i = 0; i<256;i++){
            if(s1[i] != s1[i]){
                return false;
            }
        }
        return true;
    }


bool isAnagramPresent(string txt , string pat){
    int countTxtW[256]={0}, countPat[256] = {0};

    for( int i = 0; i<pat.length();i++){
        countTxtW[txt[i]]++;
        countPat[pat[i]]++;
    }

    for( int i = pat.length(); i<txt.length();i++){
        if(areSame(countTxtW,countPat)) return true;
        countTxtW[txt[i]]++;
        countTxtW[txt[i-pat.length()]]--;
    }

    return false;
}


//06. Given two strings. Check if they are rotations of each other
// input s1: "ABCD s2:"CDAB" output: true;

bool areRotations(string s1 , string s2){
    if(s1.length() != s2.length()) return false;

    s1 = s1+s1; 

    return (s1.find(s2) != string::npos);
}

// 07.Pattern searching algorithm (naive)
//input text:"ABABAB" pat:"ABAB output : 0 2
// input: text: "AAAAA" pat: "AAA" output: 0 1 2

int patSearch(string txt, string pat){
     int n = txt.length();
    int m = pat.length();

    for( int i=0; i<=n-m;i++){
        for( int j  =0; j<m ;j++){
            if(txt[i+j] != pat[j]){
                break;
            }
            if(j == m) return i;
        }
    }

    return -1;
}


int main(){
    string s1 = "abc";
    string s2 = "bca";
    cout<<anagram(s1,s2)<<endl;

    return 0;
}