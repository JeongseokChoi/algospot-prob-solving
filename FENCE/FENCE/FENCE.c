#include <stdio.h>
#include <stdlib.h>


int find_solution(int *fence_arr, int n_fence)
{
    int max_area = 0;
    
    int *stack = malloc(n_fence * sizeof(int));
    int top = -1;

    int curr = 0;
    while (curr < n_fence)
    {
        while ((top >= 0) && (fence_arr[stack[top]] > fence_arr[curr]))
        {
            int height = fence_arr[stack[top--]];
            int width = (top >= 0)? curr - stack[top] - 1 : curr;
            max_area = (max_area < height * width)? height * width : max_area;
        }

        stack[++top] = curr++;
    }
    while (top >= 0)
    {
        int height = fence_arr[stack[top--]];
        int width = (top >= 0) ? curr - stack[top] - 1 : curr;
        max_area = (max_area < height * width) ? height * width : max_area;
    }

    free(stack);
    return max_area;
}


int main(int argc, char *argv[])
{
    int n_case;
    scanf("%d", &n_case);
    for (int i_case = 0; i_case < n_case; i_case++)
    {
        int n_fence;
        scanf("%d", &n_fence);

        int *fence_arr = malloc(n_fence * sizeof(int));
        
        for (int i_fence = 0; i_fence < n_fence; i_fence++)
            scanf("%d", &fence_arr[i_fence]);

        printf("%d\n", find_solution(fence_arr, n_fence));

        free(fence_arr);
    }

    return 0;
}
