#include <mysortfunctions.h>

// Perform counting sort on the input array v, based on the given shift and mask
void countingSort(std::vector<int> &v, int shift, int mask) {
    int n = v.size();
    std::vector<int> output(n);
    std::vector<int> count(mask + 1, 0);

    // Count the occurrences of each element after applying the mask and shift
    for (int i = 0; i < n; i++) {
        count[(v[i] >> shift) & mask]++;
    }

    // Calculate the cumulative count for each element
    for (int i = 1; i <= mask; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array using the count and input arrays
    for (int i = n - 1; i >= 0; i--) {
        output[count[(v[i] >> shift) & mask] - 1] = v[i];
        count[(v[i] >> shift) & mask]--;
    }

    // Copy the output array back to the input array
    for (int i = 0; i < n; i++) {
        v[i] = output[i];
    }
}

// Radix sort implementation
void radixsort(std::vector<int> &v, int &recursive_calls, int &depth_recursion_stack, int &pass_count, int depth) {
    recursive_calls++;
    depth_recursion_stack = std::max(depth_recursion_stack, depth);

    // If the input array is empty, return
    if (v.empty()) {
        return;
    }

    int max_element = *std::max_element(v.begin(), v.end());
    int n_bits = 4; // You can change this variable to process different amounts of bits per iteration
    int mask = (1 << n_bits) - 1;
    int shift = 0;

    // Perform counting sort for each group of bits in the elements until the max_element has been processed
    while (max_element >> shift > 0) {
        countingSort(v, shift, mask);
        pass_count++; // Increment the pass count for Radix Sort
        shift += n_bits;
    }
}

// Main Radix Sort function
void myradixsort(std::vector<int> &v, SortStats &stats) {
    // Set up initial statistics
    int recursive_calls = 0;
    int depth_recursion_stack = 0;
    int pass_count = 0; // Initialize the pass count for Radix Sort

    // Call the radixsort function to perform sorting and update statistics
    radixsort(v, recursive_calls, depth_recursion_stack, pass_count, 1);

    // Update the statistics
    stats.recursive_calls = recursive_calls;
    stats.depth_recursion_stack = depth_recursion_stack;
    stats.custom1 = pass_count;
}
