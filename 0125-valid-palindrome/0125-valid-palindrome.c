
bool isPalindrome(char* s) {
    int front = 0, rear = 0;
    char queue[100000];  
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalnum(s[i])) {
            queue[rear++] = tolower(s[i]);  
        }
    }
    
    while (front < rear) {
        if (queue[front] != queue[rear - 1]) {
            return false;  
        }
        front++;
        rear--;
    }
    
    return true;  
}