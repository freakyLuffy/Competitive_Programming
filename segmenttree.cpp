#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define ll long long
#define mod 1000000007LL
#define pb push_back
#pragma GCC target ("avx2")
#include<climits>
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define v(x,a,n) vector<x>a(n)
#define all(v) v.begin(),v.end()
#define dbg(x) cout<<#x<<"=="<<x<<"\n"
#define inf 1LL<<60
void solve(){
	int t;
	cin>>t;
	while(t--)
	{
		


		
	}
}
int a[10001],seg[4*10001],lazy[4*10001];
void build(int ind,int low,int high)
{
	if(low==high)
	{
		seg[ind]=a[low];
		return;
	}
	int mid=(low+high)/2;
	build(2*ind+1,low,mid);
	build(2*ind+2,mid+1,high);
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int query(int ind,int low,int high,int l,int r)
{  
	
	if(low>=l && high<=r)
	{
		return seg[ind];
	}
		if(high<l || low>r)
		return 0;

	int mid=(high+low)/2;
	int left=query(2*ind+1,low,mid,l,r);
	int right=query(2*ind+2,mid+1,high,l,r);

	return left+right;
}
void update(int ind,int low,int high,int val,int i)
{
	if (low == high) {
			seg[ind] = val;
			return;
		}
		int mid = (low + high) >> 1;
		if (i <= mid) update(2 * ind + 1, low, mid, val, i);
		else update(2 * ind + 2, mid + 1, high, val, i);
		seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
}
void rangeupd(int ind,int low,int high,int val ,int l,int r)
{
	if(lazy[ind]!=0)
	{
		seg[ind]+=(high-low+1)*val;
		if(high!=low)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];

		}
			lazy[ind]=0;
			return;
	}
		if(high<l || low>r || low>high)
		return;

	  if(low>=l && high<=r)
	  {
	  	seg[ind]+=(high-low+1)*val;
	  	if(low!=high)
	  	{
	  		lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];

	  	}
	  	return;
	  }
	  int mid=(low+high)/2;
	  rangeupd(2*ind+1,low,mid,val,l,r);
	  rangeupd(2*ind+2,mid+1,high,val,l,r);
	  seg[ind]+=seg[2*ind+1]+seg[2*ind+2];
}
int querysumlazy(int ind,int low,int high,int l,int r)
{
	if(lazy[ind]!=0)
	{
		seg[ind]+=(high-low+1)*lazy[ind];
		if(high!=low)
		{
			lazy[2*ind+1]+=lazy[ind];
			lazy[2*ind+2]+=lazy[ind];

		}
			lazy[ind]=0;
	}
		if(high<l || low>r || low>high)
		return 0;

	  if(low>=l && high<=r)
	  {
	  	return seg[ind];
	  }
	  int mid=(low+high)/2;
	  return querysumlazy(2*ind+1,low,mid,l,r)+querysumlazy(2*ind+2,mid+1,high,l,r);
}
int querysum(int ind,int low,int high,int l,int r)
{
	if(high<l || low>r)
	return 0;
	  if(low>=l && high<=r)
	  {
	  	return seg[ind];
	  }
	  int mid=(low+high)/2;
	  return querysumlazy(2*ind+1,low,mid,l,r)+querysumlazy(2*ind+2,mid+1,high,l,r);
}
int main() {
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	 build(0,0,n-1);
	 cout<<querysum(0,0,n-1,0,n-1);
	// update(0,0,n-1,9,4);
	/// cout<<query(0,0,n-1,0,n-1);
	// rangeupd(0,0,n-1,2,0,n-1);
//	cout<<querysum(0,0,n-1,1,2);
	return 0;
}
