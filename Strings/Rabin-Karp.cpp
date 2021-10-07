// Strings s and t must be lower case
vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; 
    const int m1 = 1e9 + 7;
    const int m2 = 1e9 + 9;
    int S = s.size(), T = t.size();

    vector<long long> p_pow1(max(S, T)),p_pow2(max(S, T)); 
    p_pow1[0] = 1;
    p_pow2[0] = 1;
    for (int i = 1; i < (int)p_pow1.size(); i++){
        p_pow1[i] = (p_pow1[i-1] * p) % m1;
        p_pow2[i] = (p_pow2[i-1] * p) % m2;
    } 
        

    vector<long long> h1(T + 1, 0),h2(T + 1, 0); 
    for (int i = 0; i < T; i++){
        h1[i+1] = (h1[i] + (t[i] - 'a' + 1) * p_pow1[i]) % m1; 
        h2[i+1] = (h2[i] + (t[i] - 'a' + 1) * p_pow2[i]) % m2; 
    }
        
    long long h_s1 = 0, h_s2=0; 
    for (int i = 0; i < S; i++){
        h_s1 = (h_s1 + (s[i] - 'a' + 1) * p_pow1[i]) % m1; 
        h_s2 = (h_s2 + (s[i] - 'a' + 1) * p_pow2[i]) % m2; 
    } 

    vector<int> occurences;
    for (int i = 0; i + S - 1 < T; i++) { 
        long long cur_h1 = (h1[i+S] + m1 - h1[i]) % m1; 
        long long cur_h2 = (h2[i+S] + m2 - h2[i]) % m2; 
        if (cur_h1==(h_s1 * p_pow1[i])%m1 && cur_h2==(h_s2 * p_pow2[i])%m2)
            occurences.push_back(i);
    }
    return occurences;
}
// Sample
// s="aba" , t="ababa"
// occurences={0,2}