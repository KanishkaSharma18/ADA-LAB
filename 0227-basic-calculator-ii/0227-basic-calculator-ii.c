int calculate(char* s){

    int nums[150000];
    int top=-1;
    int CrrNum=0;
    char prevOperator='+';

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];
        if(isdigit(c))
        {
            CrrNum = CrrNum* 10 + (c - '0');
        }

        if (c == '+' || c == '-' || c == '*' || c == '/' || s[i + 1] == '\0'){
            if (prevOperator == '+') {
                nums[++top] = CrrNum;
            } else if (prevOperator == '-'){
                nums[++top] = -CrrNum;
            } else if (prevOperator == '*'){
                nums[top] *= CrrNum;
            } else if (prevOperator == '/'){
                nums[top] = nums[top] / CrrNum;
            }
            prevOperator = c;
            CrrNum = 0;
        }
    }
    int result = 0;
    for (int i = 0; i <= top; i++){
        result += nums[i];
    }

    return result;
}