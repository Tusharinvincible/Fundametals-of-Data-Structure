#include <iostream>
#include <string.h>
#include <stack>
using namespace std;
int eval_prefix(string s){
    stack <int> st;
    int len=s.length();
    for(int i=len-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int n1=st.top();
            st.pop();
            int n2=st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(n1+n2);
                break;
            case '-':
                st.push(n1-n2);
                break;
            case '/':
                st.push(n1/n2);
            case '*':
                st.push(n1*n2);
                break;
            
            }
        }
    }
    return st.top();

}

int main(){
    string ss="-+7*45+20";
    cout<<eval_prefix(ss)<<endl;



    return 0;
}