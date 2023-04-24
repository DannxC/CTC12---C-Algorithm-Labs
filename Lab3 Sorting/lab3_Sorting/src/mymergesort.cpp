#include <mysortfunctions.h>

// Function to merge two sorted subarrays into a single sorted array
void merge(std::vector<int> &v, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Declare static vectors L and R to store the left and right subarrays.
    // As they are static, their memory allocation persists across function calls.
    // Note: This implementation is not thread-safe, as multiple threads accessing
    // these static vectors concurrently could lead to data races and unexpected behavior.
    int v_size = v.size();
    static std::vector<int> L(v_size), R(v_size);

    // Check if the sizes of the static vectors L and R are sufficient
    // for the current subarray sizes (n1 and n2). If not, resize them accordingly.
    if (L.size() < v_size) {
        L.resize(v_size);
    }
    if (R.size() < v_size) {
        R.resize(v_size);
    }

    // Copy data from v to the temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = v[left + i];
    for (j = 0; j < n2; j++)
        R[j] = v[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // Merge L and R back into v
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            i++;
        } else {
            v[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L, if any
    while (i < n1) {
        v[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R, if any
    while (j < n2) {
        v[k] = R[j];
        j++;
        k++;
    }
}

// Aux function for mymergesort_recursive, counts recursive calls and depth of recursion stack
void mergesort_recursive_aux(std::vector<int> &v, int left, int right, int &recursive_calls, int &depth_recursion_stack, int depth) {
    // Increment the number of recursive calls and update the maximum depth of the recursion stack
    recursive_calls++;
    depth_recursion_stack = std::max(depth_recursion_stack, depth);

    // Continue dividing the array if the current subarray has more than one element
    if (left < right) {
        int mid = (left + right) / 2;

        // Recursively divide the left and right subarrays
        mergesort_recursive_aux(v, left, mid, recursive_calls, depth_recursion_stack, depth + 1);
        mergesort_recursive_aux(v, mid + 1, right, recursive_calls, depth_recursion_stack, depth + 1);

        // Merge the two subarrays back together
        merge(v, left, mid, right);
    }
}

// Main function for the recursive merge sort algorithm
void mymergesort_recursive(std::vector<int> &v, SortStats &stats) {
    int recursive_calls = 0;
    int depth_recursion_stack = 0;

    // Call the auxiliary function to perform the recursive merge sort
    mergesort_recursive_aux(v, 0, v.size() - 1, recursive_calls, depth_recursion_stack, 1);

    // Update the statistics for this sorting algorithm
    stats.recursive_calls = recursive_calls;
    stats.depth_recursion_stack = depth_recursion_stack;
}

// Main function for the iterative merge sort algorithm
void mymergesort_iterative(std::vector<int> &v, SortStats &stats) {
    int n = v.size();
    int curr_size, left_start;
    int pass_count = 0;

    // Iterate through subarray sizes, doubling the size at each iteration
    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {

        // Iterate through the array, merging adjacent subarrays of size curr_size
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            
            // Calculate the end indices for the left and right subarrays to be merged
            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1);
            int mid = std::min(left_start + curr_size - 1, n - 1);

            // Merge the two adjacent subarrays
            merge(v, left_start, mid, right_end);

            // Increment the pass count
            pass_count++;
        }
    }

    // Update the statistics for this sorting algorithm
    stats.recursive_calls = 1; // In the iterative approach, there's only one call (non-recursive).
    stats.depth_recursion_stack = 1; // In the iterative approach, the depth of the recursion stack is 1.
    stats.custom1 = pass_count; // Store the pass count as custom statistic
}