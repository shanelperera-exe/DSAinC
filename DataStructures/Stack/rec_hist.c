//  Given histogram bar heights, find the largest rectangle area.

#include <stdio.h>

#define MAX 100

int max(int a, int b) { return a > b ? a : b; }

int getMaxArea(int hist[], int n) {
    int stack[MAX], top = -1;
    int max_area = 0, area, i = 0;

    while (i < n) {
        if (top == -1 || hist[stack[top]] <= hist[i]) {
            stack[++top] = i++;
        } else {
            int tp = stack[top--];
            area = hist[tp] * (top == -1 ? i : i - stack[top] - 1);
            max_area = max(max_area, area);
        }
    }

    while (top != -1) {
        int tp = stack[top--];
        area = hist[tp] * (top == -1 ? i : i - stack[top] - 1);
        max_area = max(max_area, area);
    }

    return max_area;
}

int main() {
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    printf("Maximum area: %d\n", getMaxArea(hist, n));
    return 0;
}
