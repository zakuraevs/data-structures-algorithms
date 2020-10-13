#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <utility>

using namespace std;


void solver(int n, int m, const int *p, const int *f, int &k, int *r) {

    // this variable tracks how many sets we add to r, since we can't just take the size of r.
    int counter = 0;

    // this variable tracks how many distinct elements the set cover contains so far. If it is < n, we fail
    int elements_found = 0;

    // this map has elements as keys and lists of numbers of sets which contain these elements as values
    // for example values_to_sets[4] -> {0,2} implies that element 4 is present in sets 0 and 2
    std::vector< std::vector<int> > values_to_sets;

    // this vector contains sizes of sets of index i. Works better than an array, checked.
    std::vector< int > sets_to_sizes;

    // this is a priority queue which keeps track of the set with the highest size
    // pair.first is the set size and pair.second is the set number
    std::priority_queue<std::pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        values_to_sets.push_back(std::vector<int>());
    }

    // we fill the above data structures using f and p
    int tracker = 0;
    for(int i = 1; i <= m; i++) {
        int top = p[i];
        int j = i-1;

        // we increase the size of set j from 0 to its actual size
        int set_size = top - p[j];
        sets_to_sizes.push_back(set_size);
        // while we are looking at the same set
        while(tracker < top) {
            // we add the number of the current set as one that contains the element
            values_to_sets[f[tracker]].push_back(j);
            tracker++;
        }

        // we push the pair of current set size and set number to q
        q.push(std::pair<int, int>(sets_to_sizes[j], j));
    }

    bool all_sets_empty = false;

    // main algorithm loop. while we still have elements to look at and haven't covered all elements
    while( !all_sets_empty && !(q.empty())) {

        all_sets_empty = true;

        // getting the number of the set with largest size from q
        std::pair<int,int> largest = q.top();

        // the number of this set (j)
        int largest_set = largest.second;

        // the size of this set stored in the queue. This might be wrong
        int largest_set_size = largest.first;

        //the actual size of the set j. sizes are stored and updated in sets_to_sizes
        int actual_size = sets_to_sizes[largest_set];


        // if one of these conditions is true, we discard the set from the queue and continue looping
        if(actual_size != largest_set_size) {
            q.pop();
            all_sets_empty = false;
            continue;
        }

        // at this point we found a set which is indeed large.
        // We remove it from queue, as details are stored in above variables
        q.pop();

        // we increase the number of elements found
        elements_found += actual_size;
        r[counter] = largest_set;
        counter++;

        // we are going to look inside f and examine all the elements in the largest set
        int j = 0;
        int limit = p[largest_set_size] - p[largest_set_size-1];
        int p_index = p[largest_set];
        // while we are in the largest set

        while(j < limit) {
            int element = f[p_index+j];
            // while this value is still stored in some elements
            //removed_elements.push_back(element);

            for(int head : values_to_sets[element]) {
                // this is the set we are going to remove the current
                //int head = values_to_sets[element].front();

                // we decrement the size of this set
                sets_to_sizes[head]--;

                // if the set is not empty, we put it into the queue once again.
                // this is the way of updating the queue. It is now very efficient
                // but at the beginning of each outer loop, we check if the data is correct,
                // and if not, just pop
                if(sets_to_sizes[head] > 0) {
                    q.push(std::pair<int,int>(sets_to_sizes[head], head));
                }
                // the set no longer contains the element
            }
            values_to_sets[element] = std::vector<int>();
            j++;
        }
        for (int i=0; i < m; i++) {
            all_sets_empty &= (sets_to_sizes[i] == 0);
            if (sets_to_sizes[i] > 0) {
                break;
            }
        }
    }

    // check if we successfuly found a set cover
    if(elements_found < n) {
        k = 0;
    } else{
        k = counter;
    }
}