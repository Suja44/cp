//SORTING



1)selection sort:
The first solution is based on building the sorted array from scratch: take the smallest element, place it at the beginning,
and remove it from the old array. Since we need to find the minimum element NN times,
the number of operations is N + (N-1) + (N-2) + ... + 1 = \frac{N * (N + 1)}{2} = O(N^2)N+(N−1)+(N−2)+...+1= 2N∗(N+1) =O(N^2).

code:
vector<int> sort_by_selection(vector<int> v) {
    vector<int> sorted;
    while (v.size()) {
        // find the minimum element
        int index_min = 0;
        for (int i = 1; i < (int)v.size(); i += 1) {
            if (v[i] < v[index_min]) {
                index_min = i;
            }
        }
        
        // insert it in the sorted array
        sorted.push_back(v[index_min]);
        
        // remove it from the original array
        v.erase(v.begin() + index_min);
    }
    return sorted;
}

2)Insertion sort:
For this algorithm we will always assume that the first ii elements are sorted, and insert the i+1i+1th value in its correct place.
 It is important to note that this algorithm runs in O(N) time on already sorted arrays, but is up to O(N^2) for a reverse array.
 The number of swaps is actually equal to the number of inversions (pairs of elements i,j with i<j but a[i]>a[j]) in the original array.
  
 
code:
vector<int> sort_by_insertion(vector<int> v) {
    for (int i = 1; i < (int)v.size(); i += 1) {
        // Consider the element is currently on position j, and try to move it even further left
        for (int j = i; j > 0; j -= 1) {
            if (v[j] < v[j - 1]) {
                swap(v[j], v[j - 1]);
            } else {
                break;
            }
        }
    }
    return v;
}

3)bubble sort:
Of the O(N^2)-timed sorting algorithms, the bubble sort is the one that behaves the best on averege.
  It initially assumes the array is sorted, then iterates over its elements searching for a pair of consecutive elements that are inverted.
  If it finds a pair, it swaps the elements and marks the array as not sorted. 
  It continues to iterate over the array until a whole iteration goes without any swaps, signaling that the array is sorted.

    
 code:
vector<int> bubble_sort(vector<int> v) {
    bool is_sorted; //this flag is used to remember whether at least one swap
                    // was executed in the last transversal
    do {
        is_sorted = true; // initially assume the array to be sorted
        for (int i = 1; i < (int)v.size(); i += 1) {
            if (v[i] < v[i - 1]) { //there is a "bubble" here
                is_sorted = false; // the array was not sorted in this transversal
                swap(v[i], v[i - 1]);
            }
        }
    } while (!is_sorted); // when is_sorted was still true at the end of the "for" loop, 
                          //it means no elements were swapped, so the array is sorted
    return v;
}
  
  
