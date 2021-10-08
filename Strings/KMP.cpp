vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
// "abcabcd" = [0,0,0,1,2,3,0]
// "aabaaab" = [0,1,0,1,2,2,3]

vector<int> kmp_search(string s,string t) {
    int s_size=s.size(), t_size=t.size();
    string s1=t+'#'+s;
    vector<int> pi = prefix_function(s1),ans;
    for(int i=t_size+1;i<s1.size();i++){
        if(pi[i]==t_size){
            ans.pb(i-2*t_size);
        }
    }
    return ans;
}
// s="aabaab" , t="aa" ->  ans=[0,3]