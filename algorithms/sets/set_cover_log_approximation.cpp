#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <utility>

using namespace std;


void set_partitioner(int &tracker, const int *f, const int *p, int m,
                     std::unordered_map<int, std::list<int> > &values_to_sets,
                     std::vector< std::pair< std::unordered_set<int>, int> > &sets_to_values_and_sizes,
                     better_priority_queue::updatable_priority_queue<int,int> &q) {

    for(int i = 1; i <= m; i++) {
        int top = p[i];
        int j = i-1;
        sets_to_values_and_sizes.push_back( std::pair< std::unordered_set<int>, int>() );
        while(tracker < top) {
            int element = f[tracker];
            values_to_sets[element].push_back(j);
            sets_to_values_and_sizes[j].first.insert(element);
            sets_to_values_and_sizes[j].second++;
            tracker++;
        }

        //q[j]= sets_to_values_and_sizes[j].second;
        //value, key
        q.push(j, sets_to_values_and_sizes[j].second);

    }
}


void solver(int n, int m, const int *p, const int *f, int &k, int *r) {
    int tracker = 0;
    int counter = 0;
    std::unordered_set<int> elements_found;
    std::unordered_map<int, std::list<int> > values_to_sets;
    std::vector< std::pair< std::unordered_set<int>, int> > sets_to_values_and_sizes;
    better_priority_queue::updatable_priority_queue<int,int> q;

    set_partitioner(tracker, f, p, m, values_to_sets, sets_to_values_and_sizes, q);
    //cout<< "size: " << q.size() <<endl;
    while(!q.empty()) {
        //cout << 1 << endl;
        //cout<< "size: " << q.size() <<endl;
        //value, key
        int largest_set = q.top().key;
        //cout<< "largest set: " << largest_set <<endl;
        int largest_set_size = q.top().priority;
        //cout<< "largest set size: " << largest_set_size <<endl;

        if(largest_set_size < 1) {
            break;
        }

        if(elements_found.size() == n) {
            break;
        }

        q.pop();
        for(int value: sets_to_values_and_sizes[largest_set].first){
            elements_found.insert(value);
        }


        r[counter] = largest_set;
        counter++;

        std::unordered_set<int> values_in_largest_set = sets_to_values_and_sizes[largest_set].first;

        for(int value : values_in_largest_set) {
            //cout << "dealing with value " << value << endl;
            //cout << endl;
            while(!values_to_sets[value].empty()) {

                int head = values_to_sets[value].front();
                //cout << "dealing with set " << head << endl;
                sets_to_values_and_sizes[head].first.erase(value);
                sets_to_values_and_sizes[head].second--;
                //cout << "sets_to_values_and_sizes[head].second " << sets_to_values_and_sizes[head].second << endl;
                //cout << "dealing with q entry at key " << head << endl;
                q.update(head, sets_to_values_and_sizes[head].second);
                values_to_sets[value].pop_front();
                //cout << "new top priority: " << q.top().priority <<endl;
            }
        }
    }
    if(elements_found.size() < n) {
        k = 0;
    } else{
        k = counter;
    }
}