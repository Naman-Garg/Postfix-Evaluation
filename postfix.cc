#include<bits/stdc++.h>
using namespace std;
int postfix_eval(string str)
{
     stack < int > s1;
     int len, top, below, result = 0, digit = 0, i;
     len = str.size();
     for(i = 0; i < len; i++){
          if(str[i]==' ')
               continue;
          if(str[i] >= 48 &&  str[i] <= 57){
               digit=0;
               while(str[i] != ' '){
                    int k = (int)(str[i] - 48);
                    digit = (digit * 10) + k;
                    i++;
               }
               s1.push(digit);
               i--;
          }
          else{
               top = s1.top();
               s1.pop();
               below = s1.top();
               s1.pop();
               switch(str[i]){
                    case '+' :
                          result = below + top;
                          s1.push(result);
                          break;
                    case '-' :
                         result = below - top;
                         s1.push(result);
                         break;
                    case '*' :
                         result = below * top;
                         s1.push(result);
                         break;
                    case '/' :
                         result = below / top;
                         s1.push(result);
                         break;
               }
          }
     }
     cout << s1.top();
}
int main()
{
     int t;
     string str;
     cin >> t;
     while(t--){
          getline(cin, str);
          postfix_eval(str);
     }
     return 0;
}
