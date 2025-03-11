bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {
    int stack[pushedSize], stackTop = -1, poppedIdx = 0;

    for (int i = 0; i < pushedSize; i++){
        stack[++stackTop] = pushed[i];
        while (stackTop >= 0 && poppedIdx < poppedSize && stack[stackTop] == popped[poppedIdx]){
            stackTop--;
            poppedIdx++;
        }
    }

    while (stackTop >= 0 && poppedIdx < poppedSize){
        if (stack[stackTop--] != popped[poppedIdx++]) return false;
    }

    return true;
}