ll mod_pow(ll a,ll b){
  ll res=1;
  while(b){
    if(b&1){ res=res*a%MOD; }
    a=a*a%MOD;
    b>>=1;
  }
  return res;
}
