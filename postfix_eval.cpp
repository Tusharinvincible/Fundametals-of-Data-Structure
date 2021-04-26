#include <iostream>
#include <string.h>
#include <math.h>
#include <stack>
using namespace std;
int eval_postfix(string s){
    stack <int> st;
    int len=s.length();
    for(int i=0;i<len;i++){
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
                st.push(n2-n1);
                break;
            case '/':
                st.push(n2/n1);
            case '*':
                st.push(n1*n2);
                break;
            case '^':
                st.push(pow(n1,n2));
                break;
            
            }
        }
    }
    return st.top();

}

int main(){
    string ss="46+2/5*7+";
    cout<<eval_postfix(ss)<<endl;



    return 0;
}