
int arraySum(int *a, int n) {
	int sum = 0;
	int i = 0;
	while(i<n){
	    sum+=a[i];
	    i++;
	}
	return sum;
}

int firstZero(int *a) {
    int index = 0;
    while(a[index] > 0) {
        index++;
    }
    return index;
}

void solver(int n, const int *a, const int *b, int *s)
{
    int *f = new int[n];
    int *t = new int[n];
    int i = 0;
    while(i < n) {
        f[i] = 0;
        t[i] = 0;
        s[i] = -1;
        i++;
    }
    
    while(arraySum(f, n) < n) {
        int proposer = firstZero(f);
        int preference = b[proposer * n + t[proposer]];
        if(s[preference] == -1) {
            s[preference] = proposer;
            f[proposer] = 1;
            
        } else {
            bool betterMatch = false;
            int i = 0;
            while(i < n){
                if(a[preference * n + i] == s[preference]) {
                    betterMatch = false;
                    break;
                }
                if(a[preference * n + i] == proposer) {
                    betterMatch = true;
                    break;
                }
                i++;
            }
            if(betterMatch){
                f[s[preference]] = 0;
                s[preference] = proposer;
                f[s[preference]] = 1;
            }
        }
        t[proposer]++;
    }
}