// All sub-palindromes in O(N)
// Longest Palindromic Substring

void manacher(string s){
    int n=s.size();
    vector<int> d1(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
    vector<int> d2(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
            k++;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k ;
        }
    }
    for(int i=0;i<n;i++){
        d1[i]=2*d1[i]-1;
        d2[i]=2*d2[i];
    }
    
    // s  = b a b c b a a  b c b a c c b a 
    // d1 = 1 3 1 5 1 1 1  1 5 1 1 1 1 1 1 
    // d2 = 0 0 0 0 0 0 10 0 0 0 0 0 2 0 0

    
}