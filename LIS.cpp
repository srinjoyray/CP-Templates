int lis(long long a[],int n){
   set<int> se;
   for(int i=0;i<n;i++){
      auto it = se.lower_bound(a[i]);
      if(it!=se.end()){
         se.erase(it);
      }
      se.insert(a[i]);
   } 
   return se.size();
}