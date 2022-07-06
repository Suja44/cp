
int power(int a, int b) {
	int res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % mod;
		}
		a = (a * a) % mod;
		b /= 2;
	}
	return res;
}

vi primefac(int n){
	vi v;
	for(int i=2;i*i<=n;i++){
		while(n%i==0){
			v.pb(i);
			n/=i;
		}
     
	}
	if(n>1) v.pb(n);

	return v;
}

bool isprime(int n){
for(int i=2;i*i<=n;i++){
   if(n%i==0){
   return false;
   }
  }
 return true;
} 

int divisors(int n){
	int div_num=0;
	for (int i = 1; i * i <= x; i++) {
			if (x % i == 0) {
				div_num += i * i == x ? 1 : 2;
			}
		}
		
	return div_num;
}
