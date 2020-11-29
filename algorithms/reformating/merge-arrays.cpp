// Given two sorted vectors,
// merge them into a new sorted vector and return it
// O(n) time O(n) space

// by pushing back
vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector){
    
    vector<int> res;
    int i = 0;
    int j = 0;
    int size1 = myVector.size();
    int size2 = alicesVector.size();
    
    while(i < size1 && j < size2) {
        if(myVector[i] < alicesVector[j]){
            res.push_back(myVector[i]);
            ++i;
        } else {
            res.push_back(alicesVector[j]);
            ++j;
        }
    }
    
    while(i < size1) {
        res.push_back(myVector[i]);
        ++i;
    }
    
    while(j < size2) {
        res.push_back(alicesVector[j]);
        ++j;
    }

    return res;
}

// by creating vector of desired size initially and accessing by indices
vector<int> mergeVectors(const vector<int>& myVector, const vector<int>& alicesVector){

    int i = 0;
    int j = 0;
    int k = 0;
    int size1 = myVector.size();
    int size2 = alicesVector.size();
    vector<int> res(size1 + size2);
    
    while(i < size1 && j < size2) {
        if(myVector[i] < alicesVector[j]){
            res[k] = myVector[i];
            ++i;
        } else {
            res[k] = alicesVector[j];
            ++j;
        }
        ++k;
    }
    
    while(i < size1) {
        res[k] = myVector[i];
        ++i;
        ++k;
    }
    
    while(j < size2) {
        res[k] = alicesVector[j];
        ++j;
        ++k;
    }

    return res;
}