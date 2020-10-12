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
    std::unordered_map<int, std::list<int> > values_to_sets;

    // this vector contains sizes of sets of index i. Works better than an array, checked.
    std::vector< int > sets_to_sizes;

    // this is a priority queue which keeps track of the set with the highest size
    // pair.first is the set size and pair.second is the set nummber
    std::priority_queue<std::pair<int, int>> q;

    // we fill the above data structures using f and p
    int tracker = 0;
    for(int i = 1; i <= m; i++) {
        int top = p[i];
        int j = i-1;

        // the set j has size 0 initially
        //sets_to_sizes.push_back(0);

        // we increase the size of set j from 0 to its actual size
        int set_size = p[i] - p[j];
        sets_to_sizes.push_back(set_size);

        // while we are looking at the same set
        while(tracker < top) {
            // an element in the set
            int element = f[tracker];
            // we add the number of the current set as one that contains the element
            values_to_sets[element].push_back(j);
            // we add the current element into the elements of the current set
            // we increase the size of the current set by 1
            tracker++;
        }
        //value, key
        q.push(std::pair<int, int>(sets_to_sizes[j], j));
    }
    while(!q.empty()) {
        // getting the number of the set with largest size from q
        std::pair<int,int> largest = q.top();
        // the number of this set (j)
        int largest_set = largest.second;
        //cout << "largest set " << largest_set << endl;
        // the size of this set stored in the queue
        int largest_set_size = largest.first;
        //the actual size of the set j. sizes are stored and updated in sets_to_sizes
        int actual_size = sets_to_sizes[largest_set];
        // if one of these conditions is true, we discard the set from the queue and continue looping
        if(actual_size < 1 || actual_size != largest_set_size) {
            //cout << "fail" << endl;
            q.pop();
            continue;
        }
        // at this point we found a set which is indeed large. We remove it from queue, as details are stored in above variables
        q.pop();
        // we increase the number of elements found
        elements_found = elements_found + actual_size;
        r[counter] = largest_set;
        counter++;
        /*std::unordered_set<int> values_in_largest_set;
        int j = 0;
        while(j < actual_size) {
            int value = f[p[largest_set]+j];
            values_in_largest_set.insert(value);
            j++;
        }
        for(int value : values_in_largest_set) {
            while(!values_to_sets[value].empty()) {
                int head = values_to_sets[value].front();
                sets_to_sizes[head]--;
                q.push(std::pair<int,int>(sets_to_sizes[head], head));
                values_to_sets[value].pop_front();
            }
        }*/
        int j = 0;
        int limit = p[largest_set_size] - p[largest_set_size-1];
        while(j < limit) {
            int value = f[p[largest_set]+j];
            //cout << "value with new method " << value << endl;
            while(!values_to_sets[value].empty()) {
                int head = values_to_sets[value].front();
                sets_to_sizes[head]--;
                q.push(std::pair<int,int>(sets_to_sizes[head], head));
                values_to_sets[value].pop_front();
            }
            j++;
        }
        //std::unordered_set<int> values_in_largest_set = sets[largest_set];
        //for(int value : values_in_largest_set) {
        //    cout << "value with old method " << value << endl;
        //}
        /*for(int value : values_in_largest_set) {
            while(!values_to_sets[value].empty()) {
                int head = values_to_sets[value].front();
                sets_to_sizes[head]--;
                q.push(std::pair<int,int>(sets_to_sizes[head], head));
                values_to_sets[value].pop_front();
            }
        }*/
    }
    //all good here
    if(elements_found < n) {
        k = 0;
    } else{
        k = counter;
    }
}