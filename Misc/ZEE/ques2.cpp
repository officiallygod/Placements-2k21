// C++ program for the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum possible
// area of a rectangle
int largestArea(int arr1[], int n,
                int arr2[], int m)
{
    // Initialize variables
    int end = 0, start = 0, i = 0, j = 0;

    // Sort array arr1[]
    sort(arr1, arr1 + n);

    // Sort array arr2[]
    sort(arr2, arr2 + m);

    // Traverse arr1[] and arr2[]
    while (i < n and j < m)
    {

        // If arr1[i] is same as arr2[j]
        if (arr1[i] == arr2[j])
        {

            // If no starting point
            // is found yet
            if (start == 0)
                start = arr1[i];
            else
                // Update maximum end
                end = arr1[i];
            i++;
            j++;
        }

        // If arr[i] > arr2[j]
        else if (arr1[i] > arr2[j])
            j++;
        else
            i++;
    }

    // If no rectangle is found
    if (end == 0 or start == 0)
        return 0;
    else
        // Return the area
        return (end - start);
}

// Driver Code
int main()
{
    // Given point
    int arr1[] = {1, 2, 3};

    // Given length
    int N = sizeof(arr1) / sizeof(arr1[0]);

    // Given points
    int arr2[] = {2, 3};

    // Given length
    int M = sizeof(arr2) / sizeof(arr2[0]);

    // Function Call
    cout << largestArea(arr1, N, arr2, M);

    return 0;
}
                                                             