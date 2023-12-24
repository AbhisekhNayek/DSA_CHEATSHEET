int createAtoi(string s) {

long long ans = 1;
int i = 0;
bool sign = 0;
long long maxVal = 2^31-1;

while(s[i] == ' ') i++;

if (s[i] == '-' || s[i] == '+') {

if(s[i] == '-')

sign = 1;

else

sign = 0;

i++;

}

 

if(!(s[i] >= 48 && s[i] <= 57)) return 0;

 

ans = s[i]-48;

i++;


while(i<s.size()){

if(!(s[i] >= 48 && s[i] <= 57)) break;

ans = ans * 10 + (s[i]-48);

i++;


if(sign == 0 && ans > INT_MAX)

return INT_MAX;

if(sign == 1 && ans > INT_MAX)

return INT_MIN;

}

 

 

 

return sign ? -1*ans : ans;

 

}
