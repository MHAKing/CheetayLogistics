#include <iostream>
using namespace std;

int equilibrium(int arr[], int n)
{
    int sum = 0; // initialize sum of whole array
    int leftsum = 0; // initialize leftsum

    /* Find sum of the whole array */
    for (int i = 0; i < n; ++i)
        sum += arr[i];

    for (int i = 0; i < n; ++i)
    {
        sum -= arr[i]; // sum is now right sum for index i

        if (leftsum == sum)
            return i + 1;

        leftsum += arr[i];
    }

    /* If no equilibrium index found, then return 0 */
    return -1;
}

int main()
{
    int arr1[] = {1};
    int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
    cout << "First equilibrium index is " << equilibrium(arr1, arr1_size) << endl;

    int arr2[] = {1,3,5,2,2};
    int arr2_size = sizeof(arr2) / sizeof(arr2[0]);
    cout << "First equilibrium index is " << equilibrium(arr2, arr2_size) << endl;

    return 0;
}