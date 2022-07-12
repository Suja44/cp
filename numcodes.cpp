
int modulo(int x,int N){
    return (x % N + N) %N;
}

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

vi factors_n(int n){
	vi v(n+1,0);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			v[j]++;
		}
	}

	return v;
}

vi seiv(int n){
	vi primes(n+1,1);
	primes[1]=0;
	for(int i=2;i<=n;i++){
		if(!primes[i]){
			for(int j=i*i;j<=n;j+=i){
				primes[j]=0;
			}
		}
	}

	return primes;
}
