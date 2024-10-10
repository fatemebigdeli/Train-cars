#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

void generateSequences(int n, int stack[], int top, int sequence[], int seqIndex) {
    if (seqIndex == n) {
        printArray(sequence, n);
        return;
    }


// The state when a wagon is removed from the stack
    if (top >= 0) {
        int nextInSeq = stack[top];
        int newStack[n], newSequence[n];
        for (int i = 0; i < top; i++) newStack[i] = stack[i];
        for (int i = 0; i < seqIndex; i++) newSequence[i] = sequence[i];
        newSequence[seqIndex] = nextInSeq;
        generateSequences(n, newStack, top - 1, newSequence, seqIndex + 1);
    }


// State where a new wagon is added to the stack
    if (top + 1 + seqIndex < n) {
        int newStack[n], newSequence[n];
        for (int i = 0; i <= top; i++) newStack[i] = stack[i];
        for (int i = 0; i < seqIndex; i++) newSequence[i] = sequence[i];
        newStack[top + 1] = n - top - 1 - seqIndex;
        generateSequences(n, newStack, top + 1, newSequence, seqIndex);
    }
}

int main() {
    int n;
    printf("Enter the number of wagons: ");
    scanf("%d", &n);

    int stack[n], sequence[n];
    generateSequences(n, stack, -1, sequence, 0);

    return 0;
}
