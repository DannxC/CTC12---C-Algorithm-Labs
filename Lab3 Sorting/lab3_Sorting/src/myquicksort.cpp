#include <mysortfunctions.h>

// Helper function to find the median of three values
int medianOfThree(std::vector<int> &v, int left, int right) {
    int mid = (left + right) / 2;
    
    if (v[left] > v[mid])
        std::swap(v[left], v[mid]);
    
    if (v[left] > v[right])
        std::swap(v[left], v[right]);
    
    if (v[mid] > v[right])
        std::swap(v[mid], v[right]);
    
    return mid;
}

// Partition function for QuickSort, which takes a vector, left and right indices, and a boolean for fixed pivot
int partition(std::vector<int> &v, int left, int right, bool isFixedPivot) {
    // Select the pivot index
    int pivotIndex;
    if (isFixedPivot) {
        pivotIndex = left;
    } else {
        pivotIndex = medianOfThree(v, left, right);
    }

    // Set the pivot value and swap the pivot to the leftmost position
    int pivotValue = v[pivotIndex];
    std::swap(v[pivotIndex], v[left]);

    // Initialize i and j pointers
    int i = left + 1;
    int j = right;

    // Partition the array based on pivot
    while (true) {
        while (i <= j && v[i] < pivotValue) {
            i++;
        }

        while (i <= j && v[j] > pivotValue) {
            j--;
        }

        // Swap elements if i and j pointers have not crossed
        if (i < j) {
            std::swap(v[i], v[j]);
        } else {
            break;
        }
    }

    // Swap the pivot back to its correct position
    std::swap(v[left], v[j]);

    // Return the new pivot index
    return j;
}


// Double recursive QuickSort function
void quicksort_double_recursive(std::vector<int> &v, int left, int right, int &recursive_calls, int &depth_recursion_stack, int depth) {
    // Increment the recursive_calls counter and update the depth of the recursion stack
    recursive_calls++;
    depth_recursion_stack = std::max(depth_recursion_stack, depth);

    // Perform the QuickSort if left < right
    if (left < right) {
        int pivotIndex = partition(v, left, right, false);

        // Recursively call the function on both halves of the partitioned array
        quicksort_double_recursive(v, left, pivotIndex - 1, recursive_calls, depth_recursion_stack, depth + 1);
        quicksort_double_recursive(v, pivotIndex + 1, right, recursive_calls, depth_recursion_stack, depth + 1);
    }
}

// Main double recursive QuickSort function with median of three pivot selection
void myquicksort_2recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    int recursive_calls = 0;
    int depth_recursion_stack = 0;

    quicksort_double_recursive(v, 0, v.size() - 1, recursive_calls, depth_recursion_stack, 1);

    // Update the statistics
    stats.recursive_calls = recursive_calls;
    stats.depth_recursion_stack = depth_recursion_stack;
}


// Single recursive QuickSort function
void quicksort_single_recursive(std::vector<int> &v, int left, int right, int &recursive_calls, int &depth_recursion_stack, int depth) {
    // Increment the recursive_calls counter and update the depth of the recursion stack
    recursive_calls++;
    depth_recursion_stack = std::max(depth_recursion_stack, depth);

    while (left < right) {
        int pivotIndex = partition(v, left, right, false);
        
        // Recursively call the function on the smaller partition and update the left or right pointer
        if (pivotIndex - left < right - pivotIndex) {
            quicksort_single_recursive(v, left, pivotIndex - 1, recursive_calls, depth_recursion_stack, depth + 1);
            left = pivotIndex + 1;
        } else {
            quicksort_single_recursive(v, pivotIndex + 1, right, recursive_calls, depth_recursion_stack, depth + 1);
            right = pivotIndex - 1;
        }
    }
}

// Main single recursive QuickSort function with median of three pivot selection
void myquicksort_1recursion_medianOf3(std::vector<int> &v, SortStats &stats) {
    int recursive_calls = 0;
    int depth_recursion_stack = 0;

    quicksort_single_recursive(v, 0, v.size() - 1, recursive_calls, depth_recursion_stack, 1);

    // Update the statistics
    stats.recursive_calls = recursive_calls;
    stats.depth_recursion_stack = depth_recursion_stack;
}


// Fixed pivot QuickSort function
void quicksort_fixedPivot(std::vector<int> &v, int left, int right, int &recursive_calls, int &depth_recursion_stack, int depth) {
    // Increment the recursive_calls counter and update the depth of the recursion stack
    recursive_calls++;
    depth_recursion_stack = std::max(depth_recursion_stack, depth);

    // Perform the QuickSort if left < right
    if (left < right) {
        int pivotIndex = partition(v, left, right, true);

        // Recursively call the function on both halves of the partitioned array
        quicksort_fixedPivot(v, left, pivotIndex - 1, recursive_calls, depth_recursion_stack, depth + 1);
        quicksort_fixedPivot(v, pivotIndex + 1, right, recursive_calls, depth_recursion_stack, depth + 1);
    }
}

// Main fixed pivot QuickSort function
void myquicksort_fixedPivot(std::vector<int> &v, SortStats &stats) {
    int recursive_calls = 0;
    int depth_recursion_stack = 0;

    quicksort_fixedPivot(v, 0, v.size() - 1, recursive_calls, depth_recursion_stack, 1);

    // Update the statistics
    stats.recursive_calls = recursive_calls;
    stats.depth_recursion_stack = depth_recursion_stack;
}